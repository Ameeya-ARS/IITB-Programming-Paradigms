#include <iostream>
using namespace std;

class A{
   
   public:
       int y;
       virtual void f() {cout << y << "A::f\n";}
       virtual void g() {cout << y << "A::g\n";}
  };
   
class B : public A {
   
   public:
       virtual void f() {cout << y << "B::f\n";}
       virtual void g() {cout << y << "B::g\n";}
  };
  
int main(int argc, char *argv[]){
    A *ap;
    B *bp;
    A a;
    B b;
    a.y = 10;
    b.y = 20;
    a.f(); a.g();
    b.f(); b.g();
    a = b;
    a.f(); a.g();
    b.f(); b.g();
}
