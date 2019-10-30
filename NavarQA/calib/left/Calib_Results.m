% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1240.745753808230600 ; 1242.197657135512600 ];

%-- Principal point:
cc = [ 673.918528854754640 ; 507.699971931634200 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.110072078365391 ; 0.203412618873322 ; 0.000657738730469 ; 0.003479805384982 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 16.778557279096489 ; 16.967840557313924 ];

%-- Principal point uncertainty:
cc_error = [ 13.358028504101139 ; 15.470300686458671 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.019472056136178 ; 0.082212424675654 ; 0.003021603586140 ; 0.002949098681346 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 20;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -5.628219e-01 ; 2.825224e+00 ; -3.143357e-01 ];
Tc_1  = [ -9.983988e+01 ; -4.074860e+02 ; 1.686090e+03 ];
omc_error_1 = [ 7.486265e-03 ; 1.437486e-02 ; 2.325952e-02 ];
Tc_error_1  = [ 1.858559e+01 ; 2.113237e+01 ; 2.356601e+01 ];

%-- Image #2:
omc_2 = [ 5.621555e-01 ; 2.868856e+00 ; -1.354029e-01 ];
Tc_2  = [ -1.354524e+02 ; -3.948392e+02 ; 1.400765e+03 ];
omc_error_2 = [ 2.742769e-03 ; 1.556884e-02 ; 2.506804e-02 ];
Tc_error_2  = [ 1.547485e+01 ; 1.755376e+01 ; 2.021291e+01 ];

%-- Image #3:
omc_3 = [ 1.142831e+00 ; 2.637077e+00 ; 4.280509e-01 ];
Tc_3  = [ -2.555755e+02 ; -3.133723e+02 ; 1.284745e+03 ];
omc_error_3 = [ 7.749212e-03 ; 1.731911e-02 ; 2.689277e-02 ];
Tc_error_3  = [ 1.423952e+01 ; 1.638204e+01 ; 1.975796e+01 ];

%-- Image #4:
omc_4 = [ 1.706088e+00 ; 1.739038e+00 ; 1.424378e-01 ];
Tc_4  = [ -2.819973e+02 ; -1.750589e+02 ; 1.115208e+03 ];
omc_error_4 = [ 8.996603e-03 ; 8.896219e-03 ; 1.498732e-02 ];
Tc_error_4  = [ 1.212521e+01 ; 1.407267e+01 ; 1.647856e+01 ];

%-- Image #5:
omc_5 = [ 2.569988e+00 ; 1.570799e+00 ; -6.994389e-01 ];
Tc_5  = [ -9.876275e+01 ; -2.288248e+02 ; 1.055413e+03 ];
omc_error_5 = [ 1.023597e-02 ; 1.013217e-02 ; 1.848906e-02 ];
Tc_error_5  = [ 1.156301e+01 ; 1.310598e+01 ; 1.384343e+01 ];

%-- Image #6:
omc_6 = [ 2.298566e+00 ; 1.708877e+00 ; 3.415006e-01 ];
Tc_6  = [ 5.799133e+01 ; -3.756022e+02 ; 1.368392e+03 ];
omc_error_6 = [ 1.326122e-02 ; 8.554576e-03 ; 1.962129e-02 ];
Tc_error_6  = [ 1.517646e+01 ; 1.708221e+01 ; 2.042004e+01 ];

%-- Image #7:
omc_7 = [ 2.757967e+00 ; 7.638908e-01 ; -5.108766e-03 ];
Tc_7  = [ -1.178395e+02 ; -2.938819e+02 ; 1.357655e+03 ];
omc_error_7 = [ 1.440389e-02 ; 5.898498e-03 ; 1.963155e-02 ];
Tc_error_7  = [ 1.485646e+01 ; 1.693361e+01 ; 1.961945e+01 ];

%-- Image #8:
omc_8 = [ -4.772411e-01 ; -2.785674e+00 ; 5.464236e-01 ];
Tc_8  = [ 3.918421e+02 ; -4.578581e+02 ; 1.287734e+03 ];
omc_error_8 = [ 7.254063e-03 ; 1.171404e-02 ; 2.001193e-02 ];
Tc_error_8  = [ 1.448167e+01 ; 1.638895e+01 ; 1.966854e+01 ];

%-- Image #9:
omc_9 = [ -9.290796e-01 ; -2.789858e+00 ; 8.180470e-01 ];
Tc_9  = [ 2.306912e+02 ; -3.285476e+02 ; 1.045111e+03 ];
omc_error_9 = [ 8.927597e-03 ; 9.395822e-03 ; 1.946780e-02 ];
Tc_error_9  = [ 1.156991e+01 ; 1.314129e+01 ; 1.493685e+01 ];

