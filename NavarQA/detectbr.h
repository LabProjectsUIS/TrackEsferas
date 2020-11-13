#ifndef _DETECTBR_H_
#define _DETECTBR_H_

#include <iomanip>
#include <stdio.h>
#include <tchar.h>
#include <windows.h>
#include<stdlib.h>
#include<fstream>
//#include <calibration.h>
#include <iostream> 
#include "data.h"
#include "opencv\cv.hpp"
#include <time.h>
#include <dos.h>
#include "globals.h"
#include <math.h>


namespace CustomCameraLibrary {
	using namespace cv;
	using namespace std;

#define PI 3.14159265
#define N_MARKERS 2				///< número de marcadores que la función joskstra() usa para determinar si se ha detectado un cuerpo rígido; es decir, si detecta más marcadores que este valor entonces ha detectado un cuerpo rígido.
#define N_MARKERSB 2
	//		cout << A << endl;
#define L_POINTER   219.70329913564//219.3295732//221.88//218.91
#define TETHA -3.8985//-3.503764268//3.0544//3.17
#define C_TETHA -0.95278		// corrercción del 1er giro
#define TETHA2  -2.5782			///< ángulo de la segunda rotación
#define L_POINTER2 222.1898		///< longitud del pointer, de la punta hasta la primera esfera.

#define FEMUR "FEMUR"			///< nombre que representa el femur
#define POINTER "POINTER"		///< nombre que representa el pointer
#define TIBIA "TIBIA"			///< nombre que representa la tíbia
#define GAFAS "GAFAS"			///< nombre que representa las gafas
#define PHANTON "PHANTON"		///< nombre que representa el phanton
#define BROCA "BROCA"

	const int pointer = 1;	///< indicador que representa el pointer
	const int femur = 2;	///< indicador que representa el femur
	const int tibia = 3;	///< indicador que representa la tibia
	const int gafas = 4;	///< indicador que representa las gafas
	const int phanton = 6;	///< indicador que representa el phanton
	const int broca = 5;///< indicador que representa la broca

	float DELTA = 1.5;	///< Error máximo entre la comparación de dos distancias al momento de decidir si se ha encontrado un marcador de un cuerpo rígido (en milímetro).
	bool detect_broca=false;
	bool detect_pointer = true;		///< indicador para manejar la decisión de detectar o no el pointer.
									//	Mat_<double> ejeR3 = (Mat_<double>(3, 1) << -0.086793, 0.93612, -0.34081);				// eje de rotación del pointer

									/** @struct Output
									*  @brief Esta estructura permite almacenar las características de los cuerpos rígidos que vayan siendo detectados en mientras se esta ejecutando la
									*  la función CustomCameraLibrary::joskstra()
									*  @var Output::bdr
									*  Contiene el número que identifica un cuerpo rígido, los números que identifican a un cuerpo rígido son:
									- Pointer = 1
									- Femur = 2
									- Tíbia = 3
									- Gafas = 4

									* Este orden es obtenido de la matriz de distancias de cuerpos rígidos.
									@see CustomCameraLibrary::distances
									*  @var Output::name
									*  Nombre del objeto rígido (FEMUR, POINTER, TIBIA, GAFAS).
									*  @var Output::bdrigid
									*  Matriz que contiene las coordenadas \a x, \a y, \a z de un cuerpo rígido detectado.
									*  @var Output::centroid
									*  Matriz 3x1 que contiene la coordenada del centro del circulo que forma los marcadores que componen el cuerpo rígido.
									*  @var Output::nmarkers
									*  Número de marcadores que forman el cuerpo rígido.
									*  @var Output::yaw
									*  Ángulo de euler en grados.
									*  @var Output::pitch
									*  Ángulo de euler en grados.
									*  @var Output::roll
									*  Ángulo de euler en grados.
									*  @var Output::point
									*  Si el objeto rígido detectado es el pointer entonces esta propiedad tendrá el valor del punto que toca la punta, de lo contrario será nulo el valor.
									*  @var Output::Quat
									*  Cuaternios que representan la orientación del objeto rígido.
									*/
	//time_t start, end;

	clock_t time = clock();

	struct Output {
		int bdr;
		string name;
		Mat_<double> bdrigid;	// 
		Mat_<double> centroid;	// 
		int nmarkers;			// número de marcadores
		double yaw;
		double pitch;
		double roll;
		Point3d point;			// punto proyectado del poniter
		Mat_<double> Quat;		// cuaternios
	};
	typedef struct Output BodyR;

	/** @struct Label
	*  @brief Esta estructura permite ir haciendo un seguimiento de cada uno de los nodos encontrados en proceso de indentificación de los cuerpos rígidos
	*  y es utilizada en el momento de identificar los objetos rígidos en escena.
	*  @var Label::nro
	*  Contiene el número del nodo.
	*  @var Label::prev
	*  Nodo precedente (-1 para el nodo inicial).
	*  @var Label::peso
	*  Distancia del nodo hasta el nodo de referencia.
	*  @var Label::marca
	*  Indica si la esfera ha sido marcada o no.
	*  @var Label::objR
	*  Contiene el identificador del objeto rígido al que pertenece. Según la matriz de distancias de entrada; el C.R. 1  corresponde a la 1ra fila de la matriz de distancias teóricas y así susecivamente.

	*  Ejemplo de una matriz de distancias:

	Mat_<float> distances = (Mat_<float>(4, 6) <<

	20.05, 29.26, 49.67, 39.82, 49.55, 51.53,		// POINTER

	35.22, 59.15, 25.07, 44.73, 51.63, 54.93,		//FEMUR

	89.74, 107.01, 80.03, 70.26, 103.56, 59.74,	//TIBIA

	64.75, 118.23, 183.64, 55.66, 126.57, 73.28);	//GAFAS

	* cada fila esta formada por las distancias que hay entre cada esfera que forma un cuerpo rígido. Si el objeto rígido no es identificado entonces tendrá valor de -1.
	* @see CustomCameraLibrary::distances
	* @see CustomCameraLibrary::joskstra()
	*/
	struct Label {
		int nro;												// numero del nodo.
		int prev;												// nodo precedente (-1 para el nodo inicial).
		float peso;												// distancia del nodo hasta el nodo de referencia.
		int marca;												// si la esfera ha sido marcada o no.
		int objR;												// objeto rígido al que pertenece. Según la matriz de distancias de entrada; el C.R. 1  corresponde a la 1ra fila de la matriz de distancias teóricas y así susecivamente.
	};
	typedef struct Label Sphere;

