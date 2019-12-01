#include <iostream>
using namespace std;

class Circle
{
    public:
        double radius;

        double compute_area() {
            return 3.14 * radius * radius;
        }
    private:
        double radius2;
    
    public:
        void compute_area(double rad) {
            radius2 = rad;
            double area = 3.14 * radius2 * radius2;

            cout << "Radius is: " << radius2 << endl;
            cout << "Area is: " << area << endl;
        }
};

class Parent {
    protected:
        int id_protected;
};

class Child : public Parent {
    public:
        void setId(int id) {
            id_protected = id;
        }

        void displayId() {
            cout << "id_protected is: " << id_protected << endl;
        }
};

int main()
{
    Circle obj;

    obj.radius = 5.5;
    cout << "Radius is: " << obj.radius << "\n";
    cout << "Area is: " << obj.compute_area() << endl;

    obj.compute_area(1.5);

    Child ob;
    ob.setId(81);
    ob.displayId();

    return 0;
}