#include "Unit.h"

Unit::Unit(const std::string& filename){
    //Desides what stats unit have based on the type - filename  they are given
    if(filename=="SABER"){
        hp=20;
        dmgmulti=0.25;
        name="Saber";
    } else if(filename=="LANCER"){
        hp=15;
        dmgmulti=0.5;
        name="Lancer";
    } else if(filename=="ARCHER"){
        hp=10;
        dmgmulti=0.75;
        name="Archer";
    }
    LoadTexture(filename);
}

Unit::~Unit()= default;

//Loading the teture of the given unit type
void Unit::LoadTexture(const std::string& filename){
    if (!texture.loadFromFile("../sprites/"+filename+".png")) {
        std::cerr << "Texture error player \n";
    }
    Init();
}

//Setting position of the unit png - different for User and Pc
void Unit::Init(){
    sprite.setTexture(texture);
    sprite.setOrigin(0,0);
    sprite.setPosition(0, 0);
}

//Display
void Unit::draw(sf::RenderWindow& window) const{
    window.draw(sprite);
}

float Unit::SetHp(float newhp){
    hp=newhp;
    return hp;
}

float Unit::GetHp() const{
    return hp;
}

float Unit::GetDmgMulti() const{
    return dmgmulti;
}

const std::string &Unit::getName() const {
    return name;
}


