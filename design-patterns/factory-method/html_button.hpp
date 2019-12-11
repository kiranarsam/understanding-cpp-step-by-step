#ifndef HTML_BUTTON_HPP
#define HTML_BUTTON_HPP

#include <iostream>
#include "button.hpp"

class HtmlButton : public Button {
    public:
        void render() {
            std::cout << "HtmlButton render invoked " << std::endl;
        }

        void onClick() {
            std::cout << "HtmlButton onClick invoked " << std::endl;
        }

};

#endif