uiopen('calib.fig',1)
h = gcf;
x = h.Children.Children(2).XData';
z = h.Children.Children(2).YData';
y = -h.Children.Children(2).ZData';
x = x(end:-1:1, :);
y = y(end:-1:1, :);
z = z(end:-1:1, :);
PR = [x(:), y(:), z(:)];
close all;

P3 = [mean(importdata('p11.pts'));
    mean(importdata('p21.pts'));
    mean(importdata('p31.pts'));
    mean(importdata('p41.pts'));
    mean(importdata('p51.pts'));
    mean(importdata('p61.pts'));
    mean(importdata('p71.pts'));
    mean(importdata('p81.pts'));
    mean(importdata('p91.pts'));
    mean(importdata('p101.pts'));
    mean(importdata('p111.pts'));
    mean(importdata('p121.pts'));
    mean(importdata('p131.pts'));
    mean(importdata('p141.pts'));
    mean(importdata('p151.pts'));
    mean(importdata('p161.pts'));
    mean(importdata('p171.pts'));
    mean(importdata('p181.pts'));
    mean(importdata('p191.pts'));
    mean(importdata('p201.pts'));
    mean(importdata('p211.pts'));
    mean(importdata('p221.pts'));
    mean(importdata('p231.pts'));
    mean(importdata('p241.pts'));
    mean(importdata('p251.pts'));
    mean(importdata('p261.pts'));
    mean(importdata('p271.pts'));
    mean(importdata('p281.pts'));
    mean(importdata('p291.pts'));
    mean(importdata('p301.pts'));
    mean(importdata('p311.pts'));
    mean(importdata('p321.pts'));
    mean(importdata('p331.pts'));
    mean(importdata('p341.pts'));
    mean(importdata('p351.pts'));
    mean(importdata('p361.pts'));
    mean(importdata('p371.pts'));
    mean(importdata('p381.pts'));
    mean(importdata('p391.pts'));
    mean(importdata('p401.pts'));
    mean(importdata('p411.pts'));
    mean(importdata('p421.pts'));
    mean(importdata('p431.pts'));
    mean(importdata('p441.pts'));
    mean(importdata('p451.pts'));
    mean(importdata('p461.pts'));
    mean(importdata('p471.pts'));
    mean(importdata('p481.pts'))];
P2 = [mean(importdata('p12.pts'));
    mean(importdata('p22.pts'));
    mean(importdata('p32.pts'));
    mean(importdata('p42.pts'));
    mean(importdata('p52.pts'));
    mean(importdata('p62.pts'));
    mean(importdata('p72.pts'));
    mean(importdata('p82.pts'));
    mean(importdata('p92.pts'));
    mean(importdata('p102.pts'));
    mean(importdata('p112.pts'));
    mean(importdata('p122.pts'));
    mean(importdata('p132.pts'));
    mean(importdata('p142.pts'));
    mean(importdata('p152.pts'));
    mean(importdata('p162.pts'));
    mean(importdata('p172.pts'));
    mean(importdata('p182.pts'));
    mean(importdata('p192.pts'));
    mean(importdata('p202.pts'));
    mean(importdata('p212.pts'));
    mean(importdata('p222.pts'));
    mean(importdata('p232.pts'));
    mean(importdata('p242.pts'));
    mean(importdata('p252.pts'));
    mean(importdata('p262.pts'));
    mean(importdata('p272.pts'));
    mean(importdata('p282.pts'));
    mean(importdata('p292.pts'));
    mean(importdata('p302.pts'));
    mean(importdata('p312.pts'));
    mean(importdata('p322.pts'));
    mean(importdata('p332.pts'));
    mean(importdata('p342.pts'));
    mean(importdata('p352.pts'));
    mean(importdata('p362.pts'));
    mean(importdata('p372.pts'));
    mean(importdata('p382.pts'));
    mean(importdata('p392.pts'));
    mean(importdata('p402.pts'));
    mean(importdata('p412.pts'));
    mean(importdata('p422.pts'));
    mean(importdata('p432.pts'));
    mean(importdata('p442.pts'));
    mean(importdata('p452.pts'));
    mean(importdata('p462.pts'));
    mean(importdata('p472.pts'));
    mean(importdata('p482.pts'))];
P1 = [mean(importdata('p13.pts'));
    mean(importdata('p23.pts'));
    mean(importdata('p33.pts'));
    mean(importdata('p43.pts'));
    mean(importdata('p53.pts'));
    mean(importdata('p63.pts'));
    mean(importdata('p73.pts'));
    mean(importdata('p83.pts'));
    mean(importdata('p93.pts'));
    mean(importdata('p103.pts'));
    mean(importdata('p113.pts'));
    mean(importdata('p123.pts'));
    mean(importdata('p133.pts'));
    mean(importdata('p143.pts'));
    mean(importdata('p153.pts'));
    mean(importdata('p163.pts'));
    mean(importdata('p173.pts'));
    mean(importdata('p183.pts'));
    mean(importdata('p193.pts'));
    mean(importdata('p203.pts'));
    mean(importdata('p213.pts'));
    mean(importdata('p223.pts'));
    mean(importdata('p233.pts'));
    mean(importdata('p243.pts'));
    mean(importdata('p253.pts'));
    mean(importdata('p263.pts'));
    mean(importdata('p273.pts'));
    mean(importdata('p283.pts'));
    mean(importdata('p293.pts'));
    mean(importdata('p303.pts'));
    mean(importdata('p313.pts'));
    mean(importdata('p323.pts'));
    mean(importdata('p333.pts'));
    mean(importdata('p343.pts'));
    mean(importdata('p353.pts'));
    mean(importdata('p363.pts'));
    mean(importdata('p373.pts'));
    mean(importdata('p383.pts'));
    mean(importdata('p393.pts'));
    mean(importdata('p403.pts'));
    mean(importdata('p413.pts'));
    mean(importdata('p423.pts'));
    mean(importdata('p433.pts'));
    mean(importdata('p443.pts'));
    mean(importdata('p453.pts'));
    mean(importdata('p463.pts'));
    mean(importdata('p473.pts'));
    mean(importdata('p483.pts'))];

%PR = DATOS_POINTER;

PM=(P1+P2+P3)/3;


Ux=(P3-PM)./repmat(sqrt(sum((P3-PM).*(P3-PM),2)),1,3);
val=cross(P2-PM,P3-PM,2);
Uz=(val)./repmat(sqrt(sum(val.*val,2)),1,3);
Uy=cross(Uz,Ux,2);

DELTA=PR-PM;
CompX=sum(DELTA.*Ux,2);
CompY=sum(DELTA.*Uy,2);
CompZ=sum(DELTA.*Uz,2);

PARAM=[[mean(CompX),mean(CompY),mean(CompZ)];
    [std(CompX),std(CompY),std(CompZ)];
    [max(CompX)-min(CompX),max(CompY)-min(CompY),max(CompZ)-min(CompZ)]];

%  -237.7257   84.9492   16.7374
%     0.7773    1.4939    1.8582
%     1.7935    3.3951    4.3489

%  -237.4511   82.4683   14.8407
%     0.2406    0.3151    2.1590
%     0.5388    0.6670    4.0174

% -235.1289, 88.7452, 17.7502,
% 0.8832, 2.3888, 1.9610,
% 1.9939, 5.2039, 4.5460

%   248.2036  -38.6103  -16.1400
%     0.4371    1.0546    1.9696
%     1.2752    3.2983    8.0466

%  -235.9385   86.1825   16.1401
%     0.5087    1.9071    2.1938
%     1.2371    3.9150    5.1658

%plot3(x, y, z, 'r.');
%close();