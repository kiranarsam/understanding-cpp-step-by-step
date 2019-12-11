// Concrete products are created by corresponding concrete factories.
#ifndef MAC_BUTTON_HPP
#define MAC_BUTTON_HPP

#include "button.hpp"

class MacButton : public Button {
    public:
        MacButton() {
            std::cout << "MacButton" << std::endl;
        }
        void paint() {
            std::cout << "MacButton::paint" << std::endl;
        }
        ~MacButton() {
            std::cout << "~MacButton" << std::endl;
        }
};

#endif