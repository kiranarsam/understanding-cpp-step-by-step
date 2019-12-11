#ifndef WEB_DIALOG_HPP
#define WEB_DIALOG_HPP

#include "dialog.hpp"
#include "html_button.hpp"


class WebDialog : public Dialog {
    public:
        WebDialog() {
            std::cout << "WebDialog constructor called " << std::endl;
        }
        Button* createButton() {
            return new HtmlButton();
        }

        ~WebDialog() {
            std::cout << "WebDialog destructor called " << std::endl;
        }
};


#endif