#include <iostream>
#include <cmath>
using namespace std;

class Complex {
    private:
        double real;
        double imag;
    public:
        // Default constructor
        Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {

        }

        // magnitude
        double magnitude() {
            return getMagnitude();
        }

        // magnitude: conversion operator
        operator double() {
            return getMagnitude();
        }
    private:
        // class helper function to get magnitude
        double getMagnitude() {
            return sqrt(real * real + imag * imag);
        }
};

int main() {
    Complex complex(3.0, 4.0);

    // print magnitude
    cout << complex.magnitude() << endl;

    // complex uses, conversion operator
    cout << complex << endl;

    return 0;
}

/* Here, magnitude is displaying in two ways. 1. normal and 2. conversion operator */
