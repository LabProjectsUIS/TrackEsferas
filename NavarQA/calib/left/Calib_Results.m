% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1229.904188091158400 ; 1227.921867761545400 ];

%-- Principal point:
cc = [ 643.470390116870250 ; 478.349994866746610 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.096447280988380 ; 0.130127477843623 ; -0.005260910108268 ; 0.002875873689403 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.862385027473347 ; 6.221095778880600 ];

%-- Principal point uncertainty:
cc_error = [ 7.864457584371668 ; 10.673877164632982 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.016526114224707 ; 0.085404642548346 ; 0.002210844294475 ; 0.001716405448029 ; 0.000000000000000 ];

%-- Image size:
nx = 1280;
ny = 1024;


%-- Various other variables (may be ignored if you do not use the Matlab Calibration Toolbox):
%-- Those variables are used to control which intrinsic parameters should be optimized

n_ima = 19;						% Number of calibration images
est_fc = [ 1 ; 1 ];					% Estimation indicator of the two focal variables
est_aspect_ratio = 1;				% Estimation indicator of the aspect ratio fc(2)/fc(1)
center_optim = 1;					% Estimation indicator of the principal point
est_alpha = 0;						% Estimation indicator of the skew coefficient
est_dist = [ 1 ; 1 ; 1 ; 1 ; 0 ];	% Estimation indicator of the distortion coefficients


%-- Extrinsic parameters:
%-- The rotation (omc_kk) and the translation (Tc_kk) vectors for every calibration image and their uncertainties

%-- Image #1:
omc_1 = [ 2.000812e+00 ; 2.129539e+00 ; 1.211090e-01 ];
Tc_1  = [ -5.240321e+01 ; -1.740955e+02 ; 6.671397e+02 ];
omc_error_1 = [ 6.507118e-03 ; 5.330030e-03 ; 1.105042e-02 ];
Tc_error_1  = [ 4.312415e+00 ; 5.810878e+00 ; 4.089362e+00 ];

%-- Image #2:
omc_2 = [ -2.047134e+00 ; -1.970877e+00 ; 5.573208e-01 ];
Tc_2  = [ 1.717695e+01 ; -9.990689e+01 ; 8.846106e+02 ];
omc_error_2 = [ 6.520831e-03 ; 5.348985e-03 ; 1.174509e-02 ];
Tc_error_2  = [ 5.628776e+00 ; 7.665103e+00 ; 4.774158e+00 ];

%-- Image #3:
omc_3 = [ 1.980959e+00 ; 1.811145e+00 ; 2.623104e-01 ];
Tc_3  = [ -5.405246e+01 ; -8.453331e+01 ; 9.280764e+02 ];
omc_error_3 = [ 7.774540e-03 ; 4.478320e-03 ; 1.019055e-02 ];
Tc_error_3  = [ 5.937338e+00 ; 8.056072e+00 ; 5.126195e+00 ];

%-- Image #4:
omc_4 = [ 1.548050e+00 ; 1.654342e+00 ; 8.984298e-01 ];
Tc_4  = [ -9.074522e+01 ; -1.174654e+02 ; 8.864388e+02 ];
omc_error_4 = [ 7.679517e-03 ; 4.496738e-03 ; 9.023850e-03 ];
Tc_error_4  = [ 5.704717e+00 ; 7.742709e+00 ; 5.392106e+00 ];

%-- Image #5:
omc_5 = [ 1.850785e+00 ; 1.913979e+00 ; 5.474480e-01 ];
Tc_5  = [ -1.501340e+02 ; -1.135989e+02 ; 1.057749e+03 ];
omc_error_5 = [ 7.364477e-03 ; 4.639795e-03 ; 1.053651e-02 ];
Tc_error_5  = [ 6.831938e+00 ; 9.261273e+00 ; 6.147147e+00 ];

%-- Image #6:
omc_6 = [ 1.781922e+00 ; 1.926356e+00 ; 5.892153e-01 ];
Tc_6  = [ -3.890395e+02 ; -2.013179e+02 ; 1.046128e+03 ];
omc_error_6 = [ 6.597896e-03 ; 5.754758e-03 ; 1.090748e-02 ];
Tc_error_6  = [ 7.138842e+00 ; 9.529995e+00 ; 6.843010e+00 ];

%-- Image #7:
omc_7 = [ 2.074813e+00 ; 2.065502e+00 ; 3.563306e-01 ];
Tc_7  = [ 1.818935e+02 ; -4.236115e+01 ; 1.136321e+03 ];
omc_error_7 = [ 9.032026e-03 ; 4.749415e-03 ; 1.270982e-02 ];
Tc_error_7  = [ 7.323405e+00 ; 9.953395e+00 ; 6.611042e+00 ];

%-- Image #8:
omc_8 = [ 1.985199e+00 ; 2.061346e+00 ; 4.623549e-01 ];
Tc_8  = [ 1.096115e+02 ; -2.779937e+02 ; 1.110490e+03 ];
omc_error_8 = [ 8.109264e-03 ; 5.434055e-03 ; 1.227949e-02 ];
Tc_error_8  = [ 7.190745e+00 ; 9.671494e+00 ; 7.326160e+00 ];

%-- Image #9:
omc_9 = [ 2.035959e+00 ; 2.011172e+00 ; 4.753620e-01 ];
Tc_9  = [ -1.372442e+02 ; -3.081647e+02 ; 1.108379e+03 ];
omc_error_9 = [ 7.127472e-03 ; 5.824998e-03 ; 1.280081e-02 ];
Tc_error_9  = [ 7.291716e+00 ; 9.681287e+00 ; 7.461046e+00 ];

%-- Image #10:
omc_10 = [ 1.744337e+00 ; 2.075490e+00 ; -1.011649e+00 ];
Tc_10  = [ 4.469644e+00 ; -4.719473e+01 ; 1.152852e+03 ];
omc_error_10 = [ 4.609670e-03 ; 8.338173e-03 ; 9.707429e-03 ];
Tc_error_10  = [ 7.349266e+00 ; 9.989990e+00 ; 5.850057e+00 ];

%-- Image #11:
omc_11 = [ 1.778340e+00 ; 2.102687e+00 ; -1.407703e+00 ];
Tc_11  = [ 4.400108e+01 ; -2.032794e+01 ; 1.066678e+03 ];
omc_error_11 = [ 3.785009e-03 ; 9.557700e-03 ; 9.792424e-03 ];
Tc_error_11  = [ 6.805534e+00 ; 9.256248e+00 ; 5.128029e+00 ];

%-- Image #12:
omc_12 = [ 1.871962e+00 ; 2.128158e+00 ; -9.493607e-01 ];
Tc_12  = [ -8.806040e+01 ; -3.935699e+01 ; 8.902144e+02 ];
omc_error_12 = [ 3.780628e-03 ; 8.194234e-03 ; 1.022566e-02 ];
Tc_error_12  = [ 5.645145e+00 ; 7.739596e+00 ; 4.434196e+00 ];

%-- Image #13:
omc_13 = [ 1.615393e+00 ; 1.632391e+00 ; 6.968341e-01 ];
Tc_13  = [ -1.943696e+02 ; -1.223612e+02 ; 7.721125e+02 ];
omc_error_13 = [ 7.134063e-03 ; 4.214517e-03 ; 8.621487e-03 ];
Tc_error_13  = [ 5.077760e+00 ; 6.849176e+00 ; 4.861006e+00 ];

%-- Image #14:
omc_14 = [ 1.650184e+00 ; 1.688538e+00 ; 7.797988e-01 ];
Tc_14  = [ -2.507880e+02 ; -8.496921e+01 ; 9.175718e+02 ];
omc_error_14 = [ 7.206665e-03 ; 4.131433e-03 ; 9.064667e-03 ];
Tc_error_14  = [ 6.052158e+00 ; 8.182442e+00 ; 5.749742e+00 ];

%-- Image #15:
omc_15 = [ 1.435472e+00 ; 1.310287e+00 ; 1.027999e+00 ];
Tc_15  = [ -2.547416e+02 ; -1.370151e+02 ; 8.753476e+02 ];
omc_error_15 = [ 7.642984e-03 ; 4.951728e-03 ; 7.903047e-03 ];
Tc_error_15  = [ 5.840759e+00 ; 7.822637e+00 ; 5.813779e+00 ];

%-- Image #16:
omc_16 = [ 1.669476e+00 ; 1.570706e+00 ; 8.033944e-01 ];
Tc_16  = [ -2.404999e+02 ; -1.677423e+02 ; 9.626988e+02 ];
omc_error_16 = [ 7.293274e-03 ; 4.404117e-03 ; 8.857414e-03 ];
Tc_error_16  = [ 6.368496e+00 ; 8.538311e+00 ; 6.150428e+00 ];

%-- Image #17:
omc_17 = [ 2.084430e+00 ; 1.962744e+00 ; 2.418798e-01 ];
Tc_17  = [ -6.474779e+01 ; -2.154956e+02 ; 1.083865e+03 ];
omc_error_17 = [ 7.687307e-03 ; 5.629971e-03 ; 1.250544e-02 ];
Tc_error_17  = [ 6.995879e+00 ; 9.422947e+00 ; 6.476980e+00 ];

%-- Image #18:
omc_18 = [ 2.081298e+00 ; 1.972568e+00 ; 2.263448e-01 ];
Tc_18  = [ -1.162597e+02 ; -2.147297e+02 ; 1.078310e+03 ];
omc_error_18 = [ 7.400046e-03 ; 5.807234e-03 ; 1.284763e-02 ];
Tc_error_18  = [ 6.987961e+00 ; 9.395107e+00 ; 6.478762e+00 ];

%-- Image #19:
omc_19 = [ -1.985195e+00 ; -1.963755e+00 ; 6.736219e-01 ];
Tc_19  = [ 1.426009e+02 ; -1.575467e+02 ; 1.061514e+03 ];
omc_error_19 = [ 7.305911e-03 ; 5.867516e-03 ; 1.140486e-02 ];
Tc_error_19  = [ 6.831758e+00 ; 9.245099e+00 ; 5.959413e+00 ];

