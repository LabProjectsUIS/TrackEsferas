Especificaciones de la toma de datos:
1) El archivo "P1.txt" y "P2.txt" contiene los datos tomados de las cuatro esferas más grandes del pointer en 2D para la cámara
	derecha y la cámara izquierda respectivamente, y se compone así:
	
	-Cada fila corresponde a la posición en pixeles para todas las esferas.
	-Cada 2 columnas es la posición x,y respectivamente de una esfera.
	
2)El archivo "XLObjeto.txt" contiene los datos tomados de las cuatro esferas más grandes del pointer en 3D y se compone así:
	-Cada 3 columnas es la posición x,y,z de una esfera
	-Cada fila corresponde al conjunto de posiciones de 4 esferas.
	
3) Orden de toma de datos para "P1.txt", "P2.txt" y "XLObjeto.txt" fueron las posiciones 6,5 y 4(
este orden es el mismo en el que está el archivo y en cada posición mil datos.)
	1	2	3
	*	*	*

	6	5	4
	*	*	*
				
	7	8	9
	*	*	*

4)El archivo "Calib18A.yml" es el archivo de calibración.