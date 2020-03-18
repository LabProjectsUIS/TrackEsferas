data1= importdata('punto20mil.txt');

x= linspace(0,999,1000);
y1=data1(:,1);
y2=data1(:,2);
y3=data1(:,3);

plot(x,y1,'r.')
plot(x,y2,'b.')
plot(x,y3,'g.')

%{

x = linspace(1,10,50); 
y1 = sin(x); 
plot(x,y1) 
title('Combine Plots')  
hold on  
y2 = sin(x/2); 
plot(x,y2)  
y3 = 2*sin(x); 
scatter(x,y3)   
hold off
%}