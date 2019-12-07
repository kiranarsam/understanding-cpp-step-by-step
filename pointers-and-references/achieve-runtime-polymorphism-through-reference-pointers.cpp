#include <iostream>
using namespace std;

class Base {
    public:
        virtual void display() const {
            cout << "This is Base Class display." << endl;
        }
};

class Derived : public Base {
    public:
        void display() const {
            cout << "This is Derived class display." << endl;
        }
};

void Display(Base &b) {
    b.display();
}

int main() {
    Base b;
    Derived d;
    Display(b);
    Display(d);

    return 0;
}