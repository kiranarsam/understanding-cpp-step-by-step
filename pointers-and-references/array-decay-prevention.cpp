#include <iostream>
using namespace std;

// Passing array by reference, to prevent array decay
void fun(int (&p)[7]) {
    cout << "Modified size of array by passing by reference: ";
    cout << sizeof(p) << endl;
}

int main() {
    int a[7] = {1, 2, 3, 4, 5, 6, 7};

    // Actual array size
    cout << "Actual array size: ";
    cout << sizeof(a) << endl;

    // calling function by reference
    fun(a);

    return 0;
}