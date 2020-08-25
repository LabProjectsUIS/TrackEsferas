clear; clc;
dat = importdata('D:\TrackEsferas\DOCUMENTOS\CanulaGrande.txt');
broca = importdata('D:\TrackEsferas\DOCUMENTOS\BrocaGrande.txt');
%Separando esferas

%{
CanulaGrande1= nanmean(dat(:,1:3));
CanulaGrande2= nanmean(dat(:,4:6));
CanulaGrande3= nanmean(dat(:,7:9));
CanulaGrande4= nanmean(dat(:,10:12));

d1= norm(CanulaGrande1 - CanulaGrande2);
d2= norm(CanulaGrande1 - CanulaGrande3);
d3= norm(CanulaGrande1 - CanulaGrande4);
d4= norm(CanulaGrande2 - CanulaGrande3);
d5= norm(CanulaGrande2 - CanulaGrande4);
d6= norm(CanulaGrande3 - CanulaGrande4);
%}

Broca1= nanmean(broca(:,1:3));
Broca2= nanmean(broca(:,4:6));
Broca3= nanmean(broca(:,7:9));

d1=norm(Broca1-Broca2);
d2=norm(Broca1-Broca3);
d3=norm(Broca2-Broca3);