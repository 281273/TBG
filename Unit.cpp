#include "Unit.h"

//Model::Model(int points_,int level_){
//    points=points_;
//    level=level_;
//}

Unit::Unit(const string& filename,bool active){
    if(filename=="SABER"){
        hp=20;
        dmgmulti=1.25;
        name="Saber";
    } else if(filename=="LANCER"){
        hp=15;
        dmgmulti=1.5;
        name="Lancer";
    } else if(filename=="ARCHER"){
        hp=10;
        dmgmulti=1.75;
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

//void Unit::SetStats(int typenum){
//    switch (typenum) {
//        case 1:
//            hp=20;
//            dmgmulti=1.25;
//            name="SABER";
//            break;
//        case 2:
//            hp=15;
//            dmgmulti=1.5;
//            name="LANCER";
//            break;
//        case 3:
//            hp=10;
//            dmgmulti=1.75;
//            name="ARCHER";
//            break;
//    }
//
//}
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

int Unit::Attack(){
    return 0;
}
int Unit::Heal(){
    return 0;
}
int Unit::ChangeUnit(){
    return 0;
}
int Unit::Flee(){
    return 0;
}