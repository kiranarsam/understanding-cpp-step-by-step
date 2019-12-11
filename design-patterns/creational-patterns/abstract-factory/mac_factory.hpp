#ifndef MAC_FACTORY_HPP
#define MAC_FACTORY_HPP

#include "gui_factory.hpp"
#include "mac_button.hpp"
#include "mac_checkbox.hpp"

class MacFactory : public GUIFactory {
    public:
        MacFactory() {
            std::cout << "MacFactory" << std::endl;
        }
        Button* createButton() {
            return new MacButton();
        }

        Checkbox* createCheckbox() {
            return new MacCheckbox();
        }

        ~MacFactory() {
            std::cout << "~MacFactory" << std::endl;
        }
};


#endif