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
//    A constructor
    Game();

//    Function "GameLoop"
//    Core game function controlling all the events ( Like Controller )
    void GameLoop();

private:
//    std::vector
//    containing all units taking part in the game
    std::vector <std::shared_ptr<Unit>> UnitsTab;

//    std::Vector2i
//    recponsible for containing x,y values of the current cursor position on the window
    sf::Vector2i mousePosWindow;

//    Function "UpdateMousePosition" takes one argument
//    and uses it to set a target for the position checks
//    @param window a sf::RenderWindow& argument.
    void UpadateMousePosition(sf::RenderWindow& window);

//    Function "Update" takes one argument
//    Checks for any events like "KeyPressed" and triggers corresponding actions
//    @param window a sf::RenderWindow& argument.
    void Update(sf::RenderWindow& window);

//    Function "RenderMeu" takes one argument
//    Displays the menu screen in the Game (app) window
//    @param window a sf::RenderWindow& argument.
    void RenderMenu(sf::RenderWindow& window);

//    Function "RenderGame" takes one argument
//    Displays the game screen in the Game (app) window.
//    @param window a sf::RenderWindow& argument.
    void RenderGame(sf::RenderWindow& window);

//    Function "RenderOver" takes one argument
//    Displays the gameover screen in the Game (app) window
//    @param window a sf::RenderWindow& argument.
    void RenderOver(sf::RenderWindow& window);

//    Function "RenderQTE" takes four arguments
//    Displays the quicktimeevent info like dmg we dealt with our action or prompt about the change of unit stats like "heal" or "death"
//    @param window a sf::RenderWindow& argument. Target of our display
//    @param eventinfo astd::string argument. Containt sentence we want to display
//    @param x a float argument. X position of the place we want to display in
//    @param y a float argument. Y position of the place we want to display in
    void RenderQTE(sf::RenderWindow& window,const std::string& eventinfo,float x,float y);

//    Function "CreateUnits" takes one argument
//    Creates the main units taking part in the game. For both player and pc
    void CreateUnits();

//    int variable
//    containing number corresponding to the unit player is currently using in the game [0-2]
    int activeUser;

//    int variable
//    containing number corresponding to the pc player is currently using in the game [3]
    int activePc;

//    bool variable
//    responsible for managing the turn order. Changes after every action
    bool userTurn;

//    bool variable
//    responsible for managing the current game creen [menu,game]
    bool manuUp;

//    bool variable
//    responsible for checking if the game is over. [over]
    bool over;

//    int variable
//    containing the current score in the game. Increasing after enemy unit is killed
    int score;

//    Function "Decide" takes two arguments
//    Generates random numbers between a and b
//    @param a ,a double argument. Left range of the eng
//    @param b ,a double argument. Right Range of the rng
//    @returns random number from the range a-b
    static double Decide(double a,double b);

//    Function "UserTurn" takes one argument
//    Based on the actions taken by the player, triggers corresponding functions
//    @param window a sf::RenderWindow& argument
    void UserTurn(sf::RenderWindow& window);

//    Function "PcTurn" takes one argument
//    Based on the randomnumbers and a few conditions decides on the pc actions, triggers corresponding functions
//    @param window a sf::RenderWindow& argument
    void PcTurn(sf::RenderWindow& window);

};

#endif //TBG_GAME_H
