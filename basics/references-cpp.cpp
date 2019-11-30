#include<iostream>
#include <vector>
using namespace std; 

void swap (int& first, int& second) 
{ 
    int temp = first; 
    first = second; 
    second = temp; 
} 

struct Student { 
    string name; 
    string address; 
    int rollNo; 
};

// If we remove & in below function, a new 
// copy of the student object is created. 
// We use const to avoid accidental updates 
// in the function as the purpose of the function 
// is to print s only. 
void print(const Student &s) 
{ 
	cout << s.name << " " << s.address << " " << s.rollNo; 
} 


int main() 
{ 
    int x = 10; 

    // ref is a reference to x. 
    int& ref = x; 

    // Value of x is now changed to 20 
    ref = 20; 
    cout << "x = " << x << endl ; 

    // Value of x is now changed to 30 
    x = 30; 
    cout << "ref = " << ref << endl ; 

    int a = 2, b = 3; 
    swap( a, b ); 
    cout << a << " " << b;


    vector<int> vect{ 10, 20, 30, 40 };  
  
    // We can modify elements if we  
    // use reference 
    for (int &val : vect)  
        val = val + 5; 
  
    // Printing elements 
    for (int val : vect)  
       cout << val << " "; 

    vector<string> vect1{"test practice",  
                     "test write", 
                     "test ide"};  
  
    // We avoid copy of the whole string 
    // object by using reference. 
    for (const auto &x : vect1)  
       cout << x << endl;

    return 0; 
} 
