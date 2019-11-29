% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1257.572473943735300 ; 1249.390509059036300 ];

%-- Principal point:
cc = [ 615.711314831813070 ; 517.869410966684090 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.054670678953808 ; 0.086899936618118 ; 0.000792478740742 ; -0.012651513921331 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 12.449422820692382 ; 13.368052972902797 ];

%-- Principal point uncertainty:
cc_error = [ 10.702399889943289 ; 9.779445599311245 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.019393275395843 ; 0.046697662328939 ; 0.002026067106712 ; 0.003173351481802 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 10;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -2.094635e+00 ; -2.320715e+00 ; 9.181012e-02 ];
Tc_1  = [ 1.183163e+02 ; -1.020805e+02 ; 1.046152e+03 ];
omc_error_1 = [ 7.318461e-03 ; 1.036044e-02 ; 2.047214e-02 ];
Tc_error_1  = [ 9.026880e+00 ; 8.263073e+00 ; 1.154347e+01 ];

%-- Image #2:
omc_2 = [ -1.843672e+00 ; -2.060210e+00 ; -1.063513e-01 ];
Tc_2  = [ 5.906700e+01 ; -1.567900e+02 ; 7.926149e+02 ];
omc_error_2 = [ 5.164885e-03 ; 7.305586e-03 ; 1.336878e-02 ];
Tc_error_2  = [ 6.828969e+00 ; 6.265077e+00 ; 8.520949e+00 ];

%-- Image #3:
omc_3 = [ 1.775770e+00 ; 2.324098e+00 ; -7.590171e-01 ];
Tc_3  = [ 8.667402e+01 ; -2.254074e+02 ; 8.502383e+02 ];
omc_error_3 = [ 5.020327e-03 ; 7.557873e-03 ; 1.184691e-02 ];
Tc_error_3  = [ 7.251172e+00 ; 6.657029e+00 ; 8.286957e+00 ];

%-- Image #4:
omc_4 = [ -2.042491e+00 ; -2.296138e+00 ; 3.574764e-01 ];
Tc_4  = [ 8.331777e+01 ; -3.431944e+02 ; 8.841761e+02 ];
omc_error_4 = [ 8.170573e-03 ; 7.179959e-03 ; 1.421292e-02 ];
Tc_error_4  = [ 7.779602e+00 ; 6.983414e+00 ; 9.631926e+00 ];

%-- Image #5:
omc_5 = [ -1.768580e+00 ; -2.334480e+00 ; -6.675730e-02 ];
Tc_5  = [ 8.294684e+01 ; -1.006538e+02 ; 9.629397e+02 ];
omc_error_5 = [ 5.232260e-03 ; 8.734093e-03 ; 1.725392e-02 ];
Tc_error_5  = [ 8.251564e+00 ; 7.619882e+00 ; 1.020276e+01 ];

%-- Image #6:
omc_6 = [ 2.110364e+00 ; 2.261332e+00 ; -3.015042e-01 ];
Tc_6  = [ 2.314933e+02 ; -1.687495e+02 ; 9.718968e+02 ];
omc_error_6 = [ 8.629287e-03 ; 7.000502e-03 ; 1.572506e-02 ];
Tc_error_6  = [ 8.502202e+00 ; 7.732491e+00 ; 1.050198e+01 ];

%-- Image #7:
omc_7 = [ -1.855534e+00 ; -2.053764e+00 ; 8.413063e-01 ];
Tc_7  = [ -6.077007e+01 ; -2.022313e+02 ; 9.449315e+02 ];
omc_error_7 = [ 7.804001e-03 ; 5.285433e-03 ; 1.170109e-02 ];
Tc_error_7  = [ 8.070340e+00 ; 7.351940e+00 ; 9.475262e+00 ];

%-- Image #8:
omc_8 = [ -1.664905e+00 ; -1.925549e+00 ; -8.313617e-02 ];
Tc_8  = [ -3.959978e+01 ; -2.372690e+02 ; 7.570179e+02 ];
omc_error_8 = [ 5.333067e-03 ; 6.572483e-03 ; 1.115435e-02 ];
Tc_error_8  = [ 6.530926e+00 ; 6.019108e+00 ; 8.203472e+00 ];

%-- Image #9:
omc_9 = [ -1.963139e+00 ; -2.316888e+00 ; 3.424833e-01 ];
Tc_9  = [ 4.810558e+01 ; -2.641128e+02 ; 7.344492e+02 ];
omc_error_9 = [ 7.016446e-03 ; 6.656459e-03 ; 1.266545e-02 ];
Tc_error_9  = [ 6.400593e+00 ; 5.745007e+00 ; 8.012531e+00 ];

%-- Image #10:
omc_10 = [ 1.832602e+00 ; 2.007701e+00 ; -6.920003e-01 ];
Tc_10  = [ 5.005447e+01 ; -2.423563e+02 ; 1.032994e+03 ];
omc_error_10 = [ 6.107112e-03 ; 7.295817e-03 ; 1.145869e-02 ];
Tc_error_10  = [ 8.826281e+00 ; 8.110444e+00 ; 1.003466e+01 ];

