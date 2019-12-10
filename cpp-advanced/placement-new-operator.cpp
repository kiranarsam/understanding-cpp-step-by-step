#include <iostream>
using namespace std;

int main() {

    // initial value of x
    int x  = 10;

    cout << "Before placement new: " << endl;
    cout << "x: " << x << endl;
    cout << "&x: " << &x << endl;

    // placement new changes the value of x to 100
    int *mem = new (&x) int(100);

    cout << "After placement new : " << endl;
    cout << "x: " << x << endl;
    cout << "mem : " << mem << endl;
    cout << "&x: " << &x << endl;

    return 0;
}

/*
Explanation: Here, it is clear that a new value of x is assigned 
at the address of x with the help of placement new operator. 
This is clear by the fact that the value of &X and mem is equal.
*/