#include <iostream>
using namespace std;

class Base {
    public:
        virtual void display() {
            cout << "Base::display() " << endl;
        }
};

class Derived : public Base {
    public:
        void display() {
            cout << "Derived::display() " << endl;
        }
};

int main() {
    /*Here, virtual function who() is called through object of the class
      (it will be resolved at compile time) so it can be inlined
    */
    Base b;
    b.display();

    /* Here, virtual function is called through pointer, so it cannot be inlined. */
    Base *bp = new Derived;
    bp->display();
    
    return 0;
}