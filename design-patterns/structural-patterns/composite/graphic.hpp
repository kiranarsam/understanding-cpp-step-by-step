#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

class IGraphic {
    public:
        virtual void move(int x, int y) = 0;
        virtual void draw() = 0;
        virtual ~IGraphic() = 0;
};

IGraphic::~IGraphic() { }

#endif