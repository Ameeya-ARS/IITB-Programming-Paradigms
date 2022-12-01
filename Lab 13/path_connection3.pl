check(delhi,mumbai).
check(mumbai,bangalore).
check(bangalore,chennai).
check(chennai,kolkata).
check(kolkata,patna).
connected(A,B):-check(A,B);check(B,A).