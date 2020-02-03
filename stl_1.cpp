#include <iostream>
#include <ostream>
#include<string>

using namespace std;

class shape {
	private:
		int x_pos;
		int y_pos;
		int color;
	public:
		shape () : x_pos(0), y_pos(0), color(1) {}
		
		shape (int x, int y, int c = 1) : x_pos(x), y_pos(y), color(c) {}
		
		shape (const shape& s) : x_pos(s.x_pos), y_pos(s.y_pos), color(s.color) {}
		
		~shape () {}
		
		shape& operator= (const shape& s) {
			x_pos = s.x_pos, y_pos = s.y_pos, color = s.color; return *this; 
		}
		
		int get_x_pos () { 
			return x_pos; 
		}

		int get_y_pos () { 
			return y_pos; 
		}
		
		int get_color () { 
			return color; 
		}
		
		void set_x_pos (int x) { 
			x_pos = x; 
		}
		
		void set_y_pos (int y) { 
			y_pos = y; 
		}

		void set_color (int c) { 
			color = c; 
		}
		
		virtual void DrawShape () {}

		friend ostream& operator<< (ostream& os, const shape& s);
};

ostream& operator<< (ostream& os, const shape& s) {
	os << "shape: (" << s.x_pos << "," << s.y_pos << "," << s.color << ") \n";
	return os;
}

int main(){
	// Call default constructor
	shape shape1;
	cout<<shape1;
	
	// Call constructor with parameters
	shape shape2(1, 2, 3);
	cout<<shape2;
	
	// Call constructor with shape object parameter
	shape shape3(shape2);
	cout<<shape3;
	
	// Copy operator
	shape shape4 = shape2;
	cout<<shape4;
	
	return 0;
}	

