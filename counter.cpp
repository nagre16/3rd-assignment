#include "counter.hpp"
#include "graphics.hpp"
#include "Widgets.hpp"
using namespace genv;

Counter::Counter(int x, int y, int sx, int sy, int _low, int _high)
    : Widget(x,y,sx,sy)
{
    _counting = false;
    number = 0;
    low = _low;
    high = _high;
}
Counter::Counter(int x, int y, int sx, int sy, int _low, int _high, int _steps)
    : Widget(x,y,sx,sy)
{
    _counting = false;
    number = 0;
    low = _low;
    high = _high;
    steps = _steps;
}
void Counter::handle(event ev)
{
    if(ev.type == ev_key) {
        if(ev.keycode == key_up || ev.keycode == key_pgup) {
            if(number+steps > high) {
                number = high;
            }
            else {
                number+=steps;
            }
        }
        else if(ev.keycode == key_down || ev.keycode == key_pgdn) {
            if(number-steps < low) {
                number = low;
            }
            else {
                number-=steps;
            }
        }
    }

    if(ev.type == ev_mouse && ev.button == btn_left) {
        if(ev.pos_x > _x && ev.pos_x < _x+_s_x/2 && ev.pos_y > _y && ev.pos_y < _y+_s_y/3) {
             if(number+10 > high) {
                number = high;
            }
            else {
                number+=10;
            }
        }
        else if(ev.pos_x > _x+_s_x/2 && ev.pos_x < _x+_s_x && ev.pos_y > _y && ev.pos_y < _y+_s_y/3) {
             if(number+steps > high) {
                number = high;
            }
            else {
                number+=steps;
            }
        }
        else if(ev.pos_x > _x && ev.pos_x < _x+_s_x/2 && ev.pos_y > _y+2*_s_y/3 && ev.pos_y < _y+_s_y) {
            if(number-10 < low) {
                number = low;
            }
            else {
                number-=10;
            }
        }
        else if(ev.pos_x > _x+_s_x/2 && ev.pos_x < _x+_s_x && ev.pos_y > _y+2*_s_y/3 && ev.pos_y < _y+_s_y) {
            if(number-steps < low) {
                number = low;
            }
            else {
                number-=steps;
            }
        }
    }
}

void Counter::draw()
{
    gout << move_to(_x, _y) << color(73,109,120) << box(_s_x, _s_y);
    gout << move_to(_x+2, _y+2) << color(110,150,123) << box(_s_x-4, _s_y-4); //kijelzõ rész

    gout << move_to(_x+_s_x/2, _y) << color(40,38,47) << line_to(_x+_s_x/2, _y+_s_y);
    gout << move_to(_x, _y+_s_y/3) << color(40,38,47) << line_to(_x+_s_x, _y+_s_y/3);
    gout << move_to(_x, _y+2*_s_y/3) << color(40,38,47) << line_to(_x+_s_x, _y+2*_s_y/3);

    gout << move_to(_x+_s_x/4, _y+5) << line_to(_x+5,_y+_s_y/3-5)
    << line_to(_x+_s_x/2-5, _y+_s_y/3-5) << line_to(_x+_s_x/4, _y+5); // felfele háromszög

    gout << move_to(_x+3*_s_x/4, _y+5) << line_to(_x+_s_x-5,_y+_s_y/3-5)
    << line_to(_x+_s_x/2+5, _y+_s_y/3-5) << line_to(_x+3*_s_x/4, _y+5);

    gout << move_to(_x+_s_x/4, _y+_s_y-5) << line_to(_x+5,_y+2*_s_y/3+5)
    << line_to(_x+_s_x/2-5,_y+2*_s_y/3+5) << line_to(_x+_s_x/4, _y+_s_y-5); //lefele háromszög

    gout << move_to(_x+3*_s_x/4, _y+_s_y-5) << line_to(_x+_s_x/2+5,_y+2*_s_y/3+5)
    << line_to(_x+_s_x-5,_y+2*_s_y/3+5) << line_to(_x+3*_s_x/4, _y+_s_y-5);


    gout << move_to(_x+_s_x/4,_y+_s_y/2+4) << color(40,38,47) << text(std::to_string((number-number%10)/10)); //szam*/
    if (number < -10)
        gout << move_to(_x+3*_s_x/4,_y+_s_y/2+4) << color(40,38,47) << text(std::to_string(abs(number%10))); //szam*/
    else
        gout << move_to(_x+3*_s_x/4,_y+_s_y/2+4) << color(40,38,47) << text(std::to_string(number%10));

}

int Counter::getNumber()
{
    return number;
}
