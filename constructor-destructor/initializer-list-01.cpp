#include<iostream> 
using namespace std; 

class Point { 
private: 
	int x; 
	int y; 
public: 
	Point(int i = 0, int j = 0):x(i), y(j) {} 
	/* The above use of Initializer list is optional as the 
		constructor can also be written as: 
		Point(int i = 0, int j = 0) { 
			x = i; 
			y = j; 
		} 
	*/	
	
	int getX() const {return x;} 
	int getY() const {return y;} 
}; 

int main() {
    Point p(10,20);
    return 0;
}