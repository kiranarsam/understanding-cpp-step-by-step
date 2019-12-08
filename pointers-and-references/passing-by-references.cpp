#include <iostream>
using namespace std;

void swap(int &x, int &y) {
    int z = x;
    x = y;
    y = z;
}

int main() {
    int a = 45, b = 55;

    cout << "Before swap: " << a << ", " << b << endl;
    swap(a, b);
    cout << "After swap: " << a << ", " << b << endl;

    return 0;
}