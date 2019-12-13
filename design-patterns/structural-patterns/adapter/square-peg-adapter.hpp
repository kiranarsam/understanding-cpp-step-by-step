#ifndef SQUARE_PEG_ADAPTER_HPP
#define SQUARE_PEG_ADAPTER_HPP

#include "round-peg.hpp"
#include "square-peg.hpp"
#include <cmath>

class SquarePegAdapter : public RoundPeg {

    private:
        SquarePeg *peg;
    public:
        SquarePegAdapter(SquarePeg* sp = nullptr, int rp = 5) : RoundPeg(rp) {
            std::cout << "SquarePegAdapter" << std::endl;
            peg = sp;
        }

        int getRadius() {
            std::cout << "SquarePegAdapter::getRadius()" << std::endl;
            if(peg) {
                return peg->getWidth() * sqrt(2) / 2;
            }
            else {
                return 0;
            }
        }
        ~SquarePegAdapter() {
            std::cout << "~SquarePegAdapter" << std::endl;
        }

};

#endif