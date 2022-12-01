
//code by Ameeya Ranjan Sethy, CSE, IIT Bombay
//part of CS 152/154 2021


#include <iostream>
using namespace std;

//fourth solution: more secure.. globals are gone, they are wrapped into classes
// and no more passing references to object's implementation.. that is automatic
// but we have a receiver object


class stack {
int S[100]; // S[45] is 46th element!
int top=0; // current position in stack which is empty, position indicator
int cardinality=0; // cardinality, no. of elements in the stack

public:
 void push (int elem) ;// add an element on top of stack
 int pop ();  // note the value at the top, remove the top and return the value 
 int card(); // cardinality, how many elements in stack 
};


void stack::push(int elem) {
  S[top]=elem;
  top++;
  cardinality++;
};

int stack::pop() {
  int value = S[top-1];
  top--;
  cardinality--;
  return value;
};

int stack::card() {
  return cardinality;
};
//------------- section 3 ---- user of the abstraction ------

int main () { // is a user of the object, through its abstraction... 
int e;
stack s1, s2;

  s1.push (10);
  s1.push(12);
  s1.push (14);
  e=s1.pop();
  cout <<"Last element of S1 is : " << e << endl;
  e=s1.pop();
  cout << "2nd last element of S1 is : "<< e << endl;
  cout << "Cardinality of S1 is : " << s1.card() << endl;

  s2.push(20);
  s2.push(22);
  s2.push(24);
  s2.push(26);
  e=s2.pop();
  cout <<"Last element of S2 is : " << e << endl;
  e=s2.pop();
  cout << "2nd last element of S2 is : "<< e << endl;
  cout << "Cardinality of S2 is : " << s2.card() << endl;

}
