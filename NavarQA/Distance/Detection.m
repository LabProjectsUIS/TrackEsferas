clear; clc;
Data = load('P2.txt');
x=Data(1001:2000,1);x2=Data(1001:2000,3);x3=Data(1001:2000,5);x4=Data(1001:2000,7);
y=Data(1001:2000,2);y2=Data(1001:2000,4);y3=Data(1001:2000,6);y4=Data(1001:2000,8);
hold on
scatter(x,y)
scatter(x2,y2)
scatter(x3,y3)
scatter(x4,y4)
hold off