#include "GameMaster.hpp"
#include "Widgets.hpp"

int main()
{
    event ev;
    GameMaster * pottyamoba = new GameMaster(0,0,1000,500);
    pottyamoba -> handle(ev);
    return 0;
}
