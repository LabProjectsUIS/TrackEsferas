1)El archivo "P1.txt" y "P2.txt" contiene los datos tomados de las cuatro esferas m�s grandes del pointer en 2D para la c�mara
	derecha y la c�mara izquierda respectivamente, y se compone as�:
	
	-Cada fila corresponde a la posici�n en pixeles para todas las esferas.
	-Cada 2 columnas es la posici�n x,y respectivamente de una esfera.
	-Cada mil datos es una posici�n.
	
2)El archivo "XLObjeto.txt" contiene los datos tomados de las cuatro esferas m�s grandes del pointer en 3D y se compone as�:
	-Cada 3 columnas es la posici�n x,y,z de una esfera
	-Cada fila corresponde al conjunto de posiciones de 4 esferas.
	-Cada mil datos es una posici�n.
	
3)Orden de toma de datos para "P1.txt", "P2.txt" y "XLObjeto.txt":
	-Pointer Centrado (fila 1 - 1000).
	-Pointer inclinado(fila 1001 - 2000).	
	
5)La carpeta Calib corresponde a los datos de calibraci�n.	
6)Valores de la c�mara:
	int exposure_cvalue = 2000;					///< valor por omisi�n para la exposici�n de la c�mara.
	int threshold_cvalue = 187;					///< valor por omisi�n para el threshold la c�mara.
	int intensity_cvalue = 1;					///< valor por omisi�n para la intensidad de la c�mara.
