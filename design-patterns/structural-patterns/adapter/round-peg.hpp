#ifndef ROUND_PEG_HPP
#define ROUND_PEG_HPP

#include <iostream>

class RoundPeg {
    private:
        int radius;
    public:
        RoundPeg(int r = 0) : radius(r) {
            std::cout << "RoundPeg" << std::endl;
        }

        virtual int getRadius() {
            std::cout << "RoundPeg::getRadius()" << std::endl;
            return radius;
        }

        void setRadius(int r) {
            std::cout << "RoundPeg::setRadius()" << std::endl;
            radius = r;
        }
        virtual ~RoundPeg() {
            std::cout << "~RoundPeg" << std::endl;
        }
};

#endif