% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1205.539490339826700 ; 1208.696567488198100 ];

%-- Principal point:
cc = [ 595.881461462922860 ; 510.392805377073050 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.134934883482830 ; 0.223752679585783 ; -0.002378612574768 ; -0.007753152637063 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 9.949092740043325 ; 9.920321623793184 ];

%-- Principal point uncertainty:
cc_error = [ 15.528086190035438 ; 12.615999668310753 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.023862258200064 ; 0.156917127518029 ; 0.002415323770356 ; 0.002850498901197 ; 0.000000000000000 ];

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
omc_1 = [ -1.678360e+00 ; -1.896471e+00 ; 8.602473e-01 ];
Tc_1  = [ 2.352360e+01 ; -6.291153e+01 ; 1.113972e+03 ];
omc_error_1 = [ 1.005654e-02 ; 8.321350e-03 ; 1.327048e-02 ];
Tc_error_1  = [ 1.433552e+01 ; 1.160724e+01 ; 8.791609e+00 ];

%-- Image #2:
omc_2 = [ -1.857896e+00 ; -1.966311e+00 ; 4.160046e-01 ];
Tc_2  = [ -2.995169e+01 ; -2.448652e+02 ; 1.218725e+03 ];
omc_error_2 = [ 9.169432e-03 ; 7.361915e-03 ; 1.476572e-02 ];
Tc_error_2  = [ 1.582249e+01 ; 1.272092e+01 ; 1.054141e+01 ];

%-- Image #3:
omc_3 = [ -1.567868e+00 ; -1.777194e+00 ; 7.380198e-01 ];
Tc_3  = [ -2.888800e-01 ; -1.896447e+02 ; 1.244402e+03 ];
omc_error_3 = [ 1.018076e-02 ; 8.617979e-03 ; 1.305377e-02 ];
Tc_error_3  = [ 1.609347e+01 ; 1.297293e+01 ; 9.808181e+00 ];

%-- Image #4:
omc_4 = [ -2.107543e+00 ; -2.064486e+00 ; 1.174631e-01 ];
Tc_4  = [ -1.529838e+02 ; -1.810918e+02 ; 1.324584e+03 ];
omc_error_4 = [ 9.837555e-03 ; 9.037918e-03 ; 1.965515e-02 ];
Tc_error_4  = [ 1.708800e+01 ; 1.386137e+01 ; 1.148018e+01 ];

%-- Image #5:
omc_5 = [ -2.105206e+00 ; -1.998893e+00 ; 6.022339e-02 ];
Tc_5  = [ -1.507636e+02 ; -4.975087e+01 ; 1.414084e+03 ];
omc_error_5 = [ 9.491582e-03 ; 1.026164e-02 ; 1.960859e-02 ];
Tc_error_5  = [ 1.818999e+01 ; 1.477239e+01 ; 1.219665e+01 ];

%-- Image #6:
omc_6 = [ 2.191855e+00 ; 2.162331e+00 ; 5.772382e-01 ];
Tc_6  = [ -3.461378e+02 ; -9.323654e+01 ; 1.298789e+03 ];
omc_error_6 = [ 1.208843e-02 ; 8.824369e-03 ; 2.056393e-02 ];
Tc_error_6  = [ 1.675576e+01 ; 1.380101e+01 ; 1.324301e+01 ];

%-- Image #7:
omc_7 = [ -1.955674e+00 ; -2.015839e+00 ; -4.751814e-01 ];
Tc_7  = [ -2.297036e+02 ; -2.929165e+02 ; 1.201650e+03 ];
omc_error_7 = [ 7.604598e-03 ; 9.594369e-03 ; 1.690832e-02 ];
Tc_error_7  = [ 1.575461e+01 ; 1.283354e+01 ; 1.163191e+01 ];

