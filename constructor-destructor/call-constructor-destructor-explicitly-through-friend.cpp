#include <iostream> 
using namespace std; 

class Test 
{ 
    public: 
        Test() { cout << "Constructor is executed\n"; } 
        ~Test() { cout << "Destructor is executed\n"; } 
        friend void fun(Test t); 
}; 
void fun(Test t) 
{ 
	Test(); 
	t.~Test(); 
} 

int main() 
{ 
	Test(); 
	Test t; 
	fun(t); 
	return 0; 
}
/** OUTPUT:
Constructor is executed
Destructor is executed
Constructor is executed
Constructor is executed
Destructor is executed
Destructor is executed
Destructor is executed
Destructor is executed
*/ 
