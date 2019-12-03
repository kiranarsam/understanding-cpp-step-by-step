
#include <iostream>
using namespace std;
int y;

void fun() {

    static int x;
    enum {MIN, MAX};

    class Test {

        public:
            void method() {
                cout << "Local class method() called " << endl;
                cout << "x = " << x << endl;
                cout << "MIN = " << MIN << endl;
            }

            static void display() {
                cout << "Local class display() static method called " << endl;
            }
    };

    class Test2 {
        Test t;
        public:
            void show() {
                cout << "y = " << y << endl;
            }

    };

    Test t;
    t.method();
    Test::display();
}

int main() {
    fun();
    return 0;
}