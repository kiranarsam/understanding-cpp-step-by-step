
#include <iostream>
#include <vector>

#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

using namespace std;

class Application {
    private:
        vector<Shape *> shapes;
    public:
        Application() {
            std::cout << "Application" << std::endl;
            shapes = vector<Shape*>();
        }

        void createShapes() {
            //vector<Shape> shapes;
            //Circle c1;
            shapes.push_back(new Circle());

            //Circle c2(10, 20, "RED", 15);
            shapes.push_back(new Circle(10, 20, "RED", 15));

            //Rectangle r1;
            shapes.push_back(new Rectangle());

            //Rectangle r2(5, 15, "GREEN", 20, 30);
            shapes.push_back(new Rectangle(5, 15, "GREEN", 20, 30));

            std::cout << "Vector Size: " << shapes.size() << std::endl;
            print();
        }

        void print() {
            for(auto it = shapes.begin(); it != shapes.end(); it++) {
                (*it)->print();
            }
        }

        void businessLogic() {

            vector<Shape*> shapesCopy;

            for(auto it = shapes.begin(); it != shapes.end(); it++) {
                shapesCopy.push_back((*it)->clone());
            }

            std::cout << "Vector shapesCopy Size: " << shapesCopy.size() << std::endl;

            for(auto it = shapesCopy.begin(); it != shapesCopy.end(); it++) {
                (*it)->print();
            }

            clear(shapesCopy);
        }

        void clear(vector<Shape*> &vect) {
            for(; vect.size() != 0;) {
                Shape *temp = vect.back();
                vect.pop_back();
                delete temp;
            }
        }

        ~Application() {
            std::cout << "~Application IN" << std::endl;
            clear(shapes);
            std::cout << "~Application OUT" << std::endl;
        }
};

// test the code
int main() {
    Application app;
    app.createShapes();
    app.businessLogic();

    return 0;
}