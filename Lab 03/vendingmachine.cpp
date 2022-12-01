// Program of a cold-drink Vending Machine
// Author : AMEEYA RANJAN SETHY

#include <iostream>
using namespace std;

class VendingMachine {
  int price[7]={25,30,20,15,25,20,30};
  int product_id;
 public:
	int insertcoin (int val);
	bool selectdrink (int drinkid); // returns true if successful 
        void start(int id);
};

int VendingMachine::insertcoin (int val) {
  int value;
  cout << "Insert your amount :" << val << endl ;
  cout << "If u have insufficient amount , enter 0 to cancel the purchase" << endl;
  cin >> value;
  return value;
};

bool VendingMachine::selectdrink(int drinkid){
  if(drinkid<=6)
    return true;
  else return false;
};

void VendingMachine::start(int id) {
  product_id=id;
  if(selectdrink(id) ){
  int inserted_amount = insertcoin(price[id]);
  if(inserted_amount >= price[id]) {
      cout << "Here is your cold-drink " << endl;
      int repay=inserted_amount-price[id];
      if(repay!=0)
        cout << "Here is your remaining amount : " << repay << endl;
      cout << "Thanks for buying and have a great day !!!" << endl;
      }
  else if(inserted_amount<price[id] && inserted_amount > 0){
    cout << "Sorry , you have inserted insufficient amount " << endl;
    cout << "The required amount is :" << price[id] << endl;
    cout << "Here is your amount :" << inserted_amount << endl;
    cout << "Please try again by inserting valid amount" << endl;
    start(id);
  }
  else if(inserted_amount==0)
    cout << "Purchase cancelled" << endl;
  }
  
  else cout << "INVALID ID ENTERED !!!" << endl;
};
int main () {
  int id;
  VendingMachine M;
  
  cout << "cold-drink \t ID" << endl;
  cout << "Pepsi \t \t 0" << endl;
  cout << "Sprite \t \t 1" << endl;
  cout << "Coca-cola \t 2" << endl;
  cout << "Mazaa \t \t 3" << endl;
  cout << "Fanta \t \t 4" << endl;
  cout << "Thumbs-Up \t 5" << endl;
  cout << "Mountain-Dew \t 6" << endl;
  cout << endl;
  cout << "ENTER ID OF YOUR DRINK CHOICE" << endl;
  cin >> id;
  
  M.start(id);
}
