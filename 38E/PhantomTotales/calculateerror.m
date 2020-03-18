function calculateerror(puntoCentral,dataset)
%CALCULATEERROR Summary of this function goes here
%   Detailed explanation goes here
rep = repmat(puntoCentral(1, :),3, 1);
difpar1=(rep-dataset);
result=sqrt(sum(abs(difpar1).^2, 2));
fprint(result);
end

