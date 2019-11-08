% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 630.643622523078530 ; 626.301811446005900 ];

%-- Principal point:
cc = [ 314.798536900210590 ; 245.309090209850440 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ 0.000365320669749 ; -0.027731848608662 ; -0.001997595490753 ; -0.015250030008181 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 8.295459071364711 ; 8.424820388123470 ];

%-- Principal point uncertainty:
cc_error = [ 8.065586362654631 ; 8.126994374328717 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.048154011556240 ; 0.159115404472751 ; 0.003501636455347 ; 0.005980439992846 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 512;


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
omc_1 = [ 2.061126e+00 ; 2.215828e+00 ; -1.500573e-01 ];
Tc_1  = [ 1.533429e+01 ; -2.156443e+02 ; 9.499140e+02 ];
omc_error_1 = [ 1.153131e-02 ; 1.163582e-02 ; 2.296557e-02 ];
Tc_error_1  = [ 1.225001e+01 ; 1.229126e+01 ; 1.345366e+01 ];

%-- Image #2:
omc_2 = [ -1.901877e+00 ; -2.094070e+00 ; -2.570992e-01 ];
Tc_2  = [ 4.444700e+01 ; -1.936938e+02 ; 8.407383e+02 ];
omc_error_2 = [ 8.728675e-03 ; 1.221685e-02 ; 2.308486e-02 ];
Tc_error_2  = [ 1.088469e+01 ; 1.091991e+01 ; 1.226709e+01 ];

%-- Image #3:
omc_3 = [ -1.990444e+00 ; -2.353987e+00 ; 2.995437e-01 ];
Tc_3  = [ 3.446935e+01 ; -1.971691e+02 ; 7.769427e+02 ];
omc_error_3 = [ 9.925522e-03 ; 1.068693e-02 ; 2.014613e-02 ];
Tc_error_3  = [ 1.001398e+01 ; 1.002923e+01 ; 1.095561e+01 ];

%-- Image #4:
omc_4 = [ 2.118245e+00 ; 2.089344e+00 ; -4.389649e-01 ];
Tc_4  = [ 4.716595e+01 ; -1.917873e+02 ; 8.170489e+02 ];
omc_error_4 = [ 1.013070e-02 ; 1.005740e-02 ; 1.936611e-02 ];
Tc_error_4  = [ 1.053389e+01 ; 1.051489e+01 ; 1.115887e+01 ];

%-- Image #5:
omc_5 = [ 1.710174e+00 ; 1.865992e+00 ; -5.987714e-01 ];
Tc_5  = [ 5.565266e+01 ; -1.824963e+02 ; 8.385532e+02 ];
omc_error_5 = [ 1.034695e-02 ; 1.066863e-02 ; 1.588302e-02 ];
Tc_error_5  = [ 1.072749e+01 ; 1.084814e+01 ; 1.059775e+01 ];

%-- Image #6:
omc_6 = [ 1.651056e+00 ; 2.092964e+00 ; -1.104776e+00 ];
Tc_6  = [ 5.221450e+01 ; -1.722412e+02 ; 8.901379e+02 ];
omc_error_6 = [ 8.276567e-03 ; 1.288710e-02 ; 1.731865e-02 ];
Tc_error_6  = [ 1.136280e+01 ; 1.152780e+01 ; 1.058733e+01 ];

%-- Image #7:
omc_7 = [ 1.742136e+00 ; 2.470027e+00 ; -7.030758e-01 ];
Tc_7  = [ 9.098900e+01 ; -2.169377e+02 ; 8.276216e+02 ];
omc_error_7 = [ 6.788513e-03 ; 1.200620e-02 ; 1.938414e-02 ];
Tc_error_7  = [ 1.065249e+01 ; 1.068536e+01 ; 1.109219e+01 ];

%-- Image #8:
omc_8 = [ -1.180314e+00 ; -2.769829e+00 ; 4.776016e-01 ];
Tc_8  = [ 1.499878e+02 ; -2.394268e+02 ; 8.573623e+02 ];
omc_error_8 = [ 8.098170e-03 ; 1.173725e-02 ; 1.998354e-02 ];
Tc_error_8  = [ 1.109607e+01 ; 1.113983e+01 ; 1.210855e+01 ];

%-- Image #9:
omc_9 = [ -1.225726e+00 ; -2.486068e+00 ; 4.229578e-02 ];
Tc_9  = [ 1.076987e+02 ; -2.340663e+02 ; 8.239424e+02 ];
omc_error_9 = [ 6.806943e-03 ; 1.256442e-02 ; 2.090446e-02 ];
Tc_error_9  = [ 1.067734e+01 ; 1.090684e+01 ; 1.177648e+01 ];

%-- Image #10:
omc_10 = [ -1.491079e+00 ; -2.574132e+00 ; 4.041100e-01 ];
Tc_10  = [ 8.613271e+01 ; -2.690651e+02 ; 8.874457e+02 ];
omc_error_10 = [ 9.542876e-03 ; 1.166631e-02 ; 2.024065e-02 ];
Tc_error_10  = [ 1.151141e+01 ; 1.146811e+01 ; 1.265218e+01 ];

