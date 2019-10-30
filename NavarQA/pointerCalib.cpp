#include "pointerCalib.h"



pointerCalib::pointerCalib()
{
}


pointerCalib::~pointerCalib()
{
}

void pointerCalib::updateCordinates(cv::Mat_<double> &origin) {
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
cv::Mat pointerCalib::cross_product(cv::Mat_<double> A, cv::Mat_<double> B) {
	cv::Mat_<double> C;

	for (int i = 0; i < A.rows; i++) {
		C.push_back(A.row(i).cross(B.row(i)));
	}

	return C;
}

/**
*	Define un sistema de ejes local a partir de 3 puntos dados y un punto de referencia
*	@param P1 primer punto
*	@param P2 segundo punto
*	@param P3 tercer punto
*	@param PR punto de referencia
*	@return Matriz de rotación asociada a los nuevos ejes
*/
cv::Mat_<double> pointerCalib::define_local_axis(cv::Mat_<double> P1, cv::Mat_<double> P2, cv::Mat_<double> P3, cv::Mat_<double> PR) {
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