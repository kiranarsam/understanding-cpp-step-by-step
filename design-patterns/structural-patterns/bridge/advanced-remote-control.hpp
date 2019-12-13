#ifndef ADVANCED_REMOTE_CONTROL_HPP
#define ADVANCED_REMOTE_CONTROL_HPP

#include "remote_control.hpp"

class AdvancedRemoteControl : public RemoteControl {
    public:
        AdvancedRemoteControl(IDevice* device) : RemoteControl(device) {
            std::cout << "AdvancedRemoteControl" << std::endl;
        }

        void mute() {
            device->setVolume(0);
        }

        ~AdvancedRemoteControl() {
            std::cout << "~AdvancedRemoteControl" << std::endl;
        }
};

#endif