//
// Created by Admin on 2024/04/21.
//

#ifndef TBG_UNIT_H
#define TBG_UNIT_H

#include <iostream>
#include <string>

#include "UnitType.h"
#include "User.h"
#include "Pc.h"


using namespace std;


class Unit {
public:
    Unit(UnitType& _unittype,User& _user,Pc& _pc);

    float hp;
    float dmgmulti;
    string name;

    void SetStats(int typenum);

//    virtual int Attack();
//    virtual int Heal();
//    virtual int ChangeUnit();
//    virtual int Flee();

private:
    UnitType& unittype; User& user; Pc& pc;


};


#endif //TBG_UNIT_H
