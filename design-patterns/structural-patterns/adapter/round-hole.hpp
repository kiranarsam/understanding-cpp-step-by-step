#ifndef ROUND_HOLE_HPP
#define ROUND_HOLE_HPP

#include "round-peg.hpp"
#include <iostream>

class RoundHole {
    private:
        int radius;
    public:
        RoundHole(int r = 0) : radius(r) {
            std::cout << "RoundHole" << std::endl;
        }

        int getRadius() {
            std::cout << "RoundHole::getRadius()" << std::endl;
            return radius;
        }

        bool fits(RoundPeg *rp) {
            std::cout << "RoundHole::fits()" << std::endl;
            return (getRadius() >= rp->getRadius());
        }
        ~RoundHole() {
            std::cout << "~RoundHole" << std::endl;
        }
};


#endif