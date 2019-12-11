#ifndef WIN_FACTORY_HPP
#define WIN_FACTORY_HPP

#include "gui_factory.hpp"
#include "win_button.hpp"
#include "win_checkbox.hpp"

class WinFactory : public GUIFactory {
    public:
        WinFactory() {
            std::cout << "WinFactory" << std::endl;
        }
        Button* createButton() {
            return new WinButton();
        }

        Checkbox* createCheckbox() {
            return new WinCheckbox();
        }

        ~WinFactory() {
            std::cout << "~WinFactory" << std::endl;
        }
};

#endif
