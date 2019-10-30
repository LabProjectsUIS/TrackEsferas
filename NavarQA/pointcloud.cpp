#include "pointcloud.h"

using namespace CCL;

bool Cloud::erasePoint(Point3d point) {
	try {
		cloud.erase(remove(cloud.begin(), cloud.end(), point), cloud.end());
		/*if (it != cloud.end())
		cout << "ERROR: No fue posible borrar el punto." << endl;
		else*/
		cout << "INFO: Punto borrado con éxito." << endl;

		return true;
	}
	catch (const std::exception&) {
		cout << "ERROR: No fue posible borrar el punto." << endl;
	}
	return false;
}

bool Cloud::savePoint(Point3d point, int key) {
	cout << "PIN POLLO 1" << endl;
	bool b = false;

	if (mode == AUTO) {
		this_time = clock();
		time_counter += (double)(this_time - last_time);
		last_time = this_time;
		cout << "MODO AUTOMATICO" << endl;
		cout << "PUNTOS: " << cloud.size() << endl;

		if (status == true) {
			if (time_counter > (double)(NUM_SECONDS * CLOCKS_PER_SEC)) {
				writeFile(fp, point);
				cloud.push_back(point);
				PlaySound(TEXT("beep-22.wav"), NULL, SND_FILENAME | SND_ASYNC);									// reproducir sonido beeep
				cout << point << endl;
				time_counter = 0;// -= (double)(NUM_SECONDS * CLOCKS_PER_SEC);
			
				if (cloud.size()  == 200) {
					writeFooter(fp);
					status = false;
					//PlaySound(TEXT("beep-22.wav"), NULL, SND_FILENAME | SND_ASYNC);
					PlaySound(TEXT("chicken.wav"), NULL, SND_FILENAME | SND_ASYNC);
				}
				b = true;
			}
		}		
		else cout << "INFO: No se guardan puntos." << endl;
				
//		int key = cvWaitKey(5);
	}
	else if (mode == MANUAL && status == true) {
		cout << "MODO MANUAL" << endl;
		cout << "PUNTOS: " << cloud.size() << endl;

//		int key = cvWaitKey(5);
		switch (key) {
		case 120:																							// presionar la tecla x
			//writeFile(fp, point);
			//cloud.push_back(point);
			//PlaySound(TEXT("beep-22.wav"), NULL, SND_FILENAME | SND_ASYNC);									// reproducir sonido beeep
			//cout << "INFO: Punto agregado con exito." << endl;
			//cout << "INFO: Puntos en la nube: " << cloud.size() << endl;
			break;
		case 97:																							// presionar la tecla a
			//writeFooter(fp);
//			cout << getCloud() << endl;
			break;
		default:
			break;
		}
		
		b = true;
	}
	else cout << "INFO: No se guardan puntos." << endl;

	return b;
}

bool Cloud::savePoints(vector<Point3d> src) {

	try {
		cloud.insert(cloud.end(), src.begin(), src.end());
		cout << "INFO: Puntos añadidos con éxito." << endl;
		return true;
	}
	catch (const std::exception&) {
		cout << "ERROR: No fue posible guardar los puntos." << endl;
		return false;
	}
}

bool Cloud::eraseLast() {
	try {
		cloud.pop_back();
		return true;
	}
	catch (const std::exception&) {
		cout << "ERROR: No fue posible borrar el último punto." << endl;
		return false;
	}
}

bool Cloud::findPoint(Point3d point) {
	vector<Point3d> vector = getCloud();

	if (find(vector.begin(), vector.end(), point) != vector.end()) {
		return true;
	}
	return false;
}

void Cloud::writeFile(FILE* fp, Point3d data) {
	if (fp) {
		fprintf(fp, "%f\t%f\t%f\t", data.x, data.y, data.z);
		fprintf(fp, "\n");
	}
	else cout << "malllll";
}

void Cloud::writeFooter(FILE* fp) {
	if (fp) {
//		fprintf(fp, "</Data>\n\n");
//		fprintf(fp, "</PointSet>\n");
		fclose(fp);
	}
}

void Cloud::writeHeader(FILE* fp) {
	if (fp) {
		fprintf(fp, "# .PCD v.7 - Point Cloud Data file format\n");
		fprintf(fp, "VERSION .7\n");
		fprintf(fp, "FIELDS x y z\n");
		fprintf(fp, "SIZE  8 8 8\n");
		fprintf(fp, "TYPE F F F\n");
		fprintf(fp, "COUNT 1 1 1\n");
		fprintf(fp, "WIDTH %d\n", getCloud().size());
		fprintf(fp, "HEIGHT 1\n");
		fprintf(fp, "VIEWPOINT 0 0 0 1 0 0 0\n");
		fprintf(fp, "POINTS %d\n", getCloud().size());
		fprintf(fp, "DATA ascii\n");
	}
}