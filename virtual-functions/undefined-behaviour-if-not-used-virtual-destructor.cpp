#include <iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout << "Constructing Base " << endl;
        }

        ~Base() {
            cout << "Destructing Base " << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            cout << "Constructing Derived " << endl;
        }

        ~Derived() {
            cout << "Destructing Derived " << endl;
        }
};

int main() {
    Derived *d = new Derived;
    Base *bp = d;

    delete bp; // Deleting base pointer, just check the result, how it behaves

    return 0;
}

// Although the output of following program may be different on different compilers

// Making base class destructor virtual guarantees that the object of derived class is 
// destructed properly, i.e., both base class and derived class destructors are called.