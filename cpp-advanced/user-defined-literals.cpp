// User Defined Literals (UDLs)
#include <iostream>
#include <iomanip>
using namespace std;

// Kilo Gram
long double operator"" _kg(long double x) {
    return x * 1000;
}

// Gram
long double operator"" _g(long double x) {
    return x;
}

// Milli Gram
long double operator"" _mg(long double x) {
    return x / 1000;
}

int main() {
    long double weight = 3.6_kg;
    cout << weight << endl;

    cout << setprecision(8) << (weight + 2.3_mg) << endl;
    cout << (32.3_kg / 2.0_g) << endl;
    cout << (32.3_mg * 2.0_g) << endl;

    return 0;
}