% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1220.870740233312100 ; 1222.472420746314600 ];

%-- Principal point:
cc = [ 679.340732773194420 ; 510.036349623024650 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.103724505642792 ; 0.140713246760465 ; 0.000646998921757 ; 0.006540951765082 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.684868873085127 ; 7.046351018906202 ];

%-- Principal point uncertainty:
cc_error = [ 6.350072310760506 ; 6.316741473716507 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.006890737357772 ; 0.022238794958685 ; 0.001182190260745 ; 0.001324923322114 ; 0.000000000000000 ];

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
omc_1 = [ -5.027650e-01 ; 2.526810e+00 ; -3.988905e-01 ];
Tc_1  = [ -2.415364e+02 ; -4.167030e+02 ; 1.604928e+03 ];
omc_error_1 = [ 3.079777e-03 ; 5.171053e-03 ; 7.909000e-03 ];
Tc_error_1  = [ 8.600809e+00 ; 8.455416e+00 ; 9.081877e+00 ];

%-- Image #2:
omc_2 = [ 4.918869e-01 ; 2.610074e+00 ; -4.184012e-02 ];
Tc_2  = [ -1.956192e+02 ; -4.038813e+02 ; 1.318848e+03 ];
omc_error_2 = [ 1.520694e-03 ; 5.755625e-03 ; 7.970138e-03 ];
Tc_error_2  = [ 7.099619e+00 ; 6.880128e+00 ; 7.634069e+00 ];

%-- Image #3:
omc_3 = [ 9.651870e-01 ; 2.414035e+00 ; 5.467669e-01 ];
Tc_3  = [ -2.822732e+02 ; -3.253648e+02 ; 1.176048e+03 ];
omc_error_3 = [ 2.779530e-03 ; 4.962654e-03 ; 7.234395e-03 ];
Tc_error_3  = [ 6.423540e+00 ; 6.263508e+00 ; 7.131567e+00 ];

%-- Image #4:
omc_4 = [ 1.574001e+00 ; 1.553428e+00 ; 3.805017e-01 ];
Tc_4  = [ -2.655373e+02 ; -1.863718e+02 ; 1.004739e+03 ];
omc_error_4 = [ 4.148477e-03 ; 3.836697e-03 ; 5.470359e-03 ];
Tc_error_4  = [ 5.366679e+00 ; 5.271466e+00 ; 5.886504e+00 ];

%-- Image #5:
omc_5 = [ 2.505671e+00 ; 1.518288e+00 ; -3.110943e-01 ];
Tc_5  = [ -7.403455e+01 ; -2.344426e+02 ; 1.001800e+03 ];
omc_error_5 = [ 4.886708e-03 ; 3.890772e-03 ; 8.109369e-03 ];
Tc_error_5  = [ 5.297845e+00 ; 5.103409e+00 ; 5.155972e+00 ];

%-- Image #6:
omc_6 = [ 2.104600e+00 ; 1.599578e+00 ; 6.413501e-01 ];
Tc_6  = [ -2.544789e+00 ; -3.776719e+02 ; 1.339612e+03 ];
omc_error_6 = [ 5.543956e-03 ; 3.748810e-03 ; 6.960462e-03 ];
Tc_error_6  = [ 7.109294e+00 ; 6.926040e+00 ; 8.231804e+00 ];

%-- Image #7:
omc_7 = [ 2.662339e+00 ; 7.299887e-01 ; 3.835656e-01 ];
Tc_7  = [ -1.708734e+02 ; -3.013096e+02 ; 1.280225e+03 ];
omc_error_7 = [ 5.888814e-03 ; 2.742876e-03 ; 7.603723e-03 ];
Tc_error_7  = [ 6.776675e+00 ; 6.642259e+00 ; 7.560638e+00 ];

%-- Image #8:
omc_8 = [ 5.406638e-01 ; 3.044635e+00 ; -5.177334e-01 ];
Tc_8  = [ 3.426598e+02 ; -4.492210e+02 ; 1.357171e+03 ];
omc_error_8 = [ 1.910759e-03 ; 6.574445e-03 ; 8.856884e-03 ];
Tc_error_8  = [ 7.294931e+00 ; 7.078416e+00 ; 8.148871e+00 ];

%-- Image #9:
omc_9 = [ 9.630676e-01 ; 2.732480e+00 ; -6.600074e-01 ];
Tc_9  = [ 2.485797e+02 ; -3.237807e+02 ; 1.083586e+03 ];
omc_error_9 = [ 2.183208e-03 ; 6.217743e-03 ; 7.459363e-03 ];
Tc_error_9  = [ 5.802187e+00 ; 5.617694e+00 ; 6.141977e+00 ];

