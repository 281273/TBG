//
// Created by Admin on 2024/04/21.
//

#ifndef TBG_GAME_H
#define TBG_GAME_H

#include <iostream>
#include "Unit.h"

using namespace std;

class Game {
public:
    Game(Unit& _unit);

    void runGame();
private:
    Unit& unit;


};


#endif //TBG_GAME_H
