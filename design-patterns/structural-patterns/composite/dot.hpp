#ifndef DOT_GRAPHIC_HPP
#define DOT_GRAPHIC_HPP

#include "graphic.hpp"
#include <iostream>

class Dot : public IGraphic {
    private:
        int x;
        int y;
    public:
        Dot(int a, int b) : x(a), y(b) {
            std::cout << "Dot" << std::endl;
        }

        void move(int i, int j) {
            this->x += i;
            this->y += j;
        }

        void draw() {
            std::cout << "Dot::draw()" << std::endl;
        }

        ~Dot() {
            std::cout << "~Dot" << std::endl;
        }
};

#endif