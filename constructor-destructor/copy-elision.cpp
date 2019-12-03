#include <iostream> 
using namespace std; 

class B {
    public:
        B(const char *str = "\0") { // Default constructor
            cout << "Constructor called" << endl;
        }

        B(const B& b) { // Copy Constructor
            cout << "Copy constructor called " << endl;
        }
};

int main() {
    B b = "copy me";

    return 0;
}