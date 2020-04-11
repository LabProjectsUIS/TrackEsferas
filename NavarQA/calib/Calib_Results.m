% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1209.919999859902900 ; 1211.284731082540900 ];

%-- Principal point:
cc = [ 629.881903460056610 ; 481.521959236316600 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.112706307150969 ; 0.160645760977669 ; -0.003473738435849 ; -0.000541265523409 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 7.814942022844957 ; 7.731384687084771 ];

%-- Principal point uncertainty:
cc_error = [ 7.346905690063299 ; 5.505418418588575 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.009029771996526 ; 0.024337704891608 ; 0.000958407479013 ; 0.001505415238750 ; 0.000000000000000 ];

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
omc_1 = [ 2.182829e+00 ; 2.197009e+00 ; -1.903684e-01 ];
Tc_1  = [ -3.581759e+01 ; -1.274612e+02 ; 7.594198e+02 ];
omc_error_1 = [ 4.276554e-03 ; 4.233233e-03 ; 9.399084e-03 ];
Tc_error_1  = [ 4.625419e+00 ; 3.429762e+00 ; 5.046000e+00 ];

%-- Image #2:
omc_2 = [ 2.690397e+00 ; 1.357383e+00 ; -6.516838e-02 ];
Tc_2  = [ -3.783070e+01 ; -4.595605e+01 ; 7.816205e+02 ];
omc_error_2 = [ 5.388354e-03 ; 2.246437e-03 ; 9.302928e-03 ];
Tc_error_2  = [ 4.767831e+00 ; 3.530110e+00 ; 5.174223e+00 ];

%-- Image #3:
omc_3 = [ -1.839508e+00 ; -1.886454e+00 ; 3.774718e-01 ];
Tc_3  = [ 1.217013e+02 ; -2.206246e+02 ; 9.736188e+02 ];
omc_error_3 = [ 4.474139e-03 ; 4.867895e-03 ; 9.265101e-03 ];
Tc_error_3  = [ 6.003370e+00 ; 4.446733e+00 ; 6.198893e+00 ];

%-- Image #4:
omc_4 = [ 2.313186e+00 ; 2.094969e+00 ; -1.560435e-01 ];
Tc_4  = [ 1.211378e+02 ; -1.505334e+02 ; 1.129334e+03 ];
omc_error_4 = [ 6.423263e-03 ; 5.130494e-03 ; 1.275989e-02 ];
Tc_error_4  = [ 6.917655e+00 ; 5.142667e+00 ; 7.499641e+00 ];

%-- Image #5:
omc_5 = [ -2.267229e+00 ; -2.096324e+00 ; 4.672993e-02 ];
Tc_5  = [ 1.213804e+02 ; -1.256290e+02 ; 1.369211e+03 ];
omc_error_5 = [ 8.068305e-03 ; 8.914470e-03 ; 1.852265e-02 ];
Tc_error_5  = [ 8.360631e+00 ; 6.236748e+00 ; 9.329945e+00 ];

%-- Image #6:
omc_6 = [ 2.131467e+00 ; 2.119222e+00 ; 3.378572e-01 ];
Tc_6  = [ -2.804770e+02 ; -1.109566e+02 ; 1.314548e+03 ];
omc_error_6 = [ 7.557891e-03 ; 7.971114e-03 ; 1.694719e-02 ];
Tc_error_6  = [ 8.127952e+00 ; 6.046456e+00 ; 9.940917e+00 ];

%-- Image #7:
omc_7 = [ 1.813726e+00 ; 1.914670e+00 ; 6.784404e-01 ];
Tc_7  = [ -2.121191e+02 ; -1.370950e+02 ; 1.031767e+03 ];
omc_error_7 = [ 4.745298e-03 ; 4.318054e-03 ; 8.045322e-03 ];
Tc_error_7  = [ 6.386990e+00 ; 4.735746e+00 ; 7.858688e+00 ];

%-- Image #8:
omc_8 = [ 2.240639e+00 ; 2.134723e+00 ; 3.982666e-01 ];
Tc_8  = [ -2.057871e+02 ; -2.532220e+02 ; 8.939571e+02 ];
omc_error_8 = [ 5.161164e-03 ; 5.591577e-03 ; 1.166427e-02 ];
Tc_error_8  = [ 5.650324e+00 ; 4.153600e+00 ; 6.815189e+00 ];

%-- Image #9:
omc_9 = [ -2.221689e+00 ; -1.832912e+00 ; 2.369732e-01 ];
Tc_9  = [ -1.431509e+02 ; -7.167616e+01 ; 8.243078e+02 ];
omc_error_9 = [ 4.609144e-03 ; 4.108713e-03 ; 9.898429e-03 ];
Tc_error_9  = [ 5.022085e+00 ; 3.738527e+00 ; 5.507626e+00 ];

