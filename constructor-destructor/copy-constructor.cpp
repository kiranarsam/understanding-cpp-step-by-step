#include <iostream>
using namespace std;

class Point {
    private:
        int x, y;
    public:
        Point(int x1, int y1) : x(x1), y(y1) {

        }

        //Copy Constructor
        Point(const Point &p) {
            x = p.x;
            y = p.y;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }
};

int main() {
    Point p1(10,20); // Normal constructor
    Point p2 = p1; // copy constructor is called here

    cout << "p1.x = " << p1.getX() << ",p1.y = " << p1.getY() << endl;
    cout << "p2.x = " << p2.getX() << ",p2.y = " << p2.getY() << endl;

    return 0;
}