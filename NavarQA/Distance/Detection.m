clear; clc;
Data = load('EVBROCA.txt');
x=Data(:,1);
y=Data(:,2);
plot(x,y)