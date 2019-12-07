#include <iostream>
using namespace std;

class Base {
    public:
        virtual ~Base() = 0; // pure virtual destructor
};

class Derived : public Base {
    public:
        ~Derived() {
            cout << "~Derived() is executed " << endl;
        }
};

int main() {
    Base *bp = new Derived;
    delete bp;

    return 0;
}

// Linker will produce the an error says:
// undefined reference to 'Base::~Base'
// How to make it work, check next following example.