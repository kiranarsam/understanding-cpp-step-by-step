#include <iostream>
using namespace std;

class Base {
    public:
        virtual void func(int x = 0) {
            cout << "Base::func(), x = " << x << endl;
        }

        virtual void show(int x = 10) {
            cout << "Base::show(), x = " << x << endl;
        }
};

class Derived : public Base {
    public:
        void func(int x) {
            cout << "Derived::func(), x = " << x << endl;
        }

        void show(int x = 20) {
            cout << "Derived::func(), x = " << x << endl;
        }
};

int main() {
    Derived d1;
    Base *bp = &d1;
    bp->func(); // default value x is 0

    bp->show(); // Here, default value override with base class virtual functions
                // default value x is 10, and not 20
    return 0;
}