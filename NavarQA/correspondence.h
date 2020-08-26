#ifndef _CORRESPONDENCE_H_
#define _CORRESPONDENCE_H_
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <stdio.h>
#include "opencv\cv.hpp"
#include <algorithm>
#include <vector>
#include <functional>
#include <math.h>
#include <qdebug.h>
#define PI 3.14159265
#define AREA 100								///< área mínima de las esferas de referencia de la broca
#define AREA_ESFERA_PEQ 50						///< área mínima de las esferas peque;a de referencia de los CR

#define MAX_ESFERA 20						///< cantidad máxima de esferas en la escena
#define DIST_MAX 100						///< distancia máxima a la que puede estar una esfera grande de una pequeña (de referencia)
namespace CustomCameraLibrary {
	using namespace cv;
	using namespace std;

	/**
	* Reordena un conjunto de esferas de tal manera que la correspondencia se cumpla. Las ordena siguiendo sentido horario y partiendo de la esfera más pequeña
	* que tienen los marcadores.
	* @param S una referencia al conjunto de esferas que van a ser ordenadas.
	* @param cm representa el promedio de los centroides.
	*/
	void reorden(Mat_<double> &S, Mat_<double> cm) {

		Mat_<double> N, DX1, sum, raiz, rep, Theta, ORDENADO, DX, U, ux, uy, us, Compx, Compy;
		Mat testIdx;
		cv::Mat_<double> unit(1, 3);
		unit[0][0] = 0; unit[0][1] = 0; unit[0][2] = 1;
		N = S.t();

		/*Desplazamiento al centroide.*/
		subtract(N, repeat(cm, 4, 1), DX1);

		/*Vectores unitarios a cada esfera.*/
		reduce(DX1.mul(DX1, 1), sum, 1, CV_REDUCE_SUM);
		cv::sqrt(sum, raiz);
		rep = cv::repeat(raiz, 1, 2);
		cv::divide(DX1, rep, U);

		/*Definición de un sistema coordenado x,y de tal manera que el vector unitario de la primera esfera es el eje x;
		el eje z es el perpendicular a las esferas (que solo tienen x,y en pixeles) y el eje y es el producto cruz.*/
		U(Range(0, U.rows - 3), Range(0, U.cols)).copyTo(ux);
		cv::hconcat(ux, 0, us);
		uy = cross_product(unit, us);
		uy(Range(0, uy.rows), Range(0, uy.cols - 1)).copyTo(uy);

		/*Calculo de proyecciones a los vectores unitarios x,y,z*/
		reduce(U.mul(cv::repeat(ux, 4, 1)), Compx, 1, CV_REDUCE_SUM);
		reduce(U.mul(cv::repeat(uy, 4, 1)), Compy, 1, CV_REDUCE_SUM);

		/*Calculo de los angulos con el eje x en el rango de pi a -pi y correcion de angulos negativos*/
		Theta = invTan2(Compy, Compx);

		/*Organización en sentido horario de los angulos*/
		sortIdx(Theta, testIdx, CV_SORT_ASCENDING | CV_SORT_EVERY_COLUMN);

		/*Reasignación de centroides.*/
		ORDENADO = OrderByIdx(N, testIdx, 4);   //Generar redoren by indexes
		ORDENADO = ORDENADO.t();
		ORDENADO.copyTo(S);
	}

	/**
	*	Encuentra las 4 esferas más cercanas a la esfera de referencia (la que tiene menor área).
	*	@param P es el conjunto de esferas.
	*	@param posRef es la posición de la esfera de referencia.
	*	@return un conjunto de esferas que hacen parte de un objeto rígido.
	*/
	Mat_<double> findSpheres(Mat_<double> P, int posRef) {
		Mat_<double> L(1, 1);		// L: conjunto de coord x,y de las esferas de un C.R
		Mat_<double> cm, temp;
		L(0, 0) = -100;
		double minVal;
		double maxVal;
		Point minLoc;
		Point maxLoc;
		ofstream ArchivoL;

		Mat_<double> D;
		int x = 1500;
		temp = P.t();
		reduce(temp, cm, 0, CV_REDUCE_AVG);
		// crear matriz de distancias con respecto a la posición de referencia
		for (int i = 0; i < P.cols; i++) {
			if (i != posRef)
				D.push_back(norm(P.col(posRef) - P.col(i)));
			else D.push_back(1000.00);
		}
		//				cout << L << endl;
		minMaxLoc(D, &minVal, &maxVal, &minLoc, &maxLoc);
		if (minVal<50)
		{
			L = P.col(minLoc.y);			// primera esfera del C.R.
			D(minLoc.y, 0) = x;

			for (int i = 0; i < 3; i++) {	// restantes 4 esferas del C.R
				x += 500;
				minMaxLoc(D, &minVal, &maxVal, &minLoc, &maxLoc);
				hconcat(L, P.col(minLoc.y), L);
				D(minLoc.y, 0) = (double)x;
			}
			//Guardar L antes de reordenar.
			reorden(L, cm);
		}
		else {
			L(0, 0) = -100;
		}

		return L;
		ArchivoL.close();
	}



