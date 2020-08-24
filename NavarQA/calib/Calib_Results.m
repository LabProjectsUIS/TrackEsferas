% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1219.687986211533600 ; 1225.141274035661800 ];

%-- Principal point:
cc = [ 660.724500968516050 ; 501.319201074132310 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.119563016907077 ; 0.189883008917327 ; -0.006702900456511 ; 0.004873684358119 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 9.373141868723067 ; 9.031307859583340 ];

%-- Principal point uncertainty:
cc_error = [ 15.626517006889607 ; 13.127050600743544 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.021454212152456 ; 0.083957801199166 ; 0.002635785518978 ; 0.003223632662265 ; 0.000000000000000 ];

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
omc_1 = [ 1.976331e+00 ; 2.051330e+00 ; -7.245866e-01 ];
Tc_1  = [ -8.968449e+01 ; -9.569269e+00 ; 8.619352e+02 ];
omc_error_1 = [ 6.235773e-03 ; 1.023662e-02 ; 1.479963e-02 ];
Tc_error_1  = [ 1.099219e+01 ; 9.210283e+00 ; 6.566310e+00 ];

%-- Image #2:
omc_2 = [ -1.641463e+00 ; -2.003458e+00 ; 1.175385e+00 ];
Tc_2  = [ 1.166033e+00 ; -7.609602e+01 ; 9.476076e+02 ];
omc_error_2 = [ 1.250937e-02 ; 8.358882e-03 ; 1.382992e-02 ];
Tc_error_2  = [ 1.210075e+01 ; 1.012150e+01 ; 6.359200e+00 ];

%-- Image #3:
omc_3 = [ 1.762088e+00 ; 1.782587e+00 ; 5.060866e-01 ];
Tc_3  = [ -3.100063e+02 ; -6.826529e+01 ; 9.641826e+02 ];
omc_error_3 = [ 9.544707e-03 ; 8.008835e-03 ; 1.341514e-02 ];
Tc_error_3  = [ 1.285748e+01 ; 1.065932e+01 ; 9.236074e+00 ];

%-- Image #4:
omc_4 = [ 2.062652e+00 ; 2.147637e+00 ; 7.137668e-02 ];
Tc_4  = [ -1.363106e+02 ; -1.069999e+02 ; 1.034751e+03 ];
omc_error_4 = [ 9.995710e-03 ; 1.019584e-02 ; 2.103273e-02 ];
Tc_error_4  = [ 1.333748e+01 ; 1.112359e+01 ; 8.632888e+00 ];

%-- Image #5:
omc_5 = [ 2.130976e+00 ; 2.198434e+00 ; -3.260528e-02 ];
Tc_5  = [ -1.128443e+02 ; -7.243799e+01 ; 1.289048e+03 ];
omc_error_5 = [ 1.432271e-02 ; 1.435972e-02 ; 3.179921e-02 ];
Tc_error_5  = [ 1.655511e+01 ; 1.382332e+01 ; 1.060947e+01 ];

%-- Image #6:
omc_6 = [ -1.773257e+00 ; -1.790036e+00 ; 9.982840e-01 ];
Tc_6  = [ 4.593101e+01 ; -6.130635e+01 ; 1.030724e+03 ];
omc_error_6 = [ 1.179563e-02 ; 8.242643e-03 ; 1.380028e-02 ];
Tc_error_6  = [ 1.317986e+01 ; 1.100005e+01 ; 7.065361e+00 ];

%-- Image #7:
omc_7 = [ 1.689204e+00 ; 1.657653e+00 ; 8.004371e-01 ];
Tc_7  = [ -2.629248e+02 ; -4.418960e+00 ; 8.367560e+02 ];
omc_error_7 = [ 1.105537e-02 ; 7.108151e-03 ; 1.342760e-02 ];
Tc_error_7  = [ 1.110857e+01 ; 9.270114e+00 ; 8.497757e+00 ];

%-- Image #8:
omc_8 = [ 1.876221e+00 ; 1.911295e+00 ; 5.428926e-01 ];
Tc_8  = [ -1.628894e+02 ; -1.027931e+02 ; 9.175567e+02 ];
omc_error_8 = [ 1.062331e-02 ; 8.011322e-03 ; 1.488989e-02 ];
Tc_error_8  = [ 1.190181e+01 ; 9.925055e+00 ; 8.164883e+00 ];

%-- Image #9:
omc_9 = [ 2.354160e+00 ; 1.641303e+00 ; -1.816700e-01 ];
Tc_9  = [ -4.687706e+00 ; -4.055490e+01 ; 9.317209e+02 ];
omc_error_9 = [ 1.058322e-02 ; 7.498228e-03 ; 1.802288e-02 ];
Tc_error_9  = [ 1.196829e+01 ; 9.900110e+00 ; 7.369085e+00 ];

%-- Image #10:
omc_10 = [ 1.853889e+00 ; 1.504884e+00 ; -6.868525e-01 ];
Tc_10  = [ -5.073083e+01 ; 3.037890e+00 ; 9.494146e+02 ];
omc_error_10 = [ 8.233311e-03 ; 1.006589e-02 ; 1.355848e-02 ];
Tc_error_10  = [ 1.216420e+01 ; 1.011387e+01 ; 7.324643e+00 ];

%-- Image #11:
omc_11 = [ 2.201643e+00 ; 1.335162e+00 ; -9.305458e-01 ];
Tc_11  = [ -1.278739e+01 ; 6.003661e+01 ; 9.798283e+02 ];
omc_error_11 = [ 8.359579e-03 ; 9.189064e-03 ; 1.516905e-02 ];
Tc_error_11  = [ 1.259168e+01 ; 1.046498e+01 ; 7.182939e+00 ];

%-- Image #12:
omc_12 = [ 2.003785e+00 ; 1.724634e+00 ; 4.318819e-01 ];
Tc_12  = [ -4.077212e+02 ; 2.861320e+01 ; 1.050778e+03 ];
omc_error_12 = [ 1.007059e-02 ; 7.661539e-03 ; 1.543850e-02 ];
Tc_error_12  = [ 1.430369e+01 ; 1.177820e+01 ; 1.041249e+01 ];

%-- Image #13:
omc_13 = [ 1.931498e+00 ; 1.801821e+00 ; 2.782379e-01 ];
Tc_13  = [ -4.298364e+02 ; -1.958996e+02 ; 9.928658e+02 ];
omc_error_13 = [ 8.222089e-03 ; 1.019195e-02 ; 1.497883e-02 ];
Tc_error_13  = [ 1.356639e+01 ; 1.113969e+01 ; 1.120397e+01 ];

%-- Image #14:
omc_14 = [ 1.778860e+00 ; 1.474160e+00 ; 2.758478e-01 ];
Tc_14  = [ -3.414629e+02 ; -5.817387e+01 ; 9.582427e+02 ];
omc_error_14 = [ 8.946246e-03 ; 8.967677e-03 ; 1.234361e-02 ];
Tc_error_14  = [ 1.275112e+01 ; 1.062914e+01 ; 9.531375e+00 ];

