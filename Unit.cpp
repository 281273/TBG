//
// Created by Admin on 2024/04/21.
//

#include "Unit.h"

//Model::Model(int points_,int level_){
//    points=points_;
//    level=level_;
//}

Unit::Unit(UnitType& _unittype,User& _user,Pc& _pc):unittype(_unittype),user(_user),pc(_pc){ //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){

}


void Unit::SetStats(int typenum){
    vector <string> stats=unittype.GetStats(typenum);
    hp=stof(stats[0]);
    dmgmulti=stof(stats[1]);
    name=stats[2];
}

//virtual int Unit::Attack(){
//
//}
//
//virtual int Unit::Heal(){
//
//}
//
//virtual int Unit::ChangeUnit(){
//
//}
//
//virtual int Unit::Flee(){
//
//}