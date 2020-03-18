clear; clc;
ref= 20;
data1= importdata('Punto1mil.txt');
data2= importdata('Punto19mil.txt');
data3=importdata('Punto20mil.txt');
data4=importdata('Punto18mil.txt');

%Todos a la perpendicular a la derecha
x=data1(1:1000,1);
y=data1(1:1000,2);
z=data1(1:1000,3);
x2=data2(1:1000,1);
y2=data2(1:1000,2);
z2=data2(1:1000,3);
x4=data4(1:1000,1);
y4=data4(1:1000,2);
z4=data4(1:1000,3);

datasetx=[x;x2;x4];
datasety=[y;y2;y4];
datasetz=[z;z2;z4];

figure;
hold on
scatter3(datasetx(1:1000),datasety(1:1000),datasetz(1:1000),'r');
scatter3(datasetx(1001:2000),datasety(1001:2000),datasetz(1001:2000),'b');
scatter3(datasetx(2001:3000),datasety(2001:3000),datasetz(2001:3000),'g');
title('Perpendiculares a 30° a la derecha - Puntos 1, 18 y 19');
legend({'Punto 1','Punto19','Punto 18'},'Location','northwest');
hold off

%Todos a la perpendicular a la izquierda

x2=data1(1001:2000,1);
y2=data1(1001:2000,1);
z2=data1(1001:2000,1);
x22=data2(1001:2000,1);
y22=data2(1001:2000,1);
z22=data2(1001:2000,1);
x42=data4(1001:2000,1);
y42=data4(1001:2000,1);
z42=data4(1001:2000,1);

datasetx2=[x2;x22;x42];
datasety2=[y22;y22;y42];
datasetz2=[z2;z22;z42];

figure(2);
hold on
scatter3(datasetx2(1:1000),datasety2(1:1000),datasetz2(1:1000),'r');
scatter3(datasetx2(1001:2000),datasety2(1001:2000),datasetz2(1001:2000),'b');
scatter3(datasetx2(2001:3000),datasety2(2001:3000),datasetz2(2001:3000),'g');
title('Perpendiculares a 30° a la izquierda - Puntos 1, 18 y 19');
legend('Punto 1','Punto19','Punto 18')
hold off

%Todos a la paralelo adelante
x3=data1(2001:3000,1);
y3=data1(2001:3000,1);
z3=data1(2001:3000,1);
x23=data2(2001:3000,1);
y23=data2(2001:3000,1);
z23=data2(2001:3000,1);
x43=data4(2001:3000,1);
y43=data4(2001:3000,1);
z43=data4(2001:3000,1);

datasetx3=[x3;x23;x43];
datasety3=[y3;y23;y43];
datasetz3=[z3;z23;z43];

figure;
hold on
scatter3(datasetx3(1:1000),datasety3(1:1000),datasetx3(1:1000),'r');
scatter3(datasetx3(1001:2000),datasety3(1001:2000),datasetx3(1001:2000),'b');
scatter3(datasetx3(2001:3000),datasety3(2001:3000),datasetx3(2001:3000),'g');

title('Paralelos a 30° a la adelante - Puntos 1, 18 y 19');
legend('Punto 1','Punto19','Punto 18')
hold off


%Todos paralelo atras
x4=data1(3001:4000,1);
y4=data1(3001:4000,1);
z4=data1(3001:4000,1);


figure;
scatter3(x4,y4,z4);
title('Paralelos a 30° atras - Punto 1');


%{
subplot(1,2,2);
scatter3(x2,y2,z2);
title('Punto 19(extremo izquierdo)');

figure;
subplot(1,2,1);
scatter3(x3,y3,z3);
title('Punto 20(punto central)');

subplot(1,2,2);
scatter3(x4,y4,z4);
title('Punto 18(extremo derecho)');
%}
%Calculando error en distancias
%{
punto2per30der=mean(data2(1:1000));
punto2per30izq=mean(data2(1001:2000));
punto2par30adel=mean(data2(2001:3000));
punto2a90grad=mean(data2(3001:4000));
dataset=[punto2per30der;punto2per30izq;punto2par30adel];
calculateerror(punto2a90grad,dataset,result);
%}