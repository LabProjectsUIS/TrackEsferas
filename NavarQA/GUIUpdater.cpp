#define _USE_MATH_DEFINES

#include "GUIUpdater.h"
#include "calibration.h"
#include "correspondence.h"
#include "drill.h"
#include "triangulation.h"
#include "pointcloud.h"
#include "globals.h"
#include "server.h"
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include <math.h>
#include <sstream>

using namespace std;
/**
* Constructor por defecto
*/
GUIUpdater::GUIUpdater(QObject *parent)
	: QObject(parent)
{
	showZone = true;
	takeSnapshot = false;
	doStartServer = true;
	tibiaFlag = false;
	femurFlag = false;
}

/**
* Destructor por defecto
*/
GUIUpdater::~GUIUpdater()
{
}

/**
*	 Obtiene una instancia de cada cámaras.
*	@return verdadero/falso si pudo/no pudo activar las dos cámaras.
*/
bool GUIUpdater::activateCameras() {
	// Obtener la lista de cámaras conectadas al switch.
	CameraLibrary::CameraManager::X().WaitForInitialization();
	camera_1 = CameraLibrary::CameraManager::X().GetCameraBySerial(SCAMERA_R);
	camera_2 = CameraLibrary::CameraManager::X().GetCameraBySerial(SCAMERA_L);
	if (!camera_1 || !camera_2) {
		return 1;
	}

	return 1;
}

/**
*	Configura el modo de video de las cámaras (modo Escala de grises)
*	y demás parámetros iniciales (exposición, intensidad y umbral).
*/
void GUIUpdater::startCameras() {
	camera_1->SetVideoType(Core::GrayscaleMode);
	camera_1->SetExposure(CustomCameraLibrary::exposure_cvalue);
	camera_1->SetThreshold(CustomCameraLibrary::threshold_cvalue);
	camera_1->SetIntensity(CustomCameraLibrary::intensity_cvalue);
	camera_1->SetName(CNAME_1);
	camera_1->Start();

	camera_2->SetVideoType(Core::GrayscaleMode);
	camera_2->SetExposure(CustomCameraLibrary::exposure_cvalue);
	camera_2->SetThreshold(CustomCameraLibrary::threshold_cvalue);
	camera_2->SetIntensity(CustomCameraLibrary::intensity_cvalue);
	camera_2->SetName(CNAME_2);
	camera_2->Start();
}

/**
*	Apaga las cámaras adecuadamente.
*/
void GUIUpdater::ShutDownCameras() {
	camera_1->Stop();
	camera_2->Stop();
	camera_1->Release();
	camera_2->Release();
	CameraLibrary::CameraManager::X().Shutdown();
}

/**
* Guarda un frame como imagen, en disco.
* @param fileName nombre de la imagen.
* @param img frame.
*/
void GUIUpdater::saveImage(std::string &fileName, cv::Mat img) {
	cv::imwrite(fileName, img);
}

/**
* Setter para showZone
* @param status nuevo estado
*/
void GUIUpdater::setShowZone(bool status) {
	showZone = status;
}

/**
* Setter para delta
* @param delta nuevo estado
*/
void GUIUpdater::setDelta(float delta) {
	this->delta = delta;
}

/**
* Setter para takeSnapshot
* @param status nuevo estado
*/
void GUIUpdater::setTakeSnapshot(bool status) {
	takeSnapshot = status;
}

/**
* Setter para Pics2Take
* @param numPics número de imágenes
*/
void GUIUpdater::setPics2Take(int numPics) {
	pics2Take = numPics;
}

/**
* Setter para detectRigids
* @param status nuevo estado
*/
void GUIUpdater::setDetectRigids(bool status) {
	detectRigids = status;
}

/**
* Setter para detectPointer
* @param status nuevo estado
*/
void GUIUpdater::setDetectPointer(bool status) {
	detectPointer = status;
}

/**
* Promedia los datos capturados y los devuelve organizados en una matriz
* @param datax coordenadas en x.
* @param datay coordenadas en y.
* @out matriz con coordenadas promediadas.
*/
void GUIUpdater::filter(cv::Mat_<double> datax, cv::Mat_<double> datay, cv::Mat_<double> out) {

	cv::reduce(datax, out.row(0), 0, CV_REDUCE_AVG);
	cv::reduce(datay, out.row(1), 0, CV_REDUCE_AVG);
}

/**
* Asocia las coordendas del centroide de cada uno de los huesos.
* @param centroid coordenadas en 3D del centroide del hueso.
* @param bone nombre del hueso al cual se le asociarán las coordenadas.
*/
void GUIUpdater::setCentroid(cv::Mat_<double> centroid, std::string& bone) {
	if (bone == "tibia") {
		tibiaCentroid = centroid;
		tibiaFlag = true;
	}
	else {
		femurCentroid = centroid;
		femurFlag = true;
	}
}



/**
* Calcula los ángulos de un vector en 3D respecto a cada plano
* @param vector vector al cual se le calcularán los ángulos.
* @out angles ángulos calculados.
*/
void GUIUpdater::getAngles(cv::Mat_<double>& vector, cv::Mat_<double>& angles) {
	double x, y, z, ax, ay, az;
	x = vector(0, 0);
	y = vector(1, 0);
	z = vector(2, 0);

	ax = atan2(sqrt(y*y + z*z), x);
	ax = ax * 180 / M_PI;
	ay = atan2(sqrt(x*x + z*z), y);
	ay = ay * 180 / M_PI;
	az = atan2(sqrt(y*y + x*x), z);
	az = az * 180 / M_PI;

	angles = (cv::Mat_<double>(3, 1) << ax, ay, az);
}

void GUIUpdater::setBroca(CustomCameraLibrary::BodyR &rigid, cv::Mat_<double> &data) {
	rigid.centroid = data.row(1).t();
	rigid.name = BROCA;
	rigid.Quat = data.row(0);
	rigid.bdr = 6;
	rigid.nmarkers = 4;
}