	/**
	*	Rota un vector alrededor de un eje utilizando la fórmula de rotación de Rodriges
	*	@param v vector a rotar.
	*	@param k  eje de rotación.
	*	@param angle ángulo de rotación.
	*	@return vector \a v rotado
	*/
	Mat_<double> rotateVector(Mat_<double> v, Mat_<double> k, double angle) {
		Mat_<double> v_rot;
		k = k / norm(k);
		double rad = angle*CV_PI / 180;
		v_rot = v*cos(rad) + (k.cross(v))*sin(rad) + k*(k.dot(v))*(1 - cos(rad));
		return v_rot;
	}

	void updateCordinates(cv::Mat_<double> &origin) {
		for (int r = 0; r <= cdata::phantom.rows; r++) {
			cdata::phantom.row(r) = cdata::phantom.row(r) + origin;
		}
	}

	/**
	*	Obtiene el producto cruz entre dos Mat_
	*	@param A Primer Mat_
	*	@param B Segundo Mat_
	*	@return producto cruz entre A y B
	*/
	cv::Mat cross_product(cv::Mat_<double> A, cv::Mat_<double> B) {
		cv::Mat_<double> C;

		for (int i = 0; i < A.rows; i++) {
			C.push_back(A.row(i).cross(B.row(i)));
		}

		return C;
	}
	/**
	*	Obtiene el tangente inverso entre dos Mat_
	*	@param y Primer Mat_
	*	@param x Segundo Mat_
	*	@return Tangente inverso entre x e y
	*/
	cv::Mat invTan2(cv::Mat_<double> y, cv::Mat_<double> x) {
		cv::Mat_<double> Ainv;
		double result;

		for (int i = 0; i < y.rows; i++)
		{
			for (int j = 0; j < x.cols; j++)
			{
				result = atan2(y[i][j], x[i][j]) * 180 / PI;
				if (result<0)
				{
					result = result + 360;
				}
				Ainv.push_back(result);
			}
		}
		return Ainv;
	}
	/**
	*	Ordena una matriz mediante indices determinados_
	*	@param InputMatrix Matriz a ordenar
	*	@param InputIndex Matriz de indices
		@param num filas
	*	@return temp
	*/
	cv::Mat OrderByIdx(cv::Mat_<double> InputMatrix,cv::Mat InputIndex, int num) {
		cv::Mat_<double> temp(num,2);

		if (num == 2)
		{
			temp.at<double>(0, 0) = InputMatrix.at<double>(InputIndex.at<int>(0, 0), 0);
			temp.at<double>(0, 1) = InputMatrix.at<double>(InputIndex.at<int>(0, 0), 1); //3 de idx

			temp.at<double>(1, 0) = InputMatrix.at<double>(InputIndex.at<int>(1, 0), 0);//1 de idx
			temp.at<double>(1, 1) = InputMatrix.at<double>(InputIndex.at<int>(1, 0), 1);//1 de idx

		}
		else
		{
			temp.at<double>(0, 0) = InputMatrix.at<double>(InputIndex.at<int>(0, 0), 0);
			temp.at<double>(0, 1) = InputMatrix.at<double>(InputIndex.at<int>(0, 0), 1); //3 de idx

			temp.at<double>(1, 0) = InputMatrix.at<double>(InputIndex.at<int>(1, 0), 0);//1 de idx
			temp.at<double>(1, 1) = InputMatrix.at<double>(InputIndex.at<int>(1, 0), 1);//1 de idx

			temp.at<double>(2, 0) = InputMatrix.at<double>(InputIndex.at<int>(2, 0), 0); //2 de idx
			temp.at<double>(2, 1) = InputMatrix.at<double>(InputIndex.at<int>(2, 0), 1); //2 de idx

			temp.at<double>(3, 0) = InputMatrix.at<double>(InputIndex.at<int>(3, 0), 0); //0 de idx
			temp.at<double>(3, 1) = InputMatrix.at<double>(InputIndex.at<int>(3, 0), 1); //0 de idx
		}
		

		return temp;
	}




	bool EvaluateExtent(cv::Mat_<double> Areas_Menores, cv::Mat_<double> Areas_Mayores) {

		return false;
	}

	/**
	*	Define un sistema de ejes local a partir de 3 puntos dados y un punto de referencia
	*	@param P1 primer punto
	*	@param P2 segundo punto
	*	@param P3 tercer punto
	*	@param PR punto de referencia
	*	@return Matriz de rotación asociada a los nuevos ejes
	*/
	cv::Mat_<double> define_local_axis(cv::Mat_<double> P1, cv::Mat_<double> P2, cv::Mat_<double> P3, cv::Mat_<double> PR) {
		cv::Mat_<double> PM, Ux, Uz, Uy, DELTA, CompX, CompY, CompZ, PARAM(3, 3), temp, temp2, sum_ones;
		cv::Mat_<double> val(P3.rows, P3.cols);
		PM = (P1 + P2 + P3) / 3;

		sum_ones = cv::Mat::ones(3, 1, CV_8UC1);
		cv::sqrt((P3 - PM).mul(P3 - PM) * sum_ones, temp);
		Ux = (P3 - PM) / cv::repeat(temp, 1, 3);
		val = cross_product(P2 - PM, P3 - PM);
		cv::sqrt((val).mul(val) * sum_ones, temp2);
		Uz = val / cv::repeat(temp2, 1, 3);
		Uy = cross_product(Uz, Ux);

		DELTA = PR - PM;

		CompX = (DELTA.mul(Ux)) * sum_ones;
		CompY = (DELTA.mul(Uy)) * sum_ones;
		CompZ = (DELTA.mul(Uz)) * sum_ones;

		double t_min, t_max;
		cv::Scalar mean, stddev;

		cv::meanStdDev(CompX, mean, stddev);
		PARAM(0, 0) = mean[0];
		PARAM(1, 0) = stddev[0];
		cv::meanStdDev(CompY, mean, stddev);
		PARAM(0, 1) = mean[0];
		PARAM(1, 1) = stddev[0];
		cv::meanStdDev(CompZ, mean, stddev);
		PARAM(0, 2) = mean[0];
		PARAM(1, 2) = stddev[0];
		cv::minMaxIdx(CompX, &t_min, &t_max);
		PARAM(2, 0) = t_max - t_min;
		cv::minMaxIdx(CompY, &t_min, &t_max);
		PARAM(2, 1) = t_max - t_min;
		cv::minMaxIdx(CompZ, &t_min, &t_max);
		PARAM(2, 2) = t_max - t_min;

		return PARAM;
	}

