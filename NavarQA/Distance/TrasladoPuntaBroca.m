clear;
clc;
%Punta POINTER-------%%%
pp=[5.02503;-134.937;1150.28];
%esferas BROCA------%
eb=[-230.0289459228516, -189.7269439697266, -318.3638000488281;
 137.0616912841797, 108.2502746582031, 199.3643646240234;
 1159.516723632813, 1156.42626953125, 1167.681274414063];

%Sacar CentroideBroca---------%
cb=eb(:,2);

%diferencia centroideBroca a punta pointer-----%
df = pp-cb;

%punta broca y punta pointer en metros(deben ser iguales)----%
pb=(cb+df)/1000;
pp2=pp/1000;

%%lo que se suma será el arreglo df en metros en NAVAR%%%
df2 = df/1000;
