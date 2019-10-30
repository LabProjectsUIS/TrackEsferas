# -*- encoding: utf-8 -*-

import numpy
from triangulation import stereo_triangulation

def bilineal(I, x1, x2, y1, y2):
    """Interpolación bilineal"""

    nr = I.shape[0]

    if x1 > x2:
        x1, x2 = x2, x1
        y1, y2 = y2, y1

    x21 = x2 - x1
    y21 = y2 - y1
    N = numpy.ceil(numpy.sqrt(x21*x21 + y21*y21))
    Dx = x21/N
    zn = numpy.linspace(0, N, N+1)
    xi = x1 + Dx*zn
    yi = y1 + Dx*zn*y21/x21
    x0 = numpy.floor(xi).astype(int)
    y0 = numpy.floor(yi).astype(int)

    alpha_x = xi - x0
    alpha_y = yi - y0

    a1 = (1 - alpha_y) * (1 - alpha_x)
    a2 = (1 - alpha_y) * alpha_x
    a3 = alpha_y * (1 - alpha_x)
    a4 = alpha_y * alpha_x

#    ind_lu = (x0 - 1) * nr + y0
#    ind_ru = x0 * nr + y0
#    ind_ld = (x0 - 1) * nr + y0 + 1
#    ind_rd = x0 * nr + y0 + 1

#    Ai = a1 * I[ind_lu] + a2 * I[ind_ru] + a3 * I[ind_ld] + a4 * I[Ind_rd]
    Ai = a1 * I[y0-1, x0-1] + a2 * I[y0-1, x0] + a3 * I[y0, x0-1] + a4 * I[y0, x0]

    return xi, yi, Ai

def datos_broca(I, x1, x2, y1, y2, param_broca):
    """Extrae datos de la broca"""

    THR = param_broca[1]
    NCeros2 = param_broca[2]
    Paso = param_broca[3:]
    # Interpolando
    xm = (x1+x2)/2
    ym = (y1+y2)/2
    [xt, yt, At] = bilineal(I, x1, x2, y1, y2)
    
    # Buscando punto medio
    dist = numpy.sqrt( (xt-xm)**2 + (yt-ym)**2 )
    ind = numpy.argsort(dist)
    ind0 = ind[0]
    dist = numpy.sqrt( (xt-xt[0])**2 + (yt-yt[0])**2 )
    # Busqueda de la fase
    g = 0
    for Dx in Paso:
        val = numpy.round(2*Dx)
        ex = numpy.linspace(-val, val, 2*val + 1)
        val1 = 1/numpy.sqrt(numpy.pi*Dx)
        val2 = 1/(2*Dx*Dx)
        w = val1 * numpy.exp(-val2*ex**2)
        wxt = 2 * numpy.pi / Dx
        wavex = numpy.exp(1j * ex * wxt)
        sf = numpy.convolve(At, w*wavex, 'same')
        sf *= (numpy.abs(sf) >= THR)
        g += numpy.convolve(sf, w*wavex, 'same')
    
    phase = numpy.arctan2(g.imag, g.real)
    val1 = numpy.unwrap(phase[:ind0+1][::-1])[::-1]
    val2 = numpy.unwrap(phase[ind0:])    
    phaseC = numpy.hstack([val1[:-1], val2])
    # figure(2)hold on
    # plot(dist,phaseC,'r')
    # hold off

    #Interpolación
    FaseT = numpy.linspace(-NCeros2, NCeros2, 2*NCeros2 + 1) * 2 * numpy.pi
    val = numpy.vstack([phaseC - i for i in FaseT])
    ind = numpy.argsort(numpy.abs(val), 1)
    ind12 = ind[:, :2]
    DistT = dist[ind12[:, 0]] + (FaseT - phaseC[ind12[:, 0]]) * (dist[ind12[:, 1]]-dist[ind12[:, 0]])/(phaseC[ind12[:, 1]]-phaseC[ind12[:, 0]])
    # figure(2)hold on
    # plot(DistT,zeros(size(DistT)),'r*')
    # hold off
    POSX = xt[0] + DistT*numpy.cos(numpy.arctan((yt[-1] - yt[0])/(xt[-1] - xt[0])))
    POSY = yt[0] + DistT*numpy.sin(numpy.arctan((yt[-1] - yt[0])/(xt[-1] - xt[0])))

    return POSX, POSY


