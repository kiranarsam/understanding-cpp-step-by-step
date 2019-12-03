#include <iostream>
using namespace std;

class Test {
    public:
        int a;
        Test() {
            a = 10;
            cout << "Constructor is executed" << endl;
        }
        ~Test() {
            cout << "Destructor is executed" << endl;
        }
};

static Test obj; // global static object

int main() {
    cout << "Main starts" << endl;
    cout << "obj.a = " << obj.a << endl;
    cout << "Main ends" << endl;
    return 0;
}
