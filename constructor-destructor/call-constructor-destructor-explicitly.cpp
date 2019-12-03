#include <iostream> 
using namespace std; 

class Test 
{ 
    public: 
        Test() { cout << "Constructor is executed\n"; } 
        ~Test() { cout << "Destructor is executed\n"; }

        void show() { 
            Test(); // Explict call to constructor
            this->Test::~Test(); // Explicit call to destructor
        }
}; 

int main() 
{ 
	Test(); // Explicit call to constructor 
	Test t; // local object 
	t.~Test(); // Explicit call to destructor 
    
    // We can call explict call to constructor and destructor through member function
    t.show();

	return 0; 
}
