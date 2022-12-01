// Program of a queue
// Author : AMEEYA RANJAN SETHY

#include <iostream>
using namespace std;

class Queue {
    int S[100];
    int total = 0;
 public:
	void insert (int i);
	int fetch ();
	int totality();
        
};

void Queue::insert(int i) {
  S[total]=i;
  total++;
};

int Queue::fetch() {
  int value = S[0];
  if(total==1)
    S[0]=0;
  else if(total > 1){
    for(int i=0;i<total-1;i++){
      S[i]=S[i+1];
    }
    S[total-1]=0;
  }
  total--;
  return value;
};

int Queue::totality() {
  return total;
};
int main () {
  Queue A;
  int e;
  A.insert(10);
  cout << "10 is inserted" << endl;
  cout << "Total members present in queue are : " << A.totality() << endl;
  A.insert(20);
  cout << "20 is inserted" << endl;
  cout << "Total members present in queue are : " << A.totality() << endl;
  A.insert(30);
  cout << "30 is inserted" << endl;
  cout << "Total members present in queue are : " << A.totality() << endl;
  A.insert(40);
  cout << "10 is inserted" << endl;
  cout << "Total members present in queue are : " << A.totality() << endl;
  
  A.fetch();
  cout << "Total members left in queue are : " << A.totality() << endl;
  A.fetch();
  cout << "Total members left in queue are : " << A.totality() << endl;
  A.fetch();
  cout << "Total members left in queue are : " << A.totality() << endl;
  A.fetch();
  cout << "Total members left in queue are : " << A.totality() << endl;
}