%-- Image #10:
omc_10 = [ 1.567368e+00 ; 2.023102e+00 ; 3.948501e-01 ];
Tc_10  = [ -2.241652e+02 ; -4.176077e+02 ; 1.227680e+03 ];
omc_error_10 = [ 3.682746e-03 ; 4.574737e-03 ; 6.690025e-03 ];
Tc_error_10  = [ 6.654285e+00 ; 6.409194e+00 ; 7.504861e+00 ];

%-- Image #11:
omc_11 = [ 1.035140e+00 ; 2.237231e+00 ; 7.874471e-01 ];
Tc_11  = [ -1.346452e+02 ; -3.031475e+02 ; 1.153704e+03 ];
omc_error_11 = [ 3.561334e-03 ; 4.325537e-03 ; 6.511838e-03 ];
Tc_error_11  = [ 6.170335e+00 ; 6.032715e+00 ; 6.976140e+00 ];

%-- Image #12:
omc_12 = [ 1.662182e+00 ; 2.261121e+00 ; -1.461414e-01 ];
Tc_12  = [ 1.767311e+02 ; -2.474323e+02 ; 9.943802e+02 ];
omc_error_12 = [ 3.966635e-03 ; 4.924808e-03 ; 7.308721e-03 ];
Tc_error_12  = [ 5.277736e+00 ; 5.141582e+00 ; 5.724023e+00 ];

%-- Image #13:
omc_13 = [ 2.118443e+00 ; 1.799878e+00 ; -6.391068e-02 ];
Tc_13  = [ -2.269104e+02 ; 5.836061e+01 ; 1.098899e+03 ];
omc_error_13 = [ 4.632627e-03 ; 3.784285e-03 ; 8.118764e-03 ];
Tc_error_13  = [ 5.796212e+00 ; 5.775409e+00 ; 6.168210e+00 ];

%-- Image #14:
omc_14 = [ 2.429932e+00 ; 1.371667e+00 ; 4.958998e-02 ];
Tc_14  = [ -1.732937e+02 ; -4.664284e+00 ; 9.760846e+02 ];
omc_error_14 = [ 4.569565e-03 ; 2.624147e-03 ; 7.409357e-03 ];
Tc_error_14  = [ 5.114586e+00 ; 5.072943e+00 ; 5.389967e+00 ];

%-- Image #15:
omc_15 = [ 1.459914e+00 ; 2.400035e+00 ; -7.477098e-02 ];
Tc_15  = [ -3.266395e+02 ; -1.731167e+02 ; 1.245901e+03 ];
omc_error_15 = [ 2.977970e-03 ; 5.899504e-03 ; 9.958564e-03 ];
Tc_error_15  = [ 6.626422e+00 ; 6.552982e+00 ; 7.128063e+00 ];

%-- Image #16:
omc_16 = [ -2.367984e+00 ; -1.723287e+00 ; 7.232752e-01 ];
Tc_16  = [ -2.728402e+01 ; -3.602826e+02 ; 1.484729e+03 ];
omc_error_16 = [ 6.436546e-03 ; 2.733575e-03 ; 8.537028e-03 ];
Tc_error_16  = [ 7.872878e+00 ; 7.613990e+00 ; 7.583768e+00 ];

%-- Image #17:
omc_17 = [ -2.483832e+00 ; -1.797020e+00 ; -5.955008e-01 ];
Tc_17  = [ -5.059115e+02 ; 5.929504e+01 ; 9.872854e+02 ];
omc_error_17 = [ 5.522834e-03 ; 3.761760e-03 ; 8.952837e-03 ];
Tc_error_17  = [ 5.435237e+00 ; 5.503256e+00 ; 6.663180e+00 ];

%-- Image #18:
omc_18 = [ 2.563138e+00 ; 9.007789e-01 ; 1.330987e+00 ];
Tc_18  = [ -1.625218e+02 ; -2.989170e+02 ; 1.239923e+03 ];
omc_error_18 = [ 6.272655e-03 ; 3.050703e-03 ; 6.925689e-03 ];
Tc_error_18  = [ 6.632435e+00 ; 6.466090e+00 ; 7.759233e+00 ];

%-- Image #19:
omc_19 = [ -2.663594e+00 ; -1.425931e+00 ; -2.619707e-01 ];
Tc_19  = [ -2.144681e+02 ; -2.119132e+02 ; 1.399035e+03 ];
omc_error_19 = [ 9.809182e-03 ; 4.856241e-03 ; 1.364722e-02 ];
Tc_error_19  = [ 7.383103e+00 ; 7.290882e+00 ; 8.039635e+00 ];

%-- Image #20:
omc_20 = [ 1.887048e+00 ; 2.089043e+00 ; -2.974614e-01 ];
Tc_20  = [ -8.993800e+01 ; -3.214200e+02 ; 1.378110e+03 ];
omc_error_20 = [ 3.601641e-03 ; 5.165864e-03 ; 7.946076e-03 ];
Tc_error_20  = [ 7.260287e+00 ; 7.084550e+00 ; 7.432029e+00 ];