%-- Image #8:
omc_8 = [ -1.530196e+00 ; -1.515597e+00 ; 7.054387e-01 ];
Tc_8  = [ 6.255915e+01 ; -1.258856e+02 ; 1.121321e+03 ];
omc_error_8 = [ 9.768502e-03 ; 9.347899e-03 ; 1.186689e-02 ];
Tc_error_8  = [ 1.451573e+01 ; 1.172783e+01 ; 8.861638e+00 ];

%-- Image #9:
omc_9 = [ 2.114038e+00 ; 1.585195e+00 ; -2.928916e-01 ];
Tc_9  = [ -2.959134e+02 ; -2.819820e+01 ; 1.065662e+03 ];
omc_error_9 = [ 7.997184e-03 ; 9.130230e-03 ; 1.624717e-02 ];
Tc_error_9  = [ 1.375113e+01 ; 1.127815e+01 ; 1.009901e+01 ];

%-- Image #10:
omc_10 = [ -2.312314e+00 ; -1.984870e+00 ; 5.420154e-01 ];
Tc_10  = [ -1.972133e+02 ; 3.571099e+01 ; 1.323841e+03 ];
omc_error_10 = [ 1.103337e-02 ; 7.385658e-03 ; 1.754580e-02 ];
Tc_error_10  = [ 1.697974e+01 ; 1.385463e+01 ; 1.146015e+01 ];

%-- Image #11:
omc_11 = [ 2.159834e+00 ; 2.136030e+00 ; 3.272145e-01 ];
Tc_11  = [ -4.314627e+02 ; -1.489759e+02 ; 1.159874e+03 ];
omc_error_11 = [ 1.127541e-02 ; 1.224332e-02 ; 2.627664e-02 ];
Tc_error_11  = [ 1.522296e+01 ; 1.258271e+01 ; 1.298458e+01 ];

%-- Image #12:
omc_12 = [ -1.649199e+00 ; -1.882557e+00 ; 1.912314e-02 ];
Tc_12  = [ -1.385268e+02 ; -3.040219e+02 ; 1.210629e+03 ];
omc_error_12 = [ 8.041181e-03 ; 8.926228e-03 ; 1.413738e-02 ];
Tc_error_12  = [ 1.577721e+01 ; 1.275894e+01 ; 1.105593e+01 ];

%-- Image #13:
omc_13 = [ -1.665501e+00 ; -1.831586e+00 ; 5.090352e-01 ];
Tc_13  = [ 3.012344e+01 ; -1.951790e+02 ; 1.186061e+03 ];
omc_error_13 = [ 9.002758e-03 ; 8.426720e-03 ; 1.306371e-02 ];
Tc_error_13  = [ 1.537787e+01 ; 1.239522e+01 ; 9.845967e+00 ];

%-- Image #14:
omc_14 = [ -2.131981e+00 ; -2.051937e+00 ; -8.826655e-02 ];
Tc_14  = [ -1.262679e+02 ; -1.911476e+02 ; 1.368665e+03 ];
omc_error_14 = [ 1.087809e-02 ; 1.139816e-02 ; 2.292136e-02 ];
Tc_error_14  = [ 1.770536e+01 ; 1.436562e+01 ; 1.217490e+01 ];

%-- Image #15:
omc_15 = [ 1.927661e+00 ; 1.855685e+00 ; 8.614698e-01 ];
Tc_15  = [ -2.991324e+02 ; -8.984448e+01 ; 1.105683e+03 ];
omc_error_15 = [ 1.170971e-02 ; 7.704359e-03 ; 1.614657e-02 ];
Tc_error_15  = [ 1.431170e+01 ; 1.175143e+01 ; 1.149793e+01 ];

%-- Image #16:
omc_16 = [ 1.836786e+00 ; 1.616885e+00 ; 1.002062e+00 ];
Tc_16  = [ -3.357844e+02 ; -6.759968e+01 ; 1.021379e+03 ];
omc_error_16 = [ 1.196946e-02 ; 7.655318e-03 ; 1.478407e-02 ];
Tc_error_16  = [ 1.330232e+01 ; 1.095534e+01 ; 1.125404e+01 ];

