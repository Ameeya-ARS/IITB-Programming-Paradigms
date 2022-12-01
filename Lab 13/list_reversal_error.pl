last_element([A|[]],A).
last_element([A|L],E):-last_element(L,E).

reverse_list([A|[]],A).
reverse_list([A|L],[E|U]):-last_element(L,E),reverse_list(L,U).