%-- Image #10:
omc_10 = [ 2.263674e+00 ; 1.934369e+00 ; -5.879240e-01 ];
Tc_10  = [ -5.754072e+01 ; -2.867930e+01 ; 6.692750e+02 ];
omc_error_10 = [ 3.265875e-03 ; 3.428505e-03 ; 7.733683e-03 ];
Tc_error_10  = [ 4.031984e+00 ; 2.998873e+00 ; 4.180154e+00 ];

%-- Image #11:
omc_11 = [ 2.171186e+00 ; 1.970164e+00 ; -3.276501e-01 ];
Tc_11  = [ 2.421245e+01 ; -1.635098e+02 ; 8.938202e+02 ];
omc_error_11 = [ 4.228562e-03 ; 4.320719e-03 ; 8.831456e-03 ];
Tc_error_11  = [ 5.469639e+00 ; 4.038576e+00 ; 5.845160e+00 ];

%-- Image #12:
omc_12 = [ -2.153753e+00 ; -2.090966e+00 ; -1.195706e-03 ];
Tc_12  = [ 2.024574e+01 ; -1.961633e+02 ; 9.213097e+02 ];
omc_error_12 = [ 5.609090e-03 ; 6.192483e-03 ; 1.222099e-02 ];
Tc_error_12  = [ 5.650599e+00 ; 4.207263e+00 ; 6.240324e+00 ];

%-- Image #13:
omc_13 = [ -2.301091e+00 ; -1.896650e+00 ; -4.023932e-03 ];
Tc_13  = [ 5.879024e+01 ; -1.437802e+02 ; 1.054316e+03 ];
omc_error_13 = [ 6.415840e-03 ; 6.603071e-03 ; 1.365774e-02 ];
Tc_error_13  = [ 6.447342e+00 ; 4.800818e+00 ; 7.019250e+00 ];

%-- Image #14:
omc_14 = [ 2.271549e+00 ; 1.928388e+00 ; 4.336028e-01 ];
Tc_14  = [ 3.006597e+00 ; -1.353796e+02 ; 1.120192e+03 ];
omc_error_14 = [ 5.604851e-03 ; 3.891708e-03 ; 9.864667e-03 ];
Tc_error_14  = [ 6.847439e+00 ; 5.076546e+00 ; 7.861553e+00 ];

%-- Image #15:
omc_15 = [ -2.050282e+00 ; -1.833005e+00 ; 2.892758e-01 ];
Tc_15  = [ -2.632194e+01 ; -1.188721e+02 ; 1.181002e+03 ];
omc_error_15 = [ 5.130049e-03 ; 5.166261e-03 ; 1.051620e-02 ];
Tc_error_15  = [ 7.188114e+00 ; 5.347905e+00 ; 7.496709e+00 ];

%-- Image #16:
omc_16 = [ 2.050623e+00 ; 2.109621e+00 ; -7.499758e-01 ];
Tc_16  = [ -3.409488e+01 ; -1.827590e+02 ; 1.264799e+03 ];
omc_error_16 = [ 3.689531e-03 ; 5.283387e-03 ; 9.642371e-03 ];
Tc_error_16  = [ 7.708725e+00 ; 5.740431e+00 ; 7.945984e+00 ];

%-- Image #17:
omc_17 = [ 1.982710e+00 ; 2.001509e+00 ; -6.624141e-01 ];
Tc_17  = [ -9.781132e+00 ; -1.634029e+02 ; 9.881856e+02 ];
omc_error_17 = [ 3.542820e-03 ; 4.800584e-03 ; 8.403227e-03 ];
Tc_error_17  = [ 6.021095e+00 ; 4.473441e+00 ; 6.183525e+00 ];

%-- Image #18:
omc_18 = [ 2.030064e+00 ; 2.085783e+00 ; -6.091405e-01 ];
Tc_18  = [ -2.675961e+01 ; -9.030270e+01 ; 8.005921e+02 ];
omc_error_18 = [ 3.285201e-03 ; 4.253737e-03 ; 8.121048e-03 ];
Tc_error_18  = [ 4.840244e+00 ; 3.601646e+00 ; 4.961436e+00 ];

%-- Image #19:
omc_19 = [ 1.809075e+00 ; 2.151319e+00 ; -7.849375e-01 ];
Tc_19  = [ 6.387048e+01 ; -1.848965e+02 ; 1.000612e+03 ];
omc_error_19 = [ 3.373675e-03 ; 5.042815e-03 ; 8.149180e-03 ];
Tc_error_19  = [ 6.099693e+00 ; 4.546300e+00 ; 6.121554e+00 ];

%-- Image #20:
omc_20 = [ -2.196275e+00 ; -1.882076e+00 ; 2.918318e-01 ];
Tc_20  = [ 9.479593e+01 ; -1.570018e+02 ; 1.068576e+03 ];
omc_error_20 = [ 6.718916e-03 ; 7.031740e-03 ; 1.484574e-02 ];
Tc_error_20  = [ 6.520725e+00 ; 4.863809e+00 ; 6.961828e+00 ];

