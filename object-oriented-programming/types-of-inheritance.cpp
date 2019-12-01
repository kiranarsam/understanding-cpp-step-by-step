#include <iostream>
using namespace std;

// Single Inheritance
class Vehicle {
    public:
        Vehicle() {
            cout << "Vehicle";
        }
};

class Car: public Vehicle {
    public:
        Car() {
            cout << "Car";
        }
};

// Multiple Inheritance
class FourWheeler {
    public:
        FourWheeler() {
            cout << "FourWheeler";
        }
};

class Bus: public Vehicle, public FourWheeler { // sub class derived from two base classes
    public:
        Bus() {
            cout << "Bus";
        }
};

// Multilevel Inheritance
class MarutiCar : public Car {
    public:
        MarutiCar() {
            cout << "MarutiCar";
        }
};

// Hierarchical Inheritance
class Scooter: public Vehicle {
    public:
        Scooter() {
            cout << "Scooter";
        }
};

// Hybrid Inheritance
class Fare {
    public:
        Fare() {
            cout << "Fare";
        }
};

class VolvoBus: public Vehicle, public Fare {
    public:
        VolvoBus() {
            cout << "VolvoBus";
        }
};

int main() {
    // Single Inheritance
    Car car1;

    cout << endl;

    // Multiple Inheritance
    Bus bus;

    cout << endl;

    // multiple Inheritance
    Car car2;
    MarutiCar marutiCar;

    cout << endl;

    // Hierarchical Inheritance
    Car car3;
    Scooter scooter;

    cout << endl;

    // Hybrid Inheritance
    Car car4;
    VolvoBus volvobus;

    cout << endl;
    return 0;
}
