#ifndef _GLOBALS_H_
#define _GLOBALS_H_

namespace CustomCameraLibrary {
	// Definicion teclas
	#define UP_KEY 2490368						///< valor ascii flecha arriba
	#define DOWN_KEY 2621440					///< valor ascii  flecha abajo
	#define RIGHT_KEY 2555904					///< valor ascii 
	#define LEFT_KEY 2424832					///< valor ascii 
	#define ESC_KEY 27							///< valor ascii 
	#define C_KEY 99							///< valor ascii 
	#define S_KEY 115							///< valor ascii 
	#define N_KEY 110							///< valor ascii 
	#define P_KEY 112							///< valor ascii 
	#define X_KEY 120							///< valor ascii 
	#define CNAME_1 "RIGHT CAMERA"				///< nombre para la c�mara 
	#define CNAME_2 "LEFT CAMERA"				///< nombre para la c�mara 

	#define SCAMERA_R 18773						///< serial de la c�mara 
	#define SCAMERA_L 18776						///< serial de la c�mara 

	// Constantes para el modo rastreo por OpenCV
	int threshold_value = 254;					///< valor por omisi�n en el momento de aplicarle el threshold a la im�gen (usado en tratamiento de binarizaci�n)
	int max_BINARY_value = 255;					///< m�ximo nivel de binarizado (usado en tratamiento de binarizaci�n)
	int threshold_type = 3;						///< tipo de de threshold (usado en tratamiento de binarizaci�n)

	// Constantes para la c�mara
	int exposure_cvalue = 1195;					///< valor por omisi�n para la exposici�n de la c�mara.
	int threshold_cvalue = 187;					///< valor por omisi�n para el threshold la c�mara.
	int intensity_cvalue = 2;		///< valor por omisi�n para la intensidad de la c�mara.
	
	int fps = 211;
	// Par�metros generales
	int square_size = 400;
	int cloud_size = 50;

}
namespace CCL = CustomCameraLibrary;
#endif //_GLOBALS_H_

