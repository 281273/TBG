#include "Unit.h"

//Model::Model(int points_,int level_){
//    points=points_;
//    level=level_;
//}

Unit::Unit(const string& filename){
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

void Unit::LoadTexture(const string& filename){
    if (!texture.loadFromFile("../sprites/"+filename+".png")) {
        std::cerr << "Texture error player \n";
    }
    Init();
}

void Unit::Init(){
    sprite.setTexture(texture);
    sprite.setOrigin(0,200);
    sprite.setPosition(0, 0);
}

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

const string &Unit::getName() const {
    return name;
}
