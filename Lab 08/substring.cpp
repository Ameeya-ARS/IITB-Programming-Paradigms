#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int find(string str, string sub) {  
int length1, length2;
  length1 = str.length();
  length2 = sub.length();

  assert(length2 <= length1);

   size_t found = str.find(sub);
    assert(found != string::npos);
     return found;


}

int main () {

  string s1, s2;
  s1 = "error";
  s2 = "computer";
  int a = find(s1, s2);
  cout << a << endl;
  
  return 0;

}
