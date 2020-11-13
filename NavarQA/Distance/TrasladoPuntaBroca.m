clear;
clc;
%Punta POINTER-------%%%
pp=[-98.6979;28.3691;1171.02];
%esferas BROCA------%
eb=[36.62528228759766   89.72779846191406   12.53241062164307;
 -63.83302307128906	-155.80419921875	-21.69049644470215;
 1243.23876953125	1269.800537109375	1232.235717773438];

%Sacar CentroideBroca---------%
cb=eb(:,2);

%diferencia centroideBroca a punta pointer-----%
df = pp-cb;

%punta broca y punta pointer en metros(deben ser iguales)----%
pb=(cb+df)/1000;
pp2=pp/1000;

%%lo que se suma será el arreglo df en metros en NAVAR%%%
df2 = df/1000;
