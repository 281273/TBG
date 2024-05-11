//
// Created by Admin on 2024/04/21.
//

#ifndef TBG_GAME_H
#define TBG_GAME_H

#include <memory>
#include <vector>
#include <iostream>
#include <string>
#include <random>

#include "SFML/Graphics.hpp"
#include <SFML/System/Clock.hpp>
#include "SFML/Window.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include "BackGround.h"
#include "Unit.h"
#include "PcUnit.h"
#include "UserUnit.h"
#include "Font.h"

using namespace std;

class Game {
public:
    Game();
    //Game(UserUnit& _userunit,PcUnit& _pcunit,Input& _input);

    vector <shared_ptr<Unit>> UnitsTab;
    void GameLoop();
private:
//    UserUnit& user; PcUnit& pc;
    sf::Vector2i mousePosWindow;
    void UpadateMousePosition(sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);
    void RenderMenu(sf::RenderWindow& window);
    void RenderGame(sf::RenderWindow& window);
    void RenderOver(sf::RenderWindow& window);

    void CreateUnits();

    int activeUser;
    int activePc;
    bool userTurn;
    bool manuUp;
    bool over;
    void UserTurn(sf::RenderWindow& window);
    void PcTurn(sf::RenderWindow& window);
    static double Decide(double a,double b);
};


#endif //TBG_GAME_H
