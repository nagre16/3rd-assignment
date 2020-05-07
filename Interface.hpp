#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include "Widgets.hpp"
#include "graphics.hpp"
#include "GameMaster.hpp"
#include <vector>

using namespace genv;
using namespace std;

class Interface : public Widget
{
    protected:
    bool _clicked;
    int oszlopok [7];
    vector<vector<int>> elems;
    int sorrend;
    GameMaster*g;

    public:
        Interface(int x, int y, int sx, int sy, vector<vector<int>> elems, GameMaster*g);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual vector<vector<int>> getvalue();
};

#endif // INTERFACE_HPP
