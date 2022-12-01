#include <iostream>
using namespace std;

class A{
   
   public:
       int y=10;
       virtual void f() {cout << y << "A::f\n";}
       virtual void g() {cout << y << "A::g\n";}
  };
   
class B : public A {
   int y=20;
   public:
       virtual void f() {cout << y << "B::f\n";}
       virtual void g() {cout << y << "B::g\n";}
  };
  
int main(int argc, char *argv[]){
    A *ap;
    B *bp;
    ap = new A();
    bp = new B();
    ap->f(); ap->g();
    bp->f(); bp->g();
    ap = bp;
    ap->f(); ap->g();
    bp->f(); bp->g();
}
