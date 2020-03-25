% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1222.085123259619000 ; 1223.035732404008100 ];

%-- Principal point:
cc = [ 631.579804059957610 ; 500.976365185188680 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.089527520473697 ; 0.122515828990050 ; -0.001192477109310 ; 0.000628412357068 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.527328308966757 ; 6.300076388921551 ];

%-- Principal point uncertainty:
cc_error = [ 6.781300727868816 ; 6.147320403296297 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.008450813056128 ; 0.022590678986702 ; 0.001378673036704 ; 0.001517652212845 ; 0.000000000000000 ];

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
omc_1 = [ 2.161490e+00 ; 2.268637e+00 ; -5.365064e-02 ];
Tc_1  = [ -4.403237e+01 ; -2.426083e+02 ; 1.064818e+03 ];
omc_error_1 = [ 5.779644e-03 ; 6.420287e-03 ; 1.334911e-02 ];
Tc_error_1  = [ 5.971355e+00 ; 5.324862e+00 ; 5.848700e+00 ];

%-- Image #2:
omc_2 = [ -1.992846e+00 ; -2.336883e+00 ; 1.367325e-01 ];
Tc_2  = [ 6.428648e+01 ; -3.164099e+02 ; 9.387614e+02 ];
omc_error_2 = [ 5.308522e-03 ; 5.564440e-03 ; 1.158764e-02 ];
Tc_error_2  = [ 5.338526e+00 ; 4.710332e+00 ; 5.251339e+00 ];

%-- Image #3:
omc_3 = [ -2.214838e+00 ; -2.182064e+00 ; -3.627492e-02 ];
Tc_3  = [ -7.951383e+01 ; -2.346212e+02 ; 8.315106e+02 ];
omc_error_3 = [ 5.213883e-03 ; 4.902620e-03 ; 1.115368e-02 ];
Tc_error_3  = [ 4.695229e+00 ; 4.174268e+00 ; 4.596127e+00 ];

%-- Image #4:
omc_4 = [ 1.858747e+00 ; 1.790919e+00 ; 2.873307e-01 ];
Tc_4  = [ -7.443088e+01 ; -2.142507e+02 ; 7.537419e+02 ];
omc_error_4 = [ 4.444832e-03 ; 4.289317e-03 ; 6.966394e-03 ];
Tc_error_4  = [ 4.259524e+00 ; 3.767870e+00 ; 4.259371e+00 ];

%-- Image #5:
omc_5 = [ 1.707956e+00 ; 1.760996e+00 ; 7.839840e-01 ];
Tc_5  = [ -1.636883e+02 ; -2.356329e+02 ; 6.412324e+02 ];
omc_error_5 = [ 4.617597e-03 ; 4.189336e-03 ; 6.500577e-03 ];
Tc_error_5  = [ 3.737463e+00 ; 3.276631e+00 ; 4.034761e+00 ];

%-- Image #6:
omc_6 = [ -1.807448e+00 ; -1.940252e+00 ; 5.831377e-01 ];
Tc_6  = [ 7.873790e+01 ; -2.246181e+02 ; 8.308001e+02 ];
omc_error_6 = [ 4.537490e-03 ; 3.959098e-03 ; 8.079215e-03 ];
Tc_error_6  = [ 4.699514e+00 ; 4.156126e+00 ; 4.108738e+00 ];

%-- Image #7:
omc_7 = [ 2.360032e+00 ; 1.468043e+00 ; -8.031022e-02 ];
Tc_7  = [ -4.837867e+01 ; -1.630798e+02 ; 7.738964e+02 ];
omc_error_7 = [ 4.700395e-03 ; 3.596150e-03 ; 8.006136e-03 ];
Tc_error_7  = [ 4.357073e+00 ; 3.837135e+00 ; 4.136595e+00 ];

%-- Image #8:
omc_8 = [ 2.081751e+00 ; 2.209670e+00 ; -2.709982e-01 ];
Tc_8  = [ -5.959702e+01 ; -2.983117e+02 ; 8.558543e+02 ];
omc_error_8 = [ 3.501571e-03 ; 4.881446e-03 ; 9.386083e-03 ];
Tc_error_8  = [ 4.864627e+00 ; 4.251776e+00 ; 4.766476e+00 ];

%-- Image #9:
omc_9 = [ 1.501243e+00 ; 1.927230e+00 ; -2.523657e-01 ];
Tc_9  = [ -3.956273e+01 ; -2.448697e+02 ; 8.528988e+02 ];
omc_error_9 = [ 3.607328e-03 ; 4.913714e-03 ; 6.472770e-03 ];
Tc_error_9  = [ 4.808238e+00 ; 4.248659e+00 ; 4.435748e+00 ];

%-- Image #10:
omc_10 = [ 1.869333e+00 ; 1.791924e+00 ; 2.014506e-01 ];
Tc_10  = [ -1.419835e+02 ; -2.166718e+02 ; 8.128966e+02 ];
omc_error_10 = [ 4.162289e-03 ; 4.382495e-03 ; 6.965284e-03 ];
Tc_error_10  = [ 4.597696e+00 ; 4.071412e+00 ; 4.643871e+00 ];

%-- Image #11:
omc_11 = [ -1.811876e+00 ; -1.993577e+00 ; 5.776166e-01 ];
Tc_11  = [ 3.723542e+01 ; -2.294341e+02 ; 8.593658e+02 ];
omc_error_11 = [ 4.577429e-03 ; 3.886749e-03 ; 8.316098e-03 ];
Tc_error_11  = [ 4.848397e+00 ; 4.302127e+00 ; 4.114076e+00 ];

%-- Image #12:
omc_12 = [ 1.808950e+00 ; 1.741556e+00 ; 2.953101e-02 ];
Tc_12  = [ -8.698969e+01 ; -1.953008e+02 ; 8.197957e+02 ];
omc_error_12 = [ 4.144660e-03 ; 4.422863e-03 ; 6.770459e-03 ];
Tc_error_12  = [ 4.608140e+00 ; 4.082609e+00 ; 4.525383e+00 ];

%-- Image #13:
omc_13 = [ 2.113092e+00 ; 1.866537e+00 ; -5.197432e-02 ];
Tc_13  = [ -6.916866e+01 ; -1.287090e+02 ; 6.445224e+02 ];
omc_error_13 = [ 4.054553e-03 ; 3.668813e-03 ; 7.595759e-03 ];
Tc_error_13  = [ 3.608957e+00 ; 3.201822e+00 ; 3.432566e+00 ];

%-- Image #14:
omc_14 = [ 2.140246e+00 ; 2.163606e+00 ; -3.390939e-01 ];
Tc_14  = [ -5.384206e+01 ; -1.877867e+02 ; 7.562350e+02 ];
omc_error_14 = [ 3.507497e-03 ; 4.297442e-03 ; 8.769764e-03 ];
Tc_error_14  = [ 4.240291e+00 ; 3.744781e+00 ; 3.990080e+00 ];

%-- Image #15:
omc_15 = [ 1.984258e+00 ; 1.687675e+00 ; -3.434494e-02 ];
Tc_15  = [ -1.359456e+02 ; -1.858978e+02 ; 8.314052e+02 ];
omc_error_15 = [ 4.064528e-03 ; 4.265178e-03 ; 7.132637e-03 ];
Tc_error_15  = [ 4.672085e+00 ; 4.142194e+00 ; 4.627579e+00 ];

