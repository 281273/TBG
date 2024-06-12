#include "UserUnit.h"

UserUnit::UserUnit(const std::string& filename): Unit(filename){
    LoadTexture(filename);
}

//Peronal position of the png
void UserUnit::Init(){
    sprite.setTexture(texture);
    sprite.setPosition(240, 230);
}

