#include <iostream> 
using namespace std; 

class Complex 
{ 
    private: 
        double real; 
        double imag; 

    public: 
        // Default constructor 
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {} 

        // A method to compare two Complex numbers 
        bool operator == (Complex rhs) { 
            return (real == rhs.real && imag == rhs.imag)? true : false; 
        } 
}; 

class Complex2 
{ 
    private: 
        double real; 
        double imag; 

    public: 
        // Default constructor 
        explicit Complex2(double r = 0.0, double i = 0.0) : real(r), imag(i) {} 

        // A method to compare two Complex numbers 
        bool operator == (Complex2 rhs) { 
            return (real == rhs.real && imag == rhs.imag)? true : false; 
        } 
};

int main() 
{ 
	// a Complex object 
	Complex com1(3.0, 0.0); 

	if (com1 == 3.0) 
	    cout << "Same"; 
	else
	    cout << "Not Same";

	// a Complex object 
	Complex2 com2(3.0, 0.0); 
/*
	if (com2 == 3.0)  // gives an error, no match for 'operator =='
	    cout << "Same"; 
	else
	    cout << "Not Same";
*/
    // We can still typecast the double values with complex
    	// a Complex object 
	if (com2 == (Complex2)3.0) 
	    cout << "Same"; 
	else
	    cout << "Not Same"; 
	return 0; 
} 
