function calib_pointer2(OR, PP, P, PR, PF)

ejeR2=[38114.00217519174;
 -35994.88435419842;
 -2333.51185070604];
 
 
vP=[-196.3174104839563;
 -268.7961675003171;
 939.71871329844];

 P2=[259.0355224609375;
 286.64990234375;
 1067.659057617188];

delta = 0.001;
i = 1;
s = 0;
%while i < delta
 PR = rotVect((P2-PP),ejeR2, -3.6875);
%end
disp(s);   



scatter3(OR(1,:), OR(2,:), OR(3,:))
hold on
PP=PP';
plot3(P(1), P(2), P(3), '*')
plot3(PP(1), PP(2), PP(3), '+')
x=[OR(1,2),PP(1,1)];
y=[OR(2,2),PP(2,1)];
z=[OR(3,2),PP(3,1)];
%punto proyectado, color negro.
plot3(x,y,z,'k-')
%punto referencia de calibración, color amarillo.
x=[OR(1,2),P(1,1)];
y=[OR(2,2),P(2,1)];
z=[OR(3,2),P(3,1)];
plot3(x,y,z,'k-')

a=OR(:,2)-PP;
b=OR(:,2)-P;
angle = atan2(norm(cross(a,b)),dot(a,b));

% ángulo entre el punto proyectado y el punto referencia para calibrar.
n=angle*180/pi;
['Angulo en la 1ra rotación: ', num2str(n)]

x=[OR(1,2),PR(1,1)];
y=[OR(2,2),PR(2,1)];
z=[OR(3,2),PR(3,1)];
plot3(x,y,z,'b-')

% angulo en la 2da rotación
a=OR(:,2)-PR;
b=OR(:,2)-P;
angle = atan2(norm(cross(a,b)),dot(a,b));
r=angle*180/pi;
['Angulo para corrección: ', num2str(r)]
['Angulo final para la 1ra rotación: ', num2str(abs(n-r))]



x=[OR(1,2),PF(1,1)];
y=[OR(2,2),PF(2,1)];
z=[OR(3,2),PF(3,1)];
plot3(x,y,z,'y-')



hold off
