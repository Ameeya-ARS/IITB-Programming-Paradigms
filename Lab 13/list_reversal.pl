add_element([],X,X).
add_element([H|T],X,[H|Y]):-add_element(T,X,Y).

reverse_list([],[]).
reverse_list([H],[H]).
reverse_list([H|T],RL):-reverse_list(T,RT), add_element(RT,[H],RL).