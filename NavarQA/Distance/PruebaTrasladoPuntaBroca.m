clear;
clc;
%Punta POINTER-------%%%
pp=[-185.418740;167.191207;1.09191537];
%esferas BROCA------%
eb=[-236.1246948242188, -254.1866455078125, -228.0478515625;
 -72.33403778076172, -180.6887969970703, -23.18478393554688;
 1139.377807617188, 1142.525756835938, 1137.43212890625];

%Sacar CentroideBroca---------%
cb=eb(:,2);

%%Traslado punta------%
df = [194.751973969727;-243.187274658203;-6.14626953125003];

%evaluar traslado----%
pb = cb+df;

%punta broca y punta pointer en metros(deben ser iguales)----%
pb2=pb/1000;
pp2=pp/1000;
error=mean(pb2-pp2);