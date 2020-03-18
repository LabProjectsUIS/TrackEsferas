% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1205.887044423354800 ; 1209.053916471360900 ];

%-- Principal point:
cc = [ 631.188362434963660 ; 521.934365722713100 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.101182218944982 ; 0.118305794257904 ; 0.003524628944596 ; 0.000920610760509 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.842683106963471 ; 7.026803245274070 ];

%-- Principal point uncertainty:
cc_error = [ 7.656107734092213 ; 6.878481796069101 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.010159405084943 ; 0.034473199020565 ; 0.001496412053549 ; 0.001364075881889 ; 0.000000000000000 ];

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
omc_1 = [ 2.033748e+00 ; 2.133887e+00 ; -3.081675e-01 ];
Tc_1  = [ -5.960948e+01 ; -2.240719e+02 ; 1.004138e+03 ];
omc_error_1 = [ 4.191346e-03 ; 5.542954e-03 ; 1.071150e-02 ];
Tc_error_1  = [ 6.455453e+00 ; 5.681040e+00 ; 5.351442e+00 ];

%-- Image #2:
omc_2 = [ -2.080117e+00 ; -2.190063e+00 ; -2.034720e-01 ];
Tc_2  = [ -5.879388e+01 ; -2.339389e+02 ; 8.213970e+02 ];
omc_error_2 = [ 4.992468e-03 ; 5.677588e-03 ; 1.173129e-02 ];
Tc_error_2  = [ 5.322082e+00 ; 4.726426e+00 ; 4.798573e+00 ];

%-- Image #3:
omc_3 = [ 1.812352e+00 ; 1.868395e+00 ; 6.097509e-01 ];
Tc_3  = [ 3.233471e+00 ; -2.331390e+02 ; 7.495279e+02 ];
omc_error_3 = [ 4.946756e-03 ; 4.992706e-03 ; 8.227982e-03 ];
Tc_error_3  = [ 4.877114e+00 ; 4.280139e+00 ; 4.595813e+00 ];

%-- Image #4:
omc_4 = [ -2.069711e+00 ; -2.185544e+00 ; -1.576518e-01 ];
Tc_4  = [ -1.546794e+02 ; -2.390696e+02 ; 7.588481e+02 ];
omc_error_4 = [ 5.006723e-03 ; 4.998432e-03 ; 1.145561e-02 ];
Tc_error_4  = [ 4.934333e+00 ; 4.395093e+00 ; 4.512452e+00 ];

%-- Image #5:
omc_5 = [ -2.185725e+00 ; -2.062143e+00 ; -2.884177e-01 ];
Tc_5  = [ -1.022857e+02 ; -2.277962e+02 ; 6.111664e+02 ];
omc_error_5 = [ 3.909051e-03 ; 4.213914e-03 ; 9.099739e-03 ];
Tc_error_5  = [ 4.031668e+00 ; 3.558201e+00 ; 3.636224e+00 ];

%-- Image #6:
omc_6 = [ -1.800864e+00 ; -2.009509e+00 ; -5.988436e-01 ];
Tc_6  = [ 5.452635e+00 ; -1.894564e+02 ; 7.717168e+02 ];
omc_error_6 = [ 3.054163e-03 ; 5.300987e-03 ; 9.709381e-03 ];
Tc_error_6  = [ 4.984612e+00 ; 4.421203e+00 ; 4.548802e+00 ];

%-- Image #7:
omc_7 = [ -1.659369e+00 ; -1.872381e+00 ; -7.061596e-01 ];
Tc_7  = [ -4.144537e+00 ; -1.451786e+02 ; 7.302636e+02 ];
omc_error_7 = [ 3.232642e-03 ; 5.384926e-03 ; 9.029707e-03 ];
Tc_error_7  = [ 4.687800e+00 ; 4.163641e+00 ; 4.303846e+00 ];

%-- Image #8:
omc_8 = [ 1.764956e+00 ; 1.851741e+00 ; -1.663049e-01 ];
Tc_8  = [ -6.893124e+01 ; -2.050346e+02 ; 8.891148e+02 ];
omc_error_8 = [ 4.127861e-03 ; 5.235682e-03 ; 8.341910e-03 ];
Tc_error_8  = [ 5.722324e+00 ; 5.031503e+00 ; 4.805800e+00 ];

%-- Image #9:
omc_9 = [ 2.078994e+00 ; 1.665460e+00 ; 3.373440e-01 ];
Tc_9  = [ -2.965293e+02 ; -2.184546e+02 ; 8.204925e+02 ];
omc_error_9 = [ 4.378788e-03 ; 4.714853e-03 ; 8.243221e-03 ];
Tc_error_9  = [ 5.433833e+00 ; 4.791886e+00 ; 5.248637e+00 ];

%-- Image #10:
omc_10 = [ -1.909976e+00 ; -2.026956e+00 ; 1.593674e-01 ];
Tc_10  = [ 5.111928e+01 ; -2.333836e+02 ; 8.787288e+02 ];
omc_error_10 = [ 5.175408e-03 ; 5.953089e-03 ; 1.118622e-02 ];
Tc_error_10  = [ 5.697263e+00 ; 5.027430e+00 ; 4.830579e+00 ];

%-- Image #11:
omc_11 = [ -2.116486e+00 ; -2.243920e+00 ; -5.956176e-02 ];
Tc_11  = [ -2.845498e+01 ; -2.382872e+02 ; 8.330600e+02 ];
omc_error_11 = [ 5.156227e-03 ; 5.547338e-03 ; 1.183325e-02 ];
Tc_error_11  = [ 5.387314e+00 ; 4.752356e+00 ; 4.823824e+00 ];

%-- Image #12:
omc_12 = [ -1.811579e+00 ; -1.876346e+00 ; -5.450596e-01 ];
Tc_12  = [ -7.699251e+01 ; -2.810803e+02 ; 7.889850e+02 ];
omc_error_12 = [ 3.757893e-03 ; 4.779936e-03 ; 8.939607e-03 ];
Tc_error_12  = [ 5.190415e+00 ; 4.601860e+00 ; 4.659768e+00 ];

%-- Image #13:
omc_13 = [ 2.146416e+00 ; 1.880937e+00 ; 4.131614e-01 ];
Tc_13  = [ -2.328745e+02 ; -2.286645e+02 ; 7.837807e+02 ];
omc_error_13 = [ 4.529047e-03 ; 4.670624e-03 ; 8.929861e-03 ];
Tc_error_13  = [ 5.198794e+00 ; 4.556785e+00 ; 4.845183e+00 ];

