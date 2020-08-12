Area=load('Areas.txt');
X=load('Posiciones.txt');

cm=mean(X);
%Apartir de ac� vienen las esferas sin la peque�a------->
%X=load('X.txt');
%Desplazamiento al centroide
DX=X-repmat(cm,4,1);
DX=DX.^2;
%Vectores unitarios a cada esfera   %Por aca empieza re orden{{__[[
suma=sum(DX.^2,2);
raiz=sqrt(suma);
rep=repmat(raiz,1,2);
%Uprueba=DX./repmat(sum(DX.^2,2),1,2);
U=DX./repmat(sqrt(suma),1,2);
%Definición de un sistema coordenado x,y de tal mamnera que el vector
%unitario de la primera esfera es el eje x; el eje z es el perpendicular a
%las esferas (que solo tienen coordenadas x,y en pixeles) y el eje y es el
%producto cruz.
ux=U(1,:); 

uy=cross([0,0,1],[ux,0]);
uy=uy(1:2);
%Cálculo de las proyecciones a los vectores unitarios x,y,z
rep2=repmat(ux,4,1);
MULTI=U.*rep2;
Compx=sum(U.*repmat(ux,4,1),2);
Compy=sum(U.*repmat(uy,4,1),2);
%Cálculo de los ángulos con el eje x en el rango de -pi a pi 
Theta=atan2d(Compy,Compx);

%corrección de ángulos negativos
Theta(Theta<0)=360+Theta(Theta<0);
%Organización en sentido horario de los angulos
[~,Ind]=sort(Theta);
%Reasignación de centroides
PP=[X(Ind(1),:);X(Ind(2),:);X(Ind(3),:);X(Ind(4),:)];