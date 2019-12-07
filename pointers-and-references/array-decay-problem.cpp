#include <iostream>
using namespace std;

// function to show Array Decay, passing array by value
void arrDecay(int *p) {
    // printing the size of pointer
    cout << "Modified size of array is by passing by value: ";
    cout << sizeof(p) << endl;
}

// Array Decay In case of pointer as well
void ptrDecay(int (*p)[7]) {
    cout << "Modified size of array is by passing by pointer: ";
    cout << sizeof(p) << endl;
}

int main() {
    int a[7] = {1,2,3,4,5,6,7};

    cout << "Actual size of array is: ";
    cout << sizeof(a) << endl;

    // calling function by value
    arrDecay(a);

    // calling function by pointer
    ptrDecay(&a);

    return 0;
}