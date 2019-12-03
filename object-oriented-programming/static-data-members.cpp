#include <iostream>
using namespace std;

class Fruits {
        int numberOfFruits;
    public:
        Fruits() {
            cout << "Fruits's constructor called" << endl;
        }
};

class RedFruits {
        static Fruits fruits;
    public:
        RedFruits() {
            cout << "RedFruits constructor called" << endl;
        }
        static Fruits getFruits() {
            return fruits;
        }
};

// Still static data members is not initialized, if try to access, will leads to error.

// definition of static data member fruits
Fruits RedFruits::fruits;

int main() {
    Fruits obj = RedFruits::getFruits();
    RedFruits rf1, rf2, rf3;
    Fruits obj2 = RedFruits::getFruits();

    return 0;
}
