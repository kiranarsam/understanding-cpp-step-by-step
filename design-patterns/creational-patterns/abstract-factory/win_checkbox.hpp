#ifndef WIN_CHECKBOX_HPP
#define WIN_CHECKBOX_HPP

#include "checkbox.hpp"

class WinCheckbox : public Checkbox {
    public:
        WinCheckbox() {
            std::cout << "WinCheckbox" << std::endl;
        }
        void paint() {
            std::cout << "WinCheckbox::paint" << std::endl;
        }

        ~WinCheckbox() {
            std::cout << "~WinCheckbox" << std::endl;
        }
};

#endif