#include <iostream>
using namespace std;

//Example:-
// Pure virtual function make a class abstract
// An abstract class
class Test {
        /* Data members of class */
    public:
        virtual void show() = 0; // Pure Virtual Functions
        /* Other members */
};

//A complete example:-
class Base {
        int x;
    public:
        virtual void fun() = 0;

        int getX() {
            return x;
        }
};

class Derived : public Base {
        int y;
    public:
        void fun() {
            cout << "fun() called " << endl;
        }
};

class Derived2 : public Base {

};

class Shape {
    protected:
        int x;
    public:
        virtual void display() = 0;
        Shape(int i) : x(i) {

        }
};

class Circle : public Shape {
    private:
        int y;
    public:
        Circle(int i, int j) : Shape(i), y(j) {

        }
        void display() {
            cout << "x = " << x << ", y = " << y << endl;
        }
};

int main() {

    //Test t; // Compiler error: object t is an abstract, following virtual function is pure.

    Derived d;
    d.fun();

    // We can have pointers or references of abstract class type
    Base *bp = new Derived;
    bp->fun();

    // Derived2 is not defined pure virtual function of Base, so, Derived2 class also becomes abstract
    // U cannot instantiate Derived2 object
    //Derived2 d2; //Give error, d2 is still an abstract class type.

    // An abstract class can have constructors.
    Shape *s = new Circle(10,20);
    s->display();

    return 0;
}
