clear; clc;
clear; clc;
ref = input('punto a usar como referencia\n');
PR=importdata('PR.txt');
%Punto 1 medias
par1 = mean(importdata('p1parAdel.txt'));
par2 = mean(importdata('p1parAtras.txt'));
per1 = mean(importdata('p1perDer.txt'));
per2 = mean(importdata('p1perIzq.txt'));
%centro=mean(importdata('p1a90.txt'));

%Genero dataset
dataset=[par1;par2;per1;per2];

%Punto 2 medias
par12 = mean(importdata('p2parAdel.txt'));
par22 = mean(importdata('p2parAtras.txt'));
per12 = mean(importdata('p2perDer.txt'));
per22 = mean(importdata('p2perIzq.txt'));
%centro2=mean(importdata('p2a90.txt'));

%Genero dataset
dataset2=[par12;par22;per12;per22];

%Juntando datasets para comparar
dataset3=[par1;par12];
dataset4=[par2;par22];
dataset5=[per1;per12];
dataset6=[per2;per22];

%Calculando errores
n = 2; 
rep = repmat(dataset3(ref, :), n, 1);
temp_1 = dataset3 - rep;
dist_1 = sqrt(sum(abs(dataset3).^2, 2));

PR =PR((1:2),:);
repmat_ref = repmat(PR(ref, :), n, 1);
temp_ref = PR - repmat_ref;
dist_ref = sqrt(sum(abs(temp_ref).^2, 2));
error_abs_1 = abs(dist_1 - dist_ref);



%% Creating empty figures
h1 = figure(1); hold on;
title('Error estándar - Phantom - Pointer');
%h2 = figure(2); hold on;
%title('Error cuadrático - 15 puntos');
%h3 = figure(3); hold on;
%title('Error cuadrático - 30 puntos');


plot(1:27,error_abs_1(1:27), 'r.'); %% plot puntos error en rojo
%plot(28:35,error_abs_1(28:35),'b.');
%plot(36:40,error_abs_1(36:40),'g.');
hline_1 = refline(0, media_1);
hline_1.Color = 'r';
%hline_b = refline(0, 0);
%hline_b.Color = 'k';
hline_1_1u = refline(0, media_1 + desviacion_1);
hline_1_1u.Color = 'm';
hline_1_1d = refline(0, media_1 - desviacion_1);
hline_1_1d.Color = 'm';
%legend({'Plano','Tercera Sección','Cuarta Sección','Media','Desviación Estándar'},'Location','northwest')

%hline_1_2u = refline(0, media_1 + 2*desviacion_1);
%hline_1_2u.Color = 'k';
%hline_1_2d = refline(0, media_1 - 2*desviacion_1);
%hline_1_2d.Color = 'k';
%figure(2);
%media_15 = mean(error_abs_15);
%desviacion_15 = std(error_abs_15);
%plot(error_abs_15, 'b.');
%hline_15 = refline(0, media_15);
%hline_15.Color = 'r';
%hline_15_1u = refline(0, media_15 + desviacion_15);
%hline_15_1u.Color = 'b';
%hline_15_1d = refline(0, media_15 - desviacion_15);
%hline_15_1d.Color = 'b';
%hline_15_2u = refline(0, media_15 + 2*desviacion_15);
%hline_15_2u.Color = 'k';
%hline_15_2d = refline(0, media_15 - 2*desviacion_15);
%hline_15_2d.Color = 'k';
%figure(3);
%media_30 = mean(error_abs_30);
%desviacion_30 = std(error_abs_30);
%plot(error_abs_30, 'k.');
%hline_30 = refline(0, media_30);
%hline_30.Color = 'r';20
%hline_30_1u = refline(0, media_30 + desviacion_30);
%hline_30_1u.Color = 'b';
%hline_30_1d = refline(0, media_30 - desviacion_30);
%hline_30_1d.Color = 'b';
%hline_30_2u = refline(0, media_30 + 2*desviacion_30);
%hline_30_2u.Color = 'k';
%hline_30_2d = refline(0, media_30 - 2*desviacion_30);
%hline_30_2d.Color = 'k';

%% Saving the results
mkdir('results')
cd('results')
saveas(h1, 'Error Estandar27.png');
%saveas(h2, 'Error cuadrático(15).png');
%saveas(h3, 'Error cuadrático(30).png');

input('Press enter to quit...')
close all;