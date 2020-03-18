clear; clc;
ref= 20;
data1= importdata('Punto1mil.txt');
data2= importdata('Punto19mil.txt');
data3=importdata('Punto20mil.txt');
data4=importdata('Punto18mil.txt');

x=data1(:,1);
y=data1(:,2);
z=data1(:,3);
x2=data2(:,1);
y2=data2(:,2);
z2=data2(:,3);
x3=data3(:,1);
y3=data3(:,2);
z3=data3(:,3);
x4=data4(:,1);
y4=data4(:,2);
z4=data4(:,3);

figure;
subplot(1,2,1);
scatter3(x,y,z);
title('Punto 1');

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

%Calculando error en distancias
%{
punto2per30der=mean(data2(1:1000));
punto2per30izq=mean(data2(1001:2000));
punto2par30adel=mean(data2(2001:3000));
punto2a90grad=mean(data2(3001:4000));
dataset=[punto2per30der;punto2per30izq;punto2par30adel];
calculateerror(punto2a90grad,dataset,result);
%}