	/**
	*	Obtiene el punto que toca la punta del pointer.
	*	Se genera un eje de cordenadas sobre las esferas que forman el pointer y luego se rota el vector que indica la dirección del pointer sobre un eje de rotación que
	*	viene siendo uno de los ejes del sistema de coordenada sobre el pointer.
	*	@param P1 coordenada de una esfera utilizada para formar el eje de coordenada sobre el pointer.
	*	@param P2 coordenada de una esfera utilizada para formar el eje de coordenada sobre el pointer.
	*	@param P3 coordenada de una esfera utilizada para formar el eje de coordenada sobre el pointer.
	*	@param PARAM vector que indica la vista del pointer; hacia donde apunta.
	*	@return coordenadas en 3D del punto que toca la punta del pointer.
	*/
	Point3d pointerPoint(cv::Mat_<double> &P1, cv::Mat_<double> &P2, cv::Mat_<double> &P3, cv::Mat_<double> out) {
	
		ofstream archivoP;
		if (!archivoP.is_open()) {
			archivoP.open("puntaP.txt", std::ios::app);

		}
		P1 = P1.t();
		P2 = P2.t();
		P3 = P3.t();
		cv::Mat_<double> PM, Ux, Uz, Uy, temp, temp2, sum_ones, PE;
		cv::Mat_<double> val(P3.rows, P3.cols);
		double PointerX, PointerY, PointerZ;
		
			PointerX = cdata::PARAM(0, 0);									//Si está detectando pointer evalue esto, sino evalue el otro arreglo.
			PointerY = cdata::PARAM(0, 1);
			PointerZ = cdata::PARAM(0, 2);
		int s = CustomCameraLibrary::COUNT;
		
		PM = (P1 + P2 + P3) / 3;

		sum_ones = cv::Mat::ones(3, 1, CV_8UC1);
		cv::sqrt((P3 - PM).mul(P3 - PM) * sum_ones, temp);
		Ux = (P3 - PM) / cv::repeat(temp, 1, 3);
		val = cross_product(P2 - PM, P3 - PM);
		cv::sqrt((val).mul(val) * sum_ones, temp2);
		Uz = val / cv::repeat(temp2, 1, 3);
		Uy = cross_product(Uz, Ux);

		val = PointerX*Ux + PointerY*Uy + PointerZ*Uz;
		PE = PM + val - cdata::f_cor.t();
		
		if (!PE.empty())
		{
			archivoP << PE[0][0] << "\t";
			archivoP << PE[0][1] << "\t";
			archivoP << PE[0][2] << "\t";
			archivoP << "\n";

			
		}

		archivoP.close();
		return Point3d(PE);
	}

