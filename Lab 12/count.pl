count([],H,0).
count([H|T],H,N):-count(T,H,M), N is 1+M.
count([_|T],H,N):-count(T,H,M), N is M.