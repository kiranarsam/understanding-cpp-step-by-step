#include <iostream>
#include "windows_dialog.hpp"
#include "web_dialog.hpp"


class Application {
    private:
        Dialog *dialog;
        static int applicationConfig;
        static int readApplicationConfigFile();
    public:
        Application() {
            std::cout << "Application constructor is called " << std::endl;
        }

        void initialize() {
            int config = Application::readApplicationConfigFile();

            if(config == 1) {
                dialog = new WindowsDialog();
            }
            else if(config == 2) {
                dialog = new WebDialog();
            }
            else {
                /* */
            }
        }
        void render() {
            dialog->render();
        }
        ~Application() {
            std::cout << "Application Destructor is Called " << std::endl;
            delete dialog;

        }
};

int Application::applicationConfig = 2;

int Application::readApplicationConfigFile() {
    return Application::applicationConfig;
}

int main() {
    Application app;
    app.initialize();
    app.render();

    return 0;
}