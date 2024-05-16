#ifndef TBG_GAME_H
#define TBG_GAME_H

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

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


class Game {
public:
    Game();

    std::vector <std::shared_ptr<Unit>> UnitsTab;
    void GameLoop();
private:
    //Mouse position variable
    sf::Vector2i mousePosWindow;

    //Functions updating info about game
    void UpadateMousePosition(sf::RenderWindow& window);
    void Update(sf::RenderWindow& window);

    //Functions drawing frames in window
    void RenderMenu(sf::RenderWindow& window);
    void RenderGame(sf::RenderWindow& window);
    void RenderOver(sf::RenderWindow& window);
    void RenderQTE(sf::RenderWindow& window,const std::string& eventinfo,float x,float y);

    //Function creatins playable units in the vector UnitsTab
    void CreateUnits();

    //States manipulating whats happening in the gamee
    int activeUser;
    int activePc;
    bool userTurn;
    bool manuUp;
    bool over;
    int score;

    //Function generatind random numbers from a to b
    static double Decide(double a,double b);

    //Functions making changes to Unit stats (hp etc) based on player/pc actions during their turn
    void UserTurn(sf::RenderWindow& window);
    void PcTurn(sf::RenderWindow& window);

};

#endif //TBG_GAME_H
