join([],X,X).
join([H|T],X,[H|W]):-join(T,X,W).