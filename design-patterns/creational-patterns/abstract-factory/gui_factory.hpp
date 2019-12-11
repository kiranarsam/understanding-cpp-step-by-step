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