Especificaciones de la toma de datos:
	1)Los archivos "GrisesPunta.txt", "ObjetoPunta" y "Segmento punta" 
		son los datos tomados de la punta del pointer para cada tipo de video.
	2)Los archivos "XLGrises.txt", "XLObjeto.txt" y "XLSegmento.txt"  
		son los datos tomados de las cuatro esferas más grandes del pointer para 
		cada tipo de video.
		- Cada columna corresponde a un eje, cada 3 columnas es la posición x,y,z de una esfera, y cada 
			fila corresponde al conjunto de posiciones de 4 esferas.
		- Se tomaron 1000 datos de cada angulación, en el siguiente orden:
			-Pointer centrado.
			-Pointer inclinado a la izquierda a 30°.
			-Pointer inclinado a la derecha a 30°.
			-Pointer inclinado hacia adelante a 30°.
			-Pointer inclinado hacia atrás a 30°.
			
	3)Tanto los datos de la punta, como los datos de las esferas, fueron tomados simultaneamente.
	4)El archivo "Calib11A.yml" es el archivo de calibración.