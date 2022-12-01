#include <iostream>
#include <string>
#include <cassert>
using namespace std;


int str2int (string s) {
int v=0, length, as_code;
char x;
  
  length = s.length();
  
  assert(length > 0);
  
  for(int i=0;i<length;i++){
    x = s.at(i);
    as_code = int(x);
    assert(as_code >= 48);
    assert(as_code <= 57);
    v = (v*10)+(as_code-48);
  }

  
	return v;
};

int main() {
  string a;
  a = "error";
  int n = str2int(a);
  cout << n << endl;
  
  return 0;
}
