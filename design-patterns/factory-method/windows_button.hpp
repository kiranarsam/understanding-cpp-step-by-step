#ifndef WINDOWS_BUTTON_HPP
#define WINDOWS_BUTTON_HPP

#include <iostream>
#include "button.hpp"

class WindowsButton : public Button {
    public:
        WindowsButton() {
            std::cout << "WindowsButton constructor called " << std::endl;
            callback = nullptr;
        }
        void render() {
            std::cout << "WindowsButton render invoked " << std::endl;
            if(callback) {
                callback();
            }
        }

        void onClick(onclickCB cb) {
            std::cout << "WindowsButton onClick invoked " << std::endl;
            if(cb) {
                callback = cb;
            }
        }

        ~WindowsButton() {
            std::cout << "WindowsButton destructor called " << std::endl;
            callback = nullptr;
        }
};

#endif