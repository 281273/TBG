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
#include "Input.h"

using namespace std;

class Game {
public:
//    Game(UserUnit& _user,PcUnit& _pc);
    Game();

    void MainLoop();
private:
//    UserUnit& user; PcUnit& pc;
    sf::Vector2i mousePosWindow;
    void UpadateMousePosition(sf::RenderWindow& window);

    void Update(sf::RenderWindow& window);
    void Render(sf::RenderWindow& window);

    void CreateUnits();
    vector <shared_ptr<Unit>> UnitsTab;
    int activeUser;
    int activePc;

    void GameLoop(sf::RenderWindow& window);
};


#endif //TBG_GAME_H
