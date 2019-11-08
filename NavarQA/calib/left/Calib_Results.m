% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 624.857196960993410 ; 622.220959086458270 ];

%-- Principal point:
cc = [ 308.450912406012150 ; 266.953549617473470 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.084923046655343 ; 0.109903899557704 ; 0.003923005176132 ; -0.008763575068152 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 5.873896371968350 ; 5.831979359732781 ];

%-- Principal point uncertainty:
cc_error = [ 4.837923083026993 ; 5.194910400311952 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.015647990125120 ; 0.034383711449735 ; 0.001739922716231 ; 0.002500885696409 ; 0.000000000000000 ];

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
omc_1 = [ -2.039515e+00 ; -2.286225e+00 ; 3.425165e-01 ];
Tc_1  = [ 7.893627e+00 ; -2.109505e+02 ; 6.573948e+02 ];
omc_error_1 = [ 6.379931e-03 ; 5.853707e-03 ; 1.180151e-02 ];
Tc_error_1  = [ 5.164312e+00 ; 5.436971e+00 ; 5.963008e+00 ];

%-- Image #2:
omc_2 = [ -1.814363e+00 ; -2.082717e+00 ; 7.065661e-02 ];
Tc_2  = [ -2.314192e-01 ; -2.086631e+02 ; 5.952024e+02 ];
omc_error_2 = [ 5.679178e-03 ; 6.028707e-03 ; 1.017662e-02 ];
Tc_error_2  = [ 4.719552e+00 ; 5.069405e+00 ; 5.612873e+00 ];

%-- Image #3:
omc_3 = [ -1.831391e+00 ; -2.061596e+00 ; -5.778225e-01 ];
Tc_3  = [ 1.697990e+01 ; -2.033798e+02 ; 5.741758e+02 ];
omc_error_3 = [ 4.211397e-03 ; 7.830706e-03 ; 1.056836e-02 ];
Tc_error_3  = [ 4.624565e+00 ; 4.901187e+00 ; 6.036059e+00 ];

%-- Image #4:
omc_4 = [ -1.737073e+00 ; -2.227201e+00 ; 3.715802e-02 ];
Tc_4  = [ 9.397742e+01 ; -2.113641e+02 ; 6.158102e+02 ];
omc_error_4 = [ 5.408082e-03 ; 7.111170e-03 ; 1.156601e-02 ];
Tc_error_4  = [ 4.919591e+00 ; 5.316751e+00 ; 5.876711e+00 ];

%-- Image #5:
omc_5 = [ -1.693079e+00 ; -2.289196e+00 ; 1.511403e-01 ];
Tc_5  = [ 6.051262e+01 ; -1.277443e+02 ; 6.794432e+02 ];
omc_error_5 = [ 5.314934e-03 ; 7.403517e-03 ; 1.223100e-02 ];
Tc_error_5  = [ 5.284612e+00 ; 5.746539e+00 ; 6.219970e+00 ];

%-- Image #6:
omc_6 = [ -1.894660e+00 ; -2.058413e+00 ; 5.768431e-01 ];
Tc_6  = [ -6.317707e+00 ; -2.248619e+02 ; 7.834081e+02 ];
omc_error_6 = [ 7.517593e-03 ; 5.248426e-03 ; 1.090125e-02 ];
Tc_error_6  = [ 6.167337e+00 ; 6.477339e+00 ; 6.811720e+00 ];

%-- Image #7:
omc_7 = [ 1.941353e+00 ; 2.284172e+00 ; 4.933712e-01 ];
Tc_7  = [ -9.396598e+00 ; -1.992365e+02 ; 7.747220e+02 ];
omc_error_7 = [ 7.510610e-03 ; 6.174275e-03 ; 1.324240e-02 ];
Tc_error_7  = [ 6.093881e+00 ; 6.482818e+00 ; 7.678663e+00 ];

%-- Image #8:
omc_8 = [ -2.018456e+00 ; -2.364670e+00 ; 8.150936e-02 ];
Tc_8  = [ 2.287996e+01 ; -1.674299e+02 ; 9.452988e+02 ];
omc_error_8 = [ 8.884181e-03 ; 1.128226e-02 ; 2.195471e-02 ];
Tc_error_8  = [ 7.352717e+00 ; 7.919780e+00 ; 8.974544e+00 ];

%-- Image #9:
omc_9 = [ -1.655240e+00 ; -1.869812e+00 ; -3.702667e-01 ];
Tc_9  = [ -3.270428e+01 ; -1.951694e+02 ; 6.572329e+02 ];
omc_error_9 = [ 5.460678e-03 ; 7.300086e-03 ; 9.466298e-03 ];
Tc_error_9  = [ 5.205977e+00 ; 5.584645e+00 ; 6.596700e+00 ];

%-- Image #10:
omc_10 = [ -1.729756e+00 ; -2.044027e+00 ; 4.799184e-02 ];
Tc_10  = [ -4.796585e+00 ; -2.080407e+02 ; 5.857722e+02 ];
omc_error_10 = [ 5.669643e-03 ; 6.160215e-03 ; 9.671201e-03 ];
Tc_error_10  = [ 4.647026e+00 ; 4.988025e+00 ; 5.493987e+00 ];

