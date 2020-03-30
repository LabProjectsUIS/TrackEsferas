#include "NavarQT.h"
#include "icp.h"
#include "data.h"
#include <sys\stat.h>
#include <QStyle>
#include <QDesktopWidget>

#define TIBIA 0
#define FEMUR 1
#define _TRACE_MAXLEN 500

#if _MSC_VER >= 1900
#define _PRINT_DEBUG_STRING(text) OutputDebugString(text)
#else // _MSC_VER >= 1900
#define _PRINT_DEBUG_STRING(text) afxDump << text
#endif // _MSC_VER >= 1900

/**
* Constructor por defecto
*/
NavarQT::NavarQT(QWidget *parent)
	: QWidget(parent),
	ui(new Ui::NavarQTClass)
{
	ui->setupUi(this);
	this->setAttribute(Qt::WA_DeleteOnClose);
	step = 1;
	thread = new QThread(this);
	updater = new GUIUpdater();
	process_rigids = new QProcess(this);
	ui->label_camera_right->setVisible(false);
	ui->controls->setVisible(false);
	ui->pushButton_5->setEnabled(false);
	ui->pushButton_6->setEnabled(false);
	ui->pushButton_7->setEnabled(false);
	ui->pushButton_8->setEnabled(false);
	ui->pushButton_10->setVisible(false);
	loadGif(":/gifs/s1");
	//ui->label_instructions_bottom->setVisible(false);
	doCalib = true;
	calibRetries = 3;
	calibMessage = "<html><head/><body><p>Realice la captura de 13 pares de fotograf\303\255as para continuar con el proceso de calibraci\303\263n.</p>"
			"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 15px; margin-right: 0px; -qt-list-indent: 0;\">"
			"<li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"Tengo a la mano el patr\303\263n de calibraci\303\263n</li>"
			"<li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"Iniciar la captura de im\303\241genes</li>"
			"<li style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"Verificar que para cada fotograf\303\255a el patr\303\263n aparezcan completo en las dos im\303\241genes</li></ul></body></html>";
	connect(updater, SIGNAL(startCalibration()), this, SLOT(startCalibration()));
	connect(updater, SIGNAL(doFlash()), this, SLOT(doFlash()));
	connect(updater, SIGNAL(startServer()), this, SLOT(startServer()));
	connect(updater, SIGNAL(updateLeftCamera(QImage)), this, SLOT(createLabelLeft(QImage)));
	connect(updater, SIGNAL(updateRightCamera(QImage)), this, SLOT(createLabelRight(QImage)));
	connect(thread, SIGNAL(destroyed()), updater, SLOT(deleteLater()));
	connect(updater, SIGNAL(pointerDetected()), this, SLOT(colorLabelGreen()));
	connect(updater, SIGNAL(pointerNotDetected()), this, SLOT(colorLabelRed()));

	updater->moveToThread(thread);

	thread->start();

	while (!updater->activateCameras())
	{
		qDebug("Failed to activate cameras");
	}
}

/**
* Sobreescribe el método de cierre de forma tal que la aplicación solo puede ser con una llamada explícita a close().
* @param event evento asociado al cierre de la aplicación, incluye tanto llamadas explícitas close() como señales del sistema.
*/
void NavarQT::closeEvent(QCloseEvent * event) {
	event->setAccepted(!event->spontaneous());
}

/**
* Muestra la imagen proveniente de la cámara izquierda dentro del label asignado para ello.
* @param imgSource Frame de la cámara izquierda.
*/
void NavarQT::createLabelLeft(const QImage &imgSource) {
	QPixmap i1(QPixmap::fromImage(imgSource).scaled(ui->label_camera_left->width(), ui->label_camera_left->height(), Qt::KeepAspectRatio));
	ui->label_camera_left->setPixmap(i1);
	ui->label_camera_left->repaint();
}

/**
* Muestra la imagen proveniente de la cámara derecha dentro del label asignado para ello.
* @param imgSource Frame de la cámara derecha.
*/
void NavarQT::createLabelRight(const QImage &imgSource) {
	QPixmap i1(QPixmap::fromImage(imgSource).scaled(ui->label_camera_right->width(), ui->label_camera_right->height(), Qt::KeepAspectRatio));
	ui->label_camera_right->setPixmap(i1);
	ui->label_camera_right->repaint();
}

