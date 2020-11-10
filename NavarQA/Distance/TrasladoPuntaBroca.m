clear;
clc;
%Punta POINTER-------%%%
pp=[-96.0188;-150.777;1060.57];
%esferas BROCA------%
eb=[83.03426361083984, 156.4462280273438, 49.34378051757813;
 -57.21246337890625, -68.66877746582031, -51.95152282714844;
 1298.951293945313, 1379.368774414063, 1262.78759765625];

%Sacar CentroideBroca---------%
cb=eb(:,2);

%diferencia centroideBroca a punta pointer-----%
df = pp-cb;

%punta broca y punta pointer en metros(deben ser iguales)----%
pb=(cb+df)/1000;
pp2=pp/1000;

%%lo que se suma será el arreglo df en metros en NAVAR%%%
df2 = df/1000;
