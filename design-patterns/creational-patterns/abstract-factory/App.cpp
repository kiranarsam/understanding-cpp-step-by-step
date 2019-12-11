// The application picks the factory type depending on the
// current configuration or environment settings and creates it
// at runtime (usually at the initialization stage).
#include "applicaton_configurator.hpp"
#include "win_factory.hpp"
#include "mac_factory.hpp"
#include "application.hpp"

int main() {

    Application *app;
    GUIFactory *factory;

    ApplicationConfigurator config;

    if(config.applicationConfigFile() == 1) {
        factory = new WinFactory();
    }
    else if(config.applicationConfigFile() == 2) {
        factory = new MacFactory();
    }
    else {
        // --- 
    }

    app = new Application(factory);

    app->createUI();
    app->paint();

    delete app;

    return 0;
}