/**
* Slot asociado al botón 1 ("ingresar", en la pantalla de inicio de sesión).
*/
void NavarQT::on_pushButton_1_clicked() {
	if (checkLogin(ui->lineEdit_user->text(), ui->lineEdit_password->text())) {
		ui->body->setCurrentIndex(2);
	}
}

/**
* Slot asociado al botón 2 ("Iniciar registro", en la pantalla de casos de usuario).
*/
void NavarQT::on_pushButton_2_clicked() {
	ui->body->setCurrentIndex(3);
}

/**
* Slot asociado al botón 3 (botón multiusos para el desplazamiento entre pantallas).
*/
void NavarQT::on_pushButton_3_clicked() {
	//step = 6;
	switch (step)
	{
	case 2:
		showPopUp();
		updater->setTakeSnapshot(true);
		updater->setDelta(ui->comboBox->currentText().toFloat());
		ui->pushButton_3->setEnabled(false);
		pauseNB(500);
		break;
	case 3:
		//step = 4;
		step = 6;
		process_rigids->kill();
		if (process_client) {
			process_client->kill();
		}
		updater->setDetectRigids(false);
		ui->body->setCurrentIndex(2);
		break;
	case 4:
	case 6:
		ui->label_6->setText("");
		ui->label_6->setFixedHeight(10);
		ui->label_6->setVisible(true);
		ui->pushButton_3->setEnabled(false);
		if (updater->getPointerData(current_bone)) {
			run_icp(current_bone + ".txt", current_bone + ".xyz", exp_size, teo_size, cloud_centroid);
			updater->setCentroid(cloud_centroid, current_bone);
			ui->body->setCurrentIndex(0);
			embedForeign(L"3D Viewer", ui->gridLayout_2);
			ui->label_5->setText(QApplication::translate("NavarQTClass", "<html><head/><body><p><span style=\" font-weight:600;\">Iniciar perforación</span></p><p>Seleccione tibia o fémur para iniciar el proceso de perforación.</p></body></html>", Q_NULLPTR));
			ui->pushButton_10->setText(QApplication::translate("NavarQTClass", "Reiniciar", Q_NULLPTR));
			ui->pushButton_10->setVisible(true);
			ui->pushButton_3->setText(QApplication::translate("NavarQTClass", "Continuar", Q_NULLPTR));
			switchBone();
			ui->pushButton_3->setEnabled(true);
			step++;
		}
		break;
	case 5:
		ui->pushButton_10->setVisible(false);
		ui->pushButton_3->setText(QApplication::translate("NavarQTClass", "Iniciar captura", Q_NULLPTR));
		step++;
		break;
	case 7:
		ui->pushButton_3->setVisible(false);
		ui->pushButton_10->setVisible(false);
		updater->writeMatrices();
		process_rigids->start("Resources/Unity/VisualDesktop.exe");
		updater->getRigidsData();
		
		break;
	default:
		break;
	}
}

/**
* Slot asociado al botón 4 (insutrcción 1 para la preparación de la estación de trabajo).
*/
void NavarQT::on_pushButton_4_clicked() {
	ui->pushButton_4->setEnabled(false);
	ui->pushButton_5->setEnabled(true);
	loadGif(":/gifs/s2");
}

/**
* Slot asociado al botón 5 (insutrcción 2 para la preparación de la estación de trabajo).
*/
void NavarQT::on_pushButton_5_clicked() {
	ui->pushButton_5->setEnabled(false);
	ui->pushButton_6->setEnabled(true);
	loadGif(":/gifs/s3");
	//process->kill();
}

/**
* Slot asociado al botón 6 (insutrcción 3 para la preparación de la estación de trabajo).
*/
void NavarQT::on_pushButton_6_clicked() {
	ui->pushButton_6->setEnabled(false);
	ui->pushButton_7->setEnabled(true);
	loadGif(":/gifs/s4");
}

