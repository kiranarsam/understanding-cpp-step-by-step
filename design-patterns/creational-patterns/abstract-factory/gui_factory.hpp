// The abstract factory interface declares a set of methods that
// return different abstract products. These products are called
// a family and are related by a high-level theme or concept.
// Products of one family are usually able to collaborate among
// themselves. A family of products may have several variants,
// but the products of one variant are incompatible with the
// products of another variant.

#ifndef GUI_FACTORY_HPP
#define GUI_FACTORY_HPP

#include "button.hpp"
#include "checkbox.hpp"
#include <iostream>

class GUIFactory {
    public:
        virtual Button* createButton() = 0;
        virtual Checkbox* createCheckbox() = 0;
        virtual ~GUIFactory() { }
};

#endif