#include <iostream>
#include <complex>
using namespace std;

// imaginary literal
constexpr complex <double> operator"" _i(long double d) {
    return complex <double> { 0.0 , static_cast<double>( d )};
}

int main() {
    complex<double> z = 3.0 + 4.0_i;
    complex<double> y = 2.3 + 5.0_i;

    cout << "z + y = " << z + y << endl;
    cout << "z * y = " << z * y << endl;

    cout << "abs(z) = " << abs(z) << endl;

    return 0;
}