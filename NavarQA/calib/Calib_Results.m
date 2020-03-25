% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1214.248681437002900 ; 1216.042447244799000 ];

%-- Principal point:
cc = [ 604.584789995062120 ; 505.726727501212570 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.104509670134240 ; 0.138184204149787 ; -0.000672269697687 ; -0.004957155355902 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 5.610349457568925 ; 5.249919664471261 ];

%-- Principal point uncertainty:
cc_error = [ 6.379418281076533 ; 5.258590050373658 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.007876906087830 ; 0.017092852792296 ; 0.001136811951559 ; 0.001477703969856 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 13;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 1.965401e+00 ; 2.049233e+00 ; -2.195696e-01 ];
Tc_1  = [ -8.381444e+01 ; -2.166160e+02 ; 1.022338e+03 ];
omc_error_1 = [ 3.524155e-03 ; 4.619772e-03 ; 8.138019e-03 ];
Tc_error_1  = [ 5.429278e+00 ; 4.387006e+00 ; 4.735050e+00 ];

%-- Image #2:
omc_2 = [ 2.075097e+00 ; 2.239745e+00 ; 3.662886e-01 ];
Tc_2  = [ -5.471361e+01 ; -2.315078e+02 ; 8.307386e+02 ];
omc_error_2 = [ 4.520504e-03 ; 4.545446e-03 ; 9.255788e-03 ];
Tc_error_2  = [ 4.454131e+00 ; 3.592482e+00 ; 3.912179e+00 ];

%-- Image #3:
omc_3 = [ 1.867184e+00 ; 1.971790e+00 ; 6.156938e-01 ];
Tc_3  = [ -5.414270e+01 ; -2.276340e+02 ; 6.920035e+02 ];
omc_error_3 = [ 4.229247e-03 ; 4.011112e-03 ; 6.975954e-03 ];
Tc_error_3  = [ 3.739781e+00 ; 2.990444e+00 ; 3.426549e+00 ];

%-- Image #4:
omc_4 = [ 1.769414e+00 ; 1.909404e+00 ; 8.278429e-01 ];
Tc_4  = [ -9.413577e+01 ; -2.267171e+02 ; 6.248017e+02 ];
omc_error_4 = [ 4.208186e-03 ; 3.926436e-03 ; 6.466220e-03 ];
Tc_error_4  = [ 3.422442e+00 ; 2.714353e+00 ; 3.273119e+00 ];

%-- Image #5:
omc_5 = [ -1.942141e+00 ; -2.059928e+00 ; 1.118548e-01 ];
Tc_5  = [ -1.314700e+02 ; -2.371195e+02 ; 8.697769e+02 ];
omc_error_5 = [ 4.025808e-03 ; 3.953038e-03 ; 9.985114e-03 ];
Tc_error_5  = [ 4.656973e+00 ; 3.751721e+00 ; 4.172500e+00 ];

%-- Image #6:
omc_6 = [ -1.897109e+00 ; -2.188568e+00 ; 3.350087e-01 ];
Tc_6  = [ -2.272333e+01 ; -2.352030e+02 ; 7.496193e+02 ];
omc_error_6 = [ 3.963189e-03 ; 3.745235e-03 ; 8.220572e-03 ];
Tc_error_6  = [ 4.030729e+00 ; 3.211163e+00 ; 3.397508e+00 ];

%-- Image #7:
omc_7 = [ 1.391346e-01 ; -2.610743e+00 ; -1.725805e-01 ];
Tc_7  = [ 3.454632e+02 ; -1.819268e+02 ; 6.431751e+02 ];
omc_error_7 = [ 1.476896e-03 ; 5.515609e-03 ; 6.606789e-03 ];
Tc_error_7  = [ 3.622427e+00 ; 3.031127e+00 ; 3.755422e+00 ];

%-- Image #8:
omc_8 = [ 1.970681e+00 ; 1.943111e+00 ; -4.187774e-01 ];
Tc_8  = [ -1.225939e+02 ; -1.217334e+02 ; 8.190816e+02 ];
omc_error_8 = [ 3.029629e-03 ; 4.044591e-03 ; 7.152626e-03 ];
Tc_error_8  = [ 4.318026e+00 ; 3.506090e+00 ; 3.666978e+00 ];

%-- Image #9:
omc_9 = [ 2.039120e+00 ; 1.887771e+00 ; -5.089894e-01 ];
Tc_9  = [ -1.597335e+02 ; -2.132993e+02 ; 7.791240e+02 ];
omc_error_9 = [ 2.896672e-03 ; 4.311203e-03 ; 7.600678e-03 ];
Tc_error_9  = [ 4.174437e+00 ; 3.345275e+00 ; 3.719536e+00 ];

%-- Image #10:
omc_10 = [ -1.896445e+00 ; -2.217778e+00 ; 5.003999e-01 ];
Tc_10  = [ 2.575468e+01 ; -2.629848e+02 ; 8.695875e+02 ];
omc_error_10 = [ 4.490517e-03 ; 3.619525e-03 ; 8.342808e-03 ];
Tc_error_10  = [ 4.686465e+00 ; 3.724247e+00 ; 3.813895e+00 ];

%-- Image #11:
omc_11 = [ 1.886985e+00 ; 2.240317e+00 ; -8.680248e-01 ];
Tc_11  = [ 1.011853e+02 ; -2.118783e+02 ; 8.571847e+02 ];
omc_error_11 = [ 3.100356e-03 ; 4.308857e-03 ; 7.795005e-03 ];
Tc_error_11  = [ 4.596665e+00 ; 3.677926e+00 ; 3.612457e+00 ];

%-- Image #12:
omc_12 = [ 1.901552e+00 ; 2.008475e+00 ; 3.470337e-02 ];
Tc_12  = [ 4.339927e+01 ; -2.074630e+02 ; 7.277396e+02 ];
omc_error_12 = [ 3.883387e-03 ; 4.109320e-03 ; 7.407012e-03 ];
Tc_error_12  = [ 3.909611e+00 ; 3.147599e+00 ; 3.345052e+00 ];

%-- Image #13:
omc_13 = [ 1.911678e+00 ; 1.967063e+00 ; 3.844746e-01 ];
Tc_13  = [ -8.236785e+01 ; -2.290844e+02 ; 7.335847e+02 ];
omc_error_13 = [ 3.959464e-03 ; 4.116509e-03 ; 7.106606e-03 ];
Tc_error_13  = [ 3.955091e+00 ; 3.172594e+00 ; 3.567347e+00 ];