/**
* Slot asociado al botón 7 (insutrcción 4 para la preparación de la estación de trabajo).
*/
void NavarQT::on_pushButton_7_clicked() {
	ui->pushButton_7->setEnabled(false);
	ui->pushButton_8->setEnabled(true);
	updater->ShowCameras();
}

/**
* Slot asociado al botón 8 (insutrcción 5 para la preparación de la estación de trabajo).
*/
void NavarQT::on_pushButton_8_clicked() {
	ui->horizontalSpacer_4->changeSize(50, 0);
	ui->horizontalSpacer_5->changeSize(0, 0);
	ui->horizontalSpacer_6->changeSize(0, 0);
	ui->horizontalSpacer_7->changeSize(0, 0);
	ui->pushButton_8->setEnabled(false);
	ui->label_camera_right->setVisible(true);
	updater->setShowZone(false);
	ui->instructions->setVisible(false);
	ui->controls->setVisible(true);
	ui->pushButton_10->setVisible(true);
	step = 2;
}

/**
* Slot asociado al botón 9 (botón para la selección del hueso dentro del proceso de registro).
*/
void NavarQT::on_pushButton_9_clicked() {
	startTibiaFemur();
}

/**
* Slot asociado al botón 10 (botón utilizado tanto para omitir el proceso de calibración como para iniciar la captura de la nube de puntos en el registro).
*/
void NavarQT::on_pushButton_10_clicked() { //OMITIR
	if (step == 2) {
		doCalib = false;
		calibRetries = 2;
		ui->pushButton_10->setVisible(false);
		updater->setPics2Take(0);
		startCalibration();
	}
	else {
		startTibiaFemur();
		switchBone();
		step--;
	}
}

/**
* Slot asociado al botón Close, se encarga del cierre de la aplicación.
*/
void NavarQT::on_pushButton_close_clicked() {
	
	this->close();
}

/**
* Slot asociado al botón tibia, permite selecccionar la tibia para iniciar con ella el registro.
*/
void NavarQT::on_pushButton_tibia_clicked() {
	ui->pushButton_9->setText(QApplication::translate("NavarQTClass", "Iniciar tibia", Q_NULLPTR));
	setBone(TIBIA);
}

/**
* Slot asociado al botón femur, permite selecccionar el femur para iniciar con él el registro.
*/
void NavarQT::on_pushButton_femur_clicked() {
	ui->pushButton_9->setText(QApplication::translate("NavarQTClass", "Iniciar femur", Q_NULLPTR));
	setBone(FEMUR);
}

/**
* Inicia el proceso de registro, independientemente del hueso que haya escogido el usuario.
*/
void NavarQT::startTibiaFemur() {
	ui->body->setCurrentIndex(0);
	ui->pushButton_3->setText(QApplication::translate("NavarQTClass", "Iniciar captura", Q_NULLPTR));
	ui->comboBox->setVisible(false);
	ui->label_6->setVisible(false);
	ui->pushButton_10->setVisible(false);
	ui->instructions->setVisible(false);
	ui->controls->setVisible(true);
	//ui->label_instructions_bottom->setVisible(true);
	//ui->label_instructions_bottom->setText(QApplication::translate("NavarQTClass", "<html><head/><body><p><span style=\" font-weight:600;\">Captura de puntos</span></p><p>Deslice el pointer por los puntos mostrados en la figura.</p></body></html>", Q_NULLPTR));
}

