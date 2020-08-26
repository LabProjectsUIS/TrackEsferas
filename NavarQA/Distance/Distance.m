clear; clc;
%dat = importdata('D:\TrackEsferas\DOCUMENTOS\CanulaGrande.txt');
%broca = importdata('D:\TrackEsferas\DOCUMENTOS\BrocaGrande.txt');
clavo = importdata('D:\ProyectosUIS-Precimec\TrackEsferas\Clavo.txt');
pointercorto = importdata('D:\ProyectosUIS-Precimec\TrackEsferas\PointerCorto.txt');
%Separando esferas

Pointer1= nanmean(pointercorto(:,1:3));
Pointer2= nanmean(pointercorto(:,4:6));
Pointer3= nanmean(pointercorto(:,7:9));
Pointer4= nanmean(pointercorto(:,10:12));
Pointer5= nanmean(pointercorto(:,13:15));

d1= norm(Pointer1 - Pointer2);
d2= norm(Pointer1 - Pointer3);
d3= norm(Pointer1 - Pointer4);
d4= norm(Pointer2 - Pointer3);
d5= norm(Pointer2 - Pointer4);
d6= norm(Pointer3 - Pointer4);

d7= norm(Pointer1 - Pointer5);
d8= norm(Pointer2 - Pointer5);
d9= norm(Pointer3 - Pointer5);
d10= norm(Pointer4 - Pointer5);

%{
Clavo1= nanmean(clavo(:,1:3));
Clavo2= nanmean(clavo(:,4:6));
Clavo3= nanmean(clavo(:,7:9));
Clavo4= nanmean(clavo(:,10:12));
Clavo5= nanmean(clavo(:,13:15));

d1= norm(Clavo1 - Clavo2);
d2= norm(Clavo1 - Clavo3);
d3= norm(Clavo1 - Clavo4);
d4= norm(Clavo2 - Clavo3);
d5= norm(Clavo2 - Clavo4);
d6= norm(Clavo3 - Clavo4);

d7= norm(Clavo1 - Clavo5);
d8= norm(Clavo2 - Clavo5);
d9= norm(Clavo3 - Clavo5);
d10= norm(Clavo4 - Clavo5);
%}
%{
Broca1= nanmean(broca(:,1:3));
Broca2= nanmean(broca(:,4:6));
Broca3= nanmean(broca(:,7:9));

d1=norm(Broca1-Broca2);
d2=norm(Broca1-Broca3);
d3=norm(Broca2-Broca3);
%}