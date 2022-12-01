// A program that counts the probability of
// every possibility of throwing a 6 faced dice, N times
// by using random number generator.

// AUTHOR :- AMEEYA RANJAN SETHY

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int random_no_generator(){
  int random;
  random = (rand()%6)+1; // rand() function generates random number
  return random;        // returns random value for each throw of dice
}

void loop(int N){
  int random_no ;
  int no_count[6]={0,0,0,0,0,0};
  double prob[6];    // to store the probability of different outputs
  srand(time(0));   // Used as seeding to create different sequence every time
  for(int i=1;i<=N;i++){
    random_no=random_no_generator();
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
  int N;
  cin >> N;
  loop(N);
  return 0;
}
