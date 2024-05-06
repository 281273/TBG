//
// Created by Admin on 2024/04/21.
//

#ifndef TBG_GAME_H
#define TBG_GAME_H

#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include "BackGround.h"
#include "Unit.h"
#include "PcUnit.h"
#include "UserUnit.h"

using namespace std;

class Game {
public:
//    Game(UserUnit& _user,PcUnit& _pc);
    Game();

    void GameLoop();
private:
//    UserUnit& user; PcUnit& pc;

    void Update();
    void Render();

    void CreateUnits();
    vector <shared_ptr<Unit>> UnitsTab;
};


#endif //TBG_GAME_H
