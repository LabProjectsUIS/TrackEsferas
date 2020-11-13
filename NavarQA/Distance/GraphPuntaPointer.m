PuntaPointer1 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaPointer1.txt');
PuntaPointer2 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaPointer2.txt');
PuntaPointer3 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaPointer3.txt');
PuntaPointer4 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaPointer4.txt');
PuntaBroca1 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaBroca1.txt');
PuntaBroca2 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaBroca2.txt');
PuntaBroca3 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaBroca3.txt');
PuntaBroca4 = load('D:\TrackEsferas\NavarQA\PRUEBAS\PUNTAPOINTER Y PUNTA BROCA\PuntaBroca4.txt');
means = mean(PuntaBroca1);
d1 = norm(mean(PuntaBroca1) - mean(PuntaPointer2));
d2 = norm(mean(PuntaPointer2) - mean(PuntaBroca3));
d3 = norm(mean(PuntaPointer3) - mean(PuntaPointer4));
d4 = norm(mean(PuntaPointer4) - mean(PuntaPointer1));
hold on

scatter3(PuntaPointer1(:,1),PuntaPointer1(:,2),PuntaPointer1(:,3),'b')
scatter3(PuntaPointer2(:,1),PuntaPointer2(:,2),PuntaPointer2(:,3),'b')
scatter3(PuntaPointer3(:,1),PuntaPointer3(:,2),PuntaPointer3(:,3),'b')
scatter3(PuntaPointer4(:,1),PuntaPointer4(:,2),PuntaPointer4(:,3),'b')

hold off
