#include "GameMaster.hpp"
#include "Interface.hpp"

#include "graphics.hpp"
#include "widgets.hpp"
#include <iostream>
#include <vector>


using namespace genv;
using namespace std;
GameMaster::GameMaster(int x, int y, int sx, int sy)
    : Widget(x,y,sx,sy)
{
    _checked = false;
    jatekos1 = 0;
    jatekos2 = 0;
    dontetlen = 0;
}


void GameMaster::handle(genv:: event ev)
{

}



int GameMaster::strategy(std::vector<std::vector<int>> ertekel)
{
    //sorra
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if ((ertekel[i][j] + ertekel[i][j+1] + ertekel[i][j+2] + ertekel[i][j+3]) == 4 && jatekos2 == 0) {
                jatekos1 = 1;
                return jatekos1;
            }

            else if ((ertekel[i][j] + ertekel[i][j+1] + ertekel[i][j+2] + ertekel[i][j+3]) == -4 && jatekos1 == 0) {
                jatekos2 = 1;
                return jatekos2;
            }

        }
    }
    //oszlopra
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            if ((ertekel[i][j] + ertekel[i+1][j] + ertekel[i+2][j] + ertekel[i+3][j]) == 4 && jatekos2 == 0) {
                jatekos1 = 1;
                return jatekos1;
            }
            else if ((ertekel[i][j] + ertekel[i+1][j] + ertekel[i+2][j] + ertekel[i+3][j]) == -4 && jatekos1 == 0) {
                jatekos2 = 1;
                return jatekos2;
            }

        }
    }
    //átlósan le
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if ((ertekel[i][j] + ertekel[i+1][j+1] + ertekel[i+2][j+2] + ertekel[i+3][j+3]) == 4 && jatekos2 == 0) {
                jatekos1 = 1;
                return jatekos1;
            }
            else if ((ertekel[i][j] + ertekel[i+1][j+1] + ertekel[i+2][j+2] + ertekel[i+3][j+3]) == -4 && jatekos1 == 0) {
                jatekos2 = 1;
                return jatekos2;
            }

        }
    }
    //átlósan fel
    for (int i = 3; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if ((ertekel[i][j] + ertekel[i-1][j+1] + ertekel[i-2][j+2] + ertekel[i-3][j+3]) == 4 && jatekos2 == 0) {
                jatekos1 = 1;
                return jatekos1;
            }
            else if ((ertekel[i][j] + ertekel[i-1][j+1] + ertekel[i-2][j+2] + ertekel[i-3][j+3]) == -4 && jatekos1 == 0) {
                jatekos2 = 1;
                return jatekos2;
            }

        }
    }
        if ((ertekel[0][0] == 1 || ertekel[0][0] == -1) && (ertekel[0][1] == 1 || ertekel[0][1] == -1) &&
            (ertekel[0][2] == 1 || ertekel[0][2] == -1) && (ertekel[0][3] == 1 || ertekel[0][3] == -1) &&
            (ertekel[0][4] == 1 || ertekel[0][4] == -1) && (ertekel[0][5] == 1 || ertekel[0][5] == -1) &&
            (ertekel[0][6] == 1 || ertekel[0][6] == -1) && jatekos1 == 0 && jatekos2 == 0)
        {
            dontetlen = 1;
            return dontetlen;
        }
    return 0;
}


void GameMaster::draw() {
    gout << color (149,222,227) <<  move_to (0,0) << box(500,300);
    gout << color (16,16,16) << move_to(50,100) << text("Nyomj entert az uj jatekhoz!");
    if (jatekos1 == 1) {
        gout << color(144,12,63) << move_to(150,120) << text("Az elso jatekos nyert!");
    }
    if (jatekos2 == 1) {
        gout << color(22,129,122) << move_to(150,120) << text("A masodik jatekos nyert!");
    }
    if (dontetlen == 1) {
        gout << color (16,16,16) << move_to(150,120) << text("Dontetlen!");
    }
    gout << refresh;
}

GameMaster::~GameMaster(){}
