#ifndef _CORRESPONDENCE_H_
#define _CORRESPONDENCE_H_
#include<iostream>
#include<stdlib.h>
#include<fstream>
#include <stdio.h>
#include "opencv\cv.hpp"

#define AREA 100								///< área mínima de las esferas de referencia de la broca
#define AREA_ESFERA_PEQ 50						///< área mínima de las esferas peque;a de referencia de los CR

#define MAX_ESFERA 20						///< cantidad máxima de esferas en la escena
#define DIST_MAX 100						///< distancia máxima a la que puede estar una esfera grande de una pequeña (de referencia)
namespace CustomCameraLibrary {
	using namespace cv;
	using namespace std;

	int broca_pos;							///< posición del indicador de la broca
	bool detect_broca = false;				///< indicador para determinar si se empieza a detectar o se detiene la detección de la broca.
	Mat_<double> punto_broca(2, 1);			///< matriz que almacena el punto que referencia la broca.

/*
	bool derecha(Point2d ref, Point2d sel) {
		if (sel.x > ref.x) return true; // el seleccionado esta a la derecha
		else return false;
	}

	bool izquierda(Point2d ref, Point2d sel) {
		if (sel.x < ref.x) return true; // el seleccionado esta a la izquierda
		else return false;
	}

	bool arriba(Point2d ref, Point2d sel) {
		if (sel.y < ref.y) return true; // el seleccionado esta arriba
		else return false;
	}

	bool abajo(Point2d ref, Point2d sel) {
		if (sel.y > ref.y) return true; // el seleccionado esta abajo
		else return false;
	}
	*/

