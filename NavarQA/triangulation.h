#ifndef _TRIANGULATE_POINTS_
#define _TRIANGULATE_POINTS_

#include "opencv\cv.hpp"
#include "globals.h"
namespace CustomCameraLibrary {
	using namespace cv;
	using namespace std;

	/**
	* Función que computa la posición de un conjunto de \a N puntos datas la imagen de proyección de la izquierda y la derecha.
	* Se asume que las cámaras han sido calibradas, intrísicamente, y extrínsicamente.
	* @param xL matriz 2xN de las coordenadas en pixeles de la imágen de la izquierda.
	* @param xR matriz 2xN de las coordenadas en pixeles de la imágen de la derecha.
	* @param om vector de rotación entre la cámara de la derecha y la cámara de la izquierda
	* @param T vector de translación entre la cámara de la derecha y la cámara de la izquierda (salida de la calibración estéreo)
	* @param fc_left parámetro intrínseco de la cámara izquierda (salida de la calibración estéreo).
	* @param cc_left parámetro intrínseco de la cámara izquierda (salida de la calibración estéreo).
	* @param kc_left parámetro intrínseco de la cámara izquierda (salida de la calibración estéreo).
	* @param fc_right parámetro intrínseco de la cámara derecha (salida de la calibración estéreo).
	* @param cc_right parámetro intrínseco de la cámara derecha (salida de la calibración estéreo).
	* @param kc_right parámetro intrínseco de la cámara derecha (salida de la calibración estéreo).
	* @param alpha_c_left valor 0 por omision.
	* @param alpha_c_right valor 0 por omision.
	* @param XL matriz vacía que alamcenará los puntos en 3D con respecto al marco de referencia de la cámara izquierda.
	* @param XR matriz vacía que alamcenará los puntos en 3D con respecto al marco de referencia de la cámara derecha.
	* @param alpha_c_right valor 0 por omision.
	* @return \a XL matriz 3xN de coordinadas de puntos en 3D con respecto al marco de referencia de la cámara izquierda.
	*         \a XR matriz 3xN de coordinadas de puntos en 3D con respecto al marco de referencia de la cámara derecha.
	*/
	void stereo_triangulation(Mat_<double> xL, Mat_<double> xR, Mat_<double> om, Mat_<double> T, Mat_<double> fc_left, Mat_<double> cc_left, vector<double> kc_left, double alpha_c_left, Mat_<double> fc_right, Mat_<double> cc_right, vector<double> kc_right, double alpha_c_right, Mat_<double>& XL, Mat_<double>& XR);

	void normalize_pixel(Mat_<double> x_kk, Mat_<double> fc, Mat_<double> cc, vector<double> kc, double alpha_c, Mat_<double>& x);
	void comp_distortion_oulu(Mat_<double> xd, vector<double> k, Mat_<double>& x);
	void dotProduct(Mat_<double> M, Mat_<double> N, Mat_<double>& K);
	void extendM(Mat_<double>& Z, double C);

