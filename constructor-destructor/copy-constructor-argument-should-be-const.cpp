#include <iostream>
using namespace std;

class Test {
    public:
        Test(Test &t) { }
        Test() { }
};

Test func() {
    cout << "func() is called " << endl;
    Test t;
    return t;
}

int main() {

    Test t1;
    Test t2 = func();
    return 0;
}
/**
 * Compiler Error: Test t2 = fun(); // cannot bind non-const lvalue referce to an rvalue
 * Works: If we change at line 6: Test(const Test &t) { }
*/
