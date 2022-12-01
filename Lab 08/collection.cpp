#include <iostream>
using namespace std;
#include <cassert>
// A program which is not correct
class Collection {
int *S;
int cap, card;

  public:
	Collection(int sz) {
		S = new int [sz];
		card=0;
		cap = sz;
           assert(cap == sz);
	}

	void push_back(int elem) {
 
           assert(card < cap);

           S[card] = elem;
           card++;

           assert(card < cap);

	}

	int pop_back() {
           
           assert(card > 0);

           card--;
           return S[card];

           assert(card > 0);


	}
};
int main () {

   Collection A(10);

   for(int i=1;i<=15;i++){
     A.push_back(i);
   }   
   for(int i=1;i<=15;i++){
     cout << A.pop_back() << endl;
   }
   
   return 0;
}