/**
* Envía los frames de cada una de las cámaras a la GUI mediante señales y controla la lógica de captura de imágenes.
*/
void GUIUpdater::ShowCameras() {
	pics2Take = 20;
	int cameraWidth_1 = camera_1->Width(); // Obtener la propiedad ancho de la resolucián de la cámara derecha.
	int cameraHeight_1 = camera_1->Height(); // Obtener la propiedad alto de la resolucián de la cámara derecha.

	int cameraWidth_2 = camera_2->Width();
	int cameraHeight_2 = camera_2->Height();

	cv::Point center((cameraWidth_1 - CustomCameraLibrary::square_size) / 2,
		(cameraHeight_1 - CustomCameraLibrary::square_size) / 2);

	int samples = 0;
	int c = 0;
	int launchCalib = pics2Take + 1;
	time_t t0, t1;

	cv::Mat matFrame_1(cv::Size(cameraWidth_1, cameraHeight_1), CV_8UC1);
	cv::Mat matFrame_2(cv::Size(cameraWidth_2, cameraHeight_2), CV_8UC1);
	const int BACKBUFFER_BITSPERPIXEL = 8;

	startCameras();
	int key = 0;

	cv::Mat gray, threshold_1, threshold_2;

	while (c <= pics2Take) {
		CameraLibrary::Frame *frame_1 = camera_1->GetLatestFrame();
		CameraLibrary::Frame *frame_2 = camera_2->GetLatestFrame();
		cv::Mat_<double> PP1, PP2, A1, A2, P1, P2, D1, D2;	// Matriz de Proyeccián de puntos x,y en la imagen, A1, A2, son las areas de las esferas
		cv::Mat_<double> XL, XR;					// Matriz de puntos 3D vistos desde la cámara izquierda/derecha

		t1 = time(0);
		if (c &&  delta < std::difftime(t1, t0))
			setTakeSnapshot(true);

		if (frame_1) {
			frame_1->Rasterize(cameraWidth_1, cameraHeight_1, matFrame_1.step, BACKBUFFER_BITSPERPIXEL, matFrame_1.data);

			if (showZone) {
				cv::rectangle(matFrame_1, center, center + cv::Point(CustomCameraLibrary::square_size, CustomCameraLibrary::square_size), cv::Scalar(0, 0, 255), 3);
			}
			if (takeSnapshot) {
				t0 = time(0);
				if (c) {
					std::stringstream fileName;
					fileName << "calib/right/Right" << std::setfill('0') << std::setw(2) << c << ".tif";
					saveImage(fileName.str(), matFrame_1);
					emit doFlash();
				}
				else {
					setTakeSnapshot(false);
					c++;
				}

			}
			QImage imdisplay((uchar*)matFrame_1.data, matFrame_1.cols, matFrame_1.rows, matFrame_1.step, QImage::Format_Grayscale8);
			emit updateLeftCamera(imdisplay);
			frame_1->Release();
		}
		if (frame_2) {
			frame_2->Rasterize(cameraWidth_2, cameraHeight_2, matFrame_2.step, BACKBUFFER_BITSPERPIXEL, matFrame_2.data);
			QImage imdisplay((uchar*)matFrame_2.data, matFrame_2.cols, matFrame_2.rows, matFrame_2.step, QImage::Format_Grayscale8);
			if (takeSnapshot) {
				std::stringstream fileName;
				fileName << "calib/left/Left" << std::setfill('0') << std::setw(2) << c << ".tif";
				saveImage(fileName.str(), matFrame_2);
				setTakeSnapshot(false);
				c++;
			}
			emit updateRightCamera(imdisplay);
			frame_2->Release();
		}
		QCoreApplication::processEvents();
	}

	if (c == launchCalib) {
		emit startCalibration();
	}

}

cv::Mat_<double> GUIUpdater::GetObjects2(CameraLibrary::Frame *frame, cv::Mat matFrame, cv::Mat_<double> &P, cv::Mat_<double> &A)
{
	int objects = frame->ObjectCount();
	cv::Mat_<double> PP(2, objects);

	if (objects > 0)
	{
		for (int i = 0; i <  objects; i++)
		{
			CameraLibrary::cObject *obj = frame->Object(i);
			if (obj->Area() > 20) {
				double x = obj->X();
				double y = obj->Y();

				ostringstream ostr;
				cv::Point textOrg(10, 500 + i * 20);
				ostr << "Objeto #" << i + 1 << ": X:" << x << "  Y:" << y;
				cv::String text = ostr.str();
				putText(matFrame, text, textOrg, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar::all(255), 0, false);

				//PP(0, i) = x;
				//PP(1, i) = y;

				for (int j = 0; j < PP.rows; j++) {
					switch (j)
					{
					case 0:
						PP(j, i) = x;
						break;
					case 1:
						PP(j, i) = y;
						break;
					default:
						break;
					}
				}
				A.push_back(obj->Area());
			}
		}
		PP.copyTo(P);
	}
	return PP;
}


//REALIZAR UN GETOBJECTS 2 -> QUE NO USE OPEN CV PARA RASTREO.

