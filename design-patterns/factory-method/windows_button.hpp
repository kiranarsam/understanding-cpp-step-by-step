#ifndef WINDOWS_BUTTON_HPP
#define WINDOWS_BUTTON_HPP

#include <iostream>
#include "button.hpp"

class WindowsButton : public Button {
    public:
        void render() {
            std::cout << "WindowsButton render invoked " << std::endl;
        }

        void onClick() {
            std::cout << "WindowsButton onClick invoked " << std::endl;
        }
};

#endif