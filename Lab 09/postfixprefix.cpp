// Program by Prof. R. K. Joshi
// for CS 152
// unary operator overloading: the ++ operator

#include <iostream>
using namespace std;

class A {

    int v;
	public:
		A(int x) { v = x;}
		void operator ++() {
			v = v+1;
			cout << "prefix operator ++a called : " << (v) << endl;
		}
		void operator ++(int) {
			cout << "postfix operator a++ called : " << (v) << endl;
			v = v+1;
		}
		void operator --() {
			v = v-1;
			cout << "prefix operator --a called : " << (v) << endl;
		}
		void operator --(int) {
			cout << "postfix operator a-- called : " << (v) << endl;
			v = v-1;
		}

};

int main () {

 A a(10);
	++a;
	a++;
	a--;
	--a;
}
