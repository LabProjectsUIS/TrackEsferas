% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1210.992296832341900 ; 1210.345026203723800 ];

%-- Principal point:
cc = [ 616.828410398832370 ; 521.705258230456480 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.116255759635140 ; 0.184428632481016 ; -0.000719268544503 ; -0.004174234349365 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 7.494453946697060 ; 7.231069246545467 ];

%-- Principal point uncertainty:
cc_error = [ 10.155324869831292 ; 13.024426571514368 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.018610361052181 ; 0.093342821897039 ; 0.002233215502780 ; 0.002280600263100 ; 0.000000000000000 ];

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
omc_1 = [ 2.383578e+00 ; 2.100334e-01 ; -1.008834e-01 ];
Tc_1  = [ -1.599878e+02 ; 8.739504e+01 ; 6.751095e+02 ];
omc_error_1 = [ 1.044667e-02 ; 4.277421e-03 ; 1.014988e-02 ];
Tc_error_1  = [ 5.686072e+00 ; 7.357562e+00 ; 4.743517e+00 ];

%-- Image #2:
omc_2 = [ 2.413726e+00 ; 2.659675e-01 ; -5.229397e-01 ];
Tc_2  = [ -1.475445e+02 ; 1.352834e+02 ; 8.505180e+02 ];
omc_error_2 = [ 1.005514e-02 ; 5.120645e-03 ; 1.018961e-02 ];
Tc_error_2  = [ 7.165792e+00 ; 9.241117e+00 ; 5.483100e+00 ];

%-- Image #3:
omc_3 = [ 2.227175e+00 ; 3.425136e-01 ; -6.822730e-01 ];
Tc_3  = [ -1.453254e+02 ; 1.651894e+02 ; 8.796083e+02 ];
omc_error_3 = [ 9.788032e-03 ; 6.084321e-03 ; 9.441439e-03 ];
Tc_error_3  = [ 7.430789e+00 ; 9.577742e+00 ; 5.647106e+00 ];

%-- Image #4:
omc_4 = [ 2.448798e+00 ; 1.933059e-01 ; -1.458464e+00 ];
Tc_4  = [ -4.836759e+01 ; 2.031801e+02 ; 1.037043e+03 ];
omc_error_4 = [ 9.651241e-03 ; 8.398497e-03 ; 1.091274e-02 ];
Tc_error_4  = [ 8.759634e+00 ; 1.115611e+01 ; 5.613666e+00 ];

%-- Image #5:
omc_5 = [ 2.786516e+00 ; 2.592334e-02 ; 5.204079e-01 ];
Tc_5  = [ -3.764350e+01 ; 2.202895e+02 ; 8.843728e+02 ];
omc_error_5 = [ 1.088152e-02 ; 3.497996e-03 ; 1.321014e-02 ];
Tc_error_5  = [ 7.538366e+00 ; 9.571929e+00 ; 5.974530e+00 ];

%-- Image #6:
omc_6 = [ 2.681115e+00 ; 1.832258e-01 ; -9.205268e-02 ];
Tc_6  = [ -1.735085e+01 ; 1.318724e+02 ; 1.036741e+03 ];
omc_error_6 = [ 1.064949e-02 ; 2.871752e-03 ; 1.229909e-02 ];
Tc_error_6  = [ 8.732509e+00 ; 1.121275e+01 ; 6.755338e+00 ];

%-- Image #7:
omc_7 = [ 2.957325e+00 ; 1.248421e-01 ; -2.697624e-01 ];
Tc_7  = [ -2.239165e+01 ; 2.324846e+02 ; 1.201101e+03 ];
omc_error_7 = [ 1.203009e-02 ; 2.242467e-03 ; 1.817949e-02 ];
Tc_error_7  = [ 1.016415e+01 ; 1.307424e+01 ; 7.636416e+00 ];

%-- Image #8:
omc_8 = [ 3.030018e+00 ; 1.846031e-01 ; -7.792624e-01 ];
Tc_8  = [ -6.443148e+01 ; 1.017602e+02 ; 1.188470e+03 ];
omc_error_8 = [ 1.045428e-02 ; 4.670479e-03 ; 1.354482e-02 ];
Tc_error_8  = [ 9.942231e+00 ; 1.276515e+01 ; 6.613298e+00 ];

%-- Image #9:
omc_9 = [ 3.019393e+00 ; 1.094134e-01 ; 4.702905e-01 ];
Tc_9  = [ -1.686814e+02 ; 1.471667e+02 ; 1.151182e+03 ];
omc_error_9 = [ 1.223425e-02 ; 2.304926e-03 ; 1.713530e-02 ];
Tc_error_9  = [ 9.684959e+00 ; 1.244741e+01 ; 7.340088e+00 ];

%-- Image #10:
omc_10 = [ 2.946960e+00 ; 7.012286e-02 ; -1.041211e+00 ];
Tc_10  = [ 8.433231e+01 ; 1.527011e+02 ; 1.099674e+03 ];
omc_error_10 = [ 1.012949e-02 ; 4.708296e-03 ; 1.231311e-02 ];
Tc_error_10  = [ 9.320950e+00 ; 1.183736e+01 ; 5.939774e+00 ];

%-- Image #11:
omc_11 = [ 3.059648e+00 ; 4.835997e-02 ; -2.343513e-01 ];
Tc_11  = [ -1.920372e+02 ; 1.610863e+02 ; 9.282854e+02 ];
omc_error_11 = [ 1.054271e-02 ; 2.330331e-03 ; 1.629749e-02 ];
Tc_error_11  = [ 7.811708e+00 ; 1.007326e+01 ; 5.974134e+00 ];

%-- Image #12:
omc_12 = [ 3.037626e+00 ; 5.688304e-02 ; -5.539685e-01 ];
Tc_12  = [ 1.148229e+02 ; 8.405785e+01 ; 9.690940e+02 ];
omc_error_12 = [ 9.581349e-03 ; 2.544854e-03 ; 1.578673e-02 ];
Tc_error_12  = [ 8.169594e+00 ; 1.050489e+01 ; 6.161819e+00 ];