def orientacion_P3D(I_IZQ, I_DER, POS_IZQ, POS_DER, param_broca, param_stereo):

    ## PARAMETROS

    print("pos")
    print(POS_IZQ, POS_DER)
    param_broca = numpy.hstack([param_broca[:3], numpy.linspace(param_broca[3], param_broca[4], param_broca[5])])
    I_IZQ = numpy.array(I_IZQ)
    I_DER = numpy.array(I_DER)
    POS_IZQ = numpy.array(POS_IZQ)
    POS_DER = numpy.array(POS_DER)
    param_stereo = numpy.array(param_stereo)

    #PARAMETROS DE LA BROCA
    dist_punta = param_broca[0]
    NCeros2 = param_broca[2]
    # Parametros Intrinsecos y Extrinsecos del sistema estéreo
    fc_left = param_stereo[:2]
    cc_left = param_stereo[2:4]
    kc_left = param_stereo[4:9]
    alpha_c_left = param_stereo[9]
    fc_right = param_stereo[10:12]
    cc_right = param_stereo[12:14]
    kc_right = param_stereo[14:19]
    alpha_c_right = param_stereo[19]
    om = param_stereo[20:23]
    T = param_stereo[23:26]

    ## POSICIONES EN EL ESPACIO 3D MÁXIMOS DE INTENSIDAD DEL PATRÓN
    POSx1_DER = POS_DER[0, 0]
    POSy1_DER = POS_DER[1, 0]    
    POSx2_DER = POS_DER[0, 1]
    POSy2_DER = POS_DER[1, 1]
    POSX_DER, POSY_DER = datos_broca(I_DER, POSx1_DER, POSx2_DER, POSy1_DER, POSy2_DER, param_broca)
    print("pos der x1 x2 y1 y2")
    print(POSx1_DER, POSx2_DER, POSy1_DER, POSy2_DER)
    if  ((POSX_DER[0] - POSx2_DER)**2 + (POSY_DER[1] - POSy2_DER)**2) >  ((POSX_DER[-1] - POSx2_DER)**2 + (POSY_DER[-1] - POSy2_DER)**2):
        POSX_DER = numpy.flipud(POSX_DER).T
        POSY_DER = numpy.flipud(POSY_DER).T
    
    # 
    POSx1_IZQ = POS_IZQ[0, 0]
    POSy1_IZQ = POS_IZQ[1, 0]    
    POSx2_IZQ = POS_IZQ[0, 1]
    POSy2_IZQ = POS_IZQ[1, 1]    
    [POSX_IZQ, POSY_IZQ] = datos_broca(I_IZQ, POSx1_IZQ, POSx2_IZQ, POSy1_IZQ, POSy2_IZQ, param_broca)
    print("pos izq x1 x2 y1 y2")
    print(POSx1_IZQ, POSx2_IZQ, POSy1_IZQ, POSy2_IZQ)
    if ((POSX_IZQ[0] - POSx2_IZQ)**2 + (POSY_IZQ[0] - POSy2_IZQ)**2) >  ((POSX_IZQ[-1] - POSx2_IZQ)**2 + (POSY_IZQ[-1] - POSy2_IZQ)**2):
        POSX_IZQ = numpy.flipud(POSX_IZQ).T
        POSY_IZQ = numpy.flipud(POSY_IZQ).T
    
    # coordenadas 3D
    xL = numpy.vstack([POSX_IZQ, POSY_IZQ])
    xR = numpy.vstack([POSX_DER, POSY_DER])
    [X3D_IZQ, _] = stereo_triangulation(xL, xR, om, T, fc_left, cc_left, kc_left, alpha_c_left, fc_right, cc_right, kc_right, alpha_c_right)

    # Ajuste de la linea en 3D
    X_Origen = X3D_IZQ[:, int(NCeros2)]
    XMed_IZQ = numpy.mean(X3D_IZQ, 1)
    cov = numpy.vstack([XMed_IZQ - i for i in X3D_IZQ.T])
    COV = cov.T.dot(cov) / X3D_IZQ.shape[1]
    [D, V] = numpy.linalg.eig(COV)
    ind = numpy.argmax(D)
    AUnit = V[:, ind]
    X_Punta = X_Origen + dist_punta*AUnit
    drill = numpy.array([X_Origen, X_Punta])
    print("drill")
    print(drill)

    return drill