/**
*	Identifica marcadores detectados en la escena, toma cada una de sus propiedades tales como área y posición en pixeles
*	almacena la información recolectada en matrices pasadas por referencia.
*
*	ESTA FUNCIÓN UTILIZA LAS FUNCIONES DE RASTREOS DISEÑADAS CON OPENCV PARA RASTREAR LOS MARCADORES EN ESCENA Y FUNCNIONA SOLO EN MODO GRAYSCALE  DE LAS CÁMARAS.
*	@see cFrame::trackFilteredMarker()
*	@param cframe un frame de la cámara que se usa para extraer información de los marcadores que hay en la escena.
*	@param matFrame	una matriz de la imágen de la cámara, se utiliza para escribir en pantalla algunos datos de posición de los marcadores encontrados.
*	@param P matriz vacía para se llena con las coordenadas 2D en pixeles de cada marcador detectado.
*	@param A matriz vacía para se llena con las áreas de cada esfera detectada.
*	@return una matriz que contiene las coordenadas 2D en pixeles de los marcadores detectados.
*/
void GUIUpdater::GetObjects(CustomCameraLibrary::cFrame cframe, cv::Mat matFrame, cv::Mat_<double> &P, cv::Mat_<double> &A, cv::Mat_<double> &PP_Broca) {
	int objets = cframe.markerCount();
	int obj = 0;
	int c = 0;
	int modif = 0;
	//if (objets % 5 == 2) {
	//	modif = 2;
	//}
	//Mat_<double> PP(2, objets-modif); // Array de puntos del frame
	int NP_Broca = 0;
	//evaluar cuanto objetos son mayores de area que el area mas pequeña
	

	cv::Mat_<double> PP(2, objets); // Array de puntos del frame
	
	ofstream archivoL;
	if (!archivoL.is_open()) {
		archivoL.open("Matriz.txt", std::ios::app);

	}
	if (objets > 0) {
		
		switch (objets)
		{
		case 3: 
			modif = 0; break;
		case 5:
			modif = 0; break;
		case 8:
			modif = 1; break;
		case 10:
			modif = 0; break;
		case 13:
			modif = 2; break;
		case 15:
			modif = 0; break;
		case 18:
			modif = 2; break;
		default:
			break;
		}
		cv::Mat_<double> PP_B(2, objets - modif); //array de la broca
		//Mat_<double> AA(objets-modif, 1);
		cv::Mat_<double> AA(objets, 1);
		
		for (int i = 0; i < objets; i++) {
			CustomCameraLibrary::Marker obj = cframe.marker(i);

			//				if (obj.getArea() > 20) {
			double x = obj.getX();
			double y = obj.getY();
			double Eccentr = obj.getEccentr();
			double Area = obj.getArea();
			std::ostringstream ostr;
			cv::Point textOrg(10, 500 + i * 20);
			ostr << "Objeto #" << i + 1 << ": X:" << x << "  Y:" << y << " e:" << Eccentr << " Ar:" << Area;
			cv::String text = ostr.str();
			putText(matFrame, text, textOrg, cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar::all(255), 0, false);

			if (Area < 30) 
			{
				modif = modif + 1;
			}
			//Tratamiento broca
			/*if (Area > 90 && Area < 110)
				{
				PP_Broca(0, NP_Broca) = x;
				PP_Broca(1, NP_Broca) = y;
				NP_Broca = NP_Broca + 1;
				}
			else if(i < objets - modif)
			{
				PP(0, c) = x;
				PP(1, c) = y;
				AA(c, 0) = obj.getArea();
				c++;
				}
			else
			break;
			*/
			//se excluye la broca a un rango mas alto de areas para excluir la esfera mas pequeña de todas las herramientas
			double ar = Area;
			if (Area > 55) //el siguiente al elemento más pequeño, la esfera mas pequeña del pointer la mayor area detectada es 52
			{
				PP_B(0, NP_Broca) = x;
				PP_B(1, NP_Broca) = y;
				NP_Broca = NP_Broca + 1;
			}
				PP(0, c) = x;
				PP(1, c) = y;
				AA(c, 0) = obj.getArea();
				c++;		

			
			/*					for (int j = 0; j < PP.rows; j++) {
			switch (j)
			{
			case 0:
			PP(j, i) = x;
			break;
			case 1:
			PP(j, i) = y;
			break;
			default:
			break;
			}
			}
			*/
			//A.push_back(obj->Area());

			//				}
		}
		/*
		for (int i = 0; i < PP_B.rows-1; i++)
		{
			for (int j = 0; j < PP_B.cols -1; j++)
			{
				archivoL << "Broca:" << PP_B[i][j] << "\t";
			}
			archivoL << "\n";
		}*/

		//archivoL << PP << "\t";
		/*for (int i = 0; i < PP.rows; i++)
		{
			for (int j = 0; j < PP.cols; j++)
			{
				archivoL << PP[i][j] << "\t";
			}
			archivoL << "\n";
		}*/

		archivoL.close();
		/*archivoL << "filas:"<<PP.rows<<" ,columnas: "<<PP.cols<<"\n";
		for (int i = 0; i < PP.rows ; i++)
		{
			for (int j = 0; j < PP.cols ; j++)
			{
				//archivoL << PP[i][j] << "\t";
			}
			//archivoL << "\n";
		}
		archivoL.close();*/
		/*if (NP_Broca == 2) {
		Point P1,P2,Pa,Pb;
		Mat_<double> temp;
		P1.x = PP_Broca(0, 0);
		P1.y = PP_Broca(1, 0);
		P2.x = PP_Broca(0, 1);
		P2.y = PP_Broca(1, 1);

		int W = matFrame.cols-1;
		int H = matFrame.rows - 1;
		double m = (double(P2.y) - double(P1.y)) / (double(P2.x) - double(P1.x));
		double b = P1.y - m*P1.x;

		if (abs(m) < 1) {
		Pa.x = 0;
		Pa.y = b;
		Pb.x = W;
		Pb.y = m * W + b;
		PP_Broca.copyTo(temp);
		PP_Broca(0, 0) = temp(0, 1);
		PP_Broca(1, 0) = temp(1, 1);
		PP_Broca(0, 1) = temp(0, 0);
		PP_Broca(1, 1) = temp(1, 0);
		}
		else {
		Pa.x = -b/m;
		Pa.y = 0;
		Pb.x = (H-b) / m;
		Pb.y = H;
		}*/

		//line(matFrame, Pa, Pb, Scalar(255, 255, 255), 1, 8, 0);

		//}
		PP_B.copyTo(PP_Broca);
		PP.copyTo(P);
		AA.copyTo(A);
	}
}

