#ifndef IMAGE_EDITOR_HPP
#define IMAGE_EDITOR_HPP

#include "compound_graphic.hpp"
#include "dot.hpp"
#include "circle.hpp"

class ImageEditor {
    private:
        CompoundGraphic *all;
        CompoundGraphic *group;
    public:
        ImageEditor() {
            std::cout << "ImageEditor" << std::endl;
        }
        void load() {
                all = new CompoundGraphic();
                all->add(new Dot(1,2));
                all->add(new Circle(5,3, 10));
                all->add(new Circle(15,13, 20));
                all->add(new Dot(11,22));
                all->draw();
        }

        void groupSelected(std::vector<IGraphic *> graphics) {
            group = new CompoundGraphic();
            for(auto grap : graphics) {
                group->add(grap);
                all->remove(grap);
            }
            all->add(group);
            all->draw();
        }

        std::vector<IGraphic *> getGraphics() {
            return all->getGraphics();
        }

        ~ImageEditor() {
            delete all;
            for(auto grap : group->getGraphics()) {
                delete grap;
            }
            delete group;
            std::cout << "~ImageEditor" << std::endl;
        }
};

#endif