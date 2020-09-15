#ifndef _DATACALIB_H_
#define _DATACALIB_H_

#include "opencv\cv.hpp"

namespace cdata {
	using namespace cv;

	/* Parámetros extrísecos e intrínsecos de las cámaras
	*	xL: 2xN matrix of pixel coordinates in the left image
	*   xR : 2xN matrix of pixel coordinates in the right image
	*   om, T : rotation vector and translation vector between right and left cameras(output of stereo calibration)
	*	fc_left, cc_left, ... : intrinsic parameters of the left camera(output of stereo calibration)
	*	fc_right, cc_right, ... : intrinsic parameters of the right camera(output of stereo calibration)
	*/

	/**
	* Parámetros intrínseco de la cámaras. Se debe rellenar
	*/
	Mat_<double> fc_left(2, 1);		///< Parámetros intrínseco de la cámara izquierda.
	Mat_<double> cc_left(2, 1);		///< Parámetros intrínseco de la cámara izquierda.
	Mat_<double> kc_left(5, 1);		///< Parámetros intrínseco de la cámara izquierda.
	double alpha_c_left   = 0;
	Mat_<double> fc_right(2, 1);	///< Parámetros intrínseco de la cámara derecha.
	Mat_<double> cc_right(2, 1);	///< Parámetros intrínseco de la cámara derecha. 
	Mat_<double> kc_right(5, 1);	///< Parámetros intrínseco de la cámara derecha. 
	double alpha_c_right  = 0;
	Mat_<double> om(3, 1);			///< Parámetros extrínseco de las cámaras. 
	Mat_<double> T(3, 1);			///< Parámetros extrínseco de las cámaras.

	/**
	* Matriz de distancias entre las esferas de los cuerpos rígidos.
	* La primera fila corresponde a las distancias conocidas del pointer en milímetros, la segunda a las del femur, las terceras a las de la tíbia
	* y la cuarta a la de las gafas.
	* > Siempre se debe conservar este orden.}
	25.49, 42.38, 34.64, 42.63, 48.39, 17.63,		//FEMUR
	*/

	Mat_<float> distances = (Mat_<float>(5, 6) <<
		47.50, 50.51, 39.46, 22.47, 49.08, 29.55,		// pointer corto
		54.63, 45.66, 45.56, 42.63, 44.39, 17.63,		//FEMUR o clavo
		59.81, 89.64, 79.49, 69.49, 102.91, 106.73,		//TIBIA o canula grande ver
		188.62, 126.20, 78.17, 55.66, 126.57, 79.28,	//GAFAS
		49.85, 110.45, 159.97, 0, 0, 0);      // broca grande ver 


	Mat_<float> BrocaDis = (Mat_<float>(1,2)<<
		25.11, 73.01); //Distancias broca

	Mat_<float> PARAM = (Mat_<double>(3, 3) <<
		-237.4290, 84.1204, 12.7156,
		0.7137, 0.5809, 1.7784,
		2.4929, 1.7679, 7.0501);///< PARAM	PR

	Mat_<float> PARAMPunta = (Mat_<double>(2, 3) <<
		-201.79, -127.01, 862.1006,
		1.71,-167.53, 853.49);///< PARAM	PR

	Mat_<double> f_cor = (Mat_<double>(3, 1) << 0, 0, 0);///< Parámetros extrínseco de las cámaras.
														 // 4.5238

	Mat_<double> phantom = (Mat_<float>(47, 3) <<
		0.0000, 0.0000, -1.9025,
		0.0000, 14.4400, -1.9025,
		14.4400, 0.0000, -1.9025,
		0.0000, 28.8800, -1.9025,
		28.8800, 0.0000, -1.9025,
		0.0000, 43.3200, -1.9025,
		43.3200, 0.0000, -1.9025,
		0.0000, 57.7600, -1.9025,
		57.7600, 0.0000, -1.9025,
		0.0000, 72.2200, -1.9025,
		72.2000, 0.0000, -1.9025,
		0.0000, 86.6400, -1.9025,
		86.6400, 0.0000, -1.9025,
		0.0000, 101.0800, -1.9025,
		101.0800, 0.0000, -1.9025,
		0.0000, 115.5200, -1.9025,
		115.5200, 0.0000, -1.9025,
		0.0000, 129.9600, -1.9025,
		129.9600, 0.0000, -1.9025,
		32.5000, 32.5000, -1.9025,
		16.2500, 113.7500, -1.9025,
		32.5000, 97.5000, -1.9025,
		48.7400, 81.2500, -1.9025,
		64.9900, 65.0100, -1.9025,
		81.2400, 48.7600, -1.9025,
		97.4900, 32.5100, -1.9025,
		113.7300, 16.2600, -1.9025,
		35.3600, 130.0000, 8.0975,
		59.3400, 115.9100, 8.0975,
		68.5400, 96.8200, 8.0975,
		87.6300, 87.6300, 13.0975,
		118.7379, 56.5111, 13.0975,
		87.6300, 87.6300, 13.0975,
		130.0000, 35.3600, 13.0975,
		66.8213, 130.9413, 35.2185,
		98.8913, 98.8913, 35.2326,
		130.9513, 66.8213, 35.2225,
		89.3913, 117.6713, 41.7945,
		117.6713, 89.3913, 41.7945,
		85.3813, 130.9613, 48.3565,
		108.1813, 108.1813, 48.3706,
		130.9613, 85.3813, 48.3565,
		101.8900, 130.0000, 54.1675,
		130.0000, 101.8900, 54.1675,
		120.1800, 120.1800, 54.1675,
		118.8100, 130.0000, 54.1675,
		130.0000, 118.8100, 54.1675
		);
}
#endif // _DATACALIB_H_
