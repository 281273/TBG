#include "UserUnit.h"

UserUnit::UserUnit(const string& filename): Unit(filename){
    LoadTexture(filename);
}

void UserUnit::Init(){
    sprite.setTexture(texture);
    sprite.setPosition(240, 430);
}

