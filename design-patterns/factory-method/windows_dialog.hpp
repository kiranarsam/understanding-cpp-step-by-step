#ifndef WINDOWS_DIALOG_HPP
#define WINDOWS_DIALOG_HPP

#include "dialog.hpp"
#include "windows_button.hpp"


class WindowsDialog : public Dialog {

    public:
        WindowsDialog() {
            std::cout << "WindowsDialog constructor called " << std::endl;
        }

        Button* createButton() {
            return new WindowsButton();
        }

        ~WindowsDialog() {
            std::cout << "WindowsDialog destructor called " << std::endl;
        }
};

#endif