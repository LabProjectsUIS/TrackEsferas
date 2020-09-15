% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1207.662742291169700 ; 1206.132974289092300 ];

%-- Principal point:
cc = [ 618.480597543546310 ; 494.816151747169160 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.123194713235014 ; 0.262510775781586 ; -0.001888863040795 ; -0.001537058695578 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.558552305213146 ; 6.366626369289259 ];

%-- Principal point uncertainty:
cc_error = [ 8.488343604597100 ; 11.217195168830200 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.019752446290989 ; 0.137187923718876 ; 0.001985005691041 ; 0.001784563916865 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 12;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.357439e+00 ; 8.432499e-02 ; 1.807986e-01 ];
Tc_1  = [ -8.202793e+01 ; 9.955484e+01 ; 6.397717e+02 ];
omc_error_1 = [ 9.047373e-03 ; 3.527601e-03 ; 8.379766e-03 ];
Tc_error_1  = [ 4.527034e+00 ; 6.002002e+00 ; 3.843118e+00 ];

%-- Image #2:
omc_2 = [ 2.435384e+00 ; 1.470241e-01 ; -2.318968e-01 ];
Tc_2  = [ -1.114724e+02 ; 1.499668e+02 ; 8.125873e+02 ];
omc_error_2 = [ 8.862332e-03 ; 3.248422e-03 ; 8.676367e-03 ];
Tc_error_2  = [ 5.760930e+00 ; 7.645298e+00 ; 4.576693e+00 ];

%-- Image #3:
omc_3 = [ 2.267394e+00 ; 2.060643e-01 ; -4.124093e-01 ];
Tc_3  = [ -1.159114e+02 ; 1.803174e+02 ; 8.406741e+02 ];
omc_error_3 = [ 8.717753e-03 ; 3.939398e-03 ; 8.113223e-03 ];
Tc_error_3  = [ 5.980784e+00 ; 7.936924e+00 ; 4.729658e+00 ];

%-- Image #4:
omc_4 = [ 2.589061e+00 ; 1.210289e-01 ; -1.147828e+00 ];
Tc_4  = [ -5.907367e+01 ; 2.200350e+02 ; 1.016603e+03 ];
omc_error_4 = [ 8.858680e-03 ; 5.496048e-03 ; 9.538376e-03 ];
Tc_error_4  = [ 7.225033e+00 ; 9.459752e+00 ; 4.936386e+00 ];

%-- Image #5:
omc_5 = [ 2.689565e+00 ; -3.419985e-02 ; 8.514762e-01 ];
Tc_5  = [ -1.206926e+01 ; 2.349541e+02 ; 8.716829e+02 ];
omc_error_5 = [ 8.980856e-03 ; 4.601028e-03 ; 9.940303e-03 ];
Tc_error_5  = [ 6.247415e+00 ; 8.163247e+00 ; 5.197550e+00 ];

%-- Image #6:
omc_6 = [ 2.654054e+00 ; 9.505507e-02 ; 2.264665e-01 ];
Tc_6  = [ -3.025024e+01 ; 1.489602e+02 ; 1.027107e+03 ];
omc_error_6 = [ 9.319483e-03 ; 2.742976e-03 ; 1.004145e-02 ];
Tc_error_6  = [ 7.262481e+00 ; 9.592689e+00 ; 5.874547e+00 ];

%-- Image #7:
omc_7 = [ 2.950311e+00 ; 7.433270e-02 ; 6.911061e-02 ];
Tc_7  = [ -7.372804e+01 ; 2.516482e+02 ; 1.183795e+03 ];
omc_error_7 = [ 1.105210e-02 ; 1.630304e-03 ; 1.626700e-02 ];
Tc_error_7  = [ 8.436583e+00 ; 1.111602e+01 ; 6.868631e+00 ];

%-- Image #8:
omc_8 = [ 3.076313e+00 ; 1.616272e-01 ; -4.100063e-01 ];
Tc_8  = [ -1.119127e+02 ; 1.211738e+02 ; 1.160689e+03 ];
omc_error_8 = [ 9.749824e-03 ; 2.550807e-03 ; 1.398164e-02 ];
Tc_error_8  = [ 8.163048e+00 ; 1.078952e+01 ; 5.890084e+00 ];

%-- Image #9:
omc_9 = [ 2.915247e+00 ; 8.166289e-02 ; 8.280116e-01 ];
Tc_9  = [ -2.033151e+02 ; 1.666416e+02 ; 1.097945e+03 ];
omc_error_9 = [ 9.510129e-03 ; 3.295686e-03 ; 1.117881e-02 ];
Tc_error_9  = [ 7.829731e+00 ; 1.030306e+01 ; 6.127537e+00 ];

%-- Image #10:
omc_10 = [ 3.035842e+00 ; 4.747945e-02 ; -6.769077e-01 ];
Tc_10  = [ 5.405188e+01 ; 1.696580e+02 ; 1.109523e+03 ];
omc_error_10 = [ 9.420619e-03 ; 2.551698e-03 ; 1.221107e-02 ];
Tc_error_10  = [ 7.853558e+00 ; 1.030785e+01 ; 5.395349e+00 ];

%-- Image #11:
omc_11 = [ 3.055717e+00 ; 1.539637e-02 ; 1.313687e-01 ];
Tc_11  = [ -1.756716e+02 ; 1.792807e+02 ; 8.771201e+02 ];
omc_error_11 = [ 9.074582e-03 ; 1.080330e-03 ; 1.392427e-02 ];
Tc_error_11  = [ 6.264787e+00 ; 8.277106e+00 ; 5.077023e+00 ];

%-- Image #12:
omc_12 = [ 3.070755e+00 ; 3.159294e-02 ; -1.876126e-01 ];
Tc_12  = [ 1.142270e+02 ; 9.883404e+01 ; 9.921514e+02 ];
omc_error_12 = [ 1.023422e-02 ; 1.803621e-03 ; 1.939052e-02 ];
Tc_error_12  = [ 7.021275e+00 ; 9.305653e+00 ; 5.823789e+00 ];

