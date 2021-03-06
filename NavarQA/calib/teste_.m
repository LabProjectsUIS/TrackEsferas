clear all;
close all;
clc;
DISTANCE_2_END = 220;
% P1 = [8.943741798400879;
%  11.41979122161865;
%  1277.720092773438];
% P2 = [53.90357208251953;
%  28.93946647644043;
%  1265.785888671875];
% P3 = [43.97554397583008;
%  44.8354606628418;
%  1258.765014648438];
P1 = [415.163;
    280.284;
    757.253];
P2 = [398.076;
    270.229;
    759.870];
P3 = [427.265;
    229.428;
    761.710];
plot3(P1(1), P1(2), P1(3), 'r+')
hold on;
plot3(P2(1), P2(2), P2(3), 'b+')
plot3(P3(1), P3(2), P3(3), 'k+')
deltaX = P3 - P1;
XU = deltaX / norm(deltaX);
PR = XU * DISTANCE_2_END + P3;
PR_teo = [474.813;
    15.409;
    770.819];
plot3(PR(1), PR(2), PR(3), 'g+')
plot3(PR_teo(1), PR_teo(2), PR_teo(3), 'g*')
plot3([P1(1), PR(1)], [P1(2), PR(2)], [P1(3), PR(3)])
plot3([P1(1), PR_teo(1)], [P1(2), PR_teo(2)], [P1(3), PR_teo(3)])
axis equal