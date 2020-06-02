function PP=Ordenamiento_Pointer(centroids,Area)
%Función que permite ordenar las esferas en sentido horario visto desde la
%cámara.
% centroids (matriz con datos de coordenadas x,y de las esferas) : Nx2 (5,2)
%   columna 1: coordenads x
%   columna 2: coordenads y
% Area (vector con el área de las esferas) : Nx1 (5,1)
% SE ASUME N=5 (5 ESFERAS)

% La salida es una matriz PP de 4 filas 2 columnas. De acuerdo con NavarQA la última esfera 
% debe ser la esfera más cercana a la esfera pequeña.

%Cálculo del centroide

cm=mean(centroids);
%indice de la esfera pequeña
[~,ind]=min(Area);
X=centroids;
%Distancia de las esferas a la esfera pequeña incluida la pequeña
d=sqrt(sum((X-repmat(X(ind,:),5,1)).^2,2));
[~,val]=sort(d);
%Extracción de las 4 esferas (se excluye la pequeña). En la nueva matriz de
%centros de esferas hay 4 esferas y la primera es la más cercana a la
%esfera pequeña.
N=X(val(2:end),:);
%Desplazamiento al centroide
ripit = repmat(cm,4,1);
DX=N-repmat(cm,4,1);
%Vectores unitarios a cada esfera   %Por aca empieza re orden{{__[[
xcuadrado=DX.^2;
suma=sum(xcuadrado,2);
arriba= DX;
raiz=sqrt(suma);
abajo=repmat(raiz,1,2);
U=arriba./abajo;
%Definición de un sistema coordenado x,y de tal mamnera que el vector
%unitario de la primera esfera es el eje x; el eje z es el perpendicular a
%las esferas (que solo tienen coordenadas x,y en pixeles) y el eje y es el
%producto cruz.
ux=U(1,:);
uy=cross([0,0,1],[ux,0]);
uy=uy(1:2);
%Cálculo de las proyecciones a los vectores unitarios x,y,z
Compx=sum(U.*repmat(ux,4,1),2);
Compy=sum(U.*repmat(uy,4,1),2);
%Cálculo de los ángulos con el eje x en el rango de -pi a pi 
Theta=atan2d(Compy,Compx);
%corrección de ángulos negativos
Theta(Theta<0)=360+Theta(Theta<0);
%Organización en sentido horario de los angulos
[~,Ind]=sort(Theta);
%Reasignación de centroides
PP=[N(Ind(1),:);N(Ind(2),:);N(Ind(3),:);N(Ind(4),:)];
