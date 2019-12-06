#include <iostream>
using namespace std;

// Run-Time Type Identification

class Base {
    virtual void func() { }
};

class Derived : public Base {

};

int main() {
    Base *b = new Derived;

    Derived *d = dynamic_cast<Derived *>(b);

    if(d != NULL) {
        cout << "dynamic_cast uses RTTI, works fine " << endl;
    }
    else {
        cout << "Cannot cast Base* to Derived* " << endl;
    }

    return 0;
}

// We have atleat one virtual function.
// So, above RTTI works fine with dynamic_cast