	/**
	* Reordena un conjunto de esferas de tal manera que la correspondencia se cumpla. Las ordena siguiendo sentido horario y partiendo de la esfera más pequeña
	* que tienen los marcadores.
	* @param S una referencia al conjunto de esferas que van a ser ordenadas.
	*/
	void reorden(Mat_<double> &S) {
		Point2d ref = S.col(0);
		Mat_<double> N = S.colRange(1, S.cols), tmp, L, R, U, D;					// sacar la 1era columna
		double minVal;
		double maxVal;
		Point minLoc;
		Point maxLoc;
		int up = 0, down = 0, left = 0, right = 0;// = 0;
		int x = 0;

		tmp = S.col(0);					// alamcenar la 1ra esfera identificada
		
		minMaxLoc(N.row(1), &minVal, &maxVal, &minLoc, &maxLoc);

		if (minVal < ref.y)	{ // hay arriba?
			up = 1;
			x = 0;
			for (int i = 0; i < N.cols; i++) { // contar cuántas esfera hay arriba
				if (ref.y > N(1, i)) {
					if (x == 0)
						N.col(i).copyTo(U);
					else hconcat(U, N.col(i), U);
					++x;
				}
			}
//			cout << "hay arriba: " << x << endl;// << U << endl;

			if (maxVal > ref.y) { // hay abajo?
				down = 2;
				x = 0;
				for (int i = 0; i < N.cols; i++) { // contar cuántas esfera hay arriba
					if (ref.y < N(1, i)) {
						if (x == 0)
							N.col(i).copyTo(D);
						else hconcat(D, N.col(i), D);
						++x;
					}
				}
//				cout << "hay abajo: " << x << endl;// << D << endl;
			}
		}
		else {
			down = 2;
			x = 0;
			for (int i = 0; i < N.cols; i++) { // contar cuántas esfera hay arriba
				if (ref.y < N(1, i)) {
					if (x == 0)
						N.col(i).copyTo(D);
					else hconcat(D, N.col(i), D);
					++x;
				}
			}
//			cout << "hay abajo: " << x << endl;// << D << endl;
		}

		minMaxLoc(N.row(0), &minVal, &maxVal, &minLoc, &maxLoc);

		if (maxVal > ref.x) { // hay a la derecha?
			right = 3;
			x = 0;
			for (int i = 0; i < N.cols; i++) { // contar cuántas esfera hay a la derecha
				if (ref.x < N(0, i)) {
					if (x == 0)	
						N.col(i).copyTo(R);
					else hconcat(R, N.col(i), R);
					++x;
				}
			}
//			cout << "hay derecha: " << x << endl;// << R << endl;

			if (minVal < ref.x) { // hay a la izquierda?
				left = 4;
				x = 0;
				for (int i = 0; i < N.cols; i++) { // contar cuántas esfera hay a la izquierda
					if (ref.x > N(0, i)) {
						if (x == 0)
							N.col(i).copyTo(L);
						else hconcat(L, N.col(i), L);
						++x;
					}
				}
//				cout << "hay izquierda: " << x << endl;// << L << endl;
			}
		}
		else {
			left = 4;
			x = 0;
			for (int i = 0; i < N.cols; i++) { // contar cuántas esfera hay a la izquierda
				if (ref.x > N(0, i)) {
					if (x == 0)
						N.col(i).copyTo(L);
					else hconcat(L, N.col(i), L);
					++x;
				}
			}
//			cout << "hay izquierda: " << x << endl;// << L << endl;
		}
//		cout << endl << up << down << right << left << endl;

//		cout << endl << "***********" << endl;

		// si la refrencia esta toalmente a la izq o a la derecha entonces simpre hay esferas a arriba o abajo
		if (up == 0 || down == 0) { // la referencia esta totalmente arriba o abajo
			if (up == 0) { // la referencia totalmente esta arriba
				if (R.cols < 3 && R.cols != 0 && L.cols != 0) {
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la der está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					if (R.cols > 1)
						hconcat(tmp, R.col(maxLoc.x), tmp);
					// encontramos las otras posiciones que faltan.
					minMaxLoc(L.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la izq está más abajo?
//					cout << "El siguiente es: " << endl << L.col(maxLoc.x) << endl;
					hconcat(tmp, L.col(maxLoc.x), tmp);
					if (L.cols > 1)
						hconcat(tmp, L.col(minLoc.x), tmp);
					tmp.copyTo(S);
				}
				else if (R.cols == 3) {
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la izq está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					R.row(1).at<double>(minLoc) = 10000;		// cambiar el valor de la coord que indica el corrimiento a la izq
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de arriba está más a la izq?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					R.row(1).at<double>(minLoc) = 15000;		// cambiar el valor de la coord que indica el corrimiento a la izq
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál es el menor de todos?
					hconcat(tmp, R.col(minLoc.x), tmp);
					tmp.copyTo(S);
//					cout << tmp << endl;
				}
				
			}
			else if (down == 0) { // la referencia esta totalmente abajo
				if (L.cols < 3 && L.cols != 0 && R.cols != 0) {
					// encontramos las otras posiciones que faltan.
					minMaxLoc(L.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la izq está más abajo?
//					cout << "El siguiente es: " << endl << L.col(maxLoc.x) << endl;
					hconcat(tmp, L.col(maxLoc.x), tmp);
					if (L.cols > 1)
						hconcat(tmp, L.col(minLoc.x), tmp);
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la der está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					if (R.cols > 1)
						hconcat(tmp, R.col(maxLoc.x), tmp);
					tmp.copyTo(S);
				}
				else if (L.cols == 3) {
					minMaxLoc(L.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la izq está más abajo?
//					cout << "El siguiente es: " << endl << L.col(maxLoc.x) << endl;
					hconcat(tmp, L.col(maxLoc.x), tmp);
					L.row(0).at<double>(maxLoc) = 10000;		// cambiar el valor de la coord que indica el corrimiento a la izq, se tira a la izq
					minMaxLoc(L.row(0), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de arriba está más a la izq?
//					cout << "El siguiente es: " << endl << L.col(minLoc.x) << endl;
					hconcat(tmp, L.col(minLoc.x), tmp);
					L.row(0).at<double>(minLoc) = 1500;		// cambiar el valor de la coord que indica el corrimiento a la izq
					minMaxLoc(L.row(0), &minVal, &maxVal, &minLoc, &maxLoc); // cuál es el menor de todos?
					hconcat(tmp, L.col(minLoc.x), tmp);
					tmp.copyTo(S);
//					cout << tmp << endl;
				}
				else if (R.cols == 3) {
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la der está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					R.row(1).at<double>(maxLoc) = 10000;		// cambiar el valor de la coord que indica el corrimiento a la izq
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de de la der está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					R.row(1).at<double>(minLoc) = 15000;		// cambiar el valor de la coord que indica el corrimiento a la izq
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál es el menor de todos?
					hconcat(tmp, R.col(minLoc.x), tmp);
					tmp.copyTo(S);
//					cout << tmp << endl;
				}
			}
		}
		else if (left == 0 || right == 0) { // la referencia esta totalmente a la izq o a la derecha
			if (left == 0) { // la referencia totalmente esta a la izq
				minMaxLoc(U.row(0), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de la arriba está más a la izq?
//				cout << "El siguiente es: " << endl << U.col(minLoc.x) << endl;
				hconcat(tmp, U.col(minLoc.x), tmp);
				if (U.cols > 1)
					hconcat(tmp, U.col(maxLoc.x), tmp);
				// encontramos las otras posiciones que faltan.
				minMaxLoc(D.row(0), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de abajo está más a la der?
//				cout << "El siguiente es: " << endl << D.col(maxLoc.x) << endl;
				hconcat(tmp, D.col(maxLoc.x), tmp);
				if (D.cols > 1)
					hconcat(tmp, D.col(minLoc.x), tmp);
				tmp.copyTo(S);
			}
			else { // la referencia esta totalmente a la der
				minMaxLoc(D.row(0), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de abajo está más a la der?
//				cout << "El siguiente es: " << endl << D.col(maxLoc.x) << endl;
				hconcat(tmp, D.col(maxLoc.x), tmp);
				if (D.cols > 1)
					hconcat(tmp, D.col(minLoc.x), tmp);
				   // encontramos las otras posiciones que faltan.
				minMaxLoc(U.row(0), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de las esferas de arriba está más a la izq?
//				cout << "El siguiente es: " << endl << U.col(minLoc.x) << endl;
				hconcat(tmp, U.col(minLoc.x), tmp);
				if (U.cols > 1)
					hconcat(tmp, U.col(maxLoc.x), tmp);
				tmp.copyTo(S);
				cout << tmp << endl << endl << S << endl << endl;

			}
		}
		else {
			if (R.cols == 1) {
				if (ref.y < R(1,0))	{ // si la referencia esta más arriba que la que esta a la der
					hconcat(tmp, R, tmp);
					minMaxLoc(L.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de las esferas de la izq está más abajo?
//					cout << "El siguiente es: " << endl << L.col(maxLoc.x) << endl;
					hconcat(tmp, L.col(maxLoc.x), tmp);
					if (L.cols > 1)
						hconcat(tmp, L.col(minLoc.x), tmp);
					tmp.copyTo(S);
				}
				else if (ref.y > R(1, 0)) { // si la referencia esta más abajo que la que esta a la der
					minMaxLoc(L.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de las esferas de la izq está más abajo?
//					cout << "El siguiente es: " << endl << L.col(maxLoc.x) << endl;
					hconcat(tmp, L.col(maxLoc.x), tmp);
					if (L.cols > 1)
						hconcat(tmp, L.col(minLoc.x), tmp);
					hconcat(tmp, R, tmp);
					tmp.copyTo(S);
				}
			}
			else if (L.cols == 1) {
				if (ref.y < L(1, 0)) { // si la referencia esta más arriba que la que esta a la izq
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de las esferas de la der está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					if (R.cols > 1)
						hconcat(tmp, R.col(maxLoc.x), tmp);
					hconcat(tmp, L, tmp);
					tmp.copyTo(S);
				}
				else if (ref.y > L(1, 0)) { // si la referencia esta más abajo que la que esta a la izq
					hconcat(tmp, L, tmp);
					minMaxLoc(R.row(1), &minVal, &maxVal, &minLoc, &maxLoc); // cuál de las esferas de la der está más abajo?
//					cout << "El siguiente es: " << endl << R.col(minLoc.x) << endl;
					hconcat(tmp, R.col(minLoc.x), tmp);
					if (R.cols > 1)
						hconcat(tmp, R.col(maxLoc.x), tmp);
					tmp.copyTo(S);
				}
			}
		}

//		cout << S << endl << endl << N << endl;
	}

	/**
	*	Encuentra las 4 esferas más cercanas a la esfera de referencia (la que tiene menor área).
	*	@param P es el conjunto de esferas.
	*	@param posRef es la posición de la esfera de referencia.
	*	@return un conjunto de esferas que hacen parte de un objeto rígido.
	*/
	Mat_<double> findSpheres(Mat_<double> P, int posRef) {
		Mat_<double> L(1,1);		// L: conjunto de coord x,y de las esferas de un C.R
		L(0, 0) = -100;
		double minVal;
		double maxVal;
		Point minLoc;
		Point maxLoc;
		
		Mat_<double> D;
		int x = 1500;
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
			reorden(L);
		}
		else {
			L(0, 0) = -100;
		}
		
		return L;
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
		float mayor,menor,resultado;
		cout << A;
		bool state =  false;
		//if (!detect_broca && A.rows % 5 == 0 && A.rows <= MAX_ESFERA) {
		if (!detect_broca && A.rows <= MAX_ESFERA) 
		{ //si no es broca y si las filas de A son menores o iguales a el limite(20)
			int x=0;
			Arreglo = A;
			for (int i = 0; i < A.rows; i++)
			{
				if (mayor<Arreglo(i, 0)){
					mayor = Arreglo(i, 0);
					//x = i;   //posicion del numero minimo
				}
			}
			menor = mayor;
			for (int i = 0; i < A.rows; i++)
			{
				if (menor>Arreglo(i, 0)) {
					menor = Arreglo(i, 0);
					//x = i;   //posicion del numero minimo
				}
			}
			resultado = menor; //el area mas pequeña esssssss..


			for (int i = 0; i < A.rows; i++) //recorriendo A hasta el numero de filas
			{ 
				int s = A.rows;
				double uno = A(i, 0);
				if (A(i, 0) < menor+1) 
				{	//evaluando si las areas son menores al menor
					if (x < (A.rows / 5) + 1) 
					{
						areas_men.push_back(i);		// guardar posición de las áreas más pequeñas.
						state = true;
						
					}
					else {
						cout << "ERROR: Encontradas más esferas pequeñas >> correspondence.h" << endl;
						state = false;
					}
					x++;
				}
			}
		}
		else if (detect_broca) {
			int x = 0;
			for (int i = 0; i < A.rows; i++) {
				if (A(i, 0) < AREA) {
					if (x < A.rows / 5 + 1) {		// más una esfera, la del taladro
						areas_men.push_back(i);		// guardar posición de las áreas más pequeñas.
						state = true;
						cout << A.row(i) << endl;
					}
					else {
						cout << "ERROR: No se logra detectar el indicador de la broca >> correspondence.h" << endl;
						state = false;
					}
					x++;
				}
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
		if (!A.empty() && areas(A, areas_men)) // si el arreglo de areas no es vacio, y si hay areas pequeñas (esfera mas pequeña) 
		{
			if (!detect_broca) 
			{ 
				F0 = findSpheres(P, areas_men(0, 0));
				if (F0.rows == 2 && F0.cols == 3) { 
					for (int i = 1; i < areas_men.rows; i++)
					{
						hconcat(F0, findSpheres(P, areas_men(i, 0)), F0);
					}
				}
			}
			else {
				punto_broca = cv::Mat_<double>(0, 0);
				for (int i = 0; i < areas_men.rows; i++) 
				
				{
					int k = findDrill(P, areas_men(i, 0));
					if (k >= 0) {
						//P.col(k).copyTo(punto_broca);
						punto_broca.push_back(P.col(k));
						//cout << "Broca en: " << endl << punto_broca << endl;
						/*	Mat_<int> e;
						if (k < P.cols - 1 && k > 0) {
						hconcat(P.colRange(0, k).rowRange(0, P.rows), P.colRange(k + 1, P.cols).rowRange(0, P.rows), e);
						break;
						}
						else if (k == 0) {
						e = P.colRange(1, P.cols).rowRange(0, P.rows);
						break;
						}
						else if (k == P.cols - 1) {
						e = P.colRange(0, P.cols - 1).rowRange(0, P.rows);
						break;
						}*/
					}
					else {
						if (empty(F0))
							F0 = findSpheres(P, areas_men(0, 0));
						else
							hconcat(F0, findSpheres(P, areas_men(i, 0)), F0);
					}
				}
			}
		}
		else if (P.cols == 1) {
			return P;
		}
		return F0;
	}
}

	/**
	*	Detecta la correspondencia de las esferas de la cámara izq con la derecha.
	*	@param P es el conjunto de esferas.
	*	@param A es el conjunto de áreas.
	*	@return un conjunto de esferas ordenadas según la correspondencia.
	**/
	/*void CorrespondenceDetection(Mat_<double> P, Mat_<double> A, Mat_<double> F, Mat_<double> F_Broca) {
		DBOUT("NBR")
		//Mat_<double> F;
//		vector< Mat_<double> > conjunto;															// conjunto de esferas de objetos rígidos
		// la 1ra posicion corresponde a la esfera pequeña de la tibia, la 2da a la esfera pequeña del pointer y la tercera a la esfera pequeña del femur
		Mat_<int> areas_men, D_Sort;		//	posición de las áreas menores
		Mat_<double> F0;
		int posRef,Cont;
/*		double minVal;
		double maxVal;
		Point minLoc;
		Point maxLoc;
		minMaxLoc(A, &minVal, &maxVal, &minLoc, &maxLoc);*/
		//S = P.col(minLoc.y);
//		cout << P << endl << endl << P.col(minLoc.y) << endl << endl << A << endl;
//		cout << "p" << endl;
//		int x = 0;
//		for (int i = 0; i < A.rows; i++) {
//			if (A(i, 0) < AREA) {
	//			if(x < 1)																	// CAMBIAR A if(x < 3) para leer los otros OR's, meter todas y luego verificar el tamaño de areas_men
	//				areas_men.push_back(i);		// guardar posición de las áreas más pequeñas.
//				else {
//					cout << "ERROR: Encontradas más de 3 esferas pequeñas (correspondence.h)" << endl;
//					return F;
//				}
//				x++;
//			}
//		}
//		areas_men.push_back(minLoc.y);
		//cout << A << endl;
		/*if (A.rows < 5) {
			return;
		}
		if (!A.empty() && areas(A, areas_men)) {
			//cout << areas_men;
			if (!detect_broca) {
				if (areas_men.rows>0) {
					Cont = 0;
					for (int i = 0; i < areas_men.rows; i++) {
						posRef = areas_men(i,0);
							Mat_<double> D;
							int x = 1500;
							// crear matriz de distancias con respecto a la posición de referencia
							for (int j = 0; j < P.cols; j++) {
								if (j != posRef)
									D.push_back(norm(P.col(posRef) - P.col(j)));
								else D.push_back(1000.00);
							}
							cv::sortIdx(D, D_Sort, SORT_EVERY_COLUMN + SORT_ASCENDING);
							
							if (D(D_Sort(0, 0),0) < 30 && D(D_Sort(3, 0),0) < 280)
							{
								Mat_<double> L;
								F0 = P.col(D_Sort(0, 0));
								L = F0;
								F0 = P.col(D_Sort(1, 0));
								hconcat(L, F0, L);
								F0 = P.col(D_Sort(2, 0));
								hconcat(L, F0, L);
								F0 = P.col(D_Sort(3, 0));
								hconcat(L, F0, L);
								reorden(L);
								if (Cont == 0) {
									F = L;
									Cont = 1;
								}
								else{
									hconcat(F, L, F);
								}


							}
							else if (D(D_Sort(1, 0), 0) >100)
							{
								F0  = P.col(posRef);
								F_Broca = P.col(D_Sort(0, 0));
								hconcat(F_Broca, F0, F_Broca);
							}
							
						}
					}
				}

			else {
				for (int i = 0; i < areas_men.rows; i++) {
					int k = findDrill(P, areas_men(i, 0));
//					punto_broca = Mat_<double>(2, 1);
					if (k >= 0) {
						P.col(k).copyTo(punto_broca);
						cout << "Broca en: " << endl << punto_broca << endl;
					/*	Mat_<int> e;
						if (k < P.cols - 1 && k > 0) {
							hconcat(P.colRange(0, k).rowRange(0, P.rows), P.colRange(k + 1, P.cols).rowRange(0, P.rows), e);
							break;
						}
						else if (k == 0) {
							e = P.colRange(1, P.cols).rowRange(0, P.rows);
							break;
						}
						else if (k == P.cols - 1) {
							e = P.colRange(0, P.cols - 1).rowRange(0, P.rows);
							break;
						}*/
					/*}
					else {
						if (empty(F))
							F = findSpheres(P, areas_men(0, 0));
						else 
							hconcat(F, findSpheres(P, areas_men(i, 0)), F);
					}
				}
			}
		}
	}
}*/
namespace CCL = CustomCameraLibrary;
#endif //_CORRESPONDENCE_H_