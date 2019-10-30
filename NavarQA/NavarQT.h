#pragma once

#include <QtWidgets/QWidget>
#include "ui_NavarQT.h"
#include <QtCore>
#include "GUIUpdater.h"
#include "QMessageBox.h"
#include <QtWebEngine>
#include "qurl.h"
#include "qtextbrowser.h"
#include "qmovie.h"
#include <Windows.h>
#include <shellapi.h>
#include <vtk-7.1\QVTKWidget.h>

#include <vtk-7.1\vtkRenderWindow.h>

class NavarQT : public QWidget
{
	Q_OBJECT

public:
	NavarQT(QWidget *parent = 0);
	QPointer<QThread> thread;
	QPointer<GUIUpdater> updater;
	QPointer<QProcess> process_rigids;
	QPointer<QProcess> process_client;

	~NavarQT() {
		if (process_rigids) {
			process_rigids->kill();
		}
		if (process_client) {
			process_client->kill();
		}
		updater->ShutDownCameras();
		thread->quit();
		thread->wait();
		delete ui;
	};

public slots:
	void createLabelLeft(const QImage &imgSource);
	void createLabelRight(const QImage &imgSource);
	void startCalibration();
	void startServer();
	void colorLabelGreen();
	void colorLabelRed();
	void doFlash();
	void on_pushButton_1_clicked();
	void on_pushButton_2_clicked();
	void on_pushButton_3_clicked();
	void on_pushButton_4_clicked();
	void on_pushButton_5_clicked();
	void on_pushButton_6_clicked();
	void on_pushButton_7_clicked();
	void on_pushButton_8_clicked();
	void on_pushButton_9_clicked();
	void on_pushButton_10_clicked();
	void on_pushButton_close_clicked();
	void on_pushButton_tibia_clicked();
	void on_pushButton_femur_clicked();
	void on_pushButton_step_1_clicked();
	void on_pushButton_step_2_clicked();
	void on_pushButton_step_3_clicked();
	void on_pushButton_step_4_clicked();

private:
	Ui::NavarQTClass *ui;
	void loadGif(const QString &gif);
	bool checkLogin(const QString &user, const QString &password);
	bool embedForeign(LPWSTR name, QGridLayout *layout);
	void pauseNB(int delay);
	void flash(int delay);
	bool readParams(std::string fileName);
	void startTibiaFemur();
	void setBone(int bone);
	void switchBone();
	void showPopUp();
	int step;
	cv::Mat_<double> cloud_centroid;
	std::string current_bone;
	QString calibMessage;
	double teo_size;
	double exp_size;
	bool doCalib;
	int calibRetries;
	QTimer *timer;
	QWidget *msgBox;
	void closeEvent(QCloseEvent * event);
};
