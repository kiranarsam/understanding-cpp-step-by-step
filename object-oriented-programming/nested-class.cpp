#include <iostream>

using namespace std;

class Enclosing {
    private:
        int x;
    
        class Nested {
            int y;
            void NestedFun(Enclosing *e) {
                cout << e->x << endl; // nested class can access private members of Enclosing class
            }
        };
};

class Enclosing2 {
    int x;

    class Nested {
        int y;
    };

    void Enclosing2Fun(Nested *n) {
        // cout << n->y << endl; // Comiler error, y is private in Nested
    }
};

int main() {

    return 0;
}