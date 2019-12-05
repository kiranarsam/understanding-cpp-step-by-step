#include <iostream>
using namespace std;

class Test {
    virtual static void show() { 
        cout << "Test::show() " << endl;
    }

    static void display() const {
        cout << "Test::display() " << endl;
    }
};

// Compiler error: static function cannot be virtual function
// Compiler error: static function cannot be const or volatile


