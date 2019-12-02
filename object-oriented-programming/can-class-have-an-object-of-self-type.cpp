
#include <iostream>
using namespace std;

// static member of self type
class Test1 {
    static Test1 self; // works fine
};

// class have a pointer to self type
class Test2 {
    Test2 *self; // works fine
};

class Test3 {
    //Test3 self; // Error, it is non-static
};

int main() {
    Test1 t;
    Test2 t2;
    Test3 t3;

    return 0;
}


