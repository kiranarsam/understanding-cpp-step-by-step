#include <iostream>
using namespace std;

class ImplementAbstraction {
    private:
        int a, b;
    public:
        // Methods to set values of private members
        void set(int x, int y) {
            a = x;
            b = y;
        }

        void display() {
            cout << "a = " << a << endl;
            cout << "b = " << b << endl;
        }
};

int main() {
    ImplementAbstraction obj;

    obj.set(20,30);
    obj.display();
    return 0;
}