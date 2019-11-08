function calib_pointer(OR, PP)
figure
scatter3(OR(1,:), OR(2,:), OR(3,:))
hold on
PP=PP';
%plot3(P(1), P(2), P(3), '*')
plot3(PP(1), PP(2), PP(3), '+')
x=[OR(1,1),PP(1,1)];
y=[OR(2,1),PP(2,1)];
z=[OR(3,1),PP(3,1)];

x=[OR(1,1),PF(1,1)];
y=[OR(2,1),PF(2,1)];
z=[OR(3,1),PF(3,1)];
plot3(x,y,z,'r-')

hold off