	Point3d Punta(cv::Mat_<double> &P1, cv::Mat_<double> &P2, cv::Mat_<double> &P3, cv::Mat_<double> out) {

		ofstream archivoP;
		if (!archivoP.is_open()) {
			archivoP.open("EvaluandoTABLERO.txt", std::ios::app);

		}
		P1 = P1.t();
		P2 = P2.t();
		P3 = P3.t();
		cv::Mat_<double> PM, Ux, Uz, Uy, temp, temp2, sum_ones, PE;
		cv::Mat_<double> val(P3.rows, P3.cols);
		double PointerX, PointerY, PointerZ;
		if (!detect_pointer)
		{
			PointerX = cdata::PARAM(0, 0);									//Si está detectando pointer evalue esto, sino evalue el otro arreglo.
			PointerY = cdata::PARAM(0, 1);
			PointerZ = cdata::PARAM(0, 2);
		}
		else
		{
			PointerX = cdata::PARAMPunta(0, 0);
			PointerY = cdata::PARAMPunta(0, 1);
			PointerZ = cdata::PARAMPunta(0, 2);
		}

		PM = (P1 + P2 + P3) / 3;

		sum_ones = cv::Mat::ones(3, 1, CV_8UC1);
		cv::sqrt((P3 - PM).mul(P3 - PM) * sum_ones, temp);
		Ux = (P3 - PM) / cv::repeat(temp, 1, 3);
		val = cross_product(P2 - PM, P3 - PM);
		cv::sqrt((val).mul(val) * sum_ones, temp2);
		Uz = val / cv::repeat(temp2, 1, 3);
		Uy = cross_product(Uz, Ux);

		val = PointerX*Ux + PointerY*Uy + PointerZ*Uz;
		PE = PM + val - cdata::f_cor.t();

		if (!PE.empty())
		{

			/*archivoP << PE[0][0] << "\t";
			archivoP << PE[0][1] << "\t";
			archivoP << PE[0][2] << "\t";
			archivoP << "\n";*/
			//archivoP << PE << "\n";
		}

		return Point3d(PE);
		archivoP.close();
	}
	/**
	*	Obtiene el punto que toca la punta del pointer.
	*	Se genera un eje de cordenadas sobre las esferas que forman el pointer y luego se rota el vector que indica la dirección del pointer sobre un eje de rotación que
	*	viene siendo uno de los ejes del sistema de coordenada sobre el pointer.
	*	@param P1 coordenada de una esfera utilizada para formar el eje de coordenada sobre el pointer.
	*	@param P2 coordenada de una esfera utilizada para formar el eje de coordenada sobre el pointer.
	*	@param P3 coordenada de una esfera utilizada para formar el eje de coordenada sobre el pointer.
	*	@param Out vector que indica la vista del pointer; hacia donde apunta.
	*	@return coordenadas en 3D del punto que toca la punta del pointer.
	*/
	Point3d pointerPoint2(Mat_<double> &P1, Mat_<double> &P2, Mat_<double> &P3, Mat_<double> &Out) 
	{
		//		Mat_<double> vP = (P1 - P3).cross(P2 - P3);								// vector perpendicular al circulo que esta sobre la 1ra esfera
		
		Mat_<double> vP2 = (P3 - P1).cross(P2 - P1);
		//cout << Out;
		//			vP = vP / norm(vP);
		//		Mat_<double> ejeR = (vP).cross(P1 - P3);								// eje de rotación 
		Mat_<double> ejeR2 = (vP2).cross(P3 - P1);
		//				cout << P2 << endl;
		// vector de longitud d en la dirección del pointer, Out es el vector unitario en esa dirección.
		Mat_<double> d = Out*L_POINTER2;										// encontrar un vector de longitud L_POINTER en esa dirección
		Mat_<double> p = P1 + d;												// el punto p estará ahora L_POINTER veces alejado de P2
		//cout << "PP= " << p.t() << ";" << endl << endl;
		Mat_<double> v_rot = rotateVector((P1 - p), ejeR2, (-2.9869));			// rotar el vector (P1 - p)2.5782
		Mat_<double> punto1 = P1 - v_rot;										// punto rotado la 1ra vez
		//cout << endl << endl << "PR=" << punto1 << ";" << endl << endl;

		Mat_<double> v_rot2 = rotateVector((P1 - punto1), vP2, -0.2588875);		// rotar el vector (P4 - p)
		Mat_<double> punto2 = P1 - v_rot2;										// punto rotado la 2da vez
		//cout << "PF=" << punto2 << ";" << endl << endl;
		//		Mat_<double> ppp = ((Mat_<double>(3, 1)) << -143.5078742478917, 550.9969928063921, 1430.933711072703);
		//		cout << punto2 - ppp << endl;
		//archivoP << "filas:  " << punto2.rows<<"  columnas"<<punto1.cols;
		
		return Point3d(punto2);
		
	}
	Point3d pointerPointNEW(cv::Mat_<double> &P1, cv::Mat_<double> &P2, cv::Mat_<double> &P3, cv::Mat_<double> &P4, cv::Mat_<double> &PC, cv::Mat_<double> out) {

		ofstream archivoP;
		if (!archivoP.is_open()) {
		archivoP.open("VAL.txt", std::ios::app);

		}

		PC = PC.t();

		P1 = P1.t() - PC;
		P2 = P2.t() - PC;
		P3 = P3.t() - PC;
		P4 = P4.t() - PC;
		cv::Mat_<double> uzn, Ux, Uz, Uy, temp, temp2, sum_ones, PE;
		//cv::Mat_<double> val(P3.rows, P3.cols);
		cv::Mat_<double> val, val2, val3(1, 3), ez, ex, ey, E(3, 3);

		double PointerX, PointerY, PointerZ, X2, Y2, XY, XZ, YZ, n, a, b, d, ezNorm, p3Norm;

		//int s = CustomCameraLibrary::COUNT;

		val = cross_product(P2, P3);
		uzn = val / norm(val);

		val.push_back(P1);
		val.push_back(P2);
		val.push_back(P3);
		val.push_back(P4);


		val2 = val.mul(val);
		cv::reduce(val2, val2, 0, CV_REDUCE_SUM);

		X2 = val2(0, 0);
		Y2 = val2(0, 1);
		cv::reduce(val, val, 0, CV_REDUCE_SUM);

		XY = val(0, 0) * val(0, 1);
		XZ = val(0, 0) * val(0, 2);
		YZ = val(0, 1) * val(0, 2);

		a = (XZ*Y2 - YZ*XY) / (XY*XY - X2*Y2);
		b = (YZ*X2 - XZ*XY) / (XY*XY - X2*Y2);
		d = 0;
		val3(0, 0) = a;
		val3(0, 1) = b;
		val3(0, 2) = 1;
		ezNorm = sqrt(a*a + b*b + 1);
		cv::divide(ezNorm, val3, ez);

		if (ez.dot(uzn) < 0) {
			ez = -ez;
		}

		p3Norm = sqrt(P3(0, 0)*P3(0, 0) + P3(0, 1)*P3(0, 1) + P3(0, 2)*P3(0, 2));
		cv::divide(p3Norm, P3, ex);
		ey = cross_product(ez, ex);

		E.col(0) = ex.t();
		E.col(1) = ey.t();
		E.col(2) = ez.t();

		PointerX = cdata::PARAM(0, 0);									
		PointerY = cdata::PARAM(0, 1);
		PointerZ = cdata::PARAM(0, 2);
		val = E.col(0)*PointerX + E.col(1)*PointerY + E.col(2)*PointerZ;

		PE = PC + val.t();

		archivoP << val;
		archivoP.close();
		return Point3d(PE);
	}
	void getEulerAngles(BodyR *&bRigid, int i) {

		Mat_<double> OR = bRigid[i].bdrigid;
		double alpha, beta, gamma, qx, qy, qz, qw;
		ofstream eulerangles;

		if (!eulerangles.is_open())
		{
			eulerangles.open("eulerangles.txt", std::ios::app);
		}
		if (OR.cols >= 3) {
			float sy;                        //https://blender.stackexchange.com/questions/30808/how-do-i-construct-a-transformation-matrix-from-3-vertices
			Mat_<double> v, v1, v2, x, X, Y, Z, a, b, c, b2, a2, p1, p2, p3,p4, Pc, Out;
			p1 = OR.col(0);
			p2 = OR.col(1);
			p3 = OR.col(2);

			if(bRigid[i].name != BROCA){
			p4 = OR.col(3);
			alpha = pow(norm(p2 - p3), 2)*(p1 - p2).dot(p1 - p3) / (2 * pow(norm((p1 - p2).cross(p2 - p3)), 2));
			beta = pow(norm(p1 - p3), 2)*(p2 - p1).dot(p2 - p3) / (2 * pow(norm((p1 - p2).cross(p2 - p3)), 2));
			gamma = pow(norm(p1 - p2), 2)*(p3 - p1).dot(p3 - p2) / (2 * pow(norm((p1 - p2).cross(p2 - p3)), 2));
			Pc = alpha*p1 + beta*p2 + gamma*p3;												// Punto del centro del circulo
			bRigid[i].centroid = Pc;															// Guardar el centroide del O.R.
			eulerangles << bRigid[i].centroid;
			eulerangles.close();

																								// ################################## ESTO LO PUSO DUVAN

			alpha = p2(0, 0);
			beta = p2(1, 0);
			gamma = p2(2, 0);

			alpha = p1(0, 0);
			beta = p1(1, 0);
			gamma = p1(2, 0);
			}
			// ################################## ESTO LO PUSO DUVAN
			else
			{
				bRigid[i].centroid = p2;
				eulerangles << bRigid[i].name << "\n" << OR;
				eulerangles << "centroid broca" << bRigid[i].centroid << "\n" << p2;
			}

			eulerangles.close();
			a = p2 - p1;
			b = p3 - p1;
			Z = a.cross(b);
			normalize(Z, Z);

			Y = Z.cross(a);
			normalize(Y, Y);
			normalize(a, a);

			X = a.t();
			Y = Y.t();
			Z = Z.t();

			float tr = X(0, 0) + Y(0, 1) + Z(0, 2);                     //http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/

			if (tr > 0)
			{
				float S = sqrt((float)tr + (float) 1.0) * 2; // S=4*qw 
				qw = 0.25 * S;
				qx = (Z(0, 1) - Y(0, 2)) / S;
				qy = (X(0, 2) - Z(0, 0)) / S;
				qz = (Y(0, 0) - X(0, 1)) / S;
			}
			else if ((X(0, 0) > Y(0, 1)) & (X(0, 0) > Z(0, 2)))
			{
				float S = sqrt((float)(1.0 + X(0, 0) - Y(0, 1) - Z(0, 2))) * 2; // S=4*qx 
				qw = (Z(0, 1) - Y(0, 2)) / S;
				qx = 0.25 * S;
				qy = (X(0, 1) + Y(0, 0)) / S;
				qz = (X(0, 2) + Z(0, 0)) / S;
			}
			else if (Y(0, 1) > Z(0, 2))
			{
				float S = sqrt((float)(1.0 + Y(0, 1) - X(0, 0) - Z(0, 2))) * 2; // S=4*qy
				qw = (X(0, 2) - Z(0, 0)) / S;
				qx = (X(0, 1) + Y(0, 0)) / S;
				qy = 0.25 * S;
				qz = (Y(0, 2) + Z(0, 1)) / S;
			}
			else
			{
				float S = sqrt((float)(1.0 + Z(0, 2) - X(0, 0) - Y(0, 1))) * 2; // S=4*qz
				qw = (Y(0, 0) - X(0, 1)) / S;
				qx = (X(0, 2) + Z(0, 0)) / S;
				qy = (Y(0, 2) + Z(0, 1)) / S;
				qz = 0.25 * S;
			}
			bRigid[i].yaw = 0;
			bRigid[i].pitch = 0;
			bRigid[i].roll = 0;
			Mat_<float> Q = (Mat_<float>(1, 4) << qx, qy, qz, qw);
			Q.copyTo(bRigid[i].Quat);
			
			double ss = norm(p1 - p3);
			//QString s = QString::number(ss);
			//qDebug() << s;

			if ((bRigid[i].name == POINTER) && /*(norm(p1 - p3) > 45) &&*/ detect_pointer) {					// para siempre mantener la dirección del vector que apunta al pointer
				//cout << "OR=" << OR << ";" << endl;
				Out = (p1 - p3) / norm(p1 - p3);
				//Point3d punto = pointerPointNEW(p1, p2, p3, p4, Pc, Out); //hay dos funciones pointerpoint
				Point3d punto = pointerPoint(p1, p2, p3, Out); //hay dos funciones pointerpoint
				bRigid[i].point = Point3d(punto);

			}
			if ((bRigid[i].name == BROCA)) {
				Point3d punto = Punta(p1, p2, p3, Out);
				bRigid[i].point = Point3d(punto);
			}
		}
	}

