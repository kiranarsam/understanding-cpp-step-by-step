#include <iostream>
using namespace std;

class Base {
    public:
        virtual ~Base() = 0; // pure virtual destructor
};

/* Giving definition for pure virtual destructor */
Base::~Base() {
    cout << "Pure virtual destructor is called " << endl;
}

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
