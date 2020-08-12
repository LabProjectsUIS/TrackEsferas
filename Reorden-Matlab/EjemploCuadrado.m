clear
a=5; b=12; r=10;
x=[a a+r  a+r  a a ];
y=[b b      b+r  b+r b];
C=[x;y];
plot(x,y,'r')
for i=1:4
    text(x(i),y(i),['(',num2str(x(i)),',', num2str(y(i)),')' ])
end
axis([x(1)-2 x(3)+2 y(1)-2 y(3)+2])