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
	#define CNAME_1 "RIGHT CAMERA"				///< nombre para la cámara 
	#define CNAME_2 "LEFT CAMERA"				///< nombre para la cámara 

	#define SCAMERA_R 18773						///< serial de la cámara 
	#define SCAMERA_L 18776						///< serial de la cámara 

	// Constantes para el modo rastreo por OpenCV
	int threshold_value = 254;					///< valor por omisión en el momento de aplicarle el threshold a la imágen (usado en tratamiento de binarización)
	int max_BINARY_value = 255;					///< máximo nivel de binarizado (usado en tratamiento de binarización)
	int threshold_type = 3;						///< tipo de de threshold (usado en tratamiento de binarización)

	// Constantes para la cámara
	int exposure_cvalue = 1195;					///< valor por omisión para la exposición de la cámara.
	int threshold_cvalue = 187;					///< valor por omisión para el threshold la cámara.
	int intensity_cvalue = 2;		///< valor por omisión para la intensidad de la cámara.
	
	int fps = 211;
	// Parámetros generales
	int square_size = 400;
	int cloud_size = 50;

}
namespace CCL = CustomCameraLibrary;
#endif //_GLOBALS_H_

