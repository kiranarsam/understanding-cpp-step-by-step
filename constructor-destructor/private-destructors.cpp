#include <iostream>
#include <stdlib.h>
using namespace std;

// class declaration is fine, but we cannot create object " Test t; "
class Test {
    private:
        ~Test() { }
    friend void destructTest(Test *);
};

void destructTest(Test *ptr) {
    delete ptr;
}

int main() {

    // Test t; // You cannot do object creation for private destructor.

    // You can initialise pointer
    Test *t; // Object is not created, but creates a pointer of type "Test *"

    Test *p = new Test; // This also fine, created dynamic memory allocation.
                        // It is programmers responsibility to delete it.

    //delete p; // You cannot do directly deleted created object.
                // But u can do only this "friend class"
    destructTest(p); // friend class, to delete the created object

    /* Malloc and Free usage on private destructor. */
    Test *p2 = (Test *)malloc(sizeof(Test)); // You can do malloc 
    free(p2); // directly can be done free

    return 0;
}
