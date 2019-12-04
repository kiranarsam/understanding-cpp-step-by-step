#include <iostream>
using namespace std;

class Fraction {
        int num, den;
    public:
        Fraction(int n = 0, int d = 0) : num(n), den(d) { }

        // Conversion operator: return float value of fraction
        operator float() const {
            return float(num) / float(den);
        }

        void print() {
            cout << "num = " << num << ", den = " << den << endl;
        }
};



int main() {
    Fraction f(5,10);
    float val = f;
    cout << "val = " << val << endl;

    // Automatically does implicit conversion with single argument
    Fraction f2(2,10);
    f2.print();
    f2 = 30; // Member num of f2 becomes 30, Here I have changed constructos to default.
    f2.print();

    return 0;
}