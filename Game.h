//
// Created by Admin on 2024/04/21.
//

#ifndef TBG_GAME_H
#define TBG_GAME_H

#include <iostream>
#include <string>

#include "Unit.h"

using namespace std;

class Game {
public:
    Game(Unit& _unit);


    void runGame();
private:
    Unit& unit;

    float hp{};
    float dmgmulti{};
    string name;
    void GetStats(int typenum);

};


#endif //TBG_GAME_H
