#include <iostream>
using namespace std;

class Test {
    private:
        int x; // Change the order of declaration
        int y;
    public:
        Test() : x(10), y(x+10) { }
        void print();
};

void Test::print() {
    cout << "x = " << x << ", y= " << y << endl;
}

class Test2 {
    private:
        int y;
        int x;
    public:
        Test2() : x(y-10), y(20) { } // Change order for correct initialization
        void print();
};

void Test2::print() {
    cout << "x = " << x << ", y= " << y << endl;
}

int main() {
    Test t;
    t.print();
    Test2 t2;
    t2.print();
    return 0;
}