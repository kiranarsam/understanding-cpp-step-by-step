// Concrete products are created by corresponding concrete factories.
#ifndef WIN_BUTTON_HPP
#define WIN_BUTTON_HPP

#include "button.hpp"

class WinButton : public Button {
    public:
        WinButton() {
            std::cout << "WinButton" << std::endl;
        }
        void paint() {
            std::cout << "WinButton::paint" << std::endl;
        }
        ~WinButton() {
            std::cout << "~WinButton" << std::endl;
        }
};


#endif