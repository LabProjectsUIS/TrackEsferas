# -*- encoding: utf-8 -*-

from __future__ import division
import collections
import numpy

def stereo_triangulation(xL, xR, om, T, fc_left, 
                cc_left, kc_left, alpha_c_left,
                fc_right, cc_right, kc_right, 
                alpha_c_right):
    """triangulate a position using data from two cameras"""

    N = xL.shape[1]

    om = om.reshape(3, 1)
    T = T.reshape(3, 1)
    fc_left = fc_left.reshape(2, 1)
    cc_left = cc_left.reshape(2, 1)
    kc_left = kc_left.reshape(5, 1)
    fc_right = fc_right.reshape(2, 1)
    cc_right = cc_right.reshape(2, 1)
    kc_right = kc_right.reshape(5, 1)

    xL_temp = numpy.ones((3, N))
    xR_temp = numpy.ones((3, N))

    xL_temp[:2] = pixel_normalization(xL, fc_left, 
                cc_left, kc_left, alpha_c_left)

    xR_temp[:2] = pixel_normalization(xR, fc_right, 
                cc_right, kc_right, alpha_c_right)

    R = get_rotation(om)

    u = R.dot(xL_temp)

    left_dot_left = numpy.sum(xL_temp ** 2, 0)
    right_dot_right = numpy.sum(xR_temp ** 2, 0)

    T_vect = numpy.tile(T, (1, N))

    DD = left_dot_left * right_dot_right - dot_product(u, xR_temp) ** 2

    u_dot_T = dot_product(u, T_vect)
    right_dot_T = dot_product(xR_temp, T_vect)
    u_dot_right = dot_product(u, xR_temp)

    z_left = (u_dot_right * right_dot_T - right_dot_right * u_dot_T) / DD
    z_right = (left_dot_left * right_dot_T - u_dot_T * u_dot_right) / DD

    data1 = xL_temp * numpy.tile(z_left, (3, 1))
    data2 = R.T.dot(xR_temp * numpy.tile(z_right, (3, 1)) - T_vect)

    xL_out = (data1 + data2) / 2
    xR_out = R.dot(xL_out) + T_vect

    return xL_out, xR_out
    
    

def pixel_normalization(f_mat, f_len, p_point, dist_coeff, skew_coeff):
    """normalize pixels"""

    out_temp = (f_mat - p_point) / f_len

    out_temp[0] -= skew_coeff * out_temp[1]

    if numpy.linalg.norm(dist_coeff):
        return oulu_distortion(out_temp, dist_coeff)

    return out_temp


def oulu_distortion(data, dist_coeff):
    """Apply Oulu's distortion model"""

    coeff = numpy.array([1, dist_coeff[0], dist_coeff[1], dist_coeff[-1]])
    p = dist_coeff[2:4][::-1]

    data_temp = data.copy()


    for i in xrange(19):
        r_2 = sum(data_temp ** 2) 
        coeff_radial = numpy.array([sum(c * r_2 ** n for n, c in enumerate(coeff))] * 2)
        delta = p * r_2 + 2 * numpy.sum([p * data_temp * d for d in data_temp], 1)
        data_temp = (data - delta) / coeff_radial

    return data_temp


def rotate(data, d):
    """move the last element to the first position"""

    data.rotate(d)

    return numpy.asarray(data)

def get_rotation(data):
    """calculate rotation matrix from rotation vector"""

    n, m = data.shape
    theta = numpy.linalg.norm(data, 2)
    omega = data / theta
    omega_temp = collections.deque(omega[::-1])
    omega_temp.rotate(2)
    cos_t = numpy.cos(theta)
    sin_t = numpy.sin(theta)
    omega_d = omega.dot(omega.T)

#    R_to_1 = numpy.zeros((9, 21))
#    R_to_1[::4, 0] = 1
#    R_to_1[:, 1] = R_fac_1.reshape(1,9)
#    R_to_1[:, 2] = omega_d.reshape(1,9)
#    R_to_1[:, 3:12] = numpy.eye(9) * sin_t
#    R_to_1[:, 12:] = numpy.eye(9) * (1 - cos_t)

#    R_to_2 = numpy.zeros((21, 4))
#    R_to_2[0, 3] = -sin_t
#    R_to_2[1, 3] = cos_t
#    R_to_2[2, 3] = sin_t
#    R_to_2[4:7, 1:3] = [[0, 1], [-1, 0], [0, -1]]
#    R_to_2[8:11, :2] = R_to_2[4:7, 1:3][:, ::-1]
#    for i in xrange(3):
#        R_to_2[12 + 3 * i:15 + 3 * i, :3] = numpy.eye(3) * omega[i]
#        R_to_2[12 + 3 * i:15 + 3 * i, i][:, numpy.newaxis] += omega

    i = 0
    R_fac_gen = lambda x, d, i=i: [rotate(x, d)[:] for i in xrange(n)]
    R_fac_1_i = numpy.array(R_fac_gen(omega_temp, -1))
    R_fac_1_s1d = collections.deque([-1, 1, 0])
    R_fac_1_s2d = numpy.array(R_fac_gen(R_fac_1_s1d, 1))
    R_fac_1 = R_fac_1_s2d * R_fac_1_i.reshape(3,3)

    R = (numpy.eye(n) * cos_t + 
        R_fac_1 * sin_t +
        omega_d * (1 - cos_t))

    return R

def dot_product(x, y):
    """Calculate dot product between two n x 1 or 1 x n vectors"""

    if x.shape != y.shape:
        x = x.reshape(x.shape[::-1])
        if x.shape != y.shape:
            print "error"
            print("x", x)
            print(y)
            return 0

    return numpy.sum(x * y, 0)

if __name__ == "__main__":

    print("Hola!")