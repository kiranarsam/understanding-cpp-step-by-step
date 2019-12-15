#ifndef COMPOUND_GRAPHIC_HPP
#define COMPOUND_GRAPHIC_HPP

#include "graphic.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

class CompoundGraphic : public IGraphic {
    private:
        std::vector<IGraphic *> graphics;
    public:
        CompoundGraphic() {
            std::cout << "CompoundGraphic" << std::endl;
        }
        void add(IGraphic* grap) {
            graphics.push_back(grap);
            std::cout << "CompoundGraphic::add()" << std::endl;
        }

        void remove(IGraphic* grap) {
            std::vector<IGraphic *>::iterator it;
            it = std::find(graphics.begin(), graphics.end(), grap);
            if(it != graphics.end()) {
                std::cout << "Element:  " << grap << " found at position: ";
                std::cout << it - graphics.begin() + 1 << std::endl;
                graphics.erase(it);
            }
            else
            {
                std::cout << "Element not found " << std::endl;
            }
        }

        void move(int x, int y) {
            for(auto graph : graphics) {
                graph->move(x,y);
            }
        }

        void draw() {
            for(auto graph : graphics) {
                graph->draw();
            }
        }

        std::vector<IGraphic *> getGraphics() {
            return graphics;
        }

        ~CompoundGraphic() {
            graphics.clear();
            std::cout << "~CompoundGraphic" << std::endl;
        }
};

#endif