#include <iostream>
using namespace std;

class Pet {
    public:
        virtual string getDescription() const {
            return "This is Pet Class";
        }
};

class Dog : public Pet {
    public:
        string getDescription() const {
            return "This is Dog Class";
        }
};

// Here, slices the derived class object
void describe(Pet p) {
    cout << p.getDescription() << endl;
}

int main() {
    Dog d;
    describe(d);
    
    return 0;
}