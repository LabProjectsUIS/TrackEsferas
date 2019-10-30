x_Izq_1=zeros(2,1);
x_Der_1=zeros(2,1);

%Punto 1 a analizar de la cámara izquierda.
figure(1)
I=imread('left10.tif');
imshow(I);
[x_Izq_1(1,1), x_Izq_1(2,1)] = getpts(figure(1));

%Punto 1 a analizar de la camara derecha.
figure(2)
D=imread('right10.tif');
imshow(D)
[x_Der_1(1,1), x_Der_1(2,1)] = getpts(figure(2));
[Xc_1_Izq, Xc_1_Der] = stereo_triangulation(x_Izq_1, x_Der_1,om, T, fc_left, cc_left, kc_left, alpha_c_left, fc_right,cc_right, kc_right, alpha_c_right);

x_Izq_2=zeros(2,1);
x_Der_2=zeros(2,1);
%Punto 2 a analizar de la cámara izquierda.
figure(1)
I=imread('left10.tif');
imshow(I)
[x_Izq_2(1,1), x_Izq_2(2,1)] = getpts(figure(1));
%Punto 2 a analizar de la camara derecha
figure(2)
D=imread('right10.tif');
imshow(D)
[x_Der_2(1,1), x_Der_2(2,1)] = getpts(figure(2));
[Xc_2_Izq, Xc_2_Der] = stereo_triangulation(x_Izq_2, x_Der_2,om, T, fc_left, cc_left, kc_left, alpha_c_left, fc_right,cc_right, kc_right, alpha_c_right);
dx2=(Xc_1_Izq(1,1)/10 - Xc_2_Izq(1,1)/10)^2;
dy2=(Xc_1_Izq(2,1)/10 - Xc_2_Izq(2,1)/10)^2;
dz2=(Xc_1_Izq(3,1)/10 - Xc_2_Izq(3,1)/10)^2;
d=sqrt(dx2 + dy2 + dz2);
disp(Xc_2_Izq);
disp('distancia');
disp(d);
disp('centimetros');