	/*[XL, XR] = stereo_triangulation(xL, xR, om, T, fc_left, cc_left, kc_left, alpha_c_left, fc_right, cc_right, kc_right, alpha_c_right),
	*
	* Function that computes the position of a set on N points given the left and right image projections.
	* The cameras are assumed to be calibrated, intrinsically, and extrinsically.
	*
	* Input:
	*           xL : 2xN matrix of pixel coordinates in the left image
	*           xR : 2xN matrix of pixel coordinates in the right image
	*           om, T : rotation vector and translation vector between right and left cameras(output of stereo calibration)
	* fc_left, cc_left, ... : intrinsic parameters of the left camera(output of stereo calibration)
	* fc_right, cc_right, ... : intrinsic parameters of the right camera(output of stereo calibration)
	*
	* Output :
	*
	*           XL : 3xN matrix of coordinates of the points in the left camera reference frame
	*           XR : 3xN matrix of coordinates of the points in the right camera reference frame
	*
	* Note : XR and XL are related to each other through the rigid motion equation : XR = R * XL + T, where R = rodrigues(om)
	* For more information, visit http ://www.vision.caltech.edu/bouguetj/calib_doc/htmls/example5.html
	*
	*
	* (c)Jean - Yves Bouguet - Intel Corporation - April 9th, 2003*/
	void stereo_triangulation(Mat_<double> xL, Mat_<double> xR, Mat_<double> om, Mat_<double> T, Mat_<double> fc_left, Mat_<double> cc_left, vector<double> kc_left, double alpha_c_left, Mat_<double> fc_right, Mat_<double> cc_right, vector<double> kc_right, double alpha_c_right, Mat_<double>& XL, Mat_<double>& XR) {
		Mat_<double> xt, xtt, R, u, T_vect, DD, n_xt2, n_xtt2, u2, u3, dot_uT, dot_xttT, dot_xttu, NN1, NN2, Zt, Ztt, X1, X2, transXL;
		normalize_pixel(xL, fc_left, cc_left, kc_left, alpha_c_left, xt);
		normalize_pixel(xR, fc_right, cc_right, kc_right, alpha_c_right, xtt);
		xt.push_back(cv::Mat::ones(1, xt.cols, CV_64F));
		xtt.push_back(cv::Mat::ones(1, xtt.cols, CV_64F));
		int N = xt.cols;
		CustomCameraLibrary::detectPointer = true;

		ofstream archivoXL,archivoP1, archivoP2;
		if (!archivoXL.is_open())
		{
			archivoXL.open("XLObjeto.txt", std::ios::app);
		}
		if (!archivoP1.is_open()) {
			archivoP1.open("P1.txt", std::ios::app);

		}
		if (!archivoP2.is_open()) {
			archivoP2.open("P2.txt", std::ios::app);

		}
		//-- - Rotation matrix corresponding to the rigid motion between left and right cameras :
		Rodrigues(om, R);

		//-- - Triangulation of the rays in 3D space :
		u = R * xt;
		dotProduct(xt, xt, n_xt2);
		dotProduct(xtt, xtt, n_xtt2);

		T_vect = repeat(T, 1, N);
		dotProduct(u, xtt, u2);
		pow(u2, 2, u2);
		DD = n_xt2.mul(n_xtt2) - u2;

		dotProduct(u, T_vect, dot_uT);
		dotProduct(xtt, T_vect, dot_xttT);
		dotProduct(u, xtt, dot_xttu);

		NN1 = dot_xttu.mul(dot_xttT) - n_xtt2.mul(dot_uT);
		NN2 = n_xt2.mul(dot_xttT) - dot_uT.mul(dot_xttu);

		divide(NN1.t(), DD.t(), Zt);
		divide(NN2.t(), DD.t(), Ztt);
		//cout << Zt << endl << endl;
		extendM(Zt, xt.cols);
		extendM(Ztt, xtt.cols);

		//cout << xt << endl << Zt << endl;
		X1 = xt.mul(Zt);
		X2 = R.t()*(xtt.mul(Ztt) - T_vect);

		//-- - Left coordinates :
		XL = 0.5 * (X1 + X2);
		//-- - Right coordinates :
		XR = R*XL + T_vect;
		transXL = XL.t();

		int m = -1;
		int s = -1;
		

		if (transXL.rows == 4 && transXL.cols == 3 /*&& detectPointer == true*/) //Imprimir datos de esferas es un archivo xml
		{
			CustomCameraLibrary::COUNT = CustomCameraLibrary::COUNT + 1;
			if (CustomCameraLibrary::COUNT <=1000)
			{
			
				archivoP2 << CustomCameraLibrary::COUNT << "\t";
				archivoP2 << xL[0][0] << "\t";
				archivoP2 << xL[1][0] << "\t";
				archivoP2 << xL[0][1] << "\t";
				archivoP2 << xL[1][1] << "\t";
				archivoP2 << xL[0][2] << "\t";
				archivoP2 << xL[1][2] << "\t";
				archivoP2 << xL[0][3] << "\t";
				archivoP2 << xL[1][3] << "\t";
				archivoP2 << "\n";

				archivoP1 << CustomCameraLibrary::COUNT << "\t";
				archivoP1 << xR[0][0] << "\t";
				archivoP1 << xR[1][0] << "\t";
				archivoP1 << xR[0][1] << "\t";
				archivoP1 << xR[1][1] << "\t";
				archivoP1 << xR[0][2] << "\t";
				archivoP1 << xR[1][2] << "\t";
				archivoP1 << xR[0][3] << "\t";
				archivoP1 << xR[1][3] << "\t";
				archivoP1 << "\n";

				archivoXL << CustomCameraLibrary::COUNT << "\t";
				for (m = 0; m < transXL.rows; m++) // son 4 filas entonces de 0 a 3
				{
					for (int s = 0; s < transXL.cols; s++) //son 3 columnas entocnes de 0 a 2
					{
						if (transXL[m][s] == NULL || transXL.empty())
						{
							break;
						}
						else

						{
							archivoXL << transXL[m][s] << "\t";
						}
					}
					archivoXL << "\t";
				}

				archivoXL << "\n";
			}
			else
			{
				CustomCameraLibrary::COUNT = 0;
				system("PAUSE");
			}
		}
		archivoXL.close();
		archivoP1.close();
		archivoP2.close();
	}

