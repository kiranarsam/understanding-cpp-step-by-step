#include <iostream>
using namespace std;

class Base {
    private:
        virtual void fun() {
            cout << "Base::fun() " << endl;
        }
    friend int main();
};

class Derived : public Base {
    public:
        void fun() {
            cout << "Derived::fun() " << endl;
        }
};

int main() {
    Base *ptr = new Derived;
    ptr->fun();
    return 0;
}