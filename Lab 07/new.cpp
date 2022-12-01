#include <iostream> // needed for cout
#include <sstream> // needed to use stringstream
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the FL_Window class
#include <FL/Fl_Button.H> // needed to use Fl_Button


Fl_Button *button[4][4];

using namespace std;

class Empty{   // To store the row and column of empty button
 public:
   int row ;
   int column ;
   Empty(int x, int y){
      row = x;
      column = y;
   }
};

Empty empty(3,3);

char *int2charstar (int v) {
   char *s = new char[sizeof(int)];
   sprintf(s,"%d",v);
   return s;
};

int charstar2int (const char* x){
   if(x==" ")
   return 16;
   else {
     int y;
     stringstream s(x);
     s >> y;
     return y;
   }
}

void color_change(){
   for(int i=0;i<=3;i++){
     for(int j=0;j<=3;j++){
       const char *c=button[i][j]->label();
	int num = charstar2int(c);
       if (num==(4*i+j+1)){
          button[i][j]->labelcolor(FL_BLUE);
          button[i][j]->color(FL_GREEN);
         }
       else {
          button[i][j]->color(FL_BLUE);
          button[i][j]->labelcolor(FL_YELLOW);
         }
     }
   }
}

void labelswap(int row,int column){
	const char *c;
	
	c = button[row][column]->label();
	button[row][column]->label(" ");
	button[empty.row][empty.column]->label(c);
	
	
	return;
};

void check(int row, int column){
  
  bool check = false;

  if(row!=0 && row!=3 && column!=0 && column!=3){
  	if(((row-1)==empty.row && (column)==empty.column)||((row+1)==empty.row && (column)==empty.column)||
  	((row)==empty.row && (column-1)==empty.column||(row)==empty.row && (column+1)==empty.column)){
  		check = true;
  	}

  }
  else if((row==0) && (column==1 || column==2)){
  	if(((row+1)==empty.row && (column)==empty.column)||((row)==empty.row && (column-1)==empty.column)||
  	((row)==empty.row && (column+1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if((row==3) && (column==1 || column==2)){
  	if(((row-1)==empty.row && (column)==empty.column)||((row)==empty.row && (column-1)==empty.column)||
  	((row)==empty.row && (column+1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if((column==0)&&(row==1 || row==2)){
  	if(((row-1)==empty.row && (column)==empty.column)||((row+1)==empty.row && (column)==empty.column)||
  	((row)==empty.row && (column+1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if((column==3)&&(row==1 || row==2)){
  	if(((row-1)==empty.row && (column)==empty.column)||((row+1)==empty.row && (column)==empty.column)||
  	((row)==empty.row && (column-1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if(row==0 && column==0){
  	if(((row+1)==empty.row && (column)==empty.column)||((row)==empty.row && (column+1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if(row==0 && column==3){
  	if(((row+1)==empty.row && (column)==empty.column)||((row)==empty.row && (column-1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if(row==3 && column==0){
  	if(((row-1)==empty.row && (column)==empty.column)||((row)==empty.row && (column+1)==empty.column)){
  		check = true;
  	}
  	
  }
  else if(row==3 && column==3){
  	if(((row-1)==empty.row && (column)==empty.column)||((row)==empty.row && (column-1)==empty.column)){
  		check = true;
  	}
  	
  }
     if(check){
  	labelswap(row,column);
  	empty.row = row;
  	empty.column = column;
    }
    return;
}

void randomize(){ // function to start the game with unsolved state but every state is solvable
	int a,b;
	srand(time(0));
	for(int i=0;i<=1000;i++){
		a = rand()%4;
		b = rand()%4;
		if(a==empty.row && b==empty.column)
		   continue;
		check(a,b);
	} 
	color_change();
}

class MyButton : public Fl_Button {
	int count;
	int row, column;
	public:
		MyButton (int x, int y, int w, int h, const char *l); 
		int handle(int e); // e is incoming mouse event of different kinds
 };

MyButton :: MyButton (int x,int y, int w, int h, const char *l) : Fl_Button (x,y,w,h,l) {
	count =0;
};
int MyButton :: handle (int e) {
	if (e==FL_PUSH) {
           count ++;
           row=((Fl::event_y())/100)-1; // stores the row of the mouse click
           column=((Fl::event_x())/100)-1; // stores the column  of the mouse click
           check(row,column);
           color_change();
	}
	
	return 1;
}
int main(int argc, char *argv[]) {
	Fl_Window *window;
	
window = new Fl_Window(600,700,"DEMO"); // outer window
window->color(FL_RED);
	
	for(int i=0;i<4;i++){
	    for(int j=0;j<4;j++){
	        button[i][j] = new MyButton((j+1)*100,(i+1)*100,100,100,"b");
	        button[i][j]->label(int2charstar(4*i + j + 1));
	        a=a+100;
	        button[i][j]->color(FL_BLUE);
	        button[i][j]->labelcolor(FL_YELLOW);
	    }
	}
	button[3][3]->label(" ");
	randomize(); 
	
	window->end();	
	window->show();
	
	int s = Fl::run(); // the process waits from here on for events
	cout << "Exiting.....\n";
	
	return s;
}

// How to compile : fltk-config --compile 1window.cpp
// this will produce executable file called 1window
// run it : ./1window
