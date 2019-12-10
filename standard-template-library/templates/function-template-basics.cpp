#include <iostream>
using namespace std;

template <typename T>
T myMax(T x, T y) {
    return (x > y)? x : y;
}

int main() {
    cout << myMax(3,7) << endl;
    cout << myMax(3.14, 4.13) << endl;
    cout << myMax('g', 'e') << endl;

    return 0;
}