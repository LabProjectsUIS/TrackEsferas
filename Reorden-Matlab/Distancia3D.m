DATA=load('barra.txt');
esfera1 = [DATA(1:1),DATA(2:2),DATA(3:3)];
esfera2 = [DATA(4:4),DATA(5:5),DATA(6:6)];
esfera3 = [DATA(7:7),DATA(8:8),DATA(9:9)];
esfera4 = [DATA(10:10),DATA(11:11),DATA(12:12)];
esfera5 = [DATA(13:13),DATA(14:14),DATA(15:15)];

dist1= norm(esfera1-esfera2);
dist2=norm(esfera1-esfera3);
dist3=norm(esfera1- esfera4);
dist4=norm(esfera1- esfera5);
dist5=norm(esfera2- esfera3);
dist6=norm(esfera2- esfera4);
dist7=norm(esfera2- esfera5);
dist8=norm(esfera3- esfera4);
dist9=norm(esfera3- esfera5);
dist10=norm(esfera4- esfera5);

