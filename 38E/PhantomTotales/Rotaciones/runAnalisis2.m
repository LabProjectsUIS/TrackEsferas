clear; clc;
%ref = input('punto a usar como referencia\n');
%load('PR.mat')
%data_ref = PR;
%PR = importdata('PR.txt');
data_10G = mean(importdata('10G.txt'));
data_20G = mean(importdata('20G.txt'));
data_90 = mean(importdata('90.txt'));
data_10G2 = mean(importdata('-10G.txt'));
data_20G2 = mean(importdata('-20G.txt'));
data_30G2 = mean(importdata('-30G.txt'));

n = 6; 
%rep = repmat(data_90(:, :), n, 1);


temp1=data_10G-data_90;
temp2=data_20G-data_90;
temp4=data_10G2-data_90;
temp5=data_20G2-data_90;
temp6=data_30G2-data_90;

dist1=sqrt(sum(abs(temp1).^2, 2));
dist2=sqrt(sum(abs(temp2).^2, 2));
dist4=sqrt(sum(abs(temp4).^2, 2));
dist5=sqrt(sum(abs(temp5).^2, 2));
dist6=sqrt(sum(abs(temp6).^2, 2));

distN=[dist1;dist2;dist4;dist5;dist6];
h1 = figure(1); hold on;
title('Rotaciones 10° , 20° , 30° apartir del eje central');
axis([0 5 -1 5]);
media_1 = [mean(dist1);mean(dist2);mean(dist4);mean(dist5);mean(dist6)];
desviacion_1 = std(distN);
desv_media = std(media_1);

plot(1:2,distN(1:2), 'r.');
plot(3:5,distN(3:5),'b.');
hline_1 = refline(0, 0);
hline_1.Color = 'g';
legend({'Rotacion derecha','Rotación izquierda'},'Location','northwest')

%{
rep = repmat(data_1(ref, :), n, 1);
temp_1 = data_1 - rep;
dist_1 = sqrt(sum(abs(temp_1).^2, 2));
%temp_15 = data_15 - repmat(data_15(ref, :), n, 1);
%dist_15 = sqrt(sum(abs(temp_15).^2, 2));
%temp_30 = data_30 - repmat(data_30(ref, :), n, 1);
%dist_30 = sqrt(sum(abs(temp_30).^2, 2));
PR =PR((1:40),:);
repmat_ref = repmat(PR(ref, :), n, 1);
temp_ref = PR - repmat_ref;

dist_ref = sqrt(sum(abs(temp_ref).^2, 2));

error_abs_1 = abs(dist_1 - dist_ref);
%error_abs_15 = abs(dist_15 - dist_ref);
%error_abs_30 = abs(dist_30 - dist_ref);

%% Creating empty figures
h1 = figure(1); hold on;
title('Error estándar - Phantom - Pointer');
%h2 = figure(2); hold on;
%title('Error cuadrático - 15 puntos');
%h3 = figure(3); hold on;
%title('Error cuadrático - 30 puntos');


plot(1:27,error_abs_1(1:27), 'r.'); 
plot(28:35,error_abs_1(28:35),'b.');
plot(36:40,error_abs_1(36:40),'g.');
hline_1 = refline(0, media_1);
hline_1.Color = 'r';

%hline_b = refline(0, 0);
%hline_b.Color = 'k';
hline_1_1u = refline(0, media_1 + desviacion_1);
hline_1_1u.Color = 'm';
hline_1_1d = refline(0, media_1 - desviacion_1);
hline_1_1d.Color = 'm';
legend({'Plano','Tercera Sección','Cuarta Sección','Media','Desviación Estándar'},'Location','northwest')

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
saveas(h1, 'Error Estandar (40).png');
%saveas(h2, 'Error cuadrático(15).png');
%saveas(h3, 'Error cuadrático(30).png');
%}
input('Press enter to quit...')
close all;