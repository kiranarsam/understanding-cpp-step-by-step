#include <iostream>
using namespace std;

struct Demo {
    int a;
};

int main() {
    int x = 5;
    int y = 6;

    Demo d;

    int *p;
    p = &x;
    p = &y; // 1. pointer reinitialization allowed
    int &ref = x;
    // &ref = y; // Compiler Error
    ref = y; // x value becomes 6

    p = NULL;
    // &ref = NULL; // Compiler Error

    p++; // points to next memory location
    ref++; // x value becomes 7

    cout << &p << " " << &x << endl; // different address 
    cout << &ref << " " << &x << endl; // same address

    Demo *q = &d;
    Demo &qq = d;

    q->a = 8;
    // q.a = 8; // Compiler error
    qq.a = 10;
    // qq->a = 10; // Compiler Error

    cout << p << endl; // prints the address
    cout << ref << endl; // prints the value of x

    return 0;
}