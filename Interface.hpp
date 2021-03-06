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
    int oszlopok[7] = {0};
    vector<vector<int>> elems;
    int sorrend;
    GameMaster*g;

    public:
        Interface(int x, int y, int sx, int sy, vector<vector<int>> elems);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual vector<vector<int>> getvalue();
        virtual void reset();
};

#endif // INTERFACE_HPP
