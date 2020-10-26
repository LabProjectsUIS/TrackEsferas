% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1202.722125823831200 ; 1205.887666918668200 ];

%-- Principal point:
cc = [ 608.158238450528640 ; 489.362758552008300 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.125005947000710 ; 0.183995427058858 ; -0.002757267745031 ; -0.003765064823475 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 9.060942698576117 ; 8.925855580232508 ];

%-- Principal point uncertainty:
cc_error = [ 13.679301380780357 ; 10.603923749977321 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.015708094912890 ; 0.061993450035338 ; 0.002100151968056 ; 0.002663987372874 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 16;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -1.850622e+00 ; -2.038929e+00 ; 6.919728e-01 ];
Tc_1  = [ 6.812637e-01 ; -5.862017e+01 ; 1.085470e+03 ];
omc_error_1 = [ 8.232763e-03 ; 7.005063e-03 ; 1.222992e-02 ];
Tc_error_1  = [ 1.230590e+01 ; 9.513002e+00 ; 7.895172e+00 ];

%-- Image #2:
omc_2 = [ -1.985990e+00 ; -2.102893e+00 ; 2.069165e-01 ];
Tc_2  = [ -7.675545e+01 ; -2.397030e+02 ; 1.175255e+03 ];
omc_error_2 = [ 8.129155e-03 ; 7.363573e-03 ; 1.573636e-02 ];
Tc_error_2  = [ 1.348130e+01 ; 1.035222e+01 ; 9.234617e+00 ];

%-- Image #3:
omc_3 = [ -1.715500e+00 ; -1.933209e+00 ; 5.767920e-01 ];
Tc_3  = [ -5.310374e+01 ; -1.845127e+02 ; 1.206572e+03 ];
omc_error_3 = [ 8.593333e-03 ; 7.390493e-03 ; 1.238498e-02 ];
Tc_error_3  = [ 1.375704e+01 ; 1.059538e+01 ; 8.669748e+00 ];

%-- Image #4:
omc_4 = [ -2.225060e+00 ; -2.181952e+00 ; -1.254614e-01 ];
Tc_4  = [ -2.244935e+02 ; -1.744636e+02 ; 1.254017e+03 ];
omc_error_4 = [ 1.180650e-02 ; 1.087674e-02 ; 2.507264e-02 ];
Tc_error_4  = [ 1.434700e+01 ; 1.113378e+01 ; 1.042237e+01 ];

%-- Image #5:
omc_5 = [ -2.211520e+00 ; -2.121911e+00 ; -1.734824e-01 ];
Tc_5  = [ -2.388362e+02 ; -4.320098e+01 ; 1.342595e+03 ];
omc_error_5 = [ 9.888412e-03 ; 1.049092e-02 ; 2.187135e-02 ];
Tc_error_5  = [ 1.527466e+01 ; 1.188622e+01 ; 1.098427e+01 ];

%-- Image #6:
omc_6 = [ 2.014521e+00 ; 2.038884e+00 ; 7.813301e-01 ];
Tc_6  = [ -4.024540e+02 ; -8.636091e+01 ; 1.182273e+03 ];
omc_error_6 = [ 1.009913e-02 ; 6.716852e-03 ; 1.504003e-02 ];
Tc_error_6  = [ 1.362443e+01 ; 1.076259e+01 ; 1.137247e+01 ];

%-- Image #7:
omc_7 = [ -1.988996e+00 ; -2.146799e+00 ; -7.258160e-01 ];
Tc_7  = [ -2.681996e+02 ; -2.868449e+02 ; 1.114456e+03 ];
omc_error_7 = [ 6.224829e-03 ; 8.674852e-03 ; 1.525599e-02 ];
Tc_error_7  = [ 1.301524e+01 ; 1.011423e+01 ; 1.009194e+01 ];

