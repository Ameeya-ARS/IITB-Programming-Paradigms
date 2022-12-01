reverse_list([],[]).
reverse_list([H],[H]).
reverse_list([H|T],RevList):-reverse_list(T,RevT), join(RevT,[H],RevList).

join([],X,X).
join([H|T],X,[H|Y]):-join(T,X,Y).