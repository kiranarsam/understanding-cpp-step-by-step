#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	// creating two variables of nullptr_t type i.e., with value equal to nullptr 
	nullptr_t np1, np2; 

	// <= and >= comparison always return true 
	if (np1 >= np2) 
		cout << "can compare" << endl; 
	else
		cout << "can not compare" << endl; 

	// Initialize a pointer with value equal to np1 
	char *x = np1; // same as x = nullptr (or x = NULL will also work) 
	if (x == nullptr) 
		cout << "x is null" << endl; 
	else
		cout << "x is not null" << endl;

    int *p = nullptr;
    if (p) 
		cout << "p is true" << endl; 
	else
		cout << "p is false" << endl;

	return 0; 
} 
