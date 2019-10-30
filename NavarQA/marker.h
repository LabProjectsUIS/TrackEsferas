#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <string>
#include "opencv\cv.hpp"

namespace CustomCameraLibrary {
	using namespace std;
	using namespace cv;

	/**
	*  Clase que representa un marcador reflectivo.
	*  Cuenta con propiedades que la definen y permite ir representando los marcadores que se encuentran dentro de la escena.
	*/
	class Marker
	{
	public:
		/**
		* Constructor por omisión. Establece "Marker" como tipo para cada marcador (solo es una etiqueta).
		*/
		Marker();
		/**
		* Destructor por omisión.
		*/
		~Marker(void);

		/**
		* Constructor con parámetros. Utilizado si se quiere asignar un nombre distinto al por omisión a los marcadores.
		* @param name es el mombre que se le quiere dar a un marcador. (No utilizada por el momento)
		*/
		Marker(string name);

		/**
		* Devuelve la posición \a Y en pixeles de un marcador.
		* @return la posición \a Y en pixeles de un marcador
		*/
		double Marker::getY() { return yPos; }

		/**
		* Devuelve la posición \a X en pixeles de un marcador.
		* @return la posición \a X en pixeles de un marcador
		*/
		double Marker::getX() { return xPos; }

		/**
		* Establece la posición \a X de un marcador detectado en la escena.
		* @param x un número que indica la posición en \a X en pixeles.
		*/
		void Marker::setX(float x) { xPos = x; }

		/**
		* Establece la posición \a Y de un marcador detectado en la escena.
		* @param y un número que indica la posición en \a Y en pixeles.
		*/
		void Marker::setY(float y) { yPos = y; }

		/**
		* Obtiene el "tipo" que se le haya colocado a los marcadores (El "tipo" es asignado desde el constructor).
		* @return un string que almacena el nombre de los marcadores.
		*/
		string getType() { return type; }

		/**
		* Obtiene el "tipo" que se le haya colocado a los marcadores un nombre a los marcadores detectados .
		* @param t un número que indica la posición en \a Y en pixeles.
		*/
		void setType(string t) { type = t; }

		/**
		* Obtiene el color que se le ha indicado al marcador, el color es utilizado para indicar de qué color son los marcadores (El "color" es asignado desde el constructor).
		* @return el color del marcador.
		*/
		Scalar getColor() { return Color; }

		/**
		* Asigna el color que tendrán los marcadores, el color es utilizado para indicar de qué color son los marcadores (El "color" es asignado desde el constructor).
		* @param c un color para el marcador.
		*/
		void setColor(Scalar c) { Color = c; }

		/**
		* Utilizado para guardar el área de un marcador que se ha detectado.
		* @param a área del marcador.
		*/
		void setArea(float a) { area = a; }

		/**
		* Utilizado para obtener el área de un marcador que se ha detectado.
		* @return el área del marcador.
		*/
		double getArea() { return area; }
		//		int markerCount() {	return markers.size(); }
		//		Marker marker(int i) { return markers[i]; }
		//		static vector <Marker> markers;
		double getEccentr() { return Eccentr; }
		void setEccentr(float a) { Eccentr = a; }
	private:
		/**
		*	Posición \a X en pixeles del marcador.
		*/
		double xPos;
		/**
		*	Posición \a Y en pixeles del marcador.
		*/
		double yPos;
		/**
		* Área del marcador.
		*/
		double area;
		/**
		*	Tipo o nombre del marcador.
		*/
		string type;

		/**
		* Color del marcador; por omisión se asigna el color blanco

		*    Scalar(255, 255, 255)
		*/
		Scalar Color;
		double Eccentr;
	};

	/**
	*  Clase que se utiliza como utilidad para ayudar a localizar los marcadores en escena.
	*  Ayuda a filtrar los marcadores que aprecen escena y visualiza en la pantalla aquellos marcadores que superan el filtro.
	*/
	class cFrame
	{
	public:
		/**
		* Constructor por omisión.
		*/
		cFrame();

		/**
		* Destructor por omisión.
		*/
		~cFrame();

		/**
		* Cuenta los marcadores que han pasado el filtro y se encuentran en escena, retorna un valor entero.
		* @see trackFilteredMarker()
		* @return La acantidad de marcadores detectados en escena.
		*/
		int markerCount() { return markers.size(); }

		/**
		* Accede a un elemento en específico dentro del conjunto de marcadores detectado y lo retorna.
		* @param i un entero que representa la posición del marcador dentro del conjunto de marcadores dertectados.
		* @return El marcador indicado
		*/
		Marker marker(int i) { return markers[i]; }

		/**
		* Filtra los marcadores en la escena teniendo en cuenta el área del marcador y el número máximo de marcadores u objetos que aparezcan en escena.
		* @param theMarker representa un marcador en escena y toma las propiedades de éste.
		* @param cameraFeed refrencia de un fotograma de la cámara donde se buscan contornos que pueden ser marcadores en escena.
		* @param cframe objeto de tipo cFrame utilizado para acceder a las propiedades de su clase; actualizar/reiniciar el número de marcadores detectados.
		* @param frame imágen de la cámara donde se van a dibujar los puntos que deben aparecer en el centro de los marcadores.
		*/
		void trackFilteredMarker(Marker theMarker, Mat &cameraFeed, cFrame &cframe, Mat &frame);

		/**
		* variable pública que va almacenando la cantidad de marcadores en escena.
		* Es un vector que se utiliza para ir guardando cada marcador detectado en la escena, al final de cada análisis que se le hace al fotograma, este vector
		* tendrá almacenados cada uno de los marcadores dectados y que hayan pasado el filtro.
		*/
		vector<Marker> markers;

	private:
		/**
		* Convierte un entero a una cadena de caracteres.
		* Se utiliza para convertir a string las coordenadas X,Y en pixeles de cada marcador y que estas luego puedan ser dibujadas sobre cada marcador.
		* @param number arguumento en coma flotante que será convertido.
		* @return el número convertido en string.
		*/
		string intToString(float number);

		/**
		* Dibuja los marcadores detectados en la escena (Dibuja un punto en el centro del marcador).
		* @param theMarkers un conjunto de marcadores ya detectados.
		* @param frame una referencia al fotograma donde se desea dibujar los marcadores.
		* @param contours los contornos de cada marcador detectado (utilizado para dibujar los contornos, si solo no se quiere dibujar un punto).
		* @param hierarchy utilizado en conjunto con el argumento contours para dibujar los contronos de los marcadores.
		*/
		void drawObject(vector<Marker> theMarkers, Mat &frame, vector< vector<Point> > contours, vector<Vec4i> hierarchy);
	};
}

namespace CCL = CustomCameraLibrary;
#endif //_OBJECT_H_