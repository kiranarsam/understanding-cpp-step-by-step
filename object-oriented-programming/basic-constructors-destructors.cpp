
#include <iostream>
using namespace std;

class Test {
    public:
        int id;

        Test() {
            cout << "Default constructor called" << endl;
            id = -1;
        }

        Test(int x) {
            cout << "Parameterized constructor called" << endl;
            id = x;
        }

        ~Test() {
            cout << "Destructor called for id: " << id << endl;
        }
};

int main() {
    Test t1;
    Test t2(46);

    return 0;
}