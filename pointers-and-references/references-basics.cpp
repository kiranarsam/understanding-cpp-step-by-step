#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int &ref = x; // ref is a reference to x

    ref = 20; // value of x is changed to 20
    cout << "x = " << x << endl;

    x = 30; // vlaue of ref is changed to 30
    cout << "ref = " << ref << endl;

    return 0;
}