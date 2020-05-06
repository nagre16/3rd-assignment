#ifndef WIDGETS_HPP
#define WIDGETS_HPP
#include "graphics.hpp"


class Widget
{
    public:
        Widget(int x, int y, int mx, int my);
        virtual bool kivalasztott(int mouse_x, int mouse_y);
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;
    protected:
        int _x, _y, _s_x, _s_y;
    private:
};

#endif // WIDGETS_HPP