%-- Image #8:
omc_8 = [ -1.662164e+00 ; -1.680396e+00 ; 5.430010e-01 ];
Tc_8  = [ 3.655657e+01 ; -1.217375e+02 ; 1.101470e+03 ];
omc_error_8 = [ 7.917336e-03 ; 8.068915e-03 ; 1.103852e-02 ];
Tc_error_8  = [ 1.255737e+01 ; 9.684848e+00 ; 8.037525e+00 ];

%-- Image #9:
omc_9 = [ 2.065557e+00 ; 1.444368e+00 ; -5.327162e-02 ];
Tc_9  = [ -2.997183e+02 ; -2.258117e+01 ; 9.666330e+02 ];
omc_error_9 = [ 7.240023e-03 ; 7.449498e-03 ; 1.318489e-02 ];
Tc_error_9  = [ 1.107257e+01 ; 8.679371e+00 ; 8.366222e+00 ];

%-- Image #10:
omc_10 = [ 2.322919e+00 ; 1.939048e+00 ; -2.699364e-01 ];
Tc_10  = [ -2.622846e+02 ; 4.194963e+01 ; 1.240589e+03 ];
omc_error_10 = [ 9.111304e-03 ; 9.011512e-03 ; 1.801627e-02 ];
Tc_error_10  = [ 1.410951e+01 ; 1.102798e+01 ; 9.908311e+00 ];

%-- Image #11:
omc_11 = [ 2.015641e+00 ; 2.003953e+00 ; 5.388028e-01 ];
Tc_11  = [ -4.543712e+02 ; -1.421858e+02 ; 1.027654e+03 ];
omc_error_11 = [ 8.121699e-03 ; 7.877102e-03 ; 1.534714e-02 ];
Tc_error_11  = [ 1.222518e+01 ; 9.579786e+00 ; 1.008790e+01 ];

%-- Image #12:
omc_12 = [ -1.719866e+00 ; -2.047022e+00 ; -1.754705e-01 ];
Tc_12  = [ -1.810676e+02 ; -2.983649e+02 ; 1.143482e+03 ];
omc_error_12 = [ 6.644348e-03 ; 8.141116e-03 ; 1.370333e-02 ];
Tc_error_12  = [ 1.319635e+01 ; 1.020543e+01 ; 9.701390e+00 ];

%-- Image #13:
omc_13 = [ -1.792340e+00 ; -1.988273e+00 ; 3.305106e-01 ];
Tc_13  = [ -1.023131e+01 ; -1.904571e+02 ; 1.157469e+03 ];
omc_error_13 = [ 7.385986e-03 ; 7.511490e-03 ; 1.243234e-02 ];
Tc_error_13  = [ 1.321662e+01 ; 1.018364e+01 ; 8.790273e+00 ];

%-- Image #14:
omc_14 = [ -2.230185e+00 ; -2.175083e+00 ; -3.356099e-01 ];
Tc_14  = [ -2.052724e+02 ; -1.852084e+02 ; 1.303549e+03 ];
omc_error_14 = [ 9.998886e-03 ; 1.016017e-02 ; 2.126008e-02 ];
Tc_error_14  = [ 1.493416e+01 ; 1.155513e+01 ; 1.080017e+01 ];

%-- Image #15:
omc_15 = [ 1.747148e+00 ; 1.716117e+00 ; 1.031135e+00 ];
Tc_15  = [ -3.123984e+02 ; -8.398553e+01 ; 1.004787e+03 ];
omc_error_15 = [ 1.025764e-02 ; 6.790359e-03 ; 1.214920e-02 ];
Tc_error_15  = [ 1.163249e+01 ; 9.091421e+00 ; 9.462050e+00 ];

%-- Image #16:
omc_16 = [ 1.654514e+00 ; 1.474865e+00 ; 1.159480e+00 ];
Tc_16  = [ -3.293413e+02 ; -6.208795e+01 ; 9.154594e+02 ];
omc_error_16 = [ 1.056821e-02 ; 6.981959e-03 ; 1.119409e-02 ];
Tc_error_16  = [ 1.070274e+01 ; 8.355729e+00 ; 9.050711e+00 ];

