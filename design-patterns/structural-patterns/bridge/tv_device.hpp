#ifndef TV_DEVICE_HPP
#define TV_DEVICE_HPP

#include "device.hpp"
#include <iostream>

class Tv : public IDevice {
    public:
        Tv() {
            std::cout << "Tv" << std::endl;
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

        ~Tv() {
            std::cout << "~Tv" << std::endl;
        }
};

#endif