/**
* Slot asociado al botón step_1, permite ir directamente al primero de los cuatro pasos generales.
*/
void NavarQT::on_pushButton_step_1_clicked() {
	ui->horizontalSpacer_4->changeSize(65, 0);
	ui->horizontalSpacer_5->changeSize(141, 0);
	ui->horizontalSpacer_6->changeSize(50, 0);
	ui->horizontalSpacer_7->changeSize(50, 0);
	if (process_client) {
		process_client->kill();
	}
	if (process_rigids) {
		process_rigids->kill();
	}
	updater->setPics2Take(-5);
	updater->setDetectRigids(false);
	updater->setDetectPointer(false);
	loadGif(":/gifs/s1");
	ui->body->setCurrentIndex(0);
	ui->cameras->setStyleSheet(QLatin1String(".QWidget{\n"
		"border-color: rgb(43, 170, 225);\n"
		"border-style:outset;\n"
		"border-width: 5px;\n"
		"padding: 6 px;\n"
		"}"));
	ui->pushButton_4->setVisible(true);
	ui->pushButton_4->setEnabled(true);
	ui->pushButton_5->setVisible(true);
	ui->pushButton_5->setEnabled(false);
	ui->pushButton_6->setVisible(true);
	ui->pushButton_6->setEnabled(false);
	ui->pushButton_7->setVisible(true);
	ui->pushButton_7->setEnabled(false);
	ui->pushButton_8->setVisible(true);
	ui->pushButton_8->setEnabled(false);
	ui->label_camera_left->setVisible(true);
	ui->label_camera_right->setVisible(false);
	//ui->label_instructions_bottom->setVisible(false);
	ui->comboBox->setVisible(true);
	ui->label_6->setVisible(true);
	ui->pushButton_3->setVisible(true);
	ui->pushButton_3->setEnabled(true);
	ui->pushButton_10->setVisible(true);
	ui->instructions->setVisible(true);
	ui->controls->setVisible(false);
	step = 0;
}

/**
* Slot asociado al botón step_2, permite ir directamente al segundo de los cuatro pasos generales.
*/
void NavarQT::on_pushButton_step_2_clicked() {
	ui->horizontalSpacer_4->changeSize(50, 0);
	ui->horizontalSpacer_5->changeSize(0, 0);
	ui->horizontalSpacer_6->changeSize(0, 0);
	ui->horizontalSpacer_7->changeSize(0, 0);
	if (process_client) {
		process_client->kill();
	}
	if (process_rigids) {
		process_rigids->kill();
	}
	updater->setPics2Take(-5);
	updater->setDetectRigids(false);
	updater->setDetectPointer(false);
	ui->body->setCurrentIndex(0);
	ui->cameras->setStyleSheet("border: 0");
	ui->cameras->resize(QSize(1566, ui->cameras->height()));
	ui->pushButton_4->setVisible(false);
	ui->pushButton_5->setVisible(false);
	ui->pushButton_6->setVisible(false);
	ui->pushButton_7->setVisible(false);
	ui->pushButton_8->setVisible(false);
	//ui->label_instructions_bottom->setVisible(false);
	ui->comboBox->setVisible(true);
	ui->label_6->setVisible(true);
	ui->pushButton_3->setVisible(true);
	ui->pushButton_3->setEnabled(true);
	ui->pushButton_10->setVisible(true);
	ui->instructions->setVisible(false);
	ui->controls->setVisible(true);
	step = 2;
	updater->setShowZone(false);
	ui->label_camera_right->setVisible(true);
	ui->label_camera_left->setVisible(true);
	ui->label_camera_left->setMovie(new QMovie());
	updater->ShowCameras();
}

/**
* Slot asociado al botón step_3, permite ir directamente al tercero de los cuatro pasos generales.
*/
void NavarQT::on_pushButton_step_3_clicked() {
	ui->horizontalSpacer_4->changeSize(50, 0);
	ui->horizontalSpacer_5->changeSize(0, 0);
	ui->horizontalSpacer_6->changeSize(0, 0);
	ui->horizontalSpacer_7->changeSize(0, 0);
	if (process_client) {
		process_client->kill();
	}
	if (process_rigids) {
		process_rigids->kill();
	}
	updater->setPics2Take(-5);
	updater->setDetectRigids(false);
	updater->setDetectPointer(false);
	ui->body->setCurrentIndex(0);
	ui->pushButton_4->setVisible(false);
	ui->pushButton_5->setVisible(false);
	ui->pushButton_6->setVisible(false);
	ui->pushButton_7->setVisible(false);
	ui->pushButton_8->setVisible(false);
	ui->label_camera_left->setVisible(false);
	ui->label_camera_right->setVisible(false);
	//ui->label_instructions_bottom->setVisible(false);
	ui->comboBox->setVisible(false);
	ui->label_6->setVisible(false);
	ui->pushButton_3->setVisible(true);
	ui->pushButton_3->setEnabled(true);
	ui->pushButton_10->setVisible(false);
	ui->instructions->setVisible(true);
	ui->controls->setVisible(true);
	step = 3;
	doCalib = false;
	calibRetries = 2;
	updater->setDetectRigids(true);
	startCalibration();
	//process_rigids->start("Resources/Unity/esferasTrack.exe");
	updater->getRigidsData();
}

