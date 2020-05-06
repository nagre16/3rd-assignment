#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "graphics.hpp"
#include "widgets.hpp"

class Counter : public Widget
{
    protected:
        bool _counting;
        int number;
        int low = INT_MIN;
        int high = INT_MAX;
        int steps = 1;
    public:
        //Number(int x, int y, int sx, int sy);
        Counter(int x, int y, int sx, int sy, int low, int high);
        Counter(int x, int y, int sx, int sy, int low, int high, int steps);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual int getNumber();

};

#endif // COUNTER_HPP
