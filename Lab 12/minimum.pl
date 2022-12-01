min_value([H],H).
min_value([H|T],Min):- min_value(T,Min0),(H=<Min0, Min=H ; H>Min0, Min=Min0).
