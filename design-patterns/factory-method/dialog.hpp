
#ifndef DIALOG_HPP_
#define DIALOG_HPP_

#include <iostream>
#include "button.hpp"

void closeDialog() {
    std::cout << "Closing Dialog " << std::endl;
}

class Dialog {
    public:
        Dialog() {
            std::cout << "Dialog constructor called " << std::endl;
            button = nullptr;
        }

        virtual Button* createButton() = 0;

        void render() {
            button = createButton();
            if(button) {
                button->onClick(closeDialog);
                button->render();
            }
            else
            {
                /* Button is not created */
            }
        }

        virtual ~Dialog() {
            std::cout << "Dialog destructor called " << std::endl;
            delete button;
        }
    private:
        Button *button;
};

#endif 