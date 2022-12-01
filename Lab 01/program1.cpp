// A program that counts the probability of
// every possibility of throwing a 6 faced dice, N times
// by using random number generator.

// AUTHOR :- AMEEYA RANJAN SETHY

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class probability{
  private:
         int random;
         int random_no;
         double prob[6];
         int no_count[6];
  public:
         int random_no_generator();
         void loop(int);
};

int probability::random_no_generator(){
  random = (rand()%6)+1;     // rand() function generates random number
  return random;            // returns random value for each throw of dice
}

void probability::loop(int N){
  srand(time(0));    // used as seeding to create different sequence every time
  for(int i=0;i<=5;i++)
    no_count[i]=0;  // initialization of variables to store the probability values 
  for(int i=1;i<=N;i++){
    random_no=probability::random_no_generator();
    cout << random_no << '\t';
    if (random_no==1) no_count[0]++;
    else if (random_no==2) no_count[1]++;
    else if (random_no==3) no_count[2]++;
    else if (random_no==4) no_count[3]++;
    else if (random_no==5) no_count[4]++;
    else if (random_no==6) no_count[5]++;  
  }
  cout << endl;
  for(int i=0;i<=5;i++){
    prob[i] = (no_count[i] * 1.0)/N;
    cout << "Probability of " << (i+1) << " is : " << prob[i] << endl;
  }
}

int main(){
  probability p;
  int N;
  cin >> N;
  p.loop(N);
  return 0;
}
