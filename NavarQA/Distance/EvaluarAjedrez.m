clear; clc;
Data = load('EvaluandoTABLERO.txt');

% Separando esferas
%Esfera1= mean(Data(:,1:3));
%Esfera2= mean(Data(:,4:6));
%Esfera3= mean(Data(:,7:9));
%Esfera4= mean(Data(:,10:12));
Punto1=[Data(1:50,1) Data(1:50,2) Data(1:50,3)];
Punto2=[Data(51:100,1) Data(51:100,2) Data(51:100,3)];
Punto3=[Data(101:150,1) Data(101:150,2) Data(101:150,3)];
Punto4=[Data(151:200,1) Data(151:200,2) Data(151:200,3)];
p1=mean(Punto1);
p2=mean(Punto2);
p3=mean(Punto3);
p4=mean(Punto4);

d1= norm(p3 - p1);
d2= norm(p3 - p2);
d3= norm(p3 - p4);