#include "GameMaster.hpp"
#include "Interface.hpp"

#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>
#include <vector>


const int X = 500, Y = 300;

using namespace genv;
using namespace std;
GameMaster::GameMaster(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked = false;
    jatekos1 = 0;
    jatekos2 = 0;
}


void GameMaster::handle(genv:: event ev)
{
    int focus = -1;

    vector<Widget*> w;
    gout.open(X,Y);


    vector<vector<int>> elemek1(6 , vector<int> (7, 0));
    Interface * f1 = new Interface(10,10,7*30,6*30, elemek1, this);
    w.push_back(f1);

    for (Widget * wig : w) {
        wig->draw();
    }
    gout << refresh;

    while(gin >> ev) {

        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<w.size();i++) {
                if (w[i]->kivalasztott(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }

        if (focus!=-1) {
            w[focus]->handle(ev);
        }
        gameplan(f1->getvalue());

        gout << refresh;

        gout << move_to(0,0) << color(0,0,0) << box(X,Y);

        for (Widget * wig : w) {
        wig->draw();
    }

    }
}



int GameMaster::gameplan(std::vector<std::vector<int>> ertekel)
{

}


void GameMaster::draw() {
    if (jatekos1 == 1) {
        gout << move_to (0,0) << box(1000,500) << color(200,002,050) << text("Az elso jatekos nyert!");
    }
    if (jatekos2 == 1) {
        gout << move_to (0,0) << box(1000,500) << color(253,106,002) << text("A masodik jatekos nyert!");
    }
}

GameMaster::~GameMaster(){}
