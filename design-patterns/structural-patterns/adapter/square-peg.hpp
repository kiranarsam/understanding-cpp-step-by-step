#ifndef SQUARE_PEG_HPP
#define SQUARE_PEG_HPP

#include <iostream>

class SquarePeg {
    private:
        int width;
    public:
        SquarePeg(int w = 0) :width(w) {
            std::cout << "SquarePeg" << std::endl;
        }

        int getWidth() {
            std::cout << "SquarePeg::getWidth()" << std::endl;
            return width;
        }
        ~SquarePeg() {
            std::cout << "~SquarePeg" << std::endl;
        }
};

#endif