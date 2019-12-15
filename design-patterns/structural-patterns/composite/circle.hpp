#ifndef CIRCLE_GRAPHIC_HPP
#define CIRCLE_GRAPHIC_HPP

#include "dot.hpp"
#include <iostream>

class Circle : public Dot {
    private:
        int radius;
    public:
        Circle(int x, int y, int r) : Dot(x,y), radius(r) {
            std::cout << "Circle" << std::endl;
        }

        void draw() {
            std::cout << "Circle::draw()" << std::endl;
        }

        ~Circle() {
            std::cout << "~Circle" << std::endl;
        }
};

#endif