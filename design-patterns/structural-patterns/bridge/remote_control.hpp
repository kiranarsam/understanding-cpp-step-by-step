
#ifndef REMOTE_CONTROL_HPP
#define REMOTE_CONTROL_HPP

#include "device.hpp"
#include <iostream>

class RemoteControl {
    protected:
        IDevice* device;
    public:
        RemoteControl(IDevice* d) : device(d) {
            std::cout << "RemoteControl" << std::endl;
        }

        void togglePower() {
            if(device->isEnabled()) {
                device->disable();
            }
            else {
                device->enable();
            }
        }

        void volumeDown() {
            device->setVolume(device->getVolume() - 10);
        }

        void volumeUp() {
            device->setVolume(device->getVolume() + 10);
        }
        void channelUp() {
            device->setChannel(device->getChannel() + 1);
        }
        void channelDown() {
            device->setChannel(device->getChannel() - 1);
        }

        ~RemoteControl() {
            std::cout << "~RemoteControl" << std::endl;
        }
};

#endif