//program by Prof. R.K.Joshi
//for CS152, IIT Bombay

#include <iostream>
using namespace std;

//observe definition of our own operator for use with objects,
// which means for use with values which are not primitive data types
// note the associativity from right to left

class Complex {
 float i, j;
 public:
	 Complex (int x, int y) {
		i = x; j=y;
	 }

	 Complex operator + (Complex c) {
		return Complex (i+c.i,j+c.j);
	 }
	 
	 Complex operator - (Complex c) {
	 	return Complex (i-c.i,j-c.j);
	 }
	 
	 Complex operator * (Complex c) {
	 	return Complex ((i*c.i)-(j*c.j),(i*c.j)+(j*c.i));
	 }
	 

	 void prn() { cout << i << "," << j << "i" << endl;}

};

int main () {

Complex c1(10,10), c2(20,20), c3(0,0), c4(0,0), c5(0,0);

	c3=c1+c2;
	cout << "The sum of (10,10i) and (20,20i) is : " ;
	c3.prn();
	
	c4=c2-c1;
	cout << "The difference of (10,10i) and (20,20i) is : " ;
	c4.prn();
	
	c5=c1*c2;
	cout << "The multiplication of (10,10i) and (20,20i) is : " ;
	c5.prn();
}
