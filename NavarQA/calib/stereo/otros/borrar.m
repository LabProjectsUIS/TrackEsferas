%esquina 4: PR4
OR1=[147.7182769775391, 116.5774307250977, 132.9552459716797, 164.0826263427734;
 -233.7753143310547, -271.7998962402344, -281.9706726074219, -256.8889770507813;
 1349.3193359375, 1339.508544921875, 1334.479614257813, 1339.021606445313];

OR2=[347.0943908691406, 363.4704895019531, 380.317138671875, 375.2999572753906;
 -186.3607482910156, -232.3340759277344, -223.03466796875, -183.8228149414063;
 1340.768676757813, 1328.99853515625, 1322.890502929688, 1330.6337890625];

PR=[203.8301;-36.2884;1415.0060];

%esquina 2

OR1=[244.3444976806641, 283.6847534179688, 292.4054260253906, 266.1548767089844;
 -334.8365173339844, -361.5968322753906, -343.6965026855469, -315.696533203125;
 1386.731811523438, 1370.525390625, 1367.045654296875, 1379.725830078125];


OR2=[193.6504364013672, 211.0146789550781, 228.9773406982422, 223.2886810302734;
 -445.6833190917969, -490.6463317871094, -482.2412414550781, -443.5205993652344;
 1404.250122070313, 1390.564697265625, 1391.350708007813, 1401.705444335938];

PR=[45.37;-302.3168;1472.8355];

COMP=[];

figure(3);clf;
hold on;
col=['r','b','g','k'];

OR=OR1;
MIN=10000;MAX=-100;
for i=1:4
    val=OR(:,i);
    plot3(val(1),val(2),val(3),[col(i),'*']);
    dist=OR-repmat(val,1,4);
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
plot3(PR(1),PR(2),PR(3),'y*');
hold off;

P1=OR(:,min2);
P2=OR(:,min1);
P3=OR(:,max1);

PM=(P1+P2+P3)/3;

Ux=(P3-PM)/norm(P3-PM);
val=cross(P2-PM,P3-PM);
Uz=val/norm(val);
Uy=cross(Uz,Ux);


DELTA=shiftdim(PR)-PM;
CompX=dot(DELTA,Ux);
CompY=dot(DELTA,Uy);
CompZ=dot(DELTA,Uz);
COMP=[COMP,[CompX;CompY;CompZ]];
hold on;
val=PM+Ux*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'r');

val=PM+Uy*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'b');

val=PM+Uz*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'g');

val=PM+CompX*Ux+CompY*Uy+CompZ*Uz;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'k');


norm(P1-PM),
norm(P2-PM),
norm(P3-PM),
norm(PR-PM),
OR=OR2;
MIN=10000;MAX=-100;
for i=1:4
    val=OR(:,i);
    plot3(val(1),val(2),val(3),[col(i),'*']);
    dist=OR-repmat(val,1,4);
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
plot3(PR(1),PR(2),PR(3),'y*');
hold off;

P1=OR(:,min2);
P2=OR(:,min1);
P3=OR(:,max1);

PM=(P1+P2+P3)/3;

Ux=(P3-PM)/norm(P3-PM);
val=cross(P2-PM,P3-PM);
Uz=val/norm(val);
Uy=cross(Uz,Ux);


DELTA=shiftdim(PR)-PM;
CompX=dot(DELTA,Ux);
CompY=dot(DELTA,Uy);
CompZ=dot(DELTA,Uz);
COMP=[COMP,[CompX;CompY;CompZ]];
hold on;
val=PM+Ux*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'r');

val=PM+Uy*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'b');

val=PM+Uz*20;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'g');

val=PM+CompX*Ux+CompY*Uy+CompZ*Uz;
plot3([PM(1),val(1)],[PM(2),val(2)],[PM(3),val(3)],'k');

norm(P1-PM),
norm(P2-PM),
norm(P3-PM),
norm(PR-PM),
