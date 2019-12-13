#include "advanced-remote-control.hpp"
#include "tv_device.hpp"
#include "radio_device.hpp"

class Application {
    public:
        Application() {
            std::cout << "Application" << std::endl;
        }

        void remoteControlOperations() {
            Tv tv;
            RemoteControl rc(&tv);
            rc.togglePower();
        }

        void advancedRemoteControlOperations() {
            Radio r;
            AdvancedRemoteControl arc(&r);
            arc.togglePower();
            arc.mute();
        }

        ~Application() {
            std::cout << "~Application" << std::endl;
        }
};

int main() {
    Application app;
    app.remoteControlOperations();
    app.advancedRemoteControlOperations();

    return 0;
}