%-- Image #10:
omc_10 = [ 1.733060e+00 ; 2.201612e+00 ; 1.662317e-01 ];
Tc_10  = [ -1.883343e+02 ; -4.079651e+02 ; 1.320704e+03 ];
omc_error_10 = [ 8.679954e-03 ; 1.209402e-02 ; 2.105474e-02 ];
Tc_error_10  = [ 1.458283e+01 ; 1.653408e+01 ; 1.993836e+01 ];

%-- Image #11:
omc_11 = [ 1.244002e+00 ; 2.448153e+00 ; 6.534124e-01 ];
Tc_11  = [ -1.186886e+02 ; -2.962665e+02 ; 1.223452e+03 ];
omc_error_11 = [ 8.074289e-03 ; 1.093196e-02 ; 1.837392e-02 ];
Tc_error_11  = [ 1.341740e+01 ; 1.536797e+01 ; 1.848529e+01 ];

%-- Image #12:
omc_12 = [ 1.770618e+00 ; 2.429635e+00 ; -4.201861e-01 ];
Tc_12  = [ 1.393526e+02 ; -2.500537e+02 ; 9.782293e+02 ];
omc_error_12 = [ 7.847628e-03 ; 1.115549e-02 ; 1.933823e-02 ];
Tc_error_12  = [ 1.078195e+01 ; 1.216197e+01 ; 1.377545e+01 ];

%-- Image #13:
omc_13 = [ 2.222874e+00 ; 1.911557e+00 ; -3.831769e-01 ];
Tc_13  = [ -2.107893e+02 ; 6.822130e+01 ; 1.192421e+03 ];
omc_error_13 = [ 1.055423e-02 ; 1.001127e-02 ; 2.268566e-02 ];
Tc_error_13  = [ 1.282941e+01 ; 1.506557e+01 ; 1.657912e+01 ];

%-- Image #14:
omc_14 = [ 2.531575e+00 ; 1.442947e+00 ; -3.152971e-01 ];
Tc_14  = [ -1.945853e+02 ; 3.906033e+00 ; 1.058968e+03 ];
omc_error_14 = [ 1.099334e-02 ; 7.361082e-03 ; 1.888137e-02 ];
Tc_error_14  = [ 1.139875e+01 ; 1.327882e+01 ; 1.453286e+01 ];

%-- Image #15:
omc_15 = [ 1.576938e+00 ; 2.586622e+00 ; -2.995946e-01 ];
Tc_15  = [ -2.742898e+02 ; -1.599955e+02 ; 1.365536e+03 ];
omc_error_15 = [ 6.236448e-03 ; 1.414273e-02 ; 2.520827e-02 ];
Tc_error_15  = [ 1.478963e+01 ; 1.723506e+01 ; 1.957327e+01 ];

%-- Image #16:
omc_16 = [ -2.187625e+00 ; -1.573317e+00 ; 1.006892e+00 ];
Tc_16  = [ 7.179813e+01 ; -3.543227e+02 ; 1.504506e+03 ];
omc_error_16 = [ 1.295234e-02 ; 4.969365e-03 ; 1.764953e-02 ];
Tc_error_16  = [ 1.654215e+01 ; 1.876744e+01 ; 1.960339e+01 ];

%-- Image #17:
omc_17 = [ -2.451205e+00 ; -1.652375e+00 ; -2.270636e-01 ];
Tc_17  = [ -5.111969e+02 ; 7.889797e+01 ; 1.163839e+03 ];
omc_error_17 = [ 1.326765e-02 ; 7.778155e-03 ; 2.152244e-02 ];
Tc_error_17  = [ 1.287602e+01 ; 1.536937e+01 ; 1.848471e+01 ];

%-- Image #18:
omc_18 = [ 2.798856e+00 ; 8.952255e-01 ; 9.871504e-01 ];
Tc_18  = [ -1.211522e+02 ; -2.891618e+02 ; 1.308420e+03 ];
omc_error_18 = [ 1.495583e-02 ; 6.119501e-03 ; 1.840267e-02 ];
Tc_error_18  = [ 1.431299e+01 ; 1.636238e+01 ; 1.983554e+01 ];

%-- Image #19:
omc_19 = [ -2.600688e+00 ; -1.298241e+00 ; 1.064428e-01 ];
Tc_19  = [ -1.252684e+02 ; -2.024826e+02 ; 1.481537e+03 ];
omc_error_19 = [ 1.859944e-02 ; 8.795631e-03 ; 2.982857e-02 ];
Tc_error_19  = [ 1.601997e+01 ; 1.839201e+01 ; 2.050351e+01 ];

%-- Image #20:
omc_20 = [ 1.974927e+00 ; 2.228505e+00 ; -6.065796e-01 ];
Tc_20  = [ -1.412322e+01 ; -3.159351e+02 ; 1.426887e+03 ];
omc_error_20 = [ 7.768211e-03 ; 1.208881e-02 ; 2.024348e-02 ];
Tc_error_20  = [ 1.559325e+01 ; 1.772889e+01 ; 1.943430e+01 ];

