x_Izq_1=zeros(2,1);
x_Der_1=zeros(2,1);

%Punto 1 a analizar de la cámara izquierda.
figure(1)
I=imread('Left10.tif');
imshow(I);
x_Izq_1(1,1)=369;
x_Izq_1(2,1)=340;

%Punto 1 a analizar de la camara derecha.
figure(2)
D=imread('Right10.tif');
imshow(D)
x_Der_1(1,1)=653;
x_Der_1(2,1)=271;
    
[Xc_1_Izq, Xc_1_Der] = stereo_triangulation(x_Izq_1, x_Der_1,om, T, fc_left, cc_left, kc_left, alpha_c_left, fc_right,cc_right, kc_right, alpha_c_right);
