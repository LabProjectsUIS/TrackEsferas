#include "marker.h"
#include <iostream>
#include <math.h>

using namespace CCL;

const int MAX_NUM_OBJECTS = 50;			///< Número máximo de objetos permitidos en la escena.
const int MIN_OBJECT_AREA = 15;			///< Valor mínimo del área de un objeto para que sea considerado como un marcador.

Marker::Marker() {
	//set values for default constructor
	setType("Marker");
	setColor(Scalar(255, 255, 255));
	setEccentr(double(0));
}

Marker::~Marker(void) {}

cFrame::cFrame() {}

cFrame::~cFrame() {}


string cFrame::intToString(float number) {
	std::stringstream ss;
	ss << number;
	return ss.str();
}

void  cFrame::drawObject(vector<Marker> theMarkers, Mat &frame, vector< vector<Point> > contours, vector<Vec4i> hierarchy) {

	for (int i = 0; i<theMarkers.size(); i++) {
		//descomentar si se quiere dibujar los contornos
		//		drawContours(frame, contours, i, Scalar(0, 0, 255), 1, 8, hierarchy);
		circle(frame, Point(theMarkers.at(i).getX(), theMarkers.at(i).getY()), 2, Scalar(0, 0, 255));
		//descomentar si se quiere dibujar las coordenadas de los marcadores en la escena.
		//			putText(frame, intToString(theMarkers.at(i).getX()) + " , " + intToString(theMarkers.at(i).getY()), Point(theMarkers.at(i).getX(), theMarkers.at(i).getY() + 20), 1, 1, theMarkers.at(i).getColor());
		//			putText(frame, theMarkers.at(i).getType(), Point(theMarkers.at(i).getX(), theMarkers.at(i).getY() - 20), 1, 1, theMarkers.at(i).getColor());

		//		cout << "Marcador " << i + 1 << ": X: " << theMarkers.at(i).getArea() << "  Y: " << theMarkers.at(i).getArea() << endl;
	}
}

void cFrame::trackFilteredMarker(Marker theMarker, Mat &threshold, cFrame &cframe, Mat &frame) {
	cframe.markers.clear();

	Mat temp;
	threshold.copyTo(temp);
	//these two vectors needed for output of findContours
	vector< vector<Point> > contours;
	vector<Vec4i> hierarchy;
	//find contours of filtered image using openCV findContours function
	findContours(threshold, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE);
	//use moments method to find our filtered marker
	double refArea = 0;
	bool markerFound = false;
	if (hierarchy.size() > 0) {
		int numMarkers = hierarchy.size();
		//if number of markers greater than MAX_NUM_OBJECTS we have a noisy filter
		if (numMarkers < MAX_NUM_OBJECTS) {
			for (int index = 0; index >= 0; index = hierarchy[index][0]) {

				Moments moment = moments((cv::Mat)contours[index]);
				double area = moment.m00;
				double mu20 = moment.mu20 / area;
				double mu02 = moment.mu02 / area;
				double mu11 = moment.mu11 / area;
				double lambda1 = ((mu20 + mu02) / 2) + sqrt(4 * mu11*mu11 + (mu20 - mu02)*(mu20 - mu02)) / 2;
				double lambda2 = ((mu20 + mu02) / 2) - sqrt(4 * mu11*mu11 + (mu20 - mu02)*(mu20 - mu02)) / 2;
				double Eccentr = sqrt(1 - (lambda2 / lambda1));
				if (area > MIN_OBJECT_AREA) {
					Marker marker;
					marker.setX(moment.m10 / area);
					marker.setY(moment.m01 / area);
					marker.setType(theMarker.getType());
					marker.setColor(theMarker.getColor());
					marker.setArea(area);
					marker.setEccentr(Eccentr);
					cframe.markers.push_back(marker);
					markerFound = true;
				}
				//else markerFound = false;
			}
			if (markerFound == true) {
				//draw marker location on screen
				//drawObject(cframe.markers, frame, contours, hierarchy);
			}

		}
		else putText(threshold, "Mucho ruido en escena...", Point(0, 50), 1, 2, Scalar(0, 0, 255), 2);
	}
	else
		cout << "No se detectan marcadores en la escena..." << endl;
}