/**
* Slot asociado al botón step_4, permite ir directamente al cuarto de los cuatro pasos generales.
*/
void NavarQT::on_pushButton_step_4_clicked() {
	ui->horizontalSpacer_4->changeSize(50, 0);
	ui->horizontalSpacer_5->changeSize(0, 0);
	ui->horizontalSpacer_6->changeSize(0, 0);
	ui->horizontalSpacer_7->changeSize(0, 0);
	if (process_client) {
		process_client->kill();
	}
	if (process_rigids) {
		process_rigids->kill();
	}
	updater->setPics2Take(-5);
	updater->setDetectRigids(false);
	updater->setDetectPointer(false);
	ui->body->setCurrentIndex(0);
	ui->pushButton_4->setVisible(false);
	ui->pushButton_5->setVisible(false);
	ui->pushButton_6->setVisible(false);
	ui->pushButton_7->setVisible(false);
	ui->pushButton_8->setVisible(false);
	ui->label_camera_left->setVisible(false);
	ui->label_camera_right->setVisible(false);
	//ui->label_instructions_bottom->setVisible(false);
	ui->comboBox->setVisible(false);
	ui->label_6->setVisible(false);
	ui->pushButton_3->setVisible(false);
	ui->pushButton_10->setVisible(false);
	ui->instructions->setVisible(false);
	ui->controls->setVisible(true);
	step = 7;
	updater->setDetectRigids(true);
	process_rigids->start("Resources/Unity/VisualDesktop.exe");
	updater->getRigidsData();
}

/**
* Carga los gif con instrucciones para la preparación de la estación de trabajo.
* @param gif ruta al recurso (gif) a cargar.
*/
void NavarQT::loadGif(const QString &gif) {
	QMovie *movie = new QMovie(gif);
	ui->label_camera_left->setMovie(movie);
	movie->start();
}

/**
* Colorea en rojo el indicador de detección del pointer (no detectado).
*/
void NavarQT::colorLabelRed() {
	ui->label_6->setPixmap(QPixmap());
	ui->label_6->setStyleSheet("QLabel { background-color : red; }");
	ui->label_6->repaint();
}

/**
* Colorea en verde el indicador de detección del pointer (detectado).
*/
void NavarQT::colorLabelGreen() {
	ui->label_6->setPixmap(QPixmap());
	ui->label_6->setStyleSheet("QLabel { background-color : green; }");
	ui->label_6->repaint();
}

/**
* Efecto de flash sobre la pantalla.
* @param delay duración del efecto en segundos.
*/
void NavarQT::flash(int delay) {
	QWidget myWidget;
	myWidget.setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);
	myWidget.showFullScreen();
	pauseNB(delay);
	myWidget.close();
}

/**
* Función que permite conectar la función flash a funciones sin argumentos.
*/
void NavarQT::doFlash() {
	flash(100);
}

/**
* Verifica si la combinación usuario/contraseña introducida por el usuario es correcta.
* @param user nombre de usuario.
* @param password contraseña.
*/
bool NavarQT::checkLogin(const QString &user, const QString &password) {
	if (user == "Admin" && password == "admin")
		return true;
	return false;
}

