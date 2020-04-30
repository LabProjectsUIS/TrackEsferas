1)El archivo "P1.txt" y "P2.txt" contiene los datos tomados de las cuatro esferas más grandes del pointer en 2D para la cámara
	derecha y la cámara izquierda respectivamente, y se compone así:
	
	-Cada fila corresponde a la posición en pixeles para todas las esferas.
	-Cada 2 columnas es la posición x,y respectivamente de una esfera.
	-Cada mil datos es una posición.
	
2)El archivo "XLObjeto.txt" contiene los datos tomados de las cuatro esferas más grandes del pointer en 3D y se compone así:
	-Cada 3 columnas es la posición x,y,z de una esfera
	-Cada fila corresponde al conjunto de posiciones de 4 esferas.
	-Cada mil datos es una posición.
	
3)Orden de toma de datos para "P1.txt", "P2.txt" y "XLObjeto.txt":
	-Pointer Centrado (fila 1 - 1000).
	-Pointer inclinado(fila 1001 - 2000).	
	
5)La carpeta Calib corresponde a los datos de calibración.	
6)Valores de la cámara:
	int exposure_cvalue = 2000;					///< valor por omisión para la exposición de la cámara.
	int threshold_cvalue = 187;					///< valor por omisión para el threshold la cámara.
	int intensity_cvalue = 1;					///< valor por omisión para la intensidad de la cámara.
