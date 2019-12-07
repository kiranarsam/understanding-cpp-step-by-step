#include <iostream>
using namespace std;

int fun(int &x) {
    x = 20;
}

int main() {
    int x = 10;
    fun(x);

    cout << "x = " << x << endl;
    
    return 0;
}