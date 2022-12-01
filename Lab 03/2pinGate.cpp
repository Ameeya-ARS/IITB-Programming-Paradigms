// Program for a 2 pin AND gate
// Author : AMEEYA RANJAN SETHY

#include <iostream>

using namespace std;

class Gate {

 public:
	bool fire (bool i, bool j);
	bool getoutput (bool i, bool j);

};

bool Gate::fire(bool i, bool j) {
  if(i==true){
    if(j==true)
      return true;
    else return false;
  }
  return false;
};

bool Gate::getoutput(bool i, bool j) {
  bool value = fire(i,j);
  return value;
};
int main () {
Gate And;
  cout << "Both are 1 then output is : " << And.getoutput(true,true) << endl;
  cout << "1st input is 1 and 2nd input is 0 then output is : " << And.getoutput(true,false) << endl;
  cout << "1st input is 0 and 2nd input is 1 then output is : " << And.getoutput(false,true) << endl;
  cout << "Both are 0 then output is : " << And.getoutput(false,false) << endl;

}