	/**
	*	Ejecutado en el momento de rastrear la broca. Localiza el indicador de la broca.
	*	@param P es el conjunto de esferas.
	*	@param posRef es la posición de la esfera de referencia.
	*	@return la posición en pixeles de la ubicación del indicador de la broca.
	*/
	int findDrill(Mat_<double> P, int posRef) {
		//		Mat_<double> L,; 
		double minVal;
		double maxVal;
		Point minLoc;
		Point maxLoc;
		int pos;

		if (P.cols % 5 == 1) {
			Mat_<double> D;
			int x = 1500;
			// crear matriz de distancias con respecto a la posición de referencia
			for (int i = 0; i < P.cols; i++) {
				if (i != posRef)
					D.push_back(norm(P.col(posRef) - P.col(i)));
				else {
					D.push_back(1000.00);
					pos = i;
				}
			}
			//		cout << D << endl;

			minMaxLoc(D, &minVal, &maxVal, &minLoc, &maxLoc);
			if (minVal > 100)
				return pos;
			//		L = P.col(minLoc.y);
			D(minLoc.y, 0) = x;

			for (int i = 0; i < 3; i++) {
				//			x += 500;
				minMaxLoc(D, &minVal, &maxVal, &minLoc, &maxLoc);
				if (minVal > 100)
					return pos;
				//			hconcat(L, P.col(minLoc.y), L);
				D(minLoc.y, 0) = (double)x;
			}
		}
		return -1;
	}

	/**
	*	Compara las áreas y detecta la posición de las esferas más pequeñas (esferas de referencia en cada cuerpo rígido) en el conjunto de esferas.
	*	@param A referencia al conjunto de áreas.
	*	@param areas_men matriz que será llenada con las ubicaciones de las áreas más pequeñas encontradas
	*	@return entero que indica el estado de la búsqueda de éstas esferas de referencia.
	*/
	int areas(Mat_<double> &A, Mat_<int> &areas_men)
	{
		Mat_<double> Arreglo;
		Mat_<double> Evaluate;
		Mat_<double> Promedio, Menores, rnd, Menores2, Mayores;
		int flag = 0;
		bool state = false;
		ofstream Areas;

		if (A.rows <= MAX_ESFERA) {
			int s = A.rows; //Extrae numero de objetos
			Arreglo = A;
			if (s % 5 == 0)    //Verifica que sí es multiplo de 5 que corresponde a una estrella
			{
				cv::sort(Arreglo, Evaluate, 1); //Ordenamiento de areas de menor a mayor

				for (int i = 0; i < s; i++) {   //Evaluar hasta el número de objetos
					if (s / 5 == i) {  // Evaluar la cantidad de esferas pequeñas que deberian haber
						Evaluate(Range(0, i), Range(0, Evaluate.cols)).copyTo(Menores); // Sacar areas menores
						Evaluate(Range(i, Evaluate.rows), Range(0, Evaluate.cols)).copyTo(Mayores); // Sacar areas Mayores

						for (int j = 0; j < Arreglo.rows; j++) {//Busqueda en el arreglo original las i esferas.
							for (int y = 0; y < i; y++) {
								if (Arreglo(j, 0) == Evaluate(y, 0)) { //Busqueda de esferas pequeñas

									if (flag <= i && areas_men.rows < i) {
										areas_men.push_back(j); //Envio de posicion de esfera pequeña
										state = true; //Envio de estado
										flag++;
									}
								}
							}
						}
					}
				}
			}
			if ((A.rows - 3) % 5 == 0) {
				qDebug() << "Hay una broca" << endl;
				detect_broca = true;

				cv::sort(Arreglo, Evaluate, 1); //Ordenamiento de areas de menor a mayor
			}
			
			else {
				qDebug() << "ERROR: Encontradas m�s esferas peque�as >> correspondence.h" << endl;
				//cout << "ERROR: Encontradas m�s esferas peque�as >> correspondence.h" << endl;
				//system("PAUSE");
				state = false;
			}
		}
		return state;
	}

	/**
	*	Detecta la correspondencia de las esferas de la cámara izq con la derecha.
	*	@param P es el conjunto de esferas.
	*	@param A es el conjunto de áreas.
	*	@param	F_Broca es el conjunto de esferas de la broca
	*	@return un conjunto de esferas ordenadas según la correspondencia.
	**/
	cv::Mat_<double> CorrespondenceDetection(cv::Mat_<double> P, cv::Mat_<double> A/*, cv::Mat_<double> F_Broca*/) {
		cv::Mat_<double> F0;
		cv::Mat_<int> areas_men;		//	posición de las áreas menores
										//buscar la segunda area menor tal vez asi

		ofstream Areas;
		if (!Areas.is_open()) {
			Areas.open("Areas.txt", std::ios::app);

		}
		int ar = areas(A, areas_men);
		if (!A.empty() && ar>0) { // si el arreglo de areas no es vacio, y si hay areas pequeñas (esfera mas pequeña) 

			F0 = findSpheres(P, areas_men(0, 0));
			if (areas_men.rows>1)
			{
				for (int i = 1; i < areas_men.rows; i++) {
					hconcat(F0, findSpheres(P, areas_men(i, 0)), F0);
				}
			}
		}
		else if (P.cols == 1) {
			return P;
		}
		return F0;
		Areas.close();
	}
}

namespace CCL = CustomCameraLibrary;
#endif //_CORRESPONDENCE_H_