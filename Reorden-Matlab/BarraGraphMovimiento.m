%Camara der
XY=load('BarraP1.txt');

esfera1 = XY(:,1:2);
esfera2 = XY(:,3:4);
esfera3 = XY(:,5:6);

subplot(211)
title('Cámara derecha')
hold on
plot(esfera1(:,1),esfera1(:,2),'g--o')
plot(esfera2(:,1),esfera2(:,2),'b--o')
plot(esfera3(:,1),esfera3(:,2),'y--o')
hold off

%Camara izq

XY2=load('BarraP2.txt');

esfera1I = XY2(:,1:2);
esfera2I = XY2(:,3:4);
esfera3I = XY2(:,5:6);

subplot(212)
title('Cámara izquierda')
hold on
plot(esfera1I(:,1),esfera1I(:,2),'g-o',esfera2I(:,1),esfera2I(:,2),'b-o',esfera3I(:,1),esfera3I(:,2),'y-o')
hold off