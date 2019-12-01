#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Test {
    public:
        void func(int x) {
            cout << "Value of x = " << x << endl;
        }

        void func(double x) {
            cout << "Value of x = " << x << endl;
        }

        void func(int x, int y) {
            cout << "Value of x and y is " << x << ", " << y << endl;
        }
};

int main() {
    Test t;
    t.func(30);
    t.func(32.46);
    t.func(32, 46);

    return 0;
}