	/**
	*normalize
	*
	*[xn] = normalize_pixel(x_kk, fc, cc, kc, alpha_c)
	*
	*Computes the normalized coordinates xn given the pixel coordinates x_kk
	*and the intrinsic camera parameters fc, cc and kc.
	*
	*INPUT: x_kk: Feature locations on the images
	*       fc : Camera focal length
	*       cc : Principal point coordinates
	*       kc : Distortion coefficients
	*       alpha_c : Skew coefficient
	*
	*OUTPUT : xn : Normalized feature locations on the image plane(a 2XN matrix)
	*
	*Important functions called within that program :
	*
	*comp_distortion_oulu : undistort pixel coordinates.
	*/
	void normalize_pixel(Mat_<double> x_kk, Mat_<double> fc, Mat_<double> cc, vector<double> kc, double alpha_c, Mat_<double>& x) {
		// First: Subtract principal point, and divide by the focal length :
		Mat_<double> m, n;
		divide((x_kk.row(0) - cc(0, 0)), fc(0, 0), m);
		divide((x_kk.row(1) - cc(1, 0)), fc(1, 0), n);

		Mat_<double> x_distort;
		x_distort.push_back(m);
		x_distort.push_back(n);

		x_distort.row(0) = x_distort.row(0) - alpha_c * x_distort.row(1);

		if (norm(kc))
			comp_distortion_oulu(x_distort, kc, x);
	}

	/**
	*
	*[x] = comp_distortion_oulu(xd, k)
	*
	*Compensates for radial and tangential distortion.Model From Oulu university.
	*For more informatino about the distortion model, check the forward projection mapping function :
	*project_points.m
	*
	*INPUT : xd : distorted(normalized) point coordinates in the image plane(2xN matrix)
	* k : Distortion coefficients(radial and tangential) (4x1 vector)
	*
	*OUTPUT : x : undistorted(normalized) point coordinates in the image plane(2xN matrix)
	*
	*Method : Iterative method for compensation.
	*
	*NOTE : This compensation has to be done after the subtraction
	*      of the principal point, and division by the focal length.*/

	void comp_distortion_oulu(Mat_<double> xd, vector<double> k, Mat_<double>& x) {
		double k1 = k[0];
		double k2 = k[1];
		double k3 = k[4];
		double p1 = k[2];
		double p2 = k[3];

		xd.copyTo(x);					// initial guess

		for (int i = 0; i < 19; i++) {
			Mat_<double> x0, x1, x2, x3, x4, r_2;
			pow(x, 2, x2);
			reduce(x2, r_2, 0, REDUCE_SUM);
			pow(r_2, 2, x0);
			pow(r_2, 3, x1);

			Mat_<double> k_radial = 1 + k1 * r_2 + k2 * x0 + k3 * x1;
			pow(x.row(1), 2, x3);
			pow(x.row(0), 2, x4);

			Mat_<double> m = 2 * p1*x.row(0).mul(x.row(1)) + p2*(r_2 + 2 * x4);
			Mat_<double> n = p1 * (r_2 + 2 * x3) + 2 * p2*x.row(0).mul(x.row(1));

			Mat_<double> delta_x;
			delta_x.push_back(m);
			delta_x.push_back(n);

			Mat_<double> t = (Mat_<double>(2, 1) << 1, 1);

			divide((xd - delta_x), t*k_radial, x);
		}
	}

	void dotProduct(Mat_<double> M, Mat_<double> N, Mat_<double>& K) {
		for (int i = 0; i < M.cols; i++) {
			K.push_back(M.col(i).dot(N.col(i)));
		}
	}

	void extendM(Mat_<double>& Z, double C) {
		for (int i = 0; i < 2; i++) {
			Z.push_back(Z.row(0));
		}
	}
}
namespace CCL = CustomCameraLibrary;
#endif // !_TRIANGULATE_POINTS_
