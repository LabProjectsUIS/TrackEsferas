#ifndef _POINTCLOUD_H_
#define _POINTCLOUD_H_

#include <iostream>
#include "opencv\cv.hpp"
#include <algorithm>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>

#pragma warning( disable : 4996 )

namespace CustomCameraLibrary {
	using namespace std;
	using namespace cv;

	#define MANUAL 0			///< Establece el valor 0 para el modo manual en la toma de puntos.
	#define  AUTO  1			///< Establece el valor 1 para el modo automático en la toma de puntos.
			

	/**
	*  Clase que representa una nube de puntos sacada con el pointer.
	*  Cuenta con propiedades que la definen y permite ir representando cada nube que se vaya a sacar con la ayuda del pointer.
	*/
	class Cloud
	{
	public:
//		static const int  MANUAL = 0;
//		static const int  AUTO = 1;

		/**
		* Destructor por omisión.
		*/
		~Cloud(void) {}

		/**
		*	Constructor.
		*	Inicializa la nube de puntos, estableciendo sus características.
		*	@param type una etiqueta que se le desee poner a la nube. Ej: "femur", "tibia".
		*	@param mode en que se van a tomar los datos, manual o automático (0 o 1 respectivamente).
		*/
		Cloud(string type, int mode) { 
			setType(type); 
			setMode(mode);
			this_time = clock();
			last_time = this_time;
			status = true;
			type += ".txt";
			const char * nameFile = type.c_str();
			fp = fopen(nameFile, "w");
			//writeHeader(fp);
		}

		/**
		* Devuelve el estado de la toma de puntos habilitado/deshabilitado .
		* @return verdadero o falso.
		*/
		bool getStatus() { return status; }

		/**
		*	Borra un punto de la nube de puntos e indica si ha sido o no exitosa la operación.
		*	@param point recive el punto que se intentará borrar.
		*	@return verdadero si el punto fue borrado o falso si sucede lo contrario.
		*/
		bool erasePoint(Point3d point);

		/**
		*	Guarda un punto dentro de la nube de puntos.
		*	@param point el punto que se intentará guardar.
		*	@param key el valor ascii de la tecla que se presione, -1 si no se oprime nada.
		*	Este valor es utilizado para controlar el comportamiento de la toma de puntos (pausar, reanudar y guardar).
		*	Los teclas utilizadas son:
		*	- x: Captura un punto en modo manual (se escucha un sonido por cada punto tomado con éxito).
		*	- z: Pausa/reanuda la toma de puntos.
		*	- a: Guarda los punto que han sido tomados hasta el momento.
		*	@return verdadero si el punto fue guardado o falso si sucede lo contrario.
		*/
		bool savePoint(Point3d point, int key);

		/**
		*	Guarda un conjunto de puntos dentro de la nube de puntos.
		*	@param src el conjunto de puntos que se intentará guardar.
		*	@return verdadero si los puntos fueron guardado o falso si sucede lo contrario.
		*/
		bool savePoints(vector<Point3d> src);

		/**
		*	Elimina el último punto guardado dentro de la nube de puntos.
		*	@return verdadero si el punto fue eliminado o falso si sucede lo contrario.
		*/
		bool eraseLast();

		/**
		*	Intenta localizar un punto dentro de la nube de puntos.
		*	@param points recive el punto que se intentará localizar.
		*	@return verdadero si el punto fue encontrado o falso si sucede lo contrario.
		*/
		bool findPoint(Point3d points);

		/**
		*	Obtiene la nube de puntos que se haya guardado en el momento.
		*	@return un vector con los puntos que hacen parte de la nube de puntos.
		*/
		vector<Point3d> getCloud() { return cloud; }

		/**
		*	Devuelve el tipo de nube de puntos.
		*	@see Cloud()
		*	@return el tipo de nube de puntos definido al momento de instanciar el objeto Cloud.
		*/
		string getType() { return type; }

		/**
		*	Habilita/deshabilita la toma de puntos.
		*	@param value verdadero para habilitar y falso para deshabilitar.
		*/
		void setStatus(bool value) { status = value; }

		/**
		*	Cambia la frecuencia de en la toma de datos de manera automática.
		*	Por omisión el valor es 1seg.
		*	@param value valor en segundos para la nueva frecuencia de toma de puntos.
		*/
		void setFrecuency(double value) { 
			if (value > 0)	NUM_SECONDS = value;
		}

		/**
		* Cambia el modo de tomar los puntos si el modo es automático lo cambia a manual y si es manual a automático.
		* @param m un entero que representa el modo, debe ser 0 o 1.
		*/
		void setMode(int m) { mode = m; }

		/**
		* Devuelve el modo en que se están tomando los puntos (manual a automático). Devolverá 0 cuando el modo es manual y 1 cuando es automático.
		* @return The test results
		*/
		int getMode() { return mode; }

	private:
		/**
		*	Asigna un tipo de nube de puntos. Puede ser utilizado para cambiar el nombre al a nube de puntos.
		*	@param t nuevo nombre para la nube de puntos.
		*/
		void setType(string t) { type = t; }

		/**
		*	Escribe en el buffer un nuevo punto capturado por el pointer.
		*	@param fp buffer donde se están almacenando los puntos.
		*	@param data nube de puntos que se guardará.
		*/
		void writeFile(FILE* fp, Point3d data);

		/**
		*	Cierra el buffer y guarda el archivo al disco duro (se logra con presionar la letra "a")
		*	@param fp buffer donde se están almacenando los puntos.
		*/
		void writeFooter(FILE* fp);

		/**
		*	Escribe una cabecera al archivo donde se guarda la nube de puntos (no se utiliza po el momento).
		*	@param fp buffer donde se va a escribir la cabecera.
		*/
		void writeHeader(FILE* fp);


		vector<Point3d> cloud;																///< Conjunto de puntos dentro de la nube.
		string type;																		///< Tipo de la nube de puntos (es una nombre o una marca que se le asigna)
		int mode;																			///< Modo de captura (automático o manual)
		bool status = true;																///< Determina si esta disponible la captura de nuevos puntos.
		
		clock_t this_time;																	///< Tiempo inicial de la captura de puntos.
		clock_t last_time;																	///< Último tiempo tomado en el proceso de captura de puntos.
		double time_counter = 0;															///< Un contador para llevar el tiempo transcurrido.
		double NUM_SECONDS = 0.1;															///< Frecuencia de toma de puntos en modo automático (seg)

		FILE* fp;																			///< variable para abrir y cerrar el buffer donde se guardan los puntos de la nube.
	};
}
namespace CCL = CustomCameraLibrary;
#endif //_POINTCLOUD_H_