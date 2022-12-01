
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <iostream>
using namespace std;

class Shape : public Fl_Widget  {
  	protected:
	int x, y, w, h;
	public:
		Shape (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
			this->x=x; this->y=y;
			this->w=w; this->h=h;
		}
		virtual void wipe()=0;
		virtual void refresh(int dx, int dy)=0;
		virtual int handle(int e) {
			if (e==FL_PUSH) {
				wipe();
				refresh(10,10);
			}
			 if(e==FL_KEYDOWN){
			   int a = Fl::event_key();
			   if(a==65361){
			     wipe();
			     refresh(-10,0);}
			   if(a==65362){
			     wipe();
			     refresh(0,-10);
			   }
			   if(a==65363){
			     wipe();
			     refresh(10,0);
			   }
			   if(a==65364){
			     wipe();
			     refresh(0,10);
			   }
			}	
			return 1;
		}; 
};

class MyRectangle : public Shape {
 public:
   MyRectangle (int x,int y,int w, int h) : Shape (x,y,w,h) { }
   virtual void draw() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
   }

   virtual void wipe() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_WHITE);
   }

   virtual void refresh(int dx, int dy) {
	x=x+dx;y=y+dy;
	resize(x,y,w,h);
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,120);
   }

};

class MyCircle : public Shape {
 public:
   MyCircle (int x,int y,int w) : Shape (x,y,w+20, w+20) { }
    virtual void draw() {
	fl_color(fl_rgb_color(80));
	fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
	fl_color(FL_WHITE);
	fl_pie (x,y,w,h,0,360);

   }
   virtual void refresh(int dx, int dy) {
	x=x+dx;y=y+dy;
	resize(x,y,w,h);
	fl_color(fl_rgb_color(130));
	fl_pie (x,y,w,h,0,360);
   }
};
int main(int argc, char *argv[]) {
srand(time(0));
Fl_Window *window;
window = new Fl_Window (600,600,"DEMO"); // outer window
	new MyRectangle(10,10,40,40);
	
	for (int i=0; i<25; i++) {
           new MyCircle(80+(rand()%570),80+(rand()%570), 0.1);
	}
	window->color(FL_WHITE);
    	window->end();
    	window->show();
    	return(Fl::run());  // the process waits from here on for events
}
