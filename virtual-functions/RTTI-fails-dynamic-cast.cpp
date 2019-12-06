#include <iostream>
using namespace std;

// Run-Time Type Identification

class Base {

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

// Compiler Error:
// error: cannot dynamic_cast ‘b’ (of type ‘class Base*’) to type ‘class Derived*’ 
// (source type is not polymorphic)