#include <iostream> 
using namespace std; 

int i; 

class A { 
    public: 
        ~A() 
        { 
            i=10; 
        } 
}; 

int foo() { 
	i=3; 
	A ob; 
	return i; 
} 

int& foo2() { 
	i=3; 
	A ob; 
	return i; 
}

int foo3() { 
	i=3;
    {
        A ob; 
    } 
	return i; 
}

int main() 
{ 
	cout << "i = " << foo() << endl; // i = 3, but i is updated to 10; By Destructor will be called once return value is given.
    cout << "i = " << foo2() << endl; // Now, i = 3, using reference logic
    cout << "i = " << foo3() << endl; // Now also, i = 3, using block scope logic
	return 0; 
} 

