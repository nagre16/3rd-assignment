#include "choose.hpp"
#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>
#include <iostream>
using namespace genv;

Choose::Choose(int x, int y, int sx, int sy, std::string _name, std::vector<std::string> maybe)
    : Widget(x,y,sx,sy)
{
    nameplate = _name;
    _list = maybe;
    choosen = -1;
    movement = 0;
}

void Choose::draw()
{
    gout << move_to(_x,_y-10) << color(193,115,158) << text(nameplate);
    gout << move_to(_x, _y) << color(110,150,123) << box(_s_x, _s_y);
    for (int i = 0; i < 6; i++) {
        gout << move_to(_x+2,_y+i*50+2) << color(73,109,120) << box(_s_x-4, _s_y/6-4);
        if (choosen == (i-movement) && (choosen+movement)>=0 && (choosen+movement)<6) {
            gout << move_to(_x+2,_y+(choosen+movement)*50+2) << color(193,115,158) << box(_s_x-4, _s_y/6-4);
            //std::cout << _list[choosen]; //ellenõrzésként használtam
        }

    }
    if (_list.size() <= 6) {
        for (int i = 0; i <_list.size(); i++) {
            gout << move_to(_x+5, _y+50/2+i*50+5) << color(40,38,47) << text(_list[i]);
        }

    }
    else if (_list.size() > 6) {
        for (int i = 0; i < _list.size(); i++) {
            int j;
            j= i + movement;
            if (j>=0 && j < 6)
            gout << move_to(_x+5, _y+50/2+j*50+5) << color(40,38,47) << text(_list[i]);
        }

    }

}



void Choose::handle(event ev)
{
    for (int i = 0; i < _list.size(); i++) {
        if (ev.type == ev_mouse && ev.button == btn_left && ev.pos_x > _x && ev.pos_x < _x+_s_x && ev.pos_y > _y+i*50 && ev.pos_y < _y+i*50+50)
            choosen = i-movement;
    }

    if (_list.size() > 6){
        if ((ev.type == ev_key && ev.keycode == key_down && movement != 0) || (ev.type == ev_mouse && ev.button == btn_wheeldown && movement != 0)) {
                movement+=1;
        }
        if ((ev.type == ev_key && ev.keycode == key_up && movement != (6-_list.size())) || (ev.type == ev_mouse && ev.button == btn_wheelup && movement != (6-_list.size()))) {
                movement-=1;
        }
        //std::cout << movement; ellenõrzésként használtam
    }


}

int Choose::getOne()
{
    return choosen;
}
