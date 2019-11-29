// drill.cpp : Defines the entry point for the console application.

/*-------------------------------------------------------
Interfaz 2016, all rights reserved.

This code serves as a bridge between the pattern-finder
algorithm implemented in python and the OPTITRACK SDK
coded in C / C++. For this purpose, both the Python C-API
and the numpy API are used.

Besides some mandatory steps required for the APIs to work,
the code begins starting the cameras and importing the track
function from the tracker python module.

Once the previous steps are completed an infinite loop is
started, where frames are retrieved, cast to python objects
and passed to the track function. The output is cast back
to a C++ array and the coordinates extracted from it are
accumulated till data from both cameras are retrieved. Then,
the stereo_triangulation function is called in order to get
the corresponding 3-D coordinates.

Author: Jesús Muñoz
Version: 0.1
---------------------------------------------------------*/

#ifndef _DRILL_H_
#define _DRILL_H_

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#undef _DEBUG
//#include "data.h"

#include "python.h"
#include "numpy/arrayobject.h"
#include "opencv/cv.hpp"
#include "triangulation.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>

long g_lCurrentDrillFrame = 0;
bool g_bPlayingDrill = false;
DWORD PlayingThread_Drill_ID = NULL;
HANDLE PlayingThread_HandleDrill = NULL;
const double DISTANCE_2_END = 269;

namespace CustomCameraLibrary {
	using namespace cv;

	npy_intp data_dims[2];
	double** m;
	double** m2;
	int dims;
	npy_intp size;
	double *optr;

	int control = 0;
	int cameraHeight;
	int cameraWidth;

	PyArrayObject *data, *data2, *drill;
	PyObject *refZone, *param_stereo;
	PyObject *refZone2, *param_broca;
	PyObject *args, *myModuleString, *mdict, *pythonFunc, *myModule;

	struct tip {
		Mat_<double> left;
		Mat_<double> right;
	};
	//	Mat matFrame;
	//	Mat_<double> PP;

	DWORD dResult;
	HANDLE drillSemaphore;

	int initPython(int height, int width) {
		cameraWidth = width;
		cameraHeight = height;

		Py_Initialize();
		import_array1(-1);

		/* Try to import tracker function from python */
		PyObject* sysPath = PySys_GetObject((char*)"path");
		PyList_Append(sysPath, PyString_FromString("."));

		myModuleString = PyString_FromString((char*)"bilineal");
		myModule = PyImport_Import(myModuleString);
		//DBOUT(myModuleString)
		//		Py_DECREF(myModuleString);
		if (myModule)
		{
		
			mdict = PyModule_GetDict(myModule);
			pythonFunc = PyDict_GetItemString(mdict, "orientacion_P3D");
		}
		else
		{
			std::cout << "Something went wrong while importing Python code";
			return 1;
		}
		std::cout << cameraHeight;

		data_dims[0] = cameraHeight;  // 1024
		data_dims[1] = cameraWidth; // 1280

		dims = cameraWidth * cameraHeight;
		m = new double*[cameraHeight];
		m[0] = new double[dims];

		m2 = new double*[cameraHeight];
		m2[0] = new double[dims];

		return 0;
	}

	Mat_<double> computeTip(Mat_<double> XX) {
		Mat_<double> XU, Tip, deltaX;
		deltaX = XX.col(1) - XX.col(0);
		XU = (deltaX) / norm(deltaX);
		Tip = XU * DISTANCE_2_END + XX.col(1);

		return Tip;
	}

	PyArrayObject* doDrill() {
		return (PyArrayObject*)PyObject_CallObject(pythonFunc, args);
	}

	tip findTip(Mat_<double> PPP1, Mat_<double> PPP2) {
		Mat_<double> XRB, XLB;
		tip Tip;
		stereo_triangulation(PPP2, PPP1, cdata::om, cdata::T,
			cdata::fc_left, cdata::cc_left, cdata::kc_left, 0,
			cdata::fc_right, cdata::cc_right, cdata::kc_right, 0, XLB, XRB);
		std::cout << "XLB: " << XLB << std::endl;
		std::cout << "XRB: " << XRB << std::endl;
		Tip = {
			computeTip(XLB),
			computeTip(XRB),
		};

		return Tip;
	}