/**
* Muestra una ventana emergente con el texto en @calibMessage.
* @see calibMessage
*/
void NavarQT::showPopUp() {
	QWidget *bar = new QWidget();
	msgBox = new QWidget();
	QLabel *label_icon = new QLabel();
	label_icon->setObjectName(QStringLiteral("label_icon"));
	label_icon->setPixmap(QPixmap(QString::fromUtf8(":/icons/logo-2")));
	QGridLayout *titleLayout = new QGridLayout(bar);
	QGridLayout *gridLayout = new QGridLayout(msgBox);
	titleLayout->addWidget(label_icon, 0, 1, 1, 1);
	//msgBox->setWindowIcon(QIcon(QPixmap(QString::fromUtf8(":/icons/logo"))));
	QSpacerItem *horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
	QSpacerItem *horizontalSpacer_2 = new QSpacerItem(250, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);
	titleLayout->addItem(horizontalSpacer, 0, 0, 1, 1);
	titleLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);
	QLabel *label_text = new QLabel();
	label_text->setText(tr(calibMessage.toUtf8()));
	gridLayout->addWidget(bar, 0, 0, 1, 1);
	gridLayout->addWidget(label_text, 1, 0, 1, 1);
	msgBox->setGeometry(
		QStyle::alignedRect(
			Qt::LeftToRight,
			Qt::AlignCenter,
			msgBox->size(),
			qApp->desktop()->availableGeometry()
			)
		);
	bar->resize(QSize(320, 25));
	label_text->resize(QSize(320, 210));
	//label_icon->resize(QSize(60, 25));
	msgBox->resize(QSize(320, 240));
	msgBox->setAttribute(Qt::WA_DeleteOnClose);
	msgBox->setWindowFlags(Qt::Popup);
	msgBox->show();
	pauseNB(5000);
	delete msgBox;
}

/**
* Inicia el proceso de calibración del sistema de cámaras.
*/

void NavarQT::startCalibration() {
	std::string fileName;
	
	switch (calibRetries) {
	case 3:
		fileName = "calib/stereo/otros/Calib25M.yml";
		doCalib = false;
		break;
	default:
		fileName = "calib/stereo/otros/Calib25M.yml";
		break;
	}	
	if (doCalib) { //Conexion con matlab toolkit
		SHELLEXECUTEINFO ShExecInfo = { 0 };
		ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
		ShExecInfo.hwnd = NULL;
		ShExecInfo.lpVerb = NULL;
		ShExecInfo.lpFile = L"calib.bat";
		ShExecInfo.lpParameters = L"";
		ShExecInfo.lpDirectory = NULL;
		ShExecInfo.nShow = SW_SHOW;
		ShExecInfo.hInstApp = NULL;
		ShellExecuteEx(&ShExecInfo);
		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);
	}
	if (readParams(fileName)) { //Llama funcion leer parametros del archivo de calibración
		//DBOUT("filename");
		ui->label_camera_right->setVisible(false);
		ui->label_camera_left->setVisible(false);
		ui->comboBox->setVisible(false);
		ui->label_6->setVisible(false);
		ui->pushButton_10->setVisible(false);
		ui->pushButton_3->setText(QApplication::translate("NavarQTClass", "Siguiente", Q_NULLPTR));
		ui->pushButton_3->setEnabled(true);
		step = 3;
		ui->body->setCurrentIndex(0);
		//process_rigids->start("Resources/Unity/esferasTrack2.exe");
		////process_rigids->start("Resources/Unity/VisualDesktop.exe");
		updater->getRigidsData();
	}
	
	else if(calibRetries < 3){
		calibMessage = "<html><head/><body><p>Error en la calibraci\303\263n. Se ejecutar\303\241 todo el proceso nuevamente."
			"<p>Realice la captura de 13 pares de fotograf\303\255as para continuar con el proceso de calibraci\303\263n.</p>"
			"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 15px; margin-right: 0px; -qt-list-indent: 0;\">"
			"<li style=\" margin-top:12px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"Tengo a la mano el patr\303\263n de calibraci\303\263n</li>"
			"<li style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"Iniciar la captura de im\303\241genes</li>"
			"<li style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">"
			"Verificar que para cada fotograf\303\255a el patr\303\263n aparezcan completo en las dos im\303\241genes</li></ul></body></html>";
		on_pushButton_3_clicked();
		updater->ShowCameras();
	}
	else if (calibRetries == 3) {
		//DBOUT("calibretries es tres");
		//DBOUT("bool read params",readParams(fileName));
		calibMessage = "<html><body><p>Cargando archivo de calibraci\303\263n ideal</p></body></html>";
		showPopUp();
		startCalibration();
	}
	else {
		calibMessage = "<html><body><p>Se ha encontrado un error fatal en la calibraci\303\263n y NavarQ debe cerrarse.</p></body></html>";
		showPopUp();
		this->close();
	}
}

