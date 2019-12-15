
#include "image_editor.hpp"
#include <iostream>

class Application {
    private:
        ImageEditor *ie;
    public:
        Application() {
            std::cout << "Application" << std::endl;
            ie = new ImageEditor();
        }

        void load() {
            ie->load();
        }

        void resetLoadGraphics() {
            ie->groupSelected(ie->getGraphics());
        }

        ~Application() {
            delete ie;
            std::cout << "~Application" << std::endl;
        }
};

int main() {
    Application *app = new Application();
    app->load();
    app->resetLoadGraphics();

    delete app;
    
    return 0;
}