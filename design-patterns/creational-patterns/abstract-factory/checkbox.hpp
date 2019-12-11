// Here's the base interface of another product. All products
// can interact with each other, but proper interaction is
// possible only between products of the same concrete variant.

#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

class Checkbox {
    public:
        virtual void paint() = 0;
        virtual ~Checkbox() { }
};

#endif