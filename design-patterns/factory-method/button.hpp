
#ifndef BUTTON_HPP_
#define BUTTON_HPP_

class Button {
    public:
        virtual void render() = 0;
        virtual void onClick() = 0;
};

#endif