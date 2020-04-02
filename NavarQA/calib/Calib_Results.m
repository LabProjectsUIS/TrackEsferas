% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1224.576110077542400 ; 1226.662060851817200 ];

%-- Principal point:
cc = [ 627.517966260100590 ; 496.944757972028580 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.108784086306372 ; 0.151380960066253 ; -0.000873875345790 ; 0.001215632687932 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 12.184020123263387 ; 11.536075624629396 ];

%-- Principal point uncertainty:
cc_error = [ 10.291432590855820 ; 10.509411801389762 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.015762914384292 ; 0.063072248783233 ; 0.001778702438167 ; 0.002051053947256 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 14;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.184047e+00 ; 1.963392e+00 ; -1.374471e-01 ];
Tc_1  = [ -1.477945e+02 ; 1.567335e+00 ; 1.090608e+03 ];
omc_error_1 = [ 7.058434e-03 ; 6.456082e-03 ; 1.341929e-02 ];
Tc_error_1  = [ 9.188944e+00 ; 9.359464e+00 ; 1.081620e+01 ];

%-- Image #2:
omc_2 = [ -2.321696e+00 ; -2.023206e+00 ; 3.981452e-02 ];
Tc_2  = [ -1.168480e+02 ; -2.527558e+02 ; 1.191748e+03 ];
omc_error_2 = [ 9.703764e-03 ; 7.829642e-03 ; 1.899257e-02 ];
Tc_error_2  = [ 1.013765e+01 ; 1.019604e+01 ; 1.304868e+01 ];

%-- Image #3:
omc_3 = [ 2.196431e+00 ; 1.744538e+00 ; 2.705141e-01 ];
Tc_3  = [ -8.194364e+01 ; -8.989457e+01 ; 1.431172e+03 ];
omc_error_3 = [ 8.847777e-03 ; 5.876914e-03 ; 1.243671e-02 ];
Tc_error_3  = [ 1.204349e+01 ; 1.224304e+01 ; 1.436482e+01 ];

%-- Image #4:
omc_4 = [ 2.608214e+00 ; 1.612133e+00 ; -1.656216e-02 ];
Tc_4  = [ -1.098646e+02 ; -1.342194e+02 ; 1.781394e+03 ];
omc_error_4 = [ 1.314109e-02 ; 8.536427e-03 ; 2.420966e-02 ];
Tc_error_4  = [ 1.500464e+01 ; 1.523981e+01 ; 1.814979e+01 ];

%-- Image #5:
omc_5 = [ 2.346938e+00 ; 1.477319e+00 ; 4.431738e-02 ];
Tc_5  = [ -1.492158e+02 ; 1.999880e+02 ; 1.457153e+03 ];
omc_error_5 = [ 8.941319e-03 ; 4.945677e-03 ; 1.399047e-02 ];
Tc_error_5  = [ 1.237266e+01 ; 1.259991e+01 ; 1.468379e+01 ];

%-- Image #6:
omc_6 = [ 2.346191e+00 ; 1.555172e+00 ; -2.391961e-01 ];
Tc_6  = [ -6.183028e+01 ; 1.439904e+02 ; 1.068151e+03 ];
omc_error_6 = [ 7.295976e-03 ; 4.613138e-03 ; 1.233407e-02 ];
Tc_error_6  = [ 9.065044e+00 ; 9.218551e+00 ; 1.062946e+01 ];

%-- Image #7:
omc_7 = [ 2.501581e+00 ; 1.232989e+00 ; -6.933724e-01 ];
Tc_7  = [ 3.633604e+00 ; 1.915666e+02 ; 1.077199e+03 ];
omc_error_7 = [ 6.691371e-03 ; 4.921008e-03 ; 1.109138e-02 ];
Tc_error_7  = [ 9.158263e+00 ; 9.316398e+00 ; 1.016768e+01 ];

%-- Image #8:
omc_8 = [ 1.754822e+00 ; 1.500845e+00 ; 4.475224e-01 ];
Tc_8  = [ -3.762904e+02 ; -1.030309e+02 ; 1.063829e+03 ];
omc_error_8 = [ 7.156069e-03 ; 6.077890e-03 ; 9.083938e-03 ];
Tc_error_8  = [ 9.223444e+00 ; 9.378248e+00 ; 1.268542e+01 ];

%-- Image #9:
omc_9 = [ 1.788105e+00 ; 1.580780e+00 ; 3.819045e-01 ];
Tc_9  = [ -3.075263e+02 ; -9.090666e+01 ; 7.739435e+02 ];
omc_error_9 = [ 6.931269e-03 ; 5.827867e-03 ; 8.905986e-03 ];
Tc_error_9  = [ 6.744674e+00 ; 6.860726e+00 ; 9.385577e+00 ];

%-- Image #10:
omc_10 = [ -2.242402e+00 ; -1.713391e+00 ; 6.705219e-01 ];
Tc_10  = [ 7.721930e+01 ; -6.610254e+01 ; 1.072653e+03 ];
omc_error_10 = [ 7.559333e-03 ; 4.379606e-03 ; 1.187035e-02 ];
Tc_error_10  = [ 9.059829e+00 ; 9.140295e+00 ; 9.988218e+00 ];

%-- Image #11:
omc_11 = [ -2.317579e+00 ; -1.734539e+00 ; 5.532201e-01 ];
Tc_11  = [ 1.357088e+02 ; -8.142080e+01 ; 1.275040e+03 ];
omc_error_11 = [ 8.081068e-03 ; 5.641042e-03 ; 1.454952e-02 ];
Tc_error_11  = [ 1.078944e+01 ; 1.090602e+01 ; 1.247431e+01 ];

%-- Image #12:
omc_12 = [ 2.332149e+00 ; 1.990190e+00 ; -4.946379e-01 ];
Tc_12  = [ -1.336323e+02 ; 3.901713e+00 ; 7.818684e+02 ];
omc_error_12 = [ 4.902282e-03 ; 5.746218e-03 ; 1.123437e-02 ];
Tc_error_12  = [ 6.534117e+00 ; 6.686524e+00 ; 7.635167e+00 ];

%-- Image #13:
omc_13 = [ 2.237705e+00 ; 2.009227e+00 ; -5.585570e-01 ];
Tc_13  = [ -5.911510e+01 ; 3.130170e+01 ; 1.182561e+03 ];
omc_error_13 = [ 6.041020e-03 ; 6.659825e-03 ; 1.269039e-02 ];
Tc_error_13  = [ 9.916155e+00 ; 1.010949e+01 ; 1.125903e+01 ];

%-- Image #14:
omc_14 = [ -2.617164e+00 ; -1.641624e+00 ; 2.157863e-01 ];
Tc_14  = [ 3.056932e+01 ; 3.348815e+00 ; 1.427373e+03 ];
omc_error_14 = [ 1.245358e-02 ; 9.500361e-03 ; 2.620310e-02 ];
Tc_error_14  = [ 1.201755e+01 ; 1.222017e+01 ; 1.386877e+01 ];