	/**
	*	Obtiene los ángulos de euler para cada cuerpo rígido detectado.
	*	La mayor parte de la teoría de este proceso se encuentra explicada aquí [The Mathematics of the 3D Rotation Matrix](https://www.fastgraph.com/makegames/3drotation/ "The Mathematics of the 3D Rotation Matrix")
	*	El método funciona solo cuando se detectan los 4 marcadores que conforman el cuerpo rígido.
	*	@param bRigid referencia al conjunto de cuerpos rígidos detectados, de aquí se extrae el cuerpo rígido y las coordenadas en 3D de las esferas que lo forman.
	*	@param x posición en el array de objetos rígidos del objeto rígido que se le desean obtener los ángulos de euler.
	*/
	void getEulerAnglesOld(BodyR *&bRigid, int x) {
		Mat_<double> OR = bRigid[x].bdrigid;


		if (OR.cols > 3) {
			Mat_<double> P1, P2, P3, P4, Pc, Out, Up, Upw, Right, MR;
			P1 = OR.col(0);
			P2 = OR.col(1);
			P3 = OR.col(2);
			P4 = OR.col(3);
			//cout << norm(P2 - Pc) << endl << P3 << endl;
			double alpha, betha, gamma;

			//centro del circulo
			alpha = pow(norm(P2 - P3), 2)*(P1 - P2).dot(P1 - P3) / (2 * pow(norm((P1 - P2).cross(P2 - P3)), 2));
			betha = pow(norm(P1 - P3), 2)*(P2 - P1).dot(P2 - P3) / (2 * pow(norm((P1 - P2).cross(P2 - P3)), 2));
			gamma = pow(norm(P1 - P2), 2)*(P3 - P1).dot(P3 - P2) / (2 * pow(norm((P1 - P2).cross(P2 - P3)), 2));

			Pc = alpha*P1 + betha*P2 + gamma*P3;												// Punto del centro del circulo
			bRigid[x].centroid = Pc;															// Guardar el centroide del O.R.

			cout << norm(P1 - P3) << endl;

			//cin.get();
			// CAMBIAR out POR EL VECTOR FORMADO ENTRE LA ESFERA 1 y 3
			Out = (P1 - P3) / norm(P1 - P3);//(Pc - P1).cross(Pc - P2);							// Vista o view
											//	Out = out / norm(out);							// Vector unitario de la Vista: 3ra fila de la matriz de rotación
			Upw = (Mat_<double>(3, 1) << 0, 1, 0);
			//			cout << Out << endl;
			Mat_<double> up = Upw - (Upw.dot(Out)*Out);
			Up = up / norm(up);																	// Up: 2da fila de la matriz de rotación

			Right = Up.cross(Out);																// Right: 1ra fila de la matriz de rotación

																								//	cout << norm(up) << endl << endl;

			MR.push_back(Right.t());
			MR.push_back(Up.t());
			MR.push_back(Out.t());
			//			MR = MR.t();																		// DESCOMENTAR CUANDO LAS ROTACIONES SON ZXZ
			//			cout << MR << endl;
			//	cout << "CENTRO CIRCULO" << endl << Pc << endl << endl;
			//			cout << "Mat. ROTACION" << endl << MR << endl << endl;
			//	bRigid[x].yaw   = atan2(MR(1, 0), MR(0, 0)) * 180 / PI;											// yaw
			//	bRigid[x].pitch = atan2(-MR(2, 0), sqrt(pow(MR(2, 1), 2) + pow(MR(2, 2), 2))) * 180 / PI; 		// pitch
			//	bRigid[x].roll  = atan2(MR(2, 1), MR(2, 2)) * 180 / PI;											// roll
			//////////////////////////////////////////////////////////////////////////////////////////////////////////
			Mat_<double> denom(1, 4);
			Mat_<double> Q(1, 4);																// Quaternios
			double minVal;
			double maxVal;
			Point minLoc;
			Point maxLoc;

			denom(0, 0) = 0.5*sqrt(1 + MR(0, 0) - MR(1, 1) - MR(2, 2)); //1
			denom(0, 1) = 0.5*sqrt(1 - MR(0, 0) + MR(1, 1) - MR(2, 2)); //2
			denom(0, 2) = 0.5*sqrt(1 - MR(0, 0) - MR(1, 1) + MR(2, 2)); //3
			denom(0, 3) = 0.5*sqrt(1 + MR(0, 0) + MR(1, 1) + MR(2, 2)); //0
			minMaxLoc(denom, &minVal, &maxVal, &minLoc, &maxLoc);

			switch ((int)maxLoc.x) {
			case 0:
				Q(0, 0) = denom(0, 0);
				Q(0, 1) = (MR(0, 1) + MR(1, 0)) / (4 * Q(0, 0));
				Q(0, 2) = (MR(0, 2) + MR(2, 0)) / (4 * Q(0, 0));
				Q(0, 3) = (MR(1, 2) - MR(2, 1)) / (4 * Q(0, 0));
				break;
			case 1:
				Q(0, 1) = denom(0, 1);
				Q(0, 0) = (MR(0, 1) + MR(1, 0)) / (4 * Q(0, 1));
				Q(0, 2) = (MR(1, 2) + MR(2, 1)) / (4 * Q(0, 1));
				Q(0, 3) = (MR(2, 0) - MR(0, 2)) / (4 * Q(0, 1));
				break;
			case 2:
				Q(0, 2) = denom(0, 2);
				Q(0, 0) = (MR(0, 2) + MR(2, 0)) / (4 * Q(0, 2));
				Q(0, 1) = (MR(1, 2) + MR(2, 1)) / (4 * Q(0, 2));
				Q(0, 3) = (MR(0, 1) - MR(1, 0)) / (4 * Q(0, 2));
				break;
			case 3:
				Q(0, 3) = denom(0, 3);
				Q(0, 0) = (MR(1, 2) - MR(2, 1)) / (4 * Q(0, 3));
				Q(0, 1) = (MR(2, 0) - MR(0, 2)) / (4 * Q(0, 3));
				Q(0, 2) = (MR(0, 1) - MR(1, 0)) / (4 * Q(0, 3));
				break;
			default:
				break;
			}

			//		cout << denom << endl;
			//	cout << "min val : " << minLoc << endl;
			//	cout << "max val: " << maxLoc << endl;
			//			cout <<MR << endl << Q << endl;
			Q = Q / norm(Q);
			//			cout << Q << endl;
			Q.copyTo(bRigid[x].Quat);
			// psi rotación al rededor del eje X; ángulo con respecto al eje Y-Y y Y-Z | theta rotación al rededor del eje Y; ángulo con respecto al eje X-X y X-Z | phi rotación al rededor del eje Z; giro
			// orden de rotación XYZ
			float psi = atan2(2 * (Q(0, 0)*Q(0, 3) - Q(0, 1)*Q(0, 2)), (pow(Q(0, 3), 2) - pow(Q(0, 0), 2) - pow(Q(0, 1), 2) + pow(Q(0, 2), 2)));
			float theta = asin(2 * (Q(0, 0)*Q(0, 2) + Q(0, 1)*Q(0, 3)));
			float phi = atan2(2 * (Q(0, 2)*Q(0, 3) - Q(0, 0)*Q(0, 1)), (pow(Q(0, 3), 2) + pow(Q(0, 0), 2) - pow(Q(0, 1), 2) - pow(Q(0, 2), 2)));
			//orden de rotación ZXZ
			/*			double psi = atan2((Q(0, 0)*Q(0, 2) + Q(0, 1)*Q(0, 3)), (Q(0, 0)*Q(0, 3) - Q(0, 1)*Q(0, 2)));
			double theta = acos(pow(Q(0, 3), 2) - pow(Q(0, 0), 2) - pow(Q(0, 1), 2) + pow(Q(0, 2), 2));
			double phi = atan2((Q(0, 0)*Q(0, 2) - Q(0, 1)*Q(0, 3)), (Q(0, 0)*Q(0, 3) + Q(0, 1)*Q(0, 2)));
			*/
			Mat_<double> EA = (Mat_<double>(1, 3) << psi, theta, phi) * 180 / CV_PI;							// Ángulos de Euler en grados

																												// mantener los EA entre 0 y 180
																												/*			for (int i = 0; i < EA.cols; i++) {
																												EA(0, i) = EA(0, i) - floor(EA(0, i) / 360) * 360;
																												if (EA(0, i) > 180)
																												EA(0, i) = EA(0, i) - 360;																	// modificando los ángulos de Euler para que estén entre -180 y 180
																												}*/

																												//Asignar los ángulos de euler al Cuerpo rígido
			bRigid[x].yaw = EA(0, 0);
			bRigid[x].pitch = EA(0, 1);
			bRigid[x].roll = EA(0, 2);

			//x = origin.x + radius*math.cos(math.rad(rotation.y))*math.cos(math.rad(rotation.x)), y = origin.y + radius*math.sin(math.rad(rotation.x)), z = origin.z + radius*math.sin(math.rad(rotation.y))*math.cos(math.rad(rotation.x))
			/*			double X = Pc(0, 0) + L_POINTER * cos(theta)*cos(phi);
			double Y = Pc(1, 0) + L_POINTER * sin(phi);
			double Z = Pc(2, 0) + L_POINTER * sin(theta)*cos(phi);
			Mat_<double> z;
			z.push_back(X);
			z.push_back(Y);
			z.push_back(Z);
			*/
			//			cout << "[" << X << ", " << Y << ", " << Z << "]" << endl << endl;
			//			cout << Pc << endl << endl;

			/*
			*	Encontrar el punto situado a  una distancia L_POINTER de la esfera 2 (P2), luego rotar dicho punto un ángulo TETHA+(0.58747)
			*	finalmente corregir el giro un ángulo C_TETHA entorno al eje perpendicular vP
			*/
			if ((bRigid[x].name == POINTER) && (norm(P1 - P3) > 51) && detect_pointer) {					// para siempre mantener la dirección del vector que apunta al pointer
				
				
				Point3d punto = pointerPoint(P1, P2, P3, Out);

				bRigid[x].point = Point3d(punto);

			}
			

			//			cout << norm(p.t()-Pc.t()) << endl;
			//cout << Pc << endl;
		}
	}

