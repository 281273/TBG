#include "Unit.h"

Unit::Unit(const std::string& filename){
    //Desides what stats unit have based on the type - filename  they are given
    if(filename=="SABER"){
        hp=20;
        dmgmulti=1;
        name="Saber";
    } else if(filename=="LANCER"){
        hp=15;
        dmgmulti=2;
        name="Lancer";
    } else if(filename=="ARCHER"){
        hp=10;
        dmgmulti=3;
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

int Unit::SetHp(int newhp){
    hp=newhp;
    return hp;
}

int Unit::GetHp() const{
    return hp;
}

int Unit::GetDmgMulti() const{
    return dmgmulti;
}

std::basic_string<char> Unit::getName() const {
    return name;
}


