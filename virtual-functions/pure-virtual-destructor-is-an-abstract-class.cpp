#include <iostream>
using namespace std;

class Test {
    public:
        virtual ~Test() = 0; // pure virtual destructor
};

Test::~Test() {
    cout << "Pure virtual destructor, Test is called " << endl;
}

int main() {
    Test t;
    Test *t1 = new Test;

    return 0;
}
// Compiler Error: U cannot declare a variable 't' of abstract type 'Test', 
// Compiler Error: U cannot allocate an object of abstract type 'Test'