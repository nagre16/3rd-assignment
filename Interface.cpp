#include "Interface.hpp"
#include "GameMaster.hpp"
#include "graphics.hpp"
#include "Widgets.hpp"
#include <vector>
#include <iostream>
#include <string.h>

using namespace genv;
using namespace std;

Interface::Interface(int x, int y, int sx, int sy, std::vector<vector<int>> elemek)
    : Widget(x,y,sx,sy)
{
    _clicked = false;
    elems = elemek;
    sorrend = 2;
}

void Interface::draw()
{
    gout << move_to(_x,_y) << color(149,222,227) << box(_s_x,_s_y);
    gout << move_to(350,290) << text("POTYOGTATOS AMOBA");
    for (int i = 0; i<7; i++) {
        gout << move_to(_x+i*30,_y) <<color(16,16,16) << line_to(_x+i*30,_y+_s_y);
    }
    for (int j = 0; j <6; j++) {
        gout << move_to(_x,_y+j*30) << line_to(_x+_s_x,_y+j*30);
    }
    for (size_t k = 0; k < 6; k++) {
            for (size_t m = 0; m < 7; m++) {
                if (elems[k][m] == 1) {
                gout << color(144,12,63);
                gout << move_to(_x+30*m, _y+30*k) << line(30, 30);
                gout << move_to(_x+30*m+30, _y+30*k) << line(-30, 30);
                }
                if (elems[k][m] == -1) {
                gout << color(22,129,122);
                gout << move_to(_x+30*m+1, _y+30*k+1) << box(29,29);
                }
            }

    }
}


void Interface::handle(event ev)
{
    if(ev.type == ev_mouse) {
            for (int i = 0; i < 7; i++) {
                if (ev.pos_x > _x+i*30 && ev.pos_x < _x+i*30+30  && ev.button == btn_left) {
                    if (sorrend % 2 == 0 && oszlopok[i] != 6) {
                        int szam = oszlopok[i];
                        elems[5-szam][i] = 1;
                    }
                    else if (sorrend%2 != 0 && oszlopok[i] != 6){
                        int szam = oszlopok[i];
                        elems[5-szam][i] = -1;
                    }
                    if (oszlopok[i] != 6)
                    oszlopok[i]++;
                    sorrend++;
                }
            }
    }
}

std::vector<vector<int>> Interface::getvalue()
{
    return elems;
}

void Interface::reset()
{
    elems = vector<vector<int>> (6 , vector<int> (7, 0));
    memset(oszlopok, 0, sizeof(oszlopok));
    sorrend = 2;
}
