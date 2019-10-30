#pragma once

#define NOMINMAX
#include "marker.h"
#include <QObject>
#include "cameralibrary.h" 
#include "detectbr.h"
#include "opencv\cv.hpp"
#include "qimage.h"
#include "qcoreapplication.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>

class GUIUpdater : public QObject
{
	Q_OBJECT

public:
	explicit GUIUpdater(QObject *parent = 0);
	~GUIUpdater();
	bool activateCameras();
	void startCameras();
	void ShutDownCameras();
	void ShowCameras();
	bool getPointerData(const std::string &fileName);
	void getRigidsData();
	bool calibPointer();
	void setShowZone(bool status);
	void setTakeSnapshot(bool status);
	void setPics2Take(int numPics);
	void setDetectRigids(bool status);
	void setDetectPointer(bool status);
	void setDelta(float delta);
	void writeMatrices();
	void setCentroid(cv::Mat_<double> centroid, std::string& bone);

signals:
	void updateLeftCamera(const QImage &);
	void updateRightCamera(const QImage &);
	void doFlash();
	void startCalibration();
	void startServer();
	void pointerDetected();
	void pointerNotDetected();

private:
	CameraLibrary::Camera *camera_1;
	CameraLibrary::Camera *camera_2;
	bool showZone;
	void saveImage(std::string &fileName, cv::Mat img);
	bool takeSnapshot;
	bool doStartServer;
	bool detectRigids;
	bool detectPointer;
	bool tibiaFlag;
	bool femurFlag;
	float delta;
	int pics2Take;
	cv::Mat_<double> tibiaCentroid;
	cv::Mat_<double> femurCentroid;
	void getAngles(cv::Mat_<double>& vector, cv::Mat_<double>& angles);
	void GetObjects(CustomCameraLibrary::cFrame cframe, cv::Mat matFrame, cv::Mat_<double> &P, cv::Mat_<double> &A, cv::Mat_<double> &PP_Broca);
	void filter(cv::Mat_<double> datax, cv::Mat_<double> datay, cv::Mat_<double> out);
	void setBroca(CustomCameraLibrary::BodyR &rigid, cv::Mat_<double> &data);
};