/**
* Inicia el cliente Unity para la transferencia de paquetes desde el servidor a Unity.
*/
void NavarQT::startServer() {
	process_client = new QProcess(this);
	process_client->start("Resources/Unity/sample_server/UnitySample.exe");
}

/**
* Lee los parámetros del sistema de cámaras y los carga en memoria.
* @param fileName nombre del archivo de configuración.
*/
bool NavarQT::readParams(std::string fileName) {
	struct stat buffer;
	if (stat(fileName.c_str(), &buffer) == 0) {
		cv::FileStorage fs(fileName, cv::FileStorage::READ);
		cv::Mat_<double> err(1, 1);
		//double err;
		fs["emax"] >> err;
		if (err.empty() || *err[0] > 0.9) {
			calibRetries++; //vuelve a calibrar si el eror es mayor de 0.5, se pone 0,7 porq no se ha podido mejorar la calibración
			
			return false;
		}
		/*ofstream archivo;
		if (!archivo.is_open()) {
			archivo.open("parametros.txt", std::ios::app);
		}*/
		fs["cc_left"] >> cdata::cc_left;
		fs["fc_left"] >> cdata::fc_left;
		fs["kc_left"] >> cdata::kc_left;
		//fs["alpha_c_left1"];

		fs["fc_right"] >> cdata::fc_right;
		fs["cc_right"] >> cdata::cc_right;
		fs["kc_right"] >> cdata::kc_right;
		//fs["alpha_c_right"];
		fs["om"] >> cdata::om;
		fs["T"] >> cdata::T;
		//std::remove(fileName.c_str());
		int n = 23;
		/*if (cdata::cc_left.empty() || *cdata::cc_left[0] == 0) {
			DBOUT(" ESTA VACIO Y CC_LEFT ES--- ", *cdata::cc_left[0],"\n",n)
		}
		else
		{
			DBOUT("no esta vacio y cc left es----", *cdata::cc_left[0], "\n", n)
				archivo << "\t" << *cdata::cc_left[0];
		}*/
		return true;
	}
	return false;
}

/**
* Pausa el programa por el tiempo que le indique el usuario, la pausa debería ser no bloqueante
* @param delay tiempo en segundos.
*/
void NavarQT::pauseNB(int delay) {
	QTime dieTime = QTime::currentTime().addMSecs(delay);
	while (QTime::currentTime() < dieTime) {
		QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
	}
}

/**
* Selecciona el hueso activo y actualiza el tamaño de la nube teórica.
* @param bone hueso seleccionado.
*/
void NavarQT::setBone(int bone) {
	switch (bone)
	{
	case 0:
		current_bone = "tibia";
		//teo_size = 2953;
		teo_size = 23974;
		exp_size = 200;
		break;
	case 1:
		current_bone = "femur";
		//teo_size = 3123;
		teo_size = 32986;
		exp_size = 200;
		break;
	default:
		break;
	}
}

/**
* Cambia de hueso seleccionado
* @see setBone().
*/
void NavarQT::switchBone() {
	if (current_bone == "tibia")
		setBone(FEMUR);
	else
		setBone(TIBIA);
}

/**
* Incrusta una ventana externa dentro de la aplicación
* @param name nombre de la ventana.
* @param layout que recibirá a la ventana.
*/
bool NavarQT::embedForeign(LPWSTR name, QGridLayout *layout) {
	WId id = (WId)FindWindow(NULL, name);
	if (!id)
		return 0;
	QWindow* window = QWindow::fromWinId(id);
	window->setFlags(Qt::FramelessWindowHint);
	//window->show();
	//window->requestActivate();
	QWidget* widget = QWidget::createWindowContainer(window);
	//widget->show();
	widget->setMinimumSize(QSize(815, 650));
	widget->setMaximumSize(QSize(815, 650));
	layout->addWidget(widget, 0, 1, 1, 1);
	widget->setVisible(true);

	return 1;
}