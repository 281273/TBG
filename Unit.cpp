#include "Unit.h"

#include <utility>

//Model::Model(int points_,int level_){
//    points=points_;
//    level=level_;
//}

Unit::Unit(const string& filename,string  name,float hp,float dmgmulti,bool active):hp(hp),dmgmulti(dmgmulti),name(std::move(name)){
    LoadTexture(filename);
    Init();
}

Unit::~Unit()= default;

void Unit::LoadTexture(const string& filename){
    if (!texture.loadFromFile("../sprites/"+filename+".png")) {
        std::cerr << "Texture error player \n";
    }
}

void Unit::Init(){
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
}

void Unit::draw(sf::RenderWindow& window) const {
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