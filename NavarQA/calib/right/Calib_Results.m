% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 630.049558063004840 ; 630.421823096825510 ];

%-- Principal point:
cc = [ 299.630421760827010 ; 235.577495798454440 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.082744311049208 ; 0.281816170815303 ; -0.010255729387700 ; -0.006102736089474 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 9.128366341919495 ; 9.648853232416009 ];

%-- Principal point uncertainty:
cc_error = [ 9.174368246866012 ; 9.379279848112219 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.055915501743414 ; 0.315890580239052 ; 0.004521190192193 ; 0.005299457952863 ; 0.000000000000000 ];

%-- Image size:
nx = 640;
ny = 512;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 10;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.060595e+00 ; 2.200285e+00 ; -2.048223e-01 ];
Tc_1  = [ -2.062576e+02 ; -1.841004e+02 ; 9.671369e+02 ];
omc_error_1 = [ 1.068780e-02 ; 1.423608e-02 ; 2.435485e-02 ];
Tc_error_1  = [ 1.404340e+01 ; 1.446677e+01 ; 1.503785e+01 ];

%-- Image #2:
omc_2 = [ -1.921768e+00 ; -2.089464e+00 ; -2.203576e-01 ];
Tc_2  = [ -1.784707e+02 ; -1.654185e+02 ; 8.558092e+02 ];
omc_error_2 = [ 1.239440e-02 ; 1.424858e-02 ; 2.222422e-02 ];
Tc_error_2  = [ 1.251873e+01 ; 1.282195e+01 ; 1.325680e+01 ];

%-- Image #3:
omc_3 = [ -2.001556e+00 ; -2.343494e+00 ; 3.630571e-01 ];
Tc_3  = [ -1.878892e+02 ; -1.705364e+02 ; 7.927721e+02 ];
omc_error_3 = [ 1.235128e-02 ; 9.645613e-03 ; 2.134256e-02 ];
Tc_error_3  = [ 1.142737e+01 ; 1.190146e+01 ; 1.246356e+01 ];

%-- Image #4:
omc_4 = [ 2.114022e+00 ; 2.069283e+00 ; -4.960605e-01 ];
Tc_4  = [ -1.746102e+02 ; -1.639934e+02 ; 8.323090e+02 ];
omc_error_4 = [ 8.780102e-03 ; 1.333393e-02 ; 2.030527e-02 ];
Tc_error_4  = [ 1.206500e+01 ; 1.241713e+01 ; 1.262370e+01 ];

%-- Image #5:
omc_5 = [ 1.701362e+00 ; 1.854441e+00 ; -6.428797e-01 ];
Tc_5  = [ -1.655729e+02 ; -1.545958e+02 ; 8.522332e+02 ];
omc_error_5 = [ 9.166523e-03 ; 1.395533e-02 ; 1.861017e-02 ];
Tc_error_5  = [ 1.244419e+01 ; 1.274040e+01 ; 1.173613e+01 ];

%-- Image #6:
omc_6 = [ 1.646433e+00 ; 2.071453e+00 ; -1.154372e+00 ];
Tc_6  = [ -1.678691e+02 ; -1.424176e+02 ; 9.042381e+02 ];
omc_error_6 = [ 7.376374e-03 ; 1.713023e-02 ; 1.955096e-02 ];
Tc_error_6  = [ 1.319915e+01 ; 1.359034e+01 ; 1.194450e+01 ];

%-- Image #7:
omc_7 = [ 1.742492e+00 ; 2.448928e+00 ; -7.601653e-01 ];
Tc_7  = [ -1.305042e+02 ; -1.891378e+02 ; 8.421837e+02 ];
omc_error_7 = [ 5.041555e-03 ; 1.585371e-02 ; 2.127186e-02 ];
Tc_error_7  = [ 1.222945e+01 ; 1.257023e+01 ; 1.237944e+01 ];

%-- Image #8:
omc_8 = [ -1.189255e+00 ; -2.752143e+00 ; 5.318096e-01 ];
Tc_8  = [ -7.220941e+01 ; -2.114683e+02 ; 8.722174e+02 ];
omc_error_8 = [ 9.964070e-03 ; 1.133062e-02 ; 2.265011e-02 ];
Tc_error_8  = [ 1.268754e+01 ; 1.297591e+01 ; 1.332647e+01 ];

%-- Image #9:
omc_9 = [ -1.243899e+00 ; -2.479227e+00 ; 8.612396e-02 ];
Tc_9  = [ -1.152191e+02 ; -2.070816e+02 ; 8.409836e+02 ];
omc_error_9 = [ 9.603814e-03 ; 1.383094e-02 ; 2.042470e-02 ];
Tc_error_9  = [ 1.222364e+01 ; 1.259423e+01 ; 1.331884e+01 ];

%-- Image #10:
omc_10 = [ -1.504617e+00 ; -2.564853e+00 ; 4.502146e-01 ];
Tc_10  = [ -1.362580e+02 ; -2.399305e+02 ; 9.043913e+02 ];
omc_error_10 = [ 1.152584e-02 ; 1.103417e-02 ; 2.194693e-02 ];
Tc_error_10  = [ 1.316105e+01 ; 1.351908e+01 ; 1.414263e+01 ];

