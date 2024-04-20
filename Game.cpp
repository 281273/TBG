//
// Created by Admin on 2024/04/21.
//

#include "Game.h"

Game::Game(Unit& _unit):unit(_unit){ //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){

}

void Game::runGame() {
    int hp=unit.getHp();
    cout<<hp;
}