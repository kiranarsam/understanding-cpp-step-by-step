#include <iostream>
using namespace std;

class Test {
    public:
        Test() {
            cout << "Default constructor " << endl;
        }

        Test(const Test &t) {
            cout << "Copy constructor " << endl;
        }

        Test & operator=(const Test &t) {
            cout << "Assignment operator " << endl;
            return *this;
        }
};

int main() {
    Test t1, t2;
    t2 = t1; // Assignment Operator
    Test t3 = t1; // Copy Constructor

    return 0;
}
