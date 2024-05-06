
#include "PcUnit.h"

PcUnit::PcUnit(const string& filename,bool active): Unit(filename,active){
    LoadTexture(filename);
}

void PcUnit::Init(){
    sprite.setTexture(texture);
    sprite.scale(-1,1);
    sprite.setPosition(780, 290);
}