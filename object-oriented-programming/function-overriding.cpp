#include <iostream>
using namespace std;

class Base {
    public:
        virtual void print() {
            cout << "Print Base Class" << endl;
        }
        void show() {
            cout << "Show Base Class" << endl;
        }
};

class Derived: public Base {
    public:
        void print() {
            cout << "Print Derived Class" << endl;
        }

        void show() {
            cout << "Show Derived Class" << endl;
        }
};

int main() {

    Base *bptr;
    Derived d;
    bptr = &d;

    bptr->print(); // virtual function, binded at runtime (runtime polymorphism)
    bptr->show(); // Non-virtual function, binded at compile time

    return 0;
}