#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

class Complex {
    private:
        double real;
        double imag;
    public:
        // Constructor
        Complex(double re = 0, double im = 0) : real(re), imag(im) {
            cout << "Constructor: (" << real << ", " << imag << ")" << endl;
        }

        // Destructor
        ~Complex() {
            cout << "Destructor: (" << real << ", " << imag << ")" << endl;
        }

        double normal() {
            return sqrt(real*real + imag*imag);
        }

        void print() {
            cout << "|" << real << " + j" << imag << "| = " << normal() << endl;
        }
};

int main() {

    // buffer on stack
    unsigned char buf[100];

    Complex *pc = new Complex(4.2, 5.3);
    Complex *pd = new Complex[2];

    //using placement new
    Complex *pe = new (buf) Complex(2.6, 3.9);

    //Use objects
    pc->print();
    pd[0].print();
    pd[1].print();
    pe->print();

    // Release objects. Call destructor and then release memory
    delete pc;

    delete [] pd;

    // No delete: Explicit call to destructor
    pe->~Complex();

    return 0;
}

/*
Explanation: Here the destructor is explicitly called because 
here it cannot be packaged within the delete operator because 
delete will need to release the memory which you do not have here and 
it cannot be implicit as it is a dynamic process which we want to mange yourself.
*/
