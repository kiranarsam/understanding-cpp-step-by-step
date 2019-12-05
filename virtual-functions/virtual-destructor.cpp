#include <iostream>
using namespace std;

class Base {
    public:
        Base() {
            cout << "Constuctor Base " << endl;
        }

        virtual ~Base() {
            cout << "Destructor Base " << endl;
        }
};

class Derived : public Base {
    public:
        Derived() {
            cout << "Contructor Derived" << endl;
        }

        ~Derived() {
            cout << "Destructor Derived" << endl;
        }
};

int main() {
    Derived *d = new Derived;
    Base *bp = d;

    delete bp;

    return 0;
}