#ifndef _CALIBRATION_H_
#define _CALIBRATION_H_

#include <iostream>
#include <sys/stat.h>
#include <time.h>
#include "opencv\cv.hpp"

namespace calibration {

	FILE *p1, *p2, *p3;
	time_t now;
	int count;

	cv::Mat_<double> tmp;
	bool open = true;

	bool FileExists(char* filename)
	{
		struct stat fileInfo;
		return stat(filename, &fileInfo) == 0;
	}

	void closeFile() {
		if (p1)
			fclose(p1);
		if (p2)
			fclose(p2);
		if (p3)
			fclose(p3);
	}

	void savePointerData(cv::Mat_<double> OR) {
		if (open) {
			now = time(0);
			count = 0;
			p1 = fopen("p1.pts", "w");
			p2 = fopen("p2.pts", "w");
			p3 = fopen("p3.pts", "w");
			open = false;
		}
		cv::Mat_<double> t(3, 1);
		count++;
		if (count == 11) {
			closeFile();
			std::cout << std::endl << "elapsed time: " << time(0) - now << std::endl;
		}

		if (!p1) {
			fprintf(p1, "%f\t%f\t%f\t", OR.col(3)(0, 0), OR.col(3)(1, 0), OR.col(3)(2, 0));
			fprintf(p1, "\n");
		}
		if (!p2) {
			fprintf(p2, "%f\t%f\t%f\t", OR.col(2)(0, 0), OR.col(2)(1, 0), OR.col(2)(2, 0));
			fprintf(p2, "\n");
		}
		if (p3) {
			//fprintf(p3, "%f\t%f\t%f\t", OR.col(1)(0, 0), OR.col(1)(1, 0), OR.col(1)(2, 0));
			fprintf(p3, "%f\t%f\t%f\t", OR.col(0)(0, 0), OR.col(0)(1, 0), OR.col(0)(2, 0));
			fprintf(p3, "\n");
		}
	}

	void saveImageData(cv::Mat_<double> OR) {
		cv::Mat_<double> t(2, 1);

		if (p1) {
			fprintf(p1, "%f\t%f\t", OR.col(3)(0, 0), OR.col(3)(1, 0));
			fprintf(p1, "\n");
		}
		if (p2) {
			fprintf(p2, "%f\t%f\t", OR.col(2)(0, 0), OR.col(2)(1, 0));
			fprintf(p2, "\n");
		}
		if (p3) {
			fprintf(p3, "%f\t%f\t", OR.col(1)(0, 0), OR.col(1)(1, 0));
			fprintf(p3, "\n");
		}
	}
}
#endif //_CALIBRATION_H_