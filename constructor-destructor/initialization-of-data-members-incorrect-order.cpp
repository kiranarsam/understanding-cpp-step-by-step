#include <iostream>
using namespace std;

class Test {
    private:
        int y;
        int x;
    public:
        Test() : x(10), y(x+10) { }
        void print();
};

void Test::print() {
    cout << "x = " << x << ", y= " << y << endl;
}

/*The program prints correct value of x, but some garbage value for y, 
because y is initialized before x as it appears before in the class declaration. */
int main() {
    Test t;
    t.print();
    return 0;
}