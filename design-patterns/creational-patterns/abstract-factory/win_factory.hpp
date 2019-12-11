// Concrete factories produce a family of products that belong
// to a single variant. The factory guarantees that the
// resulting products are compatible. Signatures of the concrete
// factory's methods return an abstract product, while inside
// the method a concrete product is instantiated.

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
