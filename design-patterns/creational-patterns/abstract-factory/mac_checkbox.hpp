#ifndef MAC_CHECKBOX_HPP
#define MAC_CHECKBOX_HPP

#include "checkbox.hpp"

class MacCheckbox : public Checkbox {
    public:
        MacCheckbox() {
            std::cout << "MacCheckbox" << std::endl;
        }
        void paint() {
            std::cout << "MacCheckbox::paint" << std::endl;
        }

        ~MacCheckbox() {
            std::cout << "~MacCheckbox" << std::endl;
        }
};


#endif