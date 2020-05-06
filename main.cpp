#include "graphics.hpp"
#include "counter.hpp"
#include "widgets.hpp"
#include "choose.hpp"
#include<iostream>
#include<fstream>
#include<vector>

using namespace genv;
using namespace std;

const int X = 1000, Y = 500;

void Operator(vector<Widget*>& w, ofstream& m, Counter* c1, Counter* c2, Choose* c3, Choose* c4, vector<string> dragons, vector<string> dungeons) {
    event ev;
    int focus = -1;
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
        gout << move_to(10,490) << color(73,109,120) << text("Press enter to save!");
        if (ev.type == ev_key && ev.keycode == key_enter) {
            m << c1->getNumber() << endl;
            m << c2->getNumber() << endl;
            m << dragons[c3->getOne()] << endl;
            m << dungeons[c4->getOne()] << endl << endl;
        }
        gout << refresh;

        gout << move_to(0,0) << color(0,0,0) << box(X,Y);

        for (Widget * wids : w) {
            wids->draw();
        }

    }
}



int main()
{
    vector<Widget*> w;
    gout.open(X,Y);

    Counter * c1 = new Counter(100,100,180,90,-10,24); //felsõ és alsó határral
    Counter * c2 = new Counter(100,300,180,90,-33,29,2); //felsõ és alsó határral, és lépésközzel

    w.push_back(c1);
    w.push_back(c2);

    vector<string> dragons;
    dragons.push_back("Alexstrasza");
    dragons.push_back("Nozdormu");
    dragons.push_back("Kalecgos");
    dragons.push_back("Ysera");
    dragons.push_back("Deathwing");
    dragons.push_back("Malygos");
    dragons.push_back("Brightwing");
    dragons.push_back("Nefarian");
    Choose * c3 = new Choose(400,100,100,300,"dragons",dragons);

    vector<string> dungeons;
    dungeons.push_back("The Forge of Souls");
    dungeons.push_back("Pit of Saron");
    dungeons.push_back("Halls of Reflection");
    dungeons.push_back("Trial of the Champion");
    dungeons.push_back("The Nexus");
    dungeons.push_back("Drak'Tharon Keep");
    dungeons.push_back("The Violet Hold");
    dungeons.push_back("Stratholme Past");
    Choose * c4 = new Choose(600,100,200,300,"dungeons",dungeons);

    w.push_back(c3);
    w.push_back(c4);

    for (Widget * wig : w) {
        wig->draw();
    }
    gout << refresh;

    ofstream file;
    file.open ("data.txt");

    Operator(w, file, c1, c2, c3, c4, dragons, dungeons);

    file.close();
    return 0;
}