/**
* Escribe a un archivo las coordenadas de los clavos y los ángulos de estos respecto a los huesos que les corresponden.
*/
void GUIUpdater::writeMatrices() {
	cv::Mat_<double> PP_Broca1(2, 2); // Array de puntos del frame con datos de los marcadores de la broca
	cv::Mat_<double> PP_Broca2(2, 2); // Array de puntos del frame con datos de los marcadores de la broca
	int cameraWidth_1 = camera_1->Width(); // Obtener la propiedad ancho de la resolucián de la cámara derecha.
	int cameraHeight_1 = camera_1->Height(); // Obtener la propiedad alto de la resolucián de la cámara derecha.

	int cameraWidth_2 = camera_2->Width();
	int cameraHeight_2 = camera_2->Height();

	int samples = 0;
	int sample_limit = 2;

	int erosion_type = cv::MORPH_CROSS;
	int erosion_size = 2;

	int key = 0;

	startCameras();

	DWORD wResult;

	cv::Mat matFrame_1(cv::Size(cameraWidth_1, cameraHeight_1), CV_8UC1);
	cv::Mat matFrame_2(cv::Size(cameraWidth_2, cameraHeight_2), CV_8UC1);
	const int BACKBUFFER_BITSPERPIXEL = 8;

	cv::Mat erosion_1, erosion_2;

	cv::Mat gray, threshold_1, threshold_2;

	cv::Mat element = cv::getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	cv::Mat_<double> P1_x_acum, P2_x_acum, P1_y_acum, P2_y_acum;

	//CustomCameraLibrary::initPython(1024, 1280);

	cv::Mat_<double> temporal, angles;
	FILE *fp = fopen("Resources/Casos/1/matriz.csv", "w");

	while (femurFlag && tibiaFlag) {
		CameraLibrary::Frame *frame_1 = camera_1->GetLatestFrame();
		CameraLibrary::Frame *frame_2 = camera_2->GetLatestFrame();
		cv::Mat_<double> PP1, PP2, A1, A2, P1, P2, D1, D2;	// Matriz de Proyeccián de puntos x,y en la imagen, A1, A2, son las areas de las esferas
		cv::Mat_<double> XL, XR;					// Matriz de puntos 3D vistos desde la cámara izquierda/derecha 
													//			BodyR *rigid;
		CustomCameraLibrary::cFrame cframe_1, cframe_2;

		if (frame_1) {
			frame_1->Rasterize(cameraWidth_1, cameraHeight_1, matFrame_1.step, BACKBUFFER_BITSPERPIXEL, matFrame_1.data);
			//				matFrame_1.copyTo(matFrame);
			//				ReleaseSemaphore(drillSemaphore, 1, NULL);

			cv::threshold(matFrame_1, threshold_1, CustomCameraLibrary::threshold_value,
				CustomCameraLibrary::max_BINARY_value, CustomCameraLibrary::threshold_type); // thresholding a la imágen para aislar los marcadores de la escena

			erode(threshold_1, erosion_1, element); // Aplicar la operación de erosion

			CustomCameraLibrary::Marker marker; // Crear un objeto temporal para encontrar los marcadores
			cframe_1.trackFilteredMarker(marker, threshold_1, cframe_1, matFrame_1);
			GetObjects(cframe_1, matFrame_1, PP1, A1, PP_Broca1);

			//CustomCameraLibrary::CorrespondenceDetection(PP1, A1, P1, PP_Broca1);
			frame_1->Release();
		}
		if (frame_2) {
			frame_2->Rasterize(cameraWidth_2, cameraHeight_2, matFrame_2.step, BACKBUFFER_BITSPERPIXEL, matFrame_2.data);
			//				matFrame_2.copyTo(matFrame);
			//				ReleaseSemaphore(drillSemaphore, 1, NULL);

			cv::threshold(matFrame_2, threshold_2, CustomCameraLibrary::threshold_value, CustomCameraLibrary::max_BINARY_value, CustomCameraLibrary::threshold_type); // thresholding a la imágen para aislar los marcadores de la escena

			erode(threshold_2, erosion_2, element); // Aplicar la operación de erosion

			CustomCameraLibrary::Marker marker; // Crear un objeto temporal para encontrar los marcadores
			cframe_2.trackFilteredMarker(marker, threshold_2, cframe_2, matFrame_2);
			GetObjects(cframe_2, matFrame_2, PP2, A2, PP_Broca2);

			//CustomCameraLibrary::CorrespondenceDetection(PP2, A2, P2, PP_Broca2);
			frame_2->Release();
		}

		if ((!P1.empty() && !P2.empty()) && (P1.cols == P2.cols)) {

			if (samples < sample_limit) {
				if (P1.cols == P1_x_acum.cols) {
					P1_x_acum.push_back(P1.row(0));
					P1_y_acum.push_back(P1.row(1));
					P2_x_acum.push_back(P2.row(0));
					P2_y_acum.push_back(P2.row(1));
					samples++;
				}
				else {
					samples = 1;
					P1_x_acum = P1.row(0);
					P1_y_acum = P1.row(1);
					P2_x_acum = P2.row(0);
					P2_y_acum = P2.row(1);
				}
			}
			else {
				samples = 0;
				if (P1.cols == P1_x_acum.cols) {
					filter(P1_x_acum, P1_y_acum, P1);
					filter(P2_x_acum, P2_y_acum, P2);
					P1_x_acum.release(); P2_x_acum.release(); P1_y_acum.release(); P2_y_acum.release();
					CustomCameraLibrary::stereo_triangulation(P2, P1, cdata::om, cdata::T, cdata::fc_left,
						cdata::cc_left, cdata::kc_left, 0, cdata::fc_right, cdata::cc_right,
						cdata::kc_right, 0, XL, XR);

					CustomCameraLibrary::rigid = new CustomCameraLibrary::BodyR[cdata::distances.rows];
					CustomCameraLibrary::nbr = CustomCameraLibrary::joskstra(XL.t(), cdata::distances, CustomCameraLibrary::rigid);
					if (CustomCameraLibrary::nbr > 0) {
						for (int f = 0; f < CustomCameraLibrary::nbr; f++) {
							if (CustomCameraLibrary::rigid[f].name == FEMUR && femurFlag) {
								if (CustomCameraLibrary::rigid[f].centroid(0) != 0) {
									temporal = (CustomCameraLibrary::rigid[f].centroid - femurCentroid) / 1000;
									fprintf(fp, "%f,%f,%f\n", temporal(0, 0), temporal(1, 0), temporal(2, 0));
									getAngles(temporal, angles);
									//fprintf(fp, "%f,%f,%f\n", angles(0, 0), angles(1, 0), angles(2, 0));
									fprintf(fp, "%f,%f,%f,%f\n", CustomCameraLibrary::rigid[f].Quat(0, 0), CustomCameraLibrary::rigid[f].Quat(0, 1), CustomCameraLibrary::rigid[f].Quat(0, 2), CustomCameraLibrary::rigid[f].Quat(0, 3));
									femurFlag = false;
								}
							}
							if (CustomCameraLibrary::rigid[f].name == TIBIA && tibiaFlag) {
								if (CustomCameraLibrary::rigid[f].centroid(0, 0) != 0) {
									temporal = (CustomCameraLibrary::rigid[f].centroid - tibiaCentroid) / 1000;
									fprintf(fp, "%f,%f,%f\n", temporal(0, 0), temporal(1, 0), temporal(2, 0));
									getAngles(temporal, angles);
									fprintf(fp, "%f,%f,%f\n", angles(0, 0), angles(1, 0), angles(2, 0));
									tibiaFlag = false;
								}
							}
						}
					}
				}
			}
		}
		QCoreApplication::processEvents();
	}
	fclose(fp);
}

