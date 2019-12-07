#include <iostream>
using namespace std;

class Employee {
    public:
        void fun() {
            delete this;
        }
};

int main() {
    Employee *emp = new Employee;
    emp->fun();
    emp = NULL; // Make ptr NULL to make sure that things are not accessed using ptr.

    // Invalid and undefined behaviour (Aborted (Core Dumped))
    Employee e;
    e.fun();

    return 0;
}