
#ifndef BUTTON_HPP_
#define BUTTON_HPP_

typedef void (*onclickCB)();

class Button {
    public:
        Button(){}
        virtual void render() = 0;
        virtual void onClick(onclickCB cb) = 0;
        virtual ~Button() {}
    protected:
        onclickCB callback;
};

#endif