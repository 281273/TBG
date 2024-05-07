
#include "PcUnit.h"

PcUnit::PcUnit(const string& filename): Unit(filename){
    LoadTexture(filename);
}

void PcUnit::Init(){
    sprite.setTexture(texture);
    sprite.scale(-1,1);
    sprite.setPosition(780, 290);
}

