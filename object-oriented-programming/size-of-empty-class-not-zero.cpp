#include <iostream>
using namespace std;

class Empty {

};

class Derived : Empty {
    int a;
};

class Derived1 : public Empty {

};

class Derived2 : virtual public Empty {

};

class Derived3 : public Empty {
    char c;
};

class Derived4 : virtual public Empty {
    char c;
};

class Dummy {
    char c;
};

int main() {

    Empty a, b;

    cout << "sizeof(Empty) = " << sizeof(Empty) << endl;

    if(&a == &b) {
        cout << "Impossible " << endl;
    }
    else {
        cout << "Fine " << endl;
    }

    Empty *p1 = new Empty;
    Empty *p2 = new Empty;

    if(p1 == p2) {
        cout << "Impossible " << endl;
    }
    else {
        cout << "Fine " << endl;
    }

    delete p1;
    delete p2;

    cout << "sizeof(Derived) = " << sizeof(Derived) << endl;

    cout << "sizeof(Empty) = " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) = " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) = " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) = " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) = " << sizeof(Derived4) << endl;
    cout << "sizeof(Dummy) = " << sizeof(Dummy) << endl;

    return 0;
}