
#include <iostream>
using namespace std;

class Test {
        int *ptr;
    public:
        Test(int i = 0) {
            ptr = new int(i);
        }

        Test(const Test &t) {
            if(ptr) {
                delete ptr;
            }
            ptr = new int(0);
            *ptr = *(t.ptr);
        }

        void setValue (int i) {
            *ptr = i;
        } 
        
        void print() {
            cout << *ptr << endl;
        }

        Test& operator=(const Test &t) {
            // check for self assignment
            if(this != &t) {
                if(ptr) {
                    delete ptr;
                }
                ptr = new int(0);
                *ptr = *(t.ptr);
            }

            return *this;
        }
};

int main() {
    Test t1(5);
    Test t2(30);

    Test t3 = t2; // Copy constructor
    t3.print(); // 30

    t2 = t1; // Assignment operator

    t1.setValue(10); // Change value in t1 obj
    t2.print(); // 5

    t1.print(); // 10
    return 0;
}