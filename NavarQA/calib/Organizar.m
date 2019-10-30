clear all;
close all;

load rotz;
P=zeros(size(A,1),3,5);
A=1000*A;
for i=1:5
   val=A(:,(i-1)*3+1:i*3);
   P(:,:,i)=val;
%    eval(['P',num2str(i),'=val;']);
end

clear('A');

figure(1);clf;
hold on;
col=['r','b','g','k','c'];
%eliminado el extremos
MIN=10000;MAX=-100;
for i=1:5
    val=shiftdim(P(1,:,i));
    plot3(val(1),val(2),val(3),[col(i),'*']);
    dist=shiftdim(P(1,:,:))-repmat(val,[1,5]);
    val=sqrt(sum(dist.*dist,1));
    [vect,ind]=sort(val);
    min=vect(2);
    if min<MIN
        MIN=min;
        min1=i;min2=ind(2);
    end
    max=vect(end);
    if max>MAX
        MAX=max;
        max1=i;max2=ind(end);
    end
    
end
PR=P(:,:,max2);

MIN=10000;MAX=-100;
OR=shiftdim(P(1,:,:));
OR=[OR(:,1:max2-1),OR(:,max2+1:end)];
for i=1:4
    val=OR(:,i);
    plot3(val(1),val(2),val(3),[col(i),'o']);
    dist=OR-repmat(val,[1,4]);
    val=sqrt(sum(dist.*dist,1));
    [vect,ind]=sort(val);
    min=vect(2);
    if min<MIN
        MIN=min;
        min1=i;min2=ind(2);
    end
    max=vect(end);
    if max>MAX
        MAX=max;
        max1=i;max2=ind(end);
    end
    
end
hold off;


P1=P(:,:,2);
P2=P(:,:,1);
P3=P(:,:,3);


PM=(P1+P2+P3)/3;

Ux=(P3-PM)./repmat(sqrt(sum((P3-PM).*(P3-PM),2)),1,3);
val=cross(P2-PM,P3-PM,2);
Uz=(val)./repmat(sqrt(sum(val.*val,2)),1,3);
Uy=cross(Uz,Ux,2);

DELTA=PR-PM;
CompX=sum(DELTA.*Ux,2);
CompY=sum(DELTA.*Uy,2);
CompZ=sum(DELTA.*Uz,2);

figure;plot(1:size(CompX),CompX,'r',1:size(CompY),CompY,'b',1:size(CompZ),CompZ,'g',1:size(CompZ),sqrt(CompX.*CompX+CompY.*CompY+CompZ.*CompZ),'k*')
figure(1); plot3(P1(:,1),P1(:,2),P1(:,3),'r*');hold on;
plot3(P2(:,1),P2(:,2),P2(:,3),'b*');
plot3(P3(:,1),P3(:,2),P3(:,3),'g*');
plot3(PM(:,1),PM(:,2),PM(:,3),'k*');
plot3(PR(:,1),PR(:,2),PR(:,3),'y*');
hold off;

return;
hold on;
val=PM+Ux*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'r');

val=PM+Uy*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'b');

val=PM+Uz*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'g');

val=PM+CompX*Ux+CompY*Uy+CompZ*Uz;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'k');