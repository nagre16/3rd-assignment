#ifndef CHOOSE_HPP
#define CHOOSE_HPP
#include "widgets.hpp"
#include "graphics.hpp"
#include <vector>


class Choose : public Widget
{
    protected:
        std::string nameplate;
        std::vector<std::string> _list;
        int choosen;
        int movement;
        int j;
    public:
        Choose(int x, int y, int sx, int sy, std::string _t, std::vector<std::string>);
        virtual void draw() override;
        virtual void handle(genv::event ev) override;
        virtual int getOne();

};

#endif // CHOOSE_HPP
