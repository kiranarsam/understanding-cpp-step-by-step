// Each distinct product of a product family should have a base
// interface. All variants of the product must implement this
// interface.
#ifndef BUTTON_HPP
#define BUTTON_HPP

class Button {
    public:
        virtual void paint() = 0;
        virtual ~Button() { }
};

#endif