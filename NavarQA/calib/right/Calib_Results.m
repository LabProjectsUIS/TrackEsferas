% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1260.901494150601100 ; 1258.381559810423400 ];

%-- Principal point:
cc = [ 577.946241464280890 ; 503.641492020269710 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.063199099988115 ; 0.190726789108605 ; -0.003552918841247 ; -0.011601340462642 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 14.920893457969033 ; 15.860617328730127 ];

%-- Principal point uncertainty:
cc_error = [ 11.743295742360356 ; 12.379606473506257 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.025009895519895 ; 0.136923362893092 ; 0.003110177017783 ; 0.002695173004869 ; 0.000000000000000 ];

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
omc_1 = [ -2.101217e+00 ; -2.313704e+00 ; 1.291929e-01 ];
Tc_1  = [ -9.530807e+01 ; -7.330534e+01 ; 1.062127e+03 ];
omc_error_1 = [ 9.662363e-03 ; 1.141019e-02 ; 2.348103e-02 ];
Tc_error_1  = [ 9.855897e+00 ; 1.045988e+01 ; 1.300359e+01 ];

%-- Image #2:
omc_2 = [ -1.854440e+00 ; -2.045782e+00 ; -6.037777e-02 ];
Tc_2  = [ -1.583531e+02 ; -1.341492e+02 ; 8.101483e+02 ];
omc_error_2 = [ 6.917318e-03 ; 7.437273e-03 ; 1.273283e-02 ];
Tc_error_2  = [ 7.480982e+00 ; 8.070077e+00 ; 9.997308e+00 ];

%-- Image #3:
omc_3 = [ 1.774181e+00 ; 2.316796e+00 ; -8.134137e-01 ];
Tc_3  = [ -1.289205e+02 ; -2.012248e+02 ; 8.695080e+02 ];
omc_error_3 = [ 5.017544e-03 ; 1.009086e-02 ; 1.555498e-02 ];
Tc_error_3  = [ 8.103737e+00 ; 8.675148e+00 ; 9.764319e+00 ];

%-- Image #4:
omc_4 = [ -2.045540e+00 ; -2.288311e+00 ; 4.163746e-01 ];
Tc_4  = [ -1.330357e+02 ; -3.180640e+02 ; 9.074724e+02 ];
omc_error_4 = [ 9.120046e-03 ; 6.112179e-03 ; 1.558630e-02 ];
Tc_error_4  = [ 8.492197e+00 ; 8.992721e+00 ; 1.169261e+01 ];

%-- Image #5:
omc_5 = [ -1.776574e+00 ; -2.317814e+00 ; -2.194017e-02 ];
Tc_5  = [ -1.321170e+02 ; -7.367350e+01 ; 9.785056e+02 ];
omc_error_5 = [ 6.606472e-03 ; 8.500908e-03 ; 1.555699e-02 ];
Tc_error_5  = [ 9.045235e+00 ; 9.685454e+00 ; 1.189045e+01 ];

%-- Image #6:
omc_6 = [ 2.103493e+00 ; 2.245914e+00 ; -3.473551e-01 ];
Tc_6  = [ 1.668871e+01 ; -1.424040e+02 ; 9.882950e+02 ];
omc_error_6 = [ 8.937630e-03 ; 8.932880e-03 ; 1.722923e-02 ];
Tc_error_6  = [ 9.254652e+00 ; 9.695856e+00 ; 1.221909e+01 ];

%-- Image #7:
omc_7 = [ -1.855462e+00 ; -2.033002e+00 ; 8.866233e-01 ];
Tc_7  = [ -2.745046e+02 ; -1.745129e+02 ; 9.667436e+02 ];
omc_error_7 = [ 9.457048e-03 ; 5.836530e-03 ; 1.450866e-02 ];
Tc_error_7  = [ 8.954359e+00 ; 9.701988e+00 ; 1.143152e+01 ];

%-- Image #8:
omc_8 = [ -1.681035e+00 ; -1.912058e+00 ; -4.032875e-02 ];
Tc_8  = [ -2.582825e+02 ; -2.149966e+02 ; 7.811785e+02 ];
omc_error_8 = [ 7.957085e-03 ; 7.546017e-03 ; 1.161312e-02 ];
Tc_error_8  = [ 7.236539e+00 ; 7.946831e+00 ; 9.997524e+00 ];

%-- Image #9:
omc_9 = [ -1.960277e+00 ; -2.299008e+00 ; 4.066581e-01 ];
Tc_9  = [ -1.697303e+02 ; -2.424568e+02 ; 7.554742e+02 ];
omc_error_9 = [ 8.324412e-03 ; 5.711195e-03 ; 1.466753e-02 ];
Tc_error_9  = [ 6.984299e+00 ; 7.509733e+00 ; 9.726978e+00 ];

%-- Image #10:
omc_10 = [ 1.824092e+00 ; 2.000579e+00 ; -7.364309e-01 ];
Tc_10  = [ -1.633959e+02 ; -2.137403e+02 ; 1.054382e+03 ];
omc_error_10 = [ 6.818657e-03 ; 9.402856e-03 ; 1.489266e-02 ];
Tc_error_10  = [ 9.864964e+00 ; 1.054578e+01 ; 1.167437e+01 ];

