#include <iostream>
using namespace std;

class OutofBound {
 int e;
 public:
	OutofBound (int e) {
		this->e = e;
	}

	void msg() {
		switch(e) {
			case 0: cout << "array underflow access\n"; break;
			case 1: cout << "array overflow access\n"; break;
		}
	}
	
	void new_msg() {
		switch(e) {
			case 0: cout << "Single Digit number \n";break;
			case 1: cout << "Double Digit number \n";break;
		}
	}

};

class Collection {

 int array[10];

  public:

	int & operator [] (int i) {

		if (i>=10) throw OutofBound(1);
		if (i<0) throw OutofBound(0);
		return (array[i]);
	}
	
	int & operator () (int i) {
		if(i<=9) throw OutofBound(0);
		else if(i<=99) throw OutofBound(1);
		return (array[i]);
	}

	void prn() {
		for (int i=0; i<10; i++)
			cout << array[i] << " ";
		cout << endl; 
	}
};

int main () {

 Collection c1,c2;

 for (int i=-5; i<15; i++)  {
	try {
		c1[i]=i;
	} 

	catch (OutofBound e) {
		e.msg();
	}


 }
 c1.prn();
 for (int i=5; i<15; i++)  {
	try {
		c2(i)=i;
	} 

	catch (OutofBound e) {
		e.new_msg();
	}


 }

 return 0;
}
