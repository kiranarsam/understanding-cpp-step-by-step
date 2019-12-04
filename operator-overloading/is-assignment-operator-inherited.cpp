#include <iostream>
using namespace std;

class Base {
    public:
        Base& operator=(const Base& b) {
            cout << "Base class assignment operator called " << endl;
            return *this;
        }
};

class Derived : public Base {
    public:
        Derived& operator=(const Derived& d) {
            cout << "Derived class assignment operator called " << endl;
            return *this;
        }
};

int main() {
    Derived d1, d2;
    d1.Base::operator=(d2); // calling Base class assignment operator function
                            // usng derived class
    d1 = d2;
    return 0;
}