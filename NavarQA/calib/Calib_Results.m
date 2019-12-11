% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1238.321645793132600 ; 1237.097115886118200 ];

%-- Principal point:
cc = [ 625.589951507883370 ; 521.196033642176420 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.077589901103958 ; 0.096114182790580 ; 0.000262986338023 ; 0.000726579688650 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.878275648679438 ; 6.575447615373442 ];

%-- Principal point uncertainty:
cc_error = [ 7.159010489667754 ; 7.347874426169994 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.015022605254028 ; 0.041665819111458 ; 0.001564480408789 ; 0.002324585232832 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 19;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.048591e+00 ; 2.376112e+00 ; -9.013973e-02 ];
Tc_1  = [ -2.451753e+02 ; -1.040462e+02 ; 1.045261e+03 ];
omc_error_1 = [ 6.867229e-03 ; 9.090191e-03 ; 1.778414e-02 ];
Tc_error_1  = [ 6.025763e+00 ; 6.303742e+00 ; 6.182927e+00 ];

%-- Image #2:
omc_2 = [ 2.372981e+00 ; 2.012072e+00 ; -3.468062e-01 ];
Tc_2  = [ -2.724817e+02 ; -1.017419e+02 ; 8.745831e+02 ];
omc_error_2 = [ 4.877367e-03 ; 6.142345e-03 ; 1.137421e-02 ];
Tc_error_2  = [ 5.017349e+00 ; 5.309385e+00 ; 4.913831e+00 ];

%-- Image #3:
omc_3 = [ 2.006835e+00 ; 1.767465e+00 ; -7.536440e-01 ];
Tc_3  = [ -3.034573e+02 ; -5.922062e+01 ; 8.773933e+02 ];
omc_error_3 = [ 3.435982e-03 ; 6.038043e-03 ; 8.321145e-03 ];
Tc_error_3  = [ 5.051298e+00 ; 5.377562e+00 ; 4.558873e+00 ];

%-- Image #4:
omc_4 = [ -1.686704e+00 ; -2.533161e+00 ; 3.118105e-01 ];
Tc_4  = [ -1.967183e+02 ; -1.634961e+02 ; 8.017748e+02 ];
omc_error_4 = [ 5.014699e-03 ; 5.159850e-03 ; 1.072324e-02 ];
Tc_error_4  = [ 4.619001e+00 ; 4.847520e+00 ; 4.577543e+00 ];

%-- Image #5:
omc_5 = [ 2.069268e+00 ; 2.214188e+00 ; -8.597796e-02 ];
Tc_5  = [ -2.363112e+02 ; -1.635936e+02 ; 6.626515e+02 ];
omc_error_5 = [ 4.153625e-03 ; 5.643488e-03 ; 1.084094e-02 ];
Tc_error_5  = [ 3.857309e+00 ; 4.044275e+00 ; 4.027968e+00 ];

%-- Image #6:
omc_6 = [ 2.593850e+00 ; 1.586131e+00 ; -1.382273e-01 ];
Tc_6  = [ -3.075092e+02 ; -1.315216e+02 ; 7.111729e+02 ];
omc_error_6 = [ 5.496906e-03 ; 4.910488e-03 ; 1.057264e-02 ];
Tc_error_6  = [ 4.138149e+00 ; 4.368722e+00 ; 4.357741e+00 ];

%-- Image #7:
omc_7 = [ 2.555735e+00 ; 1.688459e+00 ; -5.612473e-01 ];
Tc_7  = [ -2.878070e+02 ; -1.255659e+02 ; 7.727059e+02 ];
omc_error_7 = [ 4.271898e-03 ; 5.666161e-03 ; 9.489258e-03 ];
Tc_error_7  = [ 4.460889e+00 ; 4.725607e+00 ; 4.307388e+00 ];

%-- Image #8:
omc_8 = [ -1.847085e+00 ; -1.960262e+00 ; 6.566344e-01 ];
Tc_8  = [ -1.444477e+02 ; -1.179800e+02 ; 8.339092e+02 ];
omc_error_8 = [ 5.631635e-03 ; 4.004168e-03 ; 8.101363e-03 ];
Tc_error_8  = [ 4.763947e+00 ; 4.978272e+00 ; 4.331419e+00 ];

%-- Image #9:
omc_9 = [ -2.164579e+00 ; -2.194688e+00 ; -2.171539e-01 ];
Tc_9  = [ -3.029461e+02 ; -2.752970e+02 ; 8.724248e+02 ];
omc_error_9 = [ 9.162060e-03 ; 6.522417e-03 ; 1.603843e-02 ];
Tc_error_9  = [ 5.165751e+00 ; 5.371299e+00 ; 5.695101e+00 ];

%-- Image #10:
omc_10 = [ -2.728687e+00 ; -1.374060e+00 ; 6.918899e-01 ];
Tc_10  = [ -3.459286e+02 ; -1.247405e+02 ; 9.248452e+02 ];
omc_error_10 = [ 7.153743e-03 ; 2.241089e-03 ; 9.645859e-03 ];
Tc_error_10  = [ 5.355874e+00 ; 5.687183e+00 ; 5.101112e+00 ];

%-- Image #11:
omc_11 = [ 2.790118e+00 ; 1.231422e+00 ; -7.109651e-01 ];
Tc_11  = [ -3.700261e+02 ; -1.177529e+02 ; 9.336357e+02 ];
omc_error_11 = [ 5.059786e-03 ; 5.707109e-03 ; 9.542725e-03 ];
Tc_error_11  = [ 5.413734e+00 ; 5.771816e+00 ; 5.183569e+00 ];

%-- Image #12:
omc_12 = [ 2.684982e+00 ; 1.350576e+00 ; 2.779817e-01 ];
Tc_12  = [ -4.271561e+02 ; -1.552044e+02 ; 8.286603e+02 ];
omc_error_12 = [ 8.941930e-03 ; 6.747528e-03 ; 1.696865e-02 ];
Tc_error_12  = [ 4.925065e+00 ; 5.208847e+00 ; 5.751093e+00 ];

%-- Image #13:
omc_13 = [ 1.619440e+00 ; 2.635469e+00 ; -1.770294e-01 ];
Tc_13  = [ -1.089326e+02 ; -1.668307e+02 ; 7.408834e+02 ];
omc_error_13 = [ 3.568928e-03 ; 6.610869e-03 ; 1.236056e-02 ];
Tc_error_13  = [ 4.278327e+00 ; 4.430368e+00 ; 4.282505e+00 ];

%-- Image #14:
omc_14 = [ -1.709817e+00 ; -1.945052e+00 ; -4.705259e-01 ];
Tc_14  = [ -2.753601e+02 ; -9.053706e+01 ; 6.891461e+02 ];
omc_error_14 = [ 5.009025e-03 ; 5.680321e-03 ; 7.554780e-03 ];
Tc_error_14  = [ 4.035047e+00 ; 4.240129e+00 ; 4.520371e+00 ];

%-- Image #15:
omc_15 = [ -1.764648e+00 ; -1.960108e+00 ; -4.003403e-01 ];
Tc_15  = [ -2.849746e+02 ; -1.008174e+02 ; 6.863467e+02 ];
omc_error_15 = [ 5.161292e-03 ; 5.505753e-03 ; 7.767603e-03 ];
Tc_error_15  = [ 4.022954e+00 ; 4.231906e+00 ; 4.494494e+00 ];

%-- Image #16:
omc_16 = [ -2.268200e+00 ; -1.766511e+00 ; 9.345700e-01 ];
Tc_16  = [ -2.935417e+02 ; -6.992247e+01 ; 8.012258e+02 ];
omc_error_16 = [ 6.647193e-03 ; 3.266541e-03 ; 8.431223e-03 ];
Tc_error_16  = [ 4.595779e+00 ; 4.922655e+00 ; 4.155549e+00 ];

%-- Image #17:
omc_17 = [ 2.526142e+00 ; 1.113449e+00 ; 6.151662e-01 ];
Tc_17  = [ -3.652054e+02 ; -4.944352e+01 ; 7.443145e+02 ];
omc_error_17 = [ 7.487701e-03 ; 3.857732e-03 ; 1.071236e-02 ];
Tc_error_17  = [ 4.404658e+00 ; 4.684452e+00 ; 5.044236e+00 ];

%-- Image #18:
omc_18 = [ 1.735810e+00 ; 2.108658e+00 ; 5.289233e-01 ];
Tc_18  = [ -2.118211e+02 ; -1.256522e+02 ; 8.328583e+02 ];
omc_error_18 = [ 6.369577e-03 ; 6.041982e-03 ; 9.870309e-03 ];
Tc_error_18  = [ 4.811118e+00 ; 5.053557e+00 ; 5.105318e+00 ];

%-- Image #19:
omc_19 = [ 2.350844e+00 ; 1.066517e+00 ; 7.499672e-01 ];
Tc_19  = [ -2.847772e+02 ; 9.334650e+01 ; 6.117860e+02 ];
omc_error_19 = [ 6.993508e-03 ; 2.602687e-03 ; 8.702344e-03 ];
Tc_error_19  = [ 3.576281e+00 ; 3.840570e+00 ; 4.308020e+00 ];

