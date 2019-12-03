#include <iostream>
using namespace std;

class Test {
    public:
        Test() {
            cout << "Constructor is executed" << endl;
        }
        ~Test() {
            cout << "Destructor is executed" << endl;
        }
};

void func() {
    static Test obj; // local static object
}

int main() {
    cout << "Main starts" << endl;
    func();
    cout << "Main ends" << endl;
    return 0;
}

// the local object is static so it has scope till the lifetime of program 
// so it’s destructor will be called when main() terminates

/** What happens when we remove static in above program?
 * the object is now stack based object and it is destroyed 
 * when it is goes out of scope and its destructor will be called.
*/ 
