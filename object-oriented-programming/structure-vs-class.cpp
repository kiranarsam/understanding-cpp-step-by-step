#include <iostream>
using namespace std;

class Test1 {
    int x; // x is private
};

struct Test2 {
    int x; // x is public
};

class Base {
    public:
        int x;
};

class DerivedClass : Base { // equivalent to ==>  class DerivedClass : private Base {}

};

struct DerivedStruct : Base { // equivalent to ==> struct DerivedStruct : public Base {}

};

int main() {
    Test1 t;
    //t.x = 20; // Error

    Test2 t2;
    t2.x = 20;

    DerivedClass dc;
    //dc.x = 30; // Error 

    DerivedStruct ds;
    ds.x = 30;

    return 0;
}

