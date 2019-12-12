#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include <string>

class Circle : public Shape {
    private:
        int radius;
    public:
        Circle(int x = 0, int y = 0, std::string color = "", int r = 0) : Shape(x, y, color) {
            std::cout << "Circle" << std::endl;
            setRadius(r);
        }

        void setRadius(int r) {
            radius = r;
        }

        int getRadius() {
            return radius;
        }

        /*
        Circle(const Circle &source) {
            radius = source.radius;
        }

        Circle(const Circle *source) {
            radius = source->radius;
        }
        */

        void print() {
            Shape::print();
            std::cout << "Circle: " << radius << std::endl;
        }

        Shape* clone() {
            std::cout << "Circle::clone()" << std::endl;
            //Circle shape(getX(), getY(), getColor(), radius);
            return new Circle (getX(), getY(), getColor(), radius);
        }

        ~Circle() {
            std::cout << "~Circle" << std::endl;
        }
};

#endif