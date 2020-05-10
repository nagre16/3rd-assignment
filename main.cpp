#include <iostream>
#include <vector>
#include "Widgets.hpp"
#include "GameMaster.hpp"
#include "Interface.hpp"

using namespace genv;
using namespace std;

const int X = 500, Y = 300;

int main()
{
    event ev;
    GameMaster* potyamoba = new GameMaster(0,0,500,300);

    int focus = -1;
    vector<Widget*> w;
    gout.open(X,Y);


    vector<vector<int>> elemek1(6 , vector<int> (7, 0));
    Interface * I1 = new Interface(10,10,7*30,6*30, elemek1);
    w.push_back(I1);


    for (Widget * wig : w) {
        wig->draw();
    }
    gout << refresh;
    while(gin >> ev && ev.keycode != key_escape) {
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<w.size();i++) {
                if (w[i]->kivalasztott(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            w[focus]->handle(ev);
            if(potyamoba->strategy(I1 -> getvalue())){
                while(gin >> ev && ev.keycode != key_enter) {
                    gout << move_to(0,0) << color(0,0,0) << box(X,Y);
                    potyamoba -> draw();
                }
                I1 -> reset();
            }

        }
        gout << refresh;
        gout << move_to(0,0) << color(0,0,0) << box(X,Y);
        for (Widget * wig : w) {
            wig->draw();
        }
    }

    return 0;
}
