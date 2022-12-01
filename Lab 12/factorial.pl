factorial(0,1).
factorial(N,Final):-N>0, X is N-1, factorial(X,Res), Final is N*Res.