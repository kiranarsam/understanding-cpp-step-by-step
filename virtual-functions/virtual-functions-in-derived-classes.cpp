#include <iostream>
using namespace std;

class Base {
    public:
        virtual void show() {
            cout << "Base::show() called" << endl;
        }
};

class Derived1 : public Base
{
    public:
        void show() {
            cout << "Derived1::show() called" << endl;
        }
};

class Derived2 : public Derived1 {
    public:
        void show() {
            cout << "Derived2::show() called" << endl;
        }
};

int main() {
    Derived2 d2;
    Base *bp = &d2;

    bp->show(); // "Derived2::show()"

    return 0;
}