	/**
	*	Compara las distancias experimentales entre esferas con las teóricas para establecer si hay o no una equivalencia.
	*	@param distance distancia obtenida entre dos esferas seleccionadas en algún momento del flujo en que se están detectando los cuerpos rígidos.
	*	@see joskstra()
	*	@param vec vector que contiene las distancias teóricas entre cada esfera que forman los cuerpos rígidos.
	*	@return un entero positivo equivalente a la posición de la esfera aceptada como una esfera que hace parte del cuerpo rígido, de lo contrario devuelve -1.
	*/
	int analizer(float distance, vector<float> &vec) {
		//bool result = false;
		int result = -1;

		//	cout << "tamagno " << vec.size() << endl;

		for (int i = 0; i < vec.size(); i++) {
			float d = std::abs(distance - vec[i]);						// distancia experimental menos teórica
																		// SUGERENCIA: Recorrer toda la matriz y guardar todas las posiciones por debajo de delta
																			//y volver a evaluar la mas pequeña entre ellas.
			if (d <= DELTA) {
				//result = true;
				//vec.erase(vec.begin() + i);							// eliminar de la lista de distancias
				result = i;
				break;
			}
		}
		return result;
	}

	/**
	*	Establece un valor para el error máximo permitido en la búsqueda de las distancias que formas un cuerpo rígido.
	*   El algoritmo de búsqueda de cuerpo rígido tomará como aceptable un nodo analizado si la distancia entre el nodo fijo y el de comparación tiene un error menor o igual a este valor establecido.
	*	@see analizer()
	*	@param delta error máximo en milímetros para la búsqueda de distancias entre esferas que forman un cuerpo rígido.
	*/
	void setDelta(float delta) {
		DELTA = delta;
	}

	/**
	*   Identifica a qué número corresponde el cuerpo rígido encontrado.
	*	@see joskstra()
	*	@param position resultado de ejecutar el método analizer()
	*	@param dspSet conjunto de distancias teóricas.
	*/
	int numBRigid(int position, cv::Mat_<float> dspSet) {
		int pos = 0;
		for (int i = 0; i < dspSet.rows; i++) {
			if (position >= dspSet.cols * i && position < dspSet.cols * (i + 1)) {
				pos = i + 1;
				break;
			}
		}
		return pos;
	}

	/**
	*	De el conjunto de esferas en la escena, encuentra los objetos rígidos.
	*	A cada marcador o esfera se le asocia una etiqueta que se compone principalmente de valores:
	- peso: indica la distancia de un nodo o esfera a la esfera seleccionada.
	- marca: indica si el nodo ya ha sido analizado.
	- antecesor: inidca el nodo que le sigue como parte del mismo objeto rígido.
	*
	*	el nodo inicial tiene un peso de 0 y no tiene antecesor, se empieza analizando el primer nodo con todos los demás hasta encontrar los nodos del primer
	*	cuerpo rígido, los nodos ya selecionados como parte del primer cuerpo rígido se descartan para las siguiente búsqueda y así sucesivamente.
	*	@param spSet conjunto de coordenadas en 3D, resultantes producto de la triangulación. (8,3) para dos estrellas, (7,3) para estrella y broca, (3,3) solo broca.
	*	Equivalente a la posición en 3D de cada esfera que hace parte de los marcadores que esta en escena.
	*	@see CustomCameraLibrary::stereo_triangulation()
	*	@param dspSet distancias teóricas que hay entre cada esfera de un objeto rígido. Son utilizadas para comparar y detectar cuando se encuentra una distancia conocida. (5,6)
	*	@see CustomCameraLibrary::distances
	*	@param bRigid referencia a un array de estructuras que representa un cuerpo rígido.
	*	@see CustomCameraLibrary::Output
	*	@return el número de cuerpos rígidos detectados.
	*/
	ofstream archivoDI;
	
