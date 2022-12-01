
#include <iostream>
using namespace std;

//observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left


class Collection {
 int *array, card, maxsize; // storage and cardinality
 public:
    int get_card(){ return card; }
    int get_maxsize(){ return maxsize;}
 
	 Collection (int sz) {
		array = new int [sz];	
		card = 0;
		maxsize = sz;
	 }

	 Collection &operator << (int elem) {
		if (card < maxsize) array [card++] = elem;
		return *this;
	 }
	 
	 Collection &operator + (Collection c) {
	 	int new_maxsize = maxsize  + c.get_maxsize();
	 	int new_card = card + c.get_card();
	 	int *construct_array = new int[maxsize];
	 	for(int i=0;i<new_card;i++){
	 		if(i<card)
	 		  construct_array[i] = array[i];
	 		else
	 		  construct_array[i] = c.array[i-card];
	 	}
	 	array = construct_array;
	 	return *this;
	 }
	 
	 Collection &operator >> (int amount) { // c2 << n means to print n number of elements
	 	if(amount<card){
	 		for(int i=1;i<=amount;i++){
	 		  cout << array[--card] << endl;
	 		}
	 	}
	 	else {
	 		int am=card;
	 		cout << am << " elements are maximum present in collection " << endl;
	 		for(int i=1;i<=am;i++) {
	 		  cout << array[--card] << endl;
	 		}
	 	}
	 	return *this;
	 }

	 void prn() { 
		for (int i=0; i<maxsize; i++)
			cout << array[i] << " ";
		cout << endl;
	}
};

int main () {

	Collection c1 (3);

		c1 << 1;
		c1 << 2;
		c1 << 3;
		c1 << 4;
		c1 << 5;
		c1.prn();

		c1 >> 2;
		c1 >> 2;

	Collection c2(3);

		c2 << 1 << 2 << 3;
		c2.prn();
		c2 >> 5;
		
	Collection c3 (5);
	  c3 << 1 << 2;
	  
	Collection c4 (4);
	  c4 << 3 << 4 << 5;
	  
	 c3 = c3+c4;
	  c3.prn();

}
