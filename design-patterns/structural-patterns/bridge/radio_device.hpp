#ifndef RADIO_DEVICE_HPP
#define RADIO_DEVICE_HPP

#include "device.hpp"
#include <iostream>

class Radio : public IDevice {
    public:
        Radio() {
            std::cout << "Radio" << std::endl;
        }

        bool isEnabled() {
            return 0;
        }
        void enable() {

        }
        void disable(){

        }
        int getVolume() {
            return 0;
        }
        void setVolume(int percent) {

        }
        int getChannel() { 
            return 0;
        }
        void setChannel(int channel) {

        }

        ~Radio() {
            std::cout << "~Radio" << std::endl;
        }
};

#endif