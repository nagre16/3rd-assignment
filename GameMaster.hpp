#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "Widgets.hpp"
#include "graphics.hpp"
#include <vector>

using namespace genv;
using namespace std;

class GameMaster : public Widget
{
    bool _checked;
    int jatekos1;
    int jatekos2;
    int dontetlen;
    vector<vector<int>> ertekel;
    public:
        GameMaster(int x, int y, int sx, int sy);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual int strategy(vector<vector<int>> ertekel);
        virtual ~GameMaster();

};
#endif // GAMEMASTER_HPP