/**
* Detecta los rígidos en escena, inicia el servidor y lo utiliza para enviar los datos a la escena de Unity.
*/
void GUIUpdater::getRigidsData() {
	//cv::Mat_<double> PP_Broca1(2, 2); // Array de puntos del frame con datos de los marcadores de la broca
	//cv::Mat_<double> PP_Broca2(2, 2); // Array de puntos del frame con datos de los marcadores de la broca

	cv::Mat_<double> XBrocaNew(2, 4);

	detectRigids = true;
	doStartServer = true;
	int cameraWidth_1 = camera_1->Width(); // Obtener la propiedad ancho de la resolucián de la cámara derecha.
	int cameraHeight_1 = camera_1->Height(); // Obtener la propiedad alto de la resolucián de la cámara derecha.

	int cameraWidth_2 = camera_2->Width();
	int cameraHeight_2 = camera_2->Height();

	int samples = 0;
	int samplesbr = 0;
	int sample_limit = 1;
	int sample_limitBr = 1;

	int erosion_type = cv::MORPH_CROSS;
	int erosion_size = 2;

	int key = 0;

	startCameras();

	DWORD wResult;

	cv::Mat matFrame_1(cv::Size(cameraWidth_1, cameraHeight_1), CV_8UC1);
	cv::Mat matFrame_2(cv::Size(cameraWidth_2, cameraHeight_2), CV_8UC1);
	const int BACKBUFFER_BITSPERPIXEL = 8;

	//CustomCameraLibrary::initPython(1024, 1280);

	cv::Mat erosion_1, erosion_2;

	cv::Mat gray, threshold_1, threshold_2;

	cv::Mat element = cv::getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	cv::Mat_<double> P1_x_acum, P2_x_acum, P1_y_acum, P2_y_acum;
	cv::Mat_<double> P1Br_x_acum, P2Br_x_acum, P1Br_y_acum, P2Br_y_acum;
	//CustomCameraLibrary::Cloud Pointer(fileName, AUTO);

	//ADICIONADO PARA VERIFICAR DATOS ENVIADOS
	const char* fileNameVer = "C:\\Users\\eduar_000\\Documents\\Borrar\\Datos_Broca.txt";
	FILE *fp = fopen(fileNameVer, "w");
	int Cont = 0;

	cv::Mat_<double> temporal, angles;

	while (detectRigids) {
		CameraLibrary::Frame *frame_1 = camera_1->GetLatestFrame();
		CameraLibrary::Frame *frame_2 = camera_2->GetLatestFrame();
		cv::Mat_<double> PP1, PP2, A1, A2, P1, P2, D1, D2, PP_Broca1, PP_Broca2;	// Matriz de Proyeccián de puntos x,y en la imagen, A1, A2, son las areas de las esferas
		cv::Mat_<double> XL, XR, XBroca, XLBroca, XRBroca;					// Matriz de puntos 3D vistos desde la cámara izquierda/derecha 
																			//			BodyR *rigid;
		CustomCameraLibrary::cFrame cframe_1, cframe_2;

		//PP_Broca1(1, 0) = 9999;
		//PP_Broca2(1, 0) = 9999;
		if (frame_1) {
			frame_1->Rasterize(cameraWidth_1, cameraHeight_1, matFrame_1.step, BACKBUFFER_BITSPERPIXEL, matFrame_1.data);
			//				matFrame_1.copyTo(matFrame);
			//				ReleaseSemaphore(drillSemaphore, 1, NULL);

			cv::threshold(matFrame_1, threshold_1, CustomCameraLibrary::threshold_value,
				CustomCameraLibrary::max_BINARY_value, CustomCameraLibrary::threshold_type); // thresholding a la imágen para aislar los marcadores de la escena

																							 //erode(threshold_1, erosion_1, element); // Aplicar la operación de erosion

			CustomCameraLibrary::Marker marker; // Crear un objeto temporal para encontrar los marcadores
			cframe_1.trackFilteredMarker(marker, threshold_1, cframe_1, matFrame_1);
			GetObjects(cframe_1, matFrame_1, PP1, A1, PP_Broca1);

			//CustomCameraLibrary::CorrespondenceDetection(PP1, A1, P1, PP_Broca1);
			//P1 = CustomCameraLibrary::CorrespondenceDetection(PP1, A1, P1, PP_Broca1);
			P1 = CustomCameraLibrary::CorrespondenceDetection(PP1, A1, PP_Broca1);
			imshow("Camara Derecha", matFrame_1);
			frame_1->Release();
		}
		if (frame_2) {
			frame_2->Rasterize(cameraWidth_2, cameraHeight_2, matFrame_2.step, BACKBUFFER_BITSPERPIXEL, matFrame_2.data);
			//				matFrame_2.copyTo(matFrame);
			//				ReleaseSemaphore(drillSemaphore, 1, NULL);

			cv::threshold(matFrame_2, threshold_2, CustomCameraLibrary::threshold_value, CustomCameraLibrary::max_BINARY_value, CustomCameraLibrary::threshold_type); // thresholding a la imágen para aislar los marcadores de la escena

																																									  //erode(threshold_2, erosion_2, element); // Aplicar la operación de erosion

			CustomCameraLibrary::Marker marker; // Crear un objeto temporal para encontrar los marcadores
			cframe_2.trackFilteredMarker(marker, threshold_2, cframe_2, matFrame_2);
			GetObjects(cframe_2, matFrame_2, PP2, A2, PP_Broca2);

			//P2 = CustomCameraLibrary::CorrespondenceDetection(PP2, A2, P2, PP_Broca2);
			//CustomCameraLibrary::CorrespondenceDetection(PP2, A2, P2, PP_Broca2);
			P2 = CustomCameraLibrary::CorrespondenceDetection(PP2, A2, PP_Broca2);
			imshow("Camara Izquierda", matFrame_2);
			frame_2->Release();
		}
		if ((!PP_Broca1.empty() && !PP_Broca2.empty()) && (PP_Broca1.cols == PP_Broca2.cols)) {
			bool flag = true;
			if (samplesbr < sample_limitBr)
			{
				if (PP_Broca1.cols == P1Br_x_acum.cols) {
					P1Br_x_acum.push_back(PP_Broca1.row(0));
					P1Br_y_acum.push_back(PP_Broca1.row(1));
					P2Br_x_acum.push_back(PP_Broca2.row(0));
					P2Br_y_acum.push_back(PP_Broca2.row(1));
					samplesbr++;
				}
				else {
					samplesbr = 1;
					P1Br_x_acum = PP_Broca1.row(0);
					P1Br_y_acum = PP_Broca1.row(1);
					P2Br_x_acum = PP_Broca2.row(0);
					P2Br_y_acum = PP_Broca2.row(1);
				}
			}
			else {
				samplesbr = 0;
				if (PP_Broca1.cols == P1Br_x_acum.cols) {
					filter(P1Br_x_acum, P1Br_y_acum, PP_Broca1);
					filter(P2Br_x_acum, P2Br_y_acum, PP_Broca2);
					P1Br_x_acum.release(); P2Br_x_acum.release(); P1Br_y_acum.release(); P2Br_y_acum.release();
				}
				Beep(480, 50);

				CustomCameraLibrary::stereo_triangulation(PP_Broca2, PP_Broca1, cdata::om, cdata::T, cdata::fc_left,
					cdata::cc_left, cdata::kc_left, 0, cdata::fc_right, cdata::cc_right,
					cdata::kc_right, 0, XLBroca, XRBroca);


				//COMPARAR DISTANCIAS
				int s = 0;
				CustomCameraLibrary::rigid = new CustomCameraLibrary::BodyR[cdata::BrocaDis.rows + 1];
				CustomCameraLibrary::nbr = CustomCameraLibrary::joskstra(XLBroca.t(), cdata::distances, CustomCameraLibrary::rigid);

			}
		}
		if ((!P1.empty() && !P2.empty()) && (P1.cols == P2.cols))
		{
			Beep(350, 50);

			if (samples < sample_limit)
			{
				if (P1.cols == P1_x_acum.cols) {
					P1_x_acum.push_back(P1.row(0));
					P1_y_acum.push_back(P1.row(1));
					P2_x_acum.push_back(P2.row(0));
					P2_y_acum.push_back(P2.row(1));
					samples++;
				}
				else {
					samples = 1;
					P1_x_acum = P1.row(0);
					P1_y_acum = P1.row(1);
					P2_x_acum = P2.row(0);
					P2_y_acum = P2.row(1);
				}
			}
			else {
				samples = 0;
				if (P1.cols == P1_x_acum.cols) {
					filter(P1_x_acum, P1_y_acum, P1);
					filter(P2_x_acum, P2_y_acum, P2);
					P1_x_acum.release(); P2_x_acum.release(); P1_y_acum.release(); P2_y_acum.release();

					CustomCameraLibrary::stereo_triangulation(P2, P1, cdata::om, cdata::T, cdata::fc_left,
						cdata::cc_left, cdata::kc_left, 0, cdata::fc_right, cdata::cc_right,
						cdata::kc_right, 0, XL, XR);

					if (doStartServer) { // iniciar servidor y capturar los cuerpor rigidos en escena para crear la descripcion de ellos
						CustomCameraLibrary::rigid = new CustomCameraLibrary::BodyR[cdata::distances.rows + 1];
						CustomCameraLibrary::nbr = CustomCameraLibrary::joskstra(XL.t(), cdata::distances, CustomCameraLibrary::rigid);

						//OutputDebugString(L"nbr es.. "+ CustomCameraLibrary::nbr);
						CustomCameraLibrary::StartServer();
						doStartServer = false;
						CustomCameraLibrary::StreamFrame();
						emit startServer();
					}

					wResult = WaitForSingleObject(CustomCameraLibrary::sSemaphore, INFINITE);	// espera por la indicación del semáforo para seguir el hilo de ejecución//
					if (wResult == WAIT_OBJECT_0) {
						CustomCameraLibrary::rigid = new CustomCameraLibrary::BodyR[cdata::distances.rows + 1];
						CustomCameraLibrary::nbr = CustomCameraLibrary::joskstra(XL.t(), cdata::distances, CustomCameraLibrary::rigid);

						//TRIANGULANDO BROCA

						//if (PP_Broca1(1, 0) != 9999 && PP_Broca2(1, 0) != 9999) {

						//JOSKSTRA PARA BROCA
						int N = 1;
						if (CustomCameraLibrary::nbr > 0)
						{
							for (int f = 0; f < CustomCameraLibrary::nbr; f++) {
								if (CustomCameraLibrary::rigid[f].name == POINTER)
								{
									emit pointerDetected();
								}
								if (f == CustomCameraLibrary::nbr)
									emit pointerNotDetected();
							}
						}
						else
							emit pointerNotDetected();
						//XBroca = XLBroca.t();
						//XBroca = CustomCameraLibrary::initDrill(matFrame_1, matFrame_2, PP_Broca1, PP_Broca2);

						/*XBrocaNew(0, 0) = 0;
						XBrocaNew(0, 1) = 0;
						XBrocaNew(0, 2) = 0;
						XBrocaNew(1, 0) = 1;
						XBrocaNew(1, 1) = 3;
						XBrocaNew(1, 2) = 2;*/

						/*XBrocaNew(0, 0) = XLBroca(0, 0);
						XBrocaNew(0, 1) = XLBroca(1, 0);
						XBrocaNew(0, 2) = XLBroca(2, 0);
						XBrocaNew(1, 0) = XLBroca(0, 1);
						XBrocaNew(1, 1) = XLBroca(1, 1);
						XBrocaNew(1, 2) = XLBroca(2, 1);
						XBrocaNew(0, 3) = 0;
						XBrocaNew(1, 3) = 0;
						setBroca(CustomCameraLibrary::rigid[CustomCameraLibrary::nbr], XBrocaNew);*/
						//setBroca(CustomCameraLibrary::rigid[CustomCameraLibrary::nbr], XBroca);

						CustomCameraLibrary::nbr++;

						// ADICIONADO 
						/*if(Cont>=0){
						fprintf(fp, "DER Pix: %f\t%f\t%f\t%f\n", PP_Broca1(0,0), PP_Broca1(1, 0), PP_Broca1(0, 1), PP_Broca1(1, 1));
						fprintf(fp, "IZQ PIX: %f\t%f\t%f\t%f\n", PP_Broca2(0, 0), PP_Broca2(1, 0), PP_Broca2(0, 1), PP_Broca2(1, 1));
						fprintf(fp, "XLBroca:\n");
						fprintf(fp, "%f\t%f\t%f\n", XLBroca(0, 0), XLBroca(1, 0), XLBroca(2, 0));
						fprintf(fp, "%f\t%f\t%f\n", XLBroca(0, 1), XLBroca(1, 1), XLBroca(2, 1));*/
						/*fprintf(fp, "XBroca:\n");
						fprintf(fp, "XBroca: %f\t%f\t%f\n", XBroca(0, 0), XBroca(0, 1), XBroca(0, 2));
						fprintf(fp, "%f\t%f\t%f\n", XBroca(1, 0), XBroca(1, 1), XBroca(1, 2));*/

						//if (Cont >= 0){
						//fprintf(fp, "XBROCA: Cont=%d\n", Cont);
						//for (int ii = 0; ii < XBroca.rows; ii++) {
						//	for (int jj = 0; jj < XBroca.cols; jj++) {
						//	fprintf(fp, "%f\t",XBroca(ii, jj));
						//}
						//	fprintf(fp, "\n");
						//}
						//fprintf(fp, "\n\n");
						//}

						//	std::ostringstream ostr, ostr2;
						//	std::string text = "";// ostr.str();
						//	ostr << "C:\\Users\\eduar_000\\Documents\\Borrar\\Derecha" << Cont << ".tif";
						//	text = ostr.str();
						//	imwrite(text, matFrame_1);
						//	ostr2 << "C:\\Users\\eduar_000\\Documents\\Borrar\\Izquierda" << Cont << ".tif";
						//	text = ostr2.str();
						//	imwrite(text, matFrame_2);
						//	Cont = Cont + 1;
						//		if (Cont == 5) {
						//			fclose(fp);
						//			Beep(800, 1200);
						//			Cont = -1;
						//		}
						//}

					}
					if (CustomCameraLibrary::nbr > 0) {
						if (!ReleaseSemaphore(CustomCameraLibrary::brSemaphore, 1, NULL))
							printf("ReleaseSemaphore error: %d\n", GetLastError());
					}
					else if (!ReleaseSemaphore(CustomCameraLibrary::sSemaphore, 1, NULL))
						printf("ReleaseSemaphore error: %d\n", GetLastError());
				}
			}
		}

		QCoreApplication::processEvents();
	}
	CustomCameraLibrary::StreamFrame();
	//Beep(500, 500);
}