	Mat_<double> initDrill(Mat matFrame, Mat matFrame2, Mat_<double> P2D, Mat_<double> P2D2) {
		Mat_<double> PP(2, 4);
		PP(0, 0) = 9999;
		

		//		dResult = WaitForSingleObject(drillSemaphore, INFINITE);
		//		if (dResult == WAIT_OBJECT_0) {
		/* Workaround to cast the frame to a python object */
		for (int i = 1; i < cameraHeight; i++) {
			m[i] = m[i - 1] + cameraWidth;
			m2[i] = m2[i - 1] + cameraWidth;
		}

		for (int i = 0; i < cameraHeight; i++) {
			for (int j = 0; j < cameraWidth; j++) {
				m[i][j] = matFrame.at<unsigned char>(i, j);
				m2[i][j] = matFrame2.at<unsigned char>(i, j);
			}
		}

		data = (PyArrayObject*)PyArray_SimpleNewFromData(2, data_dims,
			NPY_DOUBLE, m[0]);
		data2 = (PyArrayObject*)PyArray_SimpleNewFromData(2, data_dims,
			NPY_DOUBLE, m2[0]);
		refZone = Py_BuildValue("((dd), (dd))", P2D(0, 0), P2D(1, 0), P2D(0, 1), P2D(1, 1));
		refZone2 = Py_BuildValue("((dd), (dd))", P2D2(0, 0), P2D2(1, 0), P2D2(0, 1), P2D2(1, 1));
		param_broca = Py_BuildValue("(dddddd)", 209.712, 1.0, 5.0, 4.7, 8.7, 41.0);
		param_stereo = Py_BuildValue("(dddddddddddddddddddddddddd)", cdata::fc_left(0, 0), cdata::fc_left(1, 0), cdata::cc_left(0, 0), cdata::cc_left(1, 0), cdata::kc_left(0, 0),
			cdata::kc_left(1, 0), cdata::kc_left(2, 0), cdata::kc_left(3, 0), cdata::kc_left(4, 0), cdata::alpha_c_left, cdata::fc_right(0, 0), cdata::fc_right(1, 0),
			cdata::cc_right(0, 0), cdata::cc_right(1, 0), cdata::kc_right(0, 0), cdata::kc_right(1, 0), cdata::kc_right(2, 0), cdata::kc_right(3, 0),
			cdata::kc_right(4, 0), cdata::alpha_c_right, cdata::om(0, 0), cdata::om(1, 0), cdata::om(2, 0), cdata::T(0, 0), cdata::T(1, 0), cdata::T(2, 0));

		/* Pack arguments and call python function */
		args = PyTuple_New(6);
		PyTuple_SetItem(args, 0, reinterpret_cast<PyObject*>(data));
		PyTuple_SetItem(args, 1, reinterpret_cast<PyObject*>(data2));
		PyTuple_SetItem(args, 2, reinterpret_cast<PyObject*>(refZone));
		PyTuple_SetItem(args, 3, reinterpret_cast<PyObject*>(refZone2));
		PyTuple_SetItem(args, 4, reinterpret_cast<PyObject*>(param_broca));
		PyTuple_SetItem(args, 5, reinterpret_cast<PyObject*>(param_stereo));
		PyArray_ENABLEFLAGS(data, NPY_ARRAY_OWNDATA);
		PyArray_ENABLEFLAGS(data2, NPY_ARRAY_OWNDATA);

		drill = doDrill();

		/* Extract coordinates only if a 2-D matrix was returned */
		if (drill && PyArray_NDIM(drill) == 2) {
			size = PyArray_SIZE(drill);
			optr = (double*)PyArray_DATA(drill);
			for (int i = 0; i < 3; i++) {
				PP(0, i) = *optr;
				optr++;
			}
			PP(0, 3) = 0;
			for (int i = 0; i < 3; i++) {
				PP(1, i) = *optr;
				optr++;
			}
			PP(1, 3) = 0;
		}
		cout << "PP" << PP;

		return PP;
	}
}
#endif //_DRILL_H_