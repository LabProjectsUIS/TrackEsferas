1)El archivo "P1.txt" y "P2.txt" contiene los datos tomados de las cuatro esferas más grandes del pointer en 2D para la cámara
	derecha y la cámara izquierda respectivamente, y se compone así:
	
	-Cada fila corresponde a la posición en pixeles para todas las esferas.
	-Cada 2 columnas es la posición x,y respectivamente de una esfera.
	
2)El archivo "XLObjeto.txt" contiene los datos tomados de las cuatro esferas más grandes del pointer en 3D y se compone así:
	-Cada 3 columnas es la posición x,y,z de una esfera
	-Cada fila corresponde al conjunto de posiciones de 4 esferas.
	
3)Orden de toma de datos para "P1.txt", "P2.txt" y "XLObjeto.txt":
	-Pointer Centrado (fila 1).
	-Pointer inclinado(fila 2).	

4)Los archivos .bmp corresponden a las imagenes de cada frame para cada cámara, dónde:
	-Terminadas en 01 es para la primera toma (Pointer Centrado).
	-Terminadas en 02 es para la segunda toma (Pointer Calibrado).
	
5)La carpeta Calib corresponde a los datos de calibración.