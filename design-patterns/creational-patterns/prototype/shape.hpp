// Base prototype
#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <iostream>

class Shape {
    private:
        int x;
        int y;
        std::string color;
    public:

        Shape(int a, int b, std::string c) : x(a), y(b), color(c) {
            std::cout << "Shape" << std::endl;
        }

        /*
        Shape(const Shape& source) {
            x = source.x;
            y = source.y;
            color = source.color;
        }
        */

        void setShape(int a, int b, std::string c) {
            x = a;
            y = b;
            color = c;
        }

        int getX() {
            return x;
        }

        int getY() {
            return y;
        }

        std::string getColor() {
            return color;
        }

        virtual void print() {
            std::cout << "Shape: "<< x << "," << y << "," << color << std::endl;
        }

        virtual Shape* clone(){
            std::cout << "Shape::clone()" << std::endl;
            //Shape s(x, y, color);
            return new Shape(x, y, color);
        }

        virtual ~Shape() {
            std::cout << "~Shape" << std::endl;
        }
};

#endif
