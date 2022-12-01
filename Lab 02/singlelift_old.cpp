#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int user_floor, current_floor=0, destination_floor, movement;
char floor_option;

class Lift{

  public:
      void floor_request();
      void move_lift();
      
  private:
      int min_floor, max_floor;
  
};

void Lift::floor_request(){

    if (floor_option == 'U' || floor_option == 'u'){
      min_floor = user_floor+1;
      max_floor = 6;
    }
    if (floor_option == 'D' || floor_option == 'd'){
      min_floor = 0;
      max_floor = user_floor-1;
    }
    cout << "Enter the floor number between " << min_floor << " and " << max_floor <<" : "<< endl;
    cin >> destination_floor;
  }
  
void Lift::move_lift(){
    movement = destination_floor - current_floor;
    current_floor = destination_floor;
  }  
  
class Floor{

   public:
       void floor_switch();
};

void Floor::floor_switch(){
    cout << "Enter U for going UP and D for going DOWN"<< endl;
    cin >> floor_option;
  }

int main(){

  Lift l1;
  Floor f0, f1, f2, f3, f4, f5, f6;
  
while (true){
  cout << "Enter your current floor number :" << endl;
  cin >> user_floor;
  if (user_floor == 0)       f0.floor_switch();
  else if (user_floor == 1)  f1.floor_switch();
  else if (user_floor == 2)  f2.floor_switch();
  else if (user_floor == 3)  f3.floor_switch();
  else if (user_floor == 4)  f4.floor_switch();
  else if (user_floor == 5)  f5.floor_switch();
  else if (user_floor == 6)  f6.floor_switch();
  else break;
  
  l1.floor_request();  
  l1.move_lift();
  
  cout << "Lift is moving and will reach in "<< movement*5 << " seconds" << endl;
  cout.flush();
  usleep(movement*5000000);
  cout << "Now the lift is in floor no :" << current_floor << endl;
 }
return 0;
}
