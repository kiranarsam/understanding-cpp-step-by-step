#ifndef HTML_BUTTON_HPP
#define HTML_BUTTON_HPP

#include <iostream>
#include "button.hpp"

class HtmlButton : public Button {
    public:
        HtmlButton() {
            std::cout << "HtmlButton constructor called " << std::endl;
            callback = nullptr;
        }
        void render() {
            std::cout << "HtmlButton render invoked " << std::endl;
            if(callback) {
                callback();
            }
        }

        void onClick(onclickCB cb) {
            std::cout << "HtmlButton onClick invoked " << std::endl;
            if(cb) {
                callback = cb;
            }
        }

        ~HtmlButton() {
            std::cout << "HtmlButton destructor called " << std::endl;
            callback = nullptr;
        }

};

#endif