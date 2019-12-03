// Initialization of reference data members 
#include<iostream> 
using namespace std; 

class Test { 
	int &t; 
public: 
	Test(int &t):t(t) {} //Initializer list must be used 
	int getT() { return t; } 
}; 

int main() { 
	int x = 20; 
	Test t1(x); // x is passed as a reference to the Test class, and initilizer list
	cout << "t1.getT() = " << t1.getT() << endl; 
	x = 30; 
	cout << "x = " << t1.getT() << endl; 
	return 0; 
} 

