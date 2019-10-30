#pragma once
#include "opencv\cv.hpp"
#include "data.h"

class pointerCalib
{
public:
	pointerCalib();
	~pointerCalib();
	void updateCordinates(cv::Mat_<double> &origin);

private:
	cv::Mat cross_product(cv::Mat_<double> A, cv::Mat_<double> B);
	cv::Mat_<double> define_local_axis(cv::Mat_<double> P1, cv::Mat_<double> P2, cv::Mat_<double> P3, cv::Mat_<double> PR);
};
