#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "button.hpp"
#include "checkbox.hpp"
#include "gui_factory.hpp"

class Application {
    private:
        GUIFactory *guiFactory;
        Button *btn;
        Checkbox *chb;
    public:
        Application(GUIFactory *factory) : guiFactory(factory) {
            std::cout << "Application" << std::endl;
        }

        void createUI() {
            btn = guiFactory->createButton();
            chb = guiFactory->createCheckbox();
        }

        void paint() {
            btn->paint();
            chb->paint();
        }

        ~Application() {
            delete btn;
            delete chb;
            delete guiFactory;
            std::cout << "~Application" << std::endl;
        }
};

#endif
