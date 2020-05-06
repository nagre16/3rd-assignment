#include "Widgets.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

Widget::Widget(int x, int y, int mx, int my) : _x(x), _y(y), _s_x(mx), _s_y(my)
{
    std::cout << "Widget\n";
}

bool Widget::kivalasztott(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_s_x  && mouse_y>_y && mouse_y<_y+_s_y;
}
