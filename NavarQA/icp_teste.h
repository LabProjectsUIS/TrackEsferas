#pragma once

#include "opencv\cv.hpp"
#include <math.h>

//Nom = 'E:\SEGUIMIENTO_BROCA_RODILLA\DATOS_BROCA\DATOS_REGISTRO_FEMUR_TIBIA_MODELO.txt';
//FID = fopen(Nom, 'rt');
//AR = fscanf(FID, '%f\t%f\t%f\t%f\t%f\t%f\n', [6, inf])';
//fclose(FID);
//Femur_Modelo = AR(1:11, 4 : 6);
//
//
//Nom = 'E:\SEGUIMIENTO_BROCA_RODILLA\DATOS_BROCA\DATOS_REGISTRO_FEMUR_VISION3D.txt';
//FID = fopen(Nom, 'rt');
//AR = fscanf(FID, '%f\t%f\t%f\n', [3, inf])';
//fclose(FID);
//Femur_Vision3D = AR;

void rowAddition(cv::Mat_<double> &mat, cv::Mat_<double> &row, int sign, cv::Mat_<double> &out) {
	for (int r = 0; r < mat.rows; r++)
		out.row(r) = mat.row(r) + sign*row;
}

void columnAddition(cv::Mat_<double> &mat, cv::Mat_<double> &col, int sign, cv::Mat_<double> &out) {
	for (int c = 0; c < mat.cols; c++)
		out.col(c) = mat.col(c) + sign*col;
}

void icp(cv::Mat_<double> &q, cv::Mat_<double> &p, int numel) {
	cv::Mat_<double> pmean, p2, qmean, q2, C, S, U, V, RN, TN, qn, val;
	cv::Mat_<double> diag, qnq2;
	double ErrorT;
    cv::reduce(p, pmean, 1, CV_REDUCE_AVG);
	rowAddition(p, pmean, -1, p2);
	cv::reduce(q, qmean, 1, CV_REDUCE_AVG);
	rowAddition(q, qmean, -1, q2);
	C = p2.t() * q2;

	cv::SVD::compute(C, S, U, V);

	int deter = cv::determinant(U*V.t());
	diag = cv::Mat::eye(3, 3, CV_8UC1);
	diag(2, 2) = (deter < 0 - deter > 0);
	RN = V * diag * U.t();
	TN = qmean.t() - RN * pmean.t();

	qn = RN * p.t();
	columnAddition(qn, TN, 1, qn);
	qn = qn.t();
	qnq2 = (qn - q).mul(qn - q);
	cv::reduce(qnq2, val, 0, CV_REDUCE_SUM);
	ErrorT = sqrt(cv::sum(val)[0] / numel);
}