#include "UserUnit.h"

UserUnit::UserUnit(const string& filename,bool active): Unit(filename,active){
    LoadTexture(filename);
}

void UserUnit::Init(){
    sprite.setTexture(texture);
    sprite.setPosition(240, 430);
}