% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1220.824949694203300 ; 1223.916689684663200 ];

%-- Principal point:
cc = [ 624.637227462533020 ; 514.262135124286370 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.104011163804184 ; 0.147348775424340 ; -0.000452492908909 ; -0.001300647186389 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.170784679146631 ; 5.812157301315616 ];

%-- Principal point uncertainty:
cc_error = [ 6.100306409293210 ; 4.729936844136790 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.008941146626144 ; 0.035759044297360 ; 0.001144661891683 ; 0.001294402229118 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 15;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ -2.196633e+00 ; -2.079345e+00 ; 7.731334e-02 ];
Tc_1  = [ -2.916619e+02 ; -2.480751e+02 ; 8.943265e+02 ];
omc_error_1 = [ 4.579883e-03 ; 3.088179e-03 ; 8.528941e-03 ];
Tc_error_1  = [ 4.558025e+00 ; 3.560416e+00 ; 5.042815e+00 ];

%-- Image #2:
omc_2 = [ -2.192562e+00 ; -2.160240e+00 ; -5.270777e-02 ];
Tc_2  = [ -1.920815e+02 ; -2.452796e+02 ; 1.152845e+03 ];
omc_error_2 = [ 6.870464e-03 ; 6.015170e-03 ; 1.417159e-02 ];
Tc_error_2  = [ 5.822886e+00 ; 4.501338e+00 ; 6.193100e+00 ];

%-- Image #3:
omc_3 = [ 2.667297e+00 ; 1.514655e+00 ; 5.379397e-01 ];
Tc_3  = [ -1.583929e+02 ; -1.680725e+02 ; 1.241677e+03 ];
omc_error_3 = [ 6.070585e-03 ; 3.264055e-03 ; 9.833090e-03 ];
Tc_error_3  = [ 6.229179e+00 ; 4.817693e+00 ; 6.734256e+00 ];

%-- Image #4:
omc_4 = [ -1.839521e+00 ; -1.655913e+00 ; 4.688875e-01 ];
Tc_4  = [ -1.961611e+01 ; -2.044310e+02 ; 1.165313e+03 ];
omc_error_4 = [ 3.885665e-03 ; 3.239918e-03 ; 5.560444e-03 ];
Tc_error_4  = [ 5.861317e+00 ; 4.497421e+00 ; 5.410755e+00 ];

%-- Image #5:
omc_5 = [ 2.146463e+00 ; 1.954034e+00 ; 5.603002e-01 ];
Tc_5  = [ -2.617207e+02 ; -1.840680e+02 ; 9.809922e+02 ];
omc_error_5 = [ 4.668020e-03 ; 4.128484e-03 ; 7.869977e-03 ];
Tc_error_5  = [ 4.976148e+00 ; 3.874896e+00 ; 5.413931e+00 ];

%-- Image #6:
omc_6 = [ -1.766613e+00 ; -1.952540e+00 ; -1.794123e-01 ];
Tc_6  = [ -1.233392e+02 ; -1.677974e+02 ; 8.170973e+02 ];
omc_error_6 = [ 2.951859e-03 ; 4.097886e-03 ; 5.763585e-03 ];
Tc_error_6  = [ 4.107759e+00 ; 3.178198e+00 ; 4.394807e+00 ];

%-- Image #7:
omc_7 = [ 2.219362e+00 ; 2.100132e+00 ; 5.899759e-01 ];
Tc_7  = [ -3.127153e+02 ; -1.284273e+02 ; 6.759250e+02 ];
omc_error_7 = [ 4.395500e-03 ; 3.501978e-03 ; 7.401570e-03 ];
Tc_error_7  = [ 3.473445e+00 ; 2.788727e+00 ; 4.089912e+00 ];

%-- Image #8:
omc_8 = [ -2.025520e+00 ; -2.226173e+00 ; 2.514937e-01 ];
Tc_8  = [ -2.037233e+02 ; -1.612139e+02 ; 7.292610e+02 ];
omc_error_8 = [ 3.864885e-03 ; 3.235944e-03 ; 6.964615e-03 ];
Tc_error_8  = [ 3.661891e+00 ; 2.859963e+00 ; 3.824244e+00 ];

%-- Image #9:
omc_9 = [ -1.878943e+00 ; -2.058884e+00 ; 3.162373e-01 ];
Tc_9  = [ -2.135586e+02 ; -1.580156e+02 ; 6.776718e+02 ];
omc_error_9 = [ 3.901166e-03 ; 3.315177e-03 ; 6.114613e-03 ];
Tc_error_9  = [ 3.407656e+00 ; 2.671237e+00 ; 3.473608e+00 ];

%-- Image #10:
omc_10 = [ 2.119964e+00 ; 2.152928e+00 ; 1.630444e-01 ];
Tc_10  = [ -2.232223e+02 ; -2.019038e+02 ; 9.062839e+02 ];
omc_error_10 = [ 4.243404e-03 ; 5.035075e-03 ; 9.569412e-03 ];
Tc_error_10  = [ 4.584911e+00 ; 3.559970e+00 ; 4.863354e+00 ];

%-- Image #11:
omc_11 = [ -2.119163e+00 ; -2.188654e+00 ; 1.846074e-01 ];
Tc_11  = [ -2.556410e+02 ; -2.142360e+02 ; 1.023512e+03 ];
omc_error_11 = [ 4.642166e-03 ; 3.635603e-03 ; 8.739630e-03 ];
Tc_error_11  = [ 5.161040e+00 ; 4.017506e+00 ; 5.395469e+00 ];

%-- Image #12:
omc_12 = [ -1.820255e+00 ; -1.905352e+00 ; 5.766117e-01 ];
Tc_12  = [ -1.978624e+02 ; -1.928703e+02 ; 1.108011e+03 ];
omc_error_12 = [ 4.362417e-03 ; 3.263813e-03 ; 6.003140e-03 ];
Tc_error_12  = [ 5.565749e+00 ; 4.311036e+00 ; 5.215395e+00 ];

%-- Image #13:
omc_13 = [ 1.820340e+00 ; 1.802944e+00 ; 7.425134e-01 ];
Tc_13  = [ -2.575154e+02 ; -1.625414e+02 ; 9.953034e+02 ];
omc_error_13 = [ 4.396038e-03 ; 3.770377e-03 ; 5.936784e-03 ];
Tc_error_13  = [ 5.020503e+00 ; 3.924056e+00 ; 5.549229e+00 ];

%-- Image #14:
omc_14 = [ -2.036371e+00 ; -2.065995e+00 ; -1.887701e-01 ];
Tc_14  = [ -2.484070e+02 ; -2.152927e+02 ; 1.370217e+03 ];
omc_error_14 = [ 5.358875e-03 ; 5.427006e-03 ; 1.061291e-02 ];
Tc_error_14  = [ 6.883827e+00 ; 5.356824e+00 ; 7.454811e+00 ];

%-- Image #15:
omc_15 = [ -1.697856e+00 ; -1.745602e+00 ; 2.301881e-01 ];
Tc_15  = [ 6.419875e+01 ; -2.239778e+02 ; 1.285275e+03 ];
omc_error_15 = [ 3.476712e-03 ; 3.987917e-03 ; 5.739551e-03 ];
Tc_error_15  = [ 6.494978e+00 ; 4.985393e+00 ; 6.315979e+00 ];