	int joskstra(Mat_<float> spSet, Mat_<float> dspSet, BodyR *&bRigid) {
		time = 0;
		Sphere *Spheres;
		if (!archivoDI.is_open()) {
			archivoDI.open("esferas3D.txt", std::ios::app);

		}
		
		int i, i0, j, countBR, w, h, cont;
		int counter_esf = 0;
		int flag1 = -1;
		float peso;
		vector<float> vec;													// vector que llevará el conjunto de distancias teóricas de los cuerpos rígidos.
		int nBRigid = dspSet.rows;											// número de cuerpos rígidos que se deberían detectar.
		int  N = spSet.rows;
		int  N2 = dspSet.rows;
		archivoDI << spSet;
		Mat d = dspSet.reshape(1, 1);										// convertir a una matriz 1xn.
		double min, max;
		minMaxLoc(d, &min, &max);											// calcular la distancia mínima y máxima entre marcadores
		d.row(0).copyTo(vec);												// copiar el contenido de la matrix 1xn a un vector.

		if ((Spheres = new Sphere[N]) == NULL) return 1;					// Crea dinámicamente el arreglo de etiquetas de esferas. 
																			// inicializar las etiquetas de nodo 
		for (i = 0; i < N; i++) {
			Spheres[i].nro = i;
			if (i != 0) {
				Spheres[i].prev = -1;										// aún no se ha definido predecesor. 
				Spheres[i].peso = -1;										// infinito .
				Spheres[i].marca = 0;
				Spheres[i].objR = -1;
			}
			else {
				Spheres[i].prev = -1;										// aún no se ha definido predecesor. 
				Spheres[i].peso = 0;										// distancia del nodo inicial o de referencia a sí mismo es cero.
				Spheres[i].marca = 0;
				Spheres[i].objR = -1;										// -1, no se ha identificado el objeto rígido al que pertenece.
			}
		}

		countBR = 0;
		while (1) {
			peso = -1;
			i0 = -1;
			Mat temp;

			for (i = 0; i < N; i++) {										// busca entre todos los nodos no marcados el más próximo, descartando los de peso infinito (-1).
				if (Spheres[i].marca == 0 && Spheres[i].peso == 0)			// si el nodo no esta marcado y su peso es mayor o igual a cero.
					if (peso == -1) {
						peso = Spheres[i].peso;								// se hace peso igual al peso del nodo para saltar el if.
						i0 = i;												// referenciamos el nodo a analizar.
					}
			}

			if (i0 == -1) { 
				break; 
			}										// termina si no encuentra.

			int pos;
			for (i = 0; i < N; i++) {
				if (Spheres[i].marca == 0 && i0 != i) {						// si el nodo no esta marcado y el nodo no es él mismo.
					pos = -1;
					float n = norm(spSet.row(i0) - spSet.row(i));			// calculando la distancia entre los dos nodos.

					if (n <= max + DELTA && n >= min - DELTA) {
						pos = analizer(n, vec);
					}

					if (pos >= 0) {
						Spheres[i].marca = 1;
						Spheres[i].prev = i0;
						Spheres[i].peso = n;
						Spheres[i].objR = numBRigid(pos, dspSet);
						temp.push_back(spSet.row(i));						// se va creando la matriz temporal con los datos del cuerpo rígido que va detectando.
																			//						cout << "***" << pos << endl;
						j = i;
					}
					else Spheres[i].peso = 0;

				}
			}

			
			if (temp.rows + 1 > N_MARKERS) 
			{
				//if (temp.rows + 2 > N_MARKERS) {	
				// identificar O.R. con un número de marcadores definidos
				
				Spheres[i0].marca = 1;
				Spheres[i0].prev = i0;
				Spheres[i0].objR = Spheres[j].objR;
				temp.push_back(spSet.row(i0));								// termina de completar la matriz temporal.
				

																			//vec_br.push_back(temp);									
																			// almacenar la matriz temporal dentro del arreglo.
				//print temp
				bRigid[countBR].bdr = Spheres[j].objR;						// marcar el objeto rígido.
				int ref = 99;
				//archivoDI << "temp: " << Spheres[0].objR << Spheres[1].objR << Spheres[2].objR << Spheres[3].objR << Spheres[4].objR << Spheres[5].objR;
				if ((Spheres[0].objR == Spheres[1].objR) || (Spheres[0].objR == Spheres[2].objR)) {
					ref = Spheres[j].objR;
				}
				else if (Spheres[1 + counter_esf].objR == Spheres[2 + counter_esf].objR) {
					ref = Spheres[1 + counter_esf].objR;
				}
				counter_esf += 3;
				/*if (j==3)
				{
					ref = 2;
				}
				else
				{
					ref = Spheres[j].objR;
				}*/

 				switch (ref) {
					//				switch (Spheres[j].objR) {
				case pointer:
					bRigid[countBR].name = POINTER;
					//OutputDebugString(L"POINTER");
					//CustomCameraLibrary::detectPointer = true;
					break;
				case femur:
					bRigid[countBR].name = FEMUR;
					//OutputDebugString(L"ES FEMUR");
					break;
				case tibia:
					bRigid[countBR].name = TIBIA;
					//OutputDebugString(L"ES TIBIA");
					break;
				case gafas:
					bRigid[countBR].name = GAFAS;
					//OutputDebugString(L"GAFAS");
					break;
				case broca:
					bRigid[countBR].name = BROCA;
					//OutputDebugString(L"ES broca");
					break;
				default:
					OutputDebugString(L"no exist");
					break;
				}
				time_t end = time;
				
				bRigid[countBR].bdrigid = temp.t();								// añadir las coordenadas de las esferas del objeto rígido.
				bRigid[countBR].nmarkers = temp.rows;	// número de marcadores en el O.R.
				
																			//Mat temp2;
																				//reduce(temp, temp2, 0, CV_REDUCE_SUM);						// sumar las filas de las coordenadas de las esferas de los objeto rígido
																				//bRigid[countBR].centroid = temp2 / temp.rows;					// calcular el centroide del objeto rígido.
																				//			    cout << "*********" << endl << bRigid[countBR].bdrigid << endl << endl;
				getEulerAngles(bRigid, countBR);								// Detectar los ángulos de Euler.
				countBR++;														//contador de objetos rígidos
				flag1 = 1;
				
			}
			else {																// objeto rígido no identificado.
				//OutputDebugString(L"No detected");
				Spheres[i0].marca = 1;
				Spheres[i0].prev = i0;
				Spheres[i0].objR = -1;
				flag1 = 0;
			}

		}

		archivoDI.close();
		return countBR;

	}


	/*	Mat_<int> findPointerDirection(Mat_<double> OR) {
	for (int i = 0; i < OR.cols; i++) {
	for (int j = 1; j < OR.cols; j++) {
	if (j > i) {
	double n = norm(OR.col(i) - OR.col(j));
	if (n > 51 && n < 53) {
	return (Mat_<double>(1,2) << i, j);
	}
	}

	}
	}
	}
	*/
	/*bool findValue(const cv::Mat &mat, double value) {
	for (int i = 0; i < mat.rows; i++) {
	const double* row = mat.ptr<double>(i);
	if (std::find(row, row + mat.cols, value) != row + mat.cols)
	return true;
	}
	return false;
	}*/

}
namespace CCL = CustomCameraLibrary;
#endif //_DETECTBR_H_

