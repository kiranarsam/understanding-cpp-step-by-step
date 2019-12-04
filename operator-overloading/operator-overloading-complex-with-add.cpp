#include <iostream>
using namespace std;

class Complex {
    private:
        int real;
        int imag;
    public:
        Complex(int r = 0, int i = 0) : real(r), imag(i) {

        }

        Complex operator+(const Complex &c){
            Complex obj;
            obj.real = real + c.real;
            obj.imag = imag + c.imag;

            return obj;
        }

        void print() {
            cout << real << " + i" << imag << endl;
        }
};

int main() {
    Complex c1(10,5), c2(2,4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();

    return 0;
}