//
// Created by Admin on 2024/04/21.
//

#include "Unit.h"

//Model::Model(int points_,int level_){
//    points=points_;
//    level=level_;
//}

Unit::Unit(User& _user,Pc& _pc):user(_user),pc(_pc){ //View& _view,Model& _model,KeyBinding& _keybinding):view(_view),model(_model),keybinding(_keybinding){

}

int Unit::GetType(){
    return 0;
}

vector<string> Unit::SetStats(int typenum){
    switch (typenum) {
        case 1:
            strhp="20";
            strdmgmulti="1.25";
            strname="SABER";
            break;
        case 2:
            strhp="15";
            strdmgmulti="1.5";
            strname="LANCER";
            break;
        case 3:
            strhp="10";
            strdmgmulti="1.75";
            strname="ARCHER";
            break;
    }
    vector <string> stats;
    stats.push_back(strhp);
    stats.push_back(strdmgmulti);
    stats.push_back(strname);

    return stats;
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