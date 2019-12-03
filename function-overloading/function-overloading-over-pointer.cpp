// PROGRAM 2 (Compiles and runs fine) 
#include<iostream> 
using namespace std; 

void fun(char *a) { 
    cout << "non-const fun() " << a << endl; 
} 

void fun(const char *a) { 
    cout << "const fun() " << a << endl; 
} 

int main() { 
    const char *ptr = "TestTheCode"; 
    fun(ptr); 
    return 0; 
} 