/**
* Si detecta el pointer, almacena los puntos barridos en un archivo. También emite señales para indicar si se está
* detectando o no el pointer en el momento.
* @param fileName nombre del archivo.
*/
bool GUIUpdater::getPointerData(const std::string &fileName) {
	detectPointer = true;
	cv::Mat_<double> PP_Broca1(2, 2); // Array de puntos del frame con datos de los marcadores de la broca
	cv::Mat_<double> PP_Broca2(2, 2); // Array de puntos del frame con datos de los marcadores de la broca
	int cameraWidth_1 = camera_1->Width(); // Obtener la propiedad ancho de la resolución de la cámara derecha.
	int cameraHeight_1 = camera_1->Height(); // Obtener la propiedad alto de la resolución de la cámara derecha.

	int cameraWidth_2 = camera_2->Width();
	int cameraHeight_2 = camera_2->Height();

	int samples = 0;
	int sample_limit = 30;

	int erosion_type = cv::MORPH_CROSS;
	int erosion_size = 2;

	int punto = 0;
	int key = 0;

	cv::Mat matFrame_1(cv::Size(cameraWidth_1, cameraHeight_1), CV_8UC1);
	cv::Mat matFrame_2(cv::Size(cameraWidth_2, cameraHeight_2), CV_8UC1);
	const int BACKBUFFER_BITSPERPIXEL = 8;

	cv::Mat erosion_1, erosion_2;

	startCameras();

	cv::Mat gray, threshold_1, threshold_2;

	CustomCameraLibrary::Cloud Pointer(fileName, AUTO);

	//CustomCameraLibrary::initPython(1024, 1280);

	cv::Mat element = cv::getStructuringElement(erosion_type,
		cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1),
		cv::Point(erosion_size, erosion_size));
	cv::Mat_<double> P1_x_acum, P2_x_acum, P1_y_acum, P2_y_acum;

	while (detectPointer) {
		CameraLibrary::Frame *frame_1 = camera_1->GetLatestFrame();
		CameraLibrary::Frame *frame_2 = camera_2->GetLatestFrame();
		cv::Mat_<double> PP1, PP2, A1, A2, P1, P2, D1, D2;	// Matriz de Proyeccián de puntos x,y en la imagen, A1, A2, son las areas de las esferas
		cv::Mat_<double> XL, XR;					// Matriz de puntos 3D vistos desde la cámara izquierda/derecha 
													//			BodyR *rigid;
		CustomCameraLibrary::cFrame cframe_1, cframe_2;

		if (frame_1) {
			frame_1->Rasterize(cameraWidth_1, cameraHeight_1, matFrame_1.step, BACKBUFFER_BITSPERPIXEL, matFrame_1.data);
			//				matFrame_1.copyTo(matFrame);
			//				ReleaseSemaphore(drillSemaphore, 1, NULL);

			cv::threshold(matFrame_1, threshold_1, CustomCameraLibrary::threshold_value,
				CustomCameraLibrary::max_BINARY_value, CustomCameraLibrary::threshold_type); // thresholding a la imágen para aislar los marcadores de la escena

			erode(threshold_1, erosion_1, element); // Aplicar la operación de erosion

			CustomCameraLibrary::Marker marker; // Crear un objeto temporal para encontrar los marcadores
			cframe_1.trackFilteredMarker(marker, threshold_1, cframe_1, matFrame_1);
			GetObjects(cframe_1, matFrame_1, PP1, A1, PP_Broca1);

			CustomCameraLibrary::CorrespondenceDetection(PP1, A1, PP_Broca1);
			frame_1->Release();
		}
		if (frame_2) {
			frame_2->Rasterize(cameraWidth_2, cameraHeight_2, matFrame_2.step, BACKBUFFER_BITSPERPIXEL, matFrame_2.data);
			//				matFrame_2.copyTo(matFrame);
			//				ReleaseSemaphore(drillSemaphore, 1, NULL);

			cv::threshold(matFrame_2, threshold_2, CustomCameraLibrary::threshold_value, CustomCameraLibrary::max_BINARY_value, CustomCameraLibrary::threshold_type); // thresholding a la imágen para aislar los marcadores de la escena

			erode(threshold_2, erosion_2, element); // Aplicar la operación de erosion

			CustomCameraLibrary::Marker marker; // Crear un objeto temporal para encontrar los marcadores
			cframe_2.trackFilteredMarker(marker, threshold_2, cframe_2, matFrame_2);
			GetObjects(cframe_2, matFrame_2, PP2, A2, PP_Broca2);

			CustomCameraLibrary::CorrespondenceDetection(PP2, A2,PP_Broca2);
			frame_2->Release();
		}
		if ((!P1.empty() && !P2.empty()) && (P1.cols == P2.cols)) {

			if (samples < sample_limit) {
				if (P1.cols == P1_x_acum.cols) {
					P1_x_acum.push_back(P1.row(0));
					P1_y_acum.push_back(P1.row(1));
					P2_x_acum.push_back(P2.row(0));
					P2_y_acum.push_back(P2.row(1));
					samples++;
				}
				else {
					samples = 1;
					P1_x_acum = P1.row(0);
					P1_y_acum = P1.row(1);
					P2_x_acum = P2.row(0);
					P2_y_acum = P2.row(1);
				}
			}
			else {
				samples = 0;
				if (P1.cols == P1_x_acum.cols) {
					filter(P1_x_acum, P1_y_acum, P1);
					filter(P2_x_acum, P2_y_acum, P2);
					P1_x_acum.release(); P2_x_acum.release(); P1_y_acum.release(); P2_y_acum.release();
					samples = 0;
					CustomCameraLibrary::stereo_triangulation(P2, P1, cdata::om, cdata::T, cdata::fc_left,
						cdata::cc_left, cdata::kc_left, 0, cdata::fc_right, cdata::cc_right,
						cdata::kc_right, 0, XL, XR);
					CustomCameraLibrary::rigid = new CustomCameraLibrary::BodyR[cdata::distances.rows];
					CustomCameraLibrary::nbr = CustomCameraLibrary::joskstra(XL.t(), cdata::distances, CustomCameraLibrary::rigid);
					if (CustomCameraLibrary::nbr > 0) 
					{
						for (int f = 0; f < CustomCameraLibrary::nbr; f++) {
							if (CustomCameraLibrary::rigid[f].name == POINTER) {
								emit pointerDetected();
								if (CustomCameraLibrary::rigid[f].point.x != NULL) {
									key++;
									Pointer.savePoint(CustomCameraLibrary::rigid[f].point, key);
									if (key == 200) {
										return 1;
									}
									break;
								}
							}
							if (f == CustomCameraLibrary::nbr)
								emit pointerNotDetected();
						}
					}
					else
						emit pointerNotDetected();
				}
			}
		}
		QCoreApplication::processEvents();
	}
	return 0;
}