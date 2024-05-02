#include <iostream>

#include "Game.h"


int main() {
    Pc pc; User user; UnitType unittype;
    Unit unit(unittype,user,pc);
    Game game(unit);
    game.runGame();
    return 0;
}

