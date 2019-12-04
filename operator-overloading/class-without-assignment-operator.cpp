#include <iostream>
using namespace std;

class Test {
        int *ptr;
    public:
        Test(int i = 0) {
            ptr = new int(i);
        }

        void setValue(int i) {
            *ptr = i;
        }

        void print() {
            cout << "*ptr = " << *ptr << endl;
        }
};

int main() {
    Test t1(5); // Assume t1 pointer address = 1200, value = 5
    Test t2;  // t2 pointer address = 1400, value = 0

    t2 = t1; // t1 address is copied in t2. So, t2 address = 1200

    t1.setValue(10); // Inside t1, value = 10
    t2.print(); // In t2, ptr is pointing to ptr of t1. So, it prints, "*ptr = 10"

    return 0;
}