#ifndef DEVICE_HPP
#define DEVICE_HPP

class IDevice {
    public:
        virtual bool isEnabled() = 0;
        virtual void enable() = 0;
        virtual void disable() = 0;
        virtual int getVolume() = 0;
        virtual void setVolume(int percent) = 0;
        virtual int getChannel() = 0;
        virtual void setChannel(int channel) = 0;
        virtual ~IDevice() = 0;
};

IDevice::~IDevice() { }

#endif