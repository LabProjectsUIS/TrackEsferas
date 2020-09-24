% Intrinsic and Extrinsic Camera Parameters
%
% This script file can be directly executed under Matlab to recover the camera intrinsic and extrinsic parameters.
% IMPORTANT: This file contains neither the structure of the calibration objects nor the image coordinates of the calibration points.
%            All those complementary variables are saved in the complete matlab data file Calib_Results.mat.
% For more information regarding the calibration model visit http://www.vision.caltech.edu/bouguetj/calib_doc/


%-- Focal length:
fc = [ 1233.063563886874600 ; 1230.271791069598100 ];

%-- Principal point:
cc = [ 630.497927535984220 ; 514.595707991476160 ];

%-- Skew coefficient:
alpha_c = 0.000000000000000;

%-- Distortion coefficients:
kc = [ -0.117026934424989 ; 0.202831334322846 ; -0.000909590929941 ; -0.000789443200537 ; 0.000000000000000 ];

%-- Focal length uncertainty:
fc_error = [ 6.711062156305781 ; 6.359988729529388 ];

%-- Principal point uncertainty:
cc_error = [ 7.564644597082810 ; 9.435496257597453 ];

%-- Skew coefficient uncertainty:
alpha_c_error = 0.000000000000000;

%-- Distortion coefficients uncertainty:
kc_error = [ 0.015248898885475 ; 0.074462288792945 ; 0.001868907112871 ; 0.001605761195824 ; 0.000000000000000 ];

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
omc_1 = [ 2.125745e+00 ; 2.293171e+00 ; -1.123828e-01 ];
Tc_1  = [ -1.207220e+02 ; -1.906249e+02 ; 6.853864e+02 ];
omc_error_1 = [ 4.790236e-03 ; 5.933183e-03 ; 1.164129e-02 ];
Tc_error_1  = [ 4.251026e+00 ; 5.290331e+00 ; 4.402053e+00 ];

%-- Image #2:
omc_2 = [ -1.860361e+00 ; -1.830499e+00 ; 7.498472e-01 ];
Tc_2  = [ -2.293725e-01 ; -1.203980e+02 ; 8.795953e+02 ];
omc_error_2 = [ 6.115995e-03 ; 4.260432e-03 ; 9.595285e-03 ];
Tc_error_2  = [ 5.399159e+00 ; 6.728755e+00 ; 4.650738e+00 ];

%-- Image #3:
omc_3 = [ 2.101603e+00 ; 1.970875e+00 ; 3.215237e-02 ];
Tc_3  = [ -5.903878e+01 ; -1.065379e+02 ; 9.398601e+02 ];
omc_error_3 = [ 7.282670e-03 ; 5.451895e-03 ; 1.139150e-02 ];
Tc_error_3  = [ 5.777877e+00 ; 7.197019e+00 ; 5.302227e+00 ];

%-- Image #4:
omc_4 = [ 1.728467e+00 ; 1.829273e+00 ; 7.504303e-01 ];
Tc_4  = [ -1.046920e+02 ; -1.390269e+02 ; 9.076922e+02 ];
omc_error_4 = [ 6.747911e-03 ; 4.288936e-03 ; 9.318562e-03 ];
Tc_error_4  = [ 5.603279e+00 ; 6.993286e+00 ; 5.648130e+00 ];

%-- Image #5:
omc_5 = [ 2.006989e+00 ; 2.077863e+00 ; 3.518604e-01 ];
Tc_5  = [ -1.202141e+02 ; -1.392798e+02 ; 1.088026e+03 ];
omc_error_5 = [ 7.299788e-03 ; 5.880694e-03 ; 1.239260e-02 ];
Tc_error_5  = [ 6.715908e+00 ; 8.376942e+00 ; 6.490537e+00 ];

%-- Image #6:
omc_6 = [ 1.935871e+00 ; 2.093561e+00 ; 4.035182e-01 ];
Tc_6  = [ -3.539108e+02 ; -2.296913e+02 ; 1.133744e+03 ];
omc_error_6 = [ 7.588317e-03 ; 8.738022e-03 ; 1.598909e-02 ];
Tc_error_6  = [ 7.296169e+00 ; 8.976973e+00 ; 7.465028e+00 ];

%-- Image #7:
omc_7 = [ -2.229534e+00 ; -2.209507e+00 ; -1.239752e-01 ];
Tc_7  = [ 2.202302e+02 ; -6.670264e+01 ; 1.082696e+03 ];
omc_error_7 = [ 5.644544e-03 ; 9.171900e-03 ; 1.513716e-02 ];
Tc_error_7  = [ 6.786368e+00 ; 8.430066e+00 ; 6.581892e+00 ];

%-- Image #8:
omc_8 = [ 2.146105e+00 ; 2.212121e+00 ; 2.523123e-01 ];
Tc_8  = [ 1.447252e+02 ; -3.023052e+02 ; 1.069823e+03 ];
omc_error_8 = [ 8.009420e-03 ; 6.430842e-03 ; 1.376535e-02 ];
Tc_error_8  = [ 6.751042e+00 ; 8.271621e+00 ; 7.182732e+00 ];

%-- Image #9:
omc_9 = [ 2.195824e+00 ; 2.156299e+00 ; 2.681462e-01 ];
Tc_9  = [ -9.439153e+01 ; -3.344420e+02 ; 1.127013e+03 ];
omc_error_9 = [ 8.094765e-03 ; 8.270753e-03 ; 1.774925e-02 ];
Tc_error_9  = [ 7.080882e+00 ; 8.682450e+00 ; 7.735917e+00 ];

%-- Image #10:
omc_10 = [ 1.695614e+00 ; 2.243850e+00 ; -1.270518e+00 ];
Tc_10  = [ 5.318203e+01 ; -7.337070e+01 ; 1.143102e+03 ];
omc_error_10 = [ 3.449886e-03 ; 8.287701e-03 ; 9.764430e-03 ];
Tc_error_10  = [ 7.001902e+00 ; 8.752039e+00 ; 5.759073e+00 ];

%-- Image #11:
omc_11 = [ -1.543271e+00 ; -2.061844e+00 ; 1.557656e+00 ];
Tc_11  = [ 7.035323e+01 ; -4.437058e+01 ; 1.050877e+03 ];
omc_error_11 = [ 7.057595e-03 ; 5.053280e-03 ; 9.810172e-03 ];
Tc_error_11  = [ 6.437085e+00 ; 8.061419e+00 ; 5.034694e+00 ];

%-- Image #12:
omc_12 = [ -1.795077e+00 ; -2.230463e+00 ; 1.194212e+00 ];
Tc_12  = [ -1.007482e+02 ; -6.087737e+01 ; 9.131963e+02 ];
omc_error_12 = [ 6.604545e-03 ; 4.667101e-03 ; 1.073194e-02 ];
Tc_error_12  = [ 5.580570e+00 ; 7.025236e+00 ; 4.567010e+00 ];

%-- Image #13:
omc_13 = [ 1.769457e+00 ; 1.811805e+00 ; 5.313487e-01 ];
Tc_13  = [ -2.327972e+02 ; -1.426784e+02 ; 8.228200e+02 ];
omc_error_13 = [ 6.052756e-03 ; 4.416671e-03 ; 8.962267e-03 ];
Tc_error_13  = [ 5.181978e+00 ; 6.458194e+00 ; 5.316940e+00 ];

%-- Image #14:
omc_14 = [ 1.818167e+00 ; 1.861484e+00 ; 6.143422e-01 ];
Tc_14  = [ -2.521440e+02 ; -1.089510e+02 ; 9.775960e+02 ];
omc_error_14 = [ 6.503890e-03 ; 4.526532e-03 ; 9.687639e-03 ];
Tc_error_14  = [ 6.117404e+00 ; 7.655649e+00 ; 6.239435e+00 ];

%-- Image #15:
omc_15 = [ 1.614757e+00 ; 1.487078e+00 ; 8.883633e-01 ];
Tc_15  = [ -2.660618e+02 ; -1.603023e+02 ; 9.366730e+02 ];
omc_error_15 = [ 6.667040e-03 ; 4.574099e-03 ; 8.248440e-03 ];
Tc_error_15  = [ 5.916732e+00 ; 7.356134e+00 ; 6.270805e+00 ];

%-- Image #16:
omc_16 = [ 1.836366e+00 ; 1.741253e+00 ; 6.360362e-01 ];
Tc_16  = [ -2.307014e+02 ; -1.924523e+02 ; 1.016346e+03 ];
omc_error_16 = [ 6.443429e-03 ; 4.532538e-03 ; 9.459341e-03 ];
Tc_error_16  = [ 6.384339e+00 ; 7.910550e+00 ; 6.548031e+00 ];

%-- Image #17:
omc_17 = [ 2.215773e+00 ; 2.112972e+00 ; 1.366452e-03 ];
Tc_17  = [ -3.068025e+01 ; -2.408883e+02 ; 1.089700e+03 ];
omc_error_17 = [ 8.330704e-03 ; 7.501281e-03 ; 1.587981e-02 ];
Tc_error_17  = [ 6.758336e+00 ; 8.362960e+00 ; 6.599031e+00 ];

%-- Image #18:
omc_18 = [ 2.210862e+00 ; 2.123343e+00 ; -1.168148e-02 ];
Tc_18  = [ -8.203437e+01 ; -2.404466e+02 ; 1.096875e+03 ];
omc_error_18 = [ 8.288307e-03 ; 7.975112e-03 ; 1.678471e-02 ];
Tc_error_18  = [ 6.799044e+00 ; 8.418567e+00 ; 6.693512e+00 ];

%-- Image #19:
omc_19 = [ -1.787263e+00 ; -1.822183e+00 ; 8.595747e-01 ];
Tc_19  = [ 1.650739e+02 ; -1.806591e+02 ; 1.018473e+03 ];
omc_error_19 = [ 6.472656e-03 ; 4.570600e-03 ; 9.428670e-03 ];
Tc_error_19  = [ 6.360658e+00 ; 7.859711e+00 ; 5.749474e+00 ];

