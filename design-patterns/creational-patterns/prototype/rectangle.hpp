// Concrete prototype. The cloning method creates a new object
// and passes it to the constructor. Until the constructor is
// finished, it has a reference to a fresh clone. Therefore,
// nobody has access to a partly-built clone. This keeps the
// cloning result consistent.

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle : public Shape {
    private:
        int width;
        int height;
    public:
        Rectangle(int x = 0, int y = 0, std::string color = "", int w = 0, int h = 0)
                : Shape(x, y, color)
        {
            std::cout << "Rectangle" << std::endl;
            setRectangle(w, h);
        }

        void setRectangle(int w, int h) {
            width = w;
            height = h;
        }
        int getWidth() {
            return width;
        }

        int getHeight() {
            return height;
        }
        /*
        Rectangle(const Rectangle &source) {
            width = source.width;
            height = source.height;
            setShape()
        }

        Rectangle(const Rectangle *source) {
            width = source->width;
            height = source->height;
        }
        */

        void print() {
            Shape::print();
            std::cout << "Rectangle: " << width << ", " << height << std::endl;
        }
        Shape* clone() {
            std::cout << "Rectangle::clone()" << std::endl;
            //Rectangle shape(getX(), getY(), getColor(), width, height);
            return new Rectangle(getX(), getY(), getColor(), width, height);
        }

        ~Rectangle() {
            std::cout << "~Rectangle" << std::endl;
        }
};

#endif