#include <iostream>
using namespace std;

class Student {
    public:
        // Default constructor
        Student() {

        }

};

class Point {
    private:
        int x, y;
    public:
        // Parameterized constructor
        Point(int x1, int y1) {
            x = x1;
            y = y1;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
};

int main() {
    Student s;
    Point p1(10,20);

    //Point p; // This will give compiler error, There is no default constructor
    return 0;
}


