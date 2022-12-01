// Program To replicate the functioning of a basic Lift
// Author : AMEEYA RANJAN SETHY

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Lift{

     int min_floor, max_floor, capacity;
     int current_floor = 0;
     int direction; // 1 refers UPWARD direction and -1 refers DOWNWARD direction
     int passengers; // no of people in lift at a specific point of time
     vector<int> requests = {}; // vector to store the list of floor requests made by people
     public:
         Lift(int the_min_floor, int the_max_floor, int the_capacity){ // constructor to initialize the variables
             min_floor = the_min_floor; // lowest floor available for lift
             max_floor = the_max_floor; // highest floor available for lift
             capacity = the_capacity; // maximum people that can be carried by the lift
         }
         void start_lift();
         
     private:
         void set_request();
         void set_direction(int);
         int verify_request(int);
         int is_request_valid(int);
};

void Lift::set_request(){
    string str_dest_floors; // To store the sequence of floor requests entered in a single floor in string format
    string str_dest_floor; // to store a single floor from the above sequence in string format
    int dest_floor; // To store a single floor in integer format
    
    int number_of_requests = capacity - passengers;
    cout << "\n" << number_of_requests << " passengers can enter in the elevator right now\n";
    cout << "\nEnter   GO   if no one enters from the floor \nOr to exit from program if elevator is idle\n";
    cout << "\nEnter destination floor numbers(separated by a space if more than one passenger)\n";
    
    getline (cin,str_dest_floors); // To consider the spaces in input and take input of multiple floor requests
    stringstream sstream(str_dest_floors); // To extract a single floor from the list string
    
    while(sstream >> str_dest_floor){
        if(str_dest_floor == "GO")
            return;
        else{
            dest_floor = stoi(str_dest_floor); // To convert string data into integer data
            if(passengers < capacity){
                int is_valid = is_request_valid(dest_floor);
                if(is_valid == 4){ // Only case 4 was the VALID condition
                    if(passengers==0)
                        set_direction(dest_floor); // Because direction will be changed only when 1st person enters the lift
                    passengers++;
                    requests.push_back(dest_floor); // vector function to store the floor requested  by a person
                }
            }
            else if(passengers == capacity){
                cout << "Elevator full!! Cannot accept more requests\n";
                return;
            }
        }
    
    }
}

int Lift::verify_request(int floor){
    if (passengers!=0 && direction == 1 && floor < current_floor) // Lift is moving UPWARD but a person wants to go DOWNWARD
         return 1;
    else if(passengers!=0 && direction == -1 && floor > current_floor) // Lift is moving DOWNWARD but a person wants to go UPWARD
         return 2;
    else if(floor < min_floor || floor > max_floor) // INVALID condition
         return 3;
    else return 4; // VALID condition
}

int Lift::is_request_valid(int floor){
   int issue = verify_request(floor);
   
   if (issue == 1){
       cout << "\n****Lift is Going UP**** \n";
       cout << "*****REQUEST  DENIED*****\n";
   }
   else if(issue == 2){
       cout <<"\n****Lift is Going DOWN**** \n";
       cout << "*****REQUEST  DENIED*****\n";
   }
   else if(issue == 3){
       cout <<"\n****Invalid Floor Request**** \n";
       cout << "*****REQUEST  DENIED*****\n";
   }
   return issue;
}

void Lift::set_direction(int floor){
    if (floor > current_floor)
        direction = 1; // will instruct lift to move UPWARD
    else if (floor < current_floor)
        direction = -1; // Will instruct lift to move DOWNWARD
}

void Lift::start_lift(){
    cout << "\nFLOOR : " << current_floor << "\tNumber of Occupants : " << passengers <<"\n";
    
    set_request(); // sort() function sorts the numbers in ascending order by default
    sort(requests.begin(),requests.end());
    int next_floor;
    while(!requests.empty()){ // .empty() function returns true when vector is empty and vice-versa
        if(direction == 1)
            next_floor = requests[0]; // Lift is moving UPWARD so we have to consider the requests in ascending order
        else if(direction==-1)
            next_floor = requests[requests.size()-1]; // Lift is moving DOWNWARD so we have to consider the requests in descending order
        auto next_floor_req = find(requests.begin(),requests.end(),next_floor); // auto detects the data type automatically as per the need
        while (next_floor_req != requests.end()) // to clear all the requests of the next floor
 		{
 			requests.erase(next_floor_req); //removing next floor's requests
 			passengers--;
 			next_floor_req = find(requests.begin(), requests.end(), next_floor);
 		}
    current_floor = next_floor;

 		string dir;
 		if (direction == 1)
 		{
 			dir = "UP";
 		}
 		else
 		{		
 			dir = "DOWN";
 		}

 		//Entering requests for current floor
 		cout << "\n=======================================================\n"
    		"FLOOR : " << current_floor 
    		<< "\tNumber of Occupants : " << passengers 
    		<< "\n\nDIRECTION : " << dir 
    		<< "\tTotal Capacity : " << capacity
    		<< "\n\nMinimum floor number is " << min_floor
    		<< "\tMaximum floor number is " << max_floor
    		<< "\n\n=======================================================\n";

 		if (current_floor == max_floor)
 		{
 			direction = -1; // Lift has reached the highest floor so now it has to move DOWNWARD
 		}
		else if (current_floor == min_floor) 		
		{
 			direction = +1; // Lift has reached the lowest floor so no it has to move UPWARD
 		}

 		set_request();
 		sort(requests.begin(), requests.end());	
 
    }
}

int main(){
    
    int min_floor_no, max_floor_no, total_capacity;
    cout << "Enter the minimum and maximum floor number : " << endl;
    cin >> min_floor_no >> max_floor_no;
    cout << "\n Enter the maximum capacity of the lift : \n";
    cin >> total_capacity;
    cin.ignore(); // To ignore the \n that gets automatically stored in str_dest_fllors when we press ENTER for cin >> capacity 
    
    Lift lift1(min_floor_no, max_floor_no, total_capacity);
    lift1.start_lift();
    
    return 0;
}
