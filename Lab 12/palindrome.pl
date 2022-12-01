palindrome([]).
palindrome([H]).
palindrome([H|T]):-first([H|T],X,L1),last(L1,X,L2),palindrome(L2).

first([H|T],H,T).
last([T],T,[]).
last([H|T],L,[H|A]):-last(T,L,A).