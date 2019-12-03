#include <iostream>
using namespace std;

class Final; // Forward declaration, The class  to be made Final

class MakeFinal {
    private:
        MakeFinal() {
            cout << "MakeFinal Constructor " << endl;
        }

    friend class Final;
};

class Final : virtual MakeFinal {
    public:
        Final() {
            cout << "Final Constructor " << endl;
        }
};

/**
 * In constructor 'Derived::Derived()
 * error: 'MakeFinal::Makefinal()' is private within this context
 * error: 'MakeFinal::MakeFinal()' is inaccessible
*/
/*
class Derived : public Final {      // This will give compiler error
    public:
        Derived() {
            cout << "Derived Constructor" << endl;
        }
};

class Derived2 : public MakeFinal { // Compiler error
    public:
        Derived2() {
            cout << "Derived2 Constructor " << endl;
        }
};
*/
int main(int argc, char *argv[]) {
    Final f;
    return 0;
}