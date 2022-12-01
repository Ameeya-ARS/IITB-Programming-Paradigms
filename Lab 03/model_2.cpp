
//code by Ameeya Ranjan Sethy, CSE, IIT Bombay
//part of CS 152/154 2021

#include <iostream>
using namespace std;

//second solution: allows two instaces of the abstraction in main

//--------------- section 1 ---- interface of the abstraction 
//declarations give us the abstraction (interface)

void push (int elem, int *S, int *top, int *card); // add an element on top of stack
int pop (int *S, int *top, int *card);  // note the value at the top, remove the top and return the value 
int card(int *S, int *top, int *card); // cardinality, how many elements in stack 

//-----------section 2 --- implementation of the abstraction--
// definitions give us the implementation of the abstraction (bodies)


int S1[100]; // S[45] is 46th element!
int top1=0; // current position in stack which is empty, position indicator
int card1=0; // cardinality, no. of elements in the stack

int S2[100]; // S[45] is 46th element!
int top2=0; // current position in stack which is empty, position indicator
int card2=0; // cardinality, no. of elements in the stack


void push(int elem, int *S, int *top, int *card) {
  int a=*top , b=*card;
  S[a]=elem;
  a++;
  b++;
  *top = a;
  *card = b;
};

int pop (int *S, int *top, int *card) {
  int a=*top , b=*card;
  int value = S[a-1];
  a--;
  b--;
  *top = a;
  *card = b;
  return value;
};

int card(int *S, int *top, int *card) {
  return *card;
};
//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction... 
int e;
  push (10, S1, &top1, &card1);
  push(12, S1, &top1, &card1);
  push (14, S1, &top1, &card1);
  e=pop(S1, &top1, &card1);
  cout <<"Last element of S1 is : " << e << endl;
  e=pop(S1, &top1, &card1);
  cout << "2nd last element of S1 is : "<< e << endl;
  cout << "Cardinality of S1 is : " << s1.card(S1, &top1, &card1) << endl;

  push (20, S2, &top2, &card2);
  push(22, S2, &top2, &card2);
  push (24, S2, &top2, &card2);
  e=pop(S2, &top2, &card2);
  cout <<"Last element of S1 is : " << e << endl;
  e=pop(S2, &top2, &card2);
  cout << "2nd last element of S1 is : "<< e << endl;
  cout << "Cardinality of S1 is : " << s2.card(S2, &top2, &card2) << endl;
}
