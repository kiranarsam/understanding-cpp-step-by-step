
#include <iostream>
using namespace std;

class Test {
    protected:
        int x;
    public:
        Test(int i) : x(i) { }
        void func() {
            cout << "func() called" << endl;
        }
        void func() const {
            cout << "func() const called " << endl;
        }
};

int main(int argc, char *argv[]) {
    Test t1 (10);
    const Test t2(20);
    t1.func();
    t2.func();

    return 0;
}
