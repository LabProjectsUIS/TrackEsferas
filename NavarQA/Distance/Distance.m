clear; clc;
dat = importdata('C:\Users\preci\OneDrive\Documentos\CalibMotive\Takes\DatosInstrumentos.csv');

% Separando esferas
%{
Esfera1= mean(Data(:,1:3));
Esfera2= mean(Data(:,4:6));
Esfera3= mean(Data(:,7:9));
Esfera4= mean(Data(:,10:12));

d1= norm(Esfera1 - Esfera2);
d2= norm(Esfera1 - Esfera3);
d3= norm(Esfera1 - Esfera4);
d4= norm(Esfera2 - Esfera3);
d5= norm(Esfera2 - Esfera4);
d6= norm(Esfera3 - Esfera4);
%}