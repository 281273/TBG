//
// Created by Admin on 2024/04/21.
//

#include "Game.h"

Game::Game(Unit& _unit):unit(_unit){ //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){

}

void Game::GetStats(int typenum) {
    vector <string> stats=unit.SetStats(typenum);
    hp=stof(stats[0]);
    dmgmulti=stof(stats[1]);
    name=stats[2];
}



void Game::runGame() {
    GetStats(2);
    cout<<hp<<" "<<dmgmulti<<" "<<name;
}