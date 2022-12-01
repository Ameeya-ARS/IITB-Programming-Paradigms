
//code by Ameeya Ranjan Sethy, CSE, IIT Bombay
//part of CS 152/154 2021


#include <iostream>
using namespace std;

//third solution: structure the body elements... neater and safer,, encapsulating elements in one structure
//second solution: allows two instaces of the abstraction in main
// first solution does not permit that..


struct Stack {
int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int card=0; // cardinality, no. of elements in the stack
};

 void push (int elem, struct Stack *A) ;// add an element on top of stack
 int pop (struct Stack *A);  // note the value at the top, remove the top and return the value 
 int card(struct Stack *A); // cardinality, how many elements in stack 



void push(int elem, struct Stack *A) {
  A->S[A->top]=elem;
  (A->top)++;
  (A->card)++;
};

int pop(struct Stack *A) {
  int value=A->S[(A->top)-1];
  (A->top)--;
  (A->card)--;
  return value;
};

int card(struct Stack *A) {
  return (A->card);
};

//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction... 
int e;
struct Stack s1, s2;

  push (10,&s1);
  push(12,&s1);
  push(14,&s1);
  e=pop(&s1);
  cout << e << endl;
  e=pop(&s1);
  cout << e << endl;
  cout << "Cardinality of S1 is : " << card(&s1) << endl;

  push (20,&s1);
  push(22,&s1);
  push(24,&s1);
  push(26,&s1);
  e=pop(&s1);
  cout << e << endl;
  e=pop(&s1);
  cout << e << endl;
  cout << "Cardinality of S2 is : " << card(&s2) << endl;

}
