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
    Unit(User& _user,Pc& _pc);

    int GetType();


    string strhp;
    string strdmgmulti;
    string strname;

    vector <string> SetStats(int typenum);

//    virtual int Attack();
//    virtual int Heal();
//    virtual int ChangeUnit();
//    virtual int Flee();

private:
    User& user; Pc& pc;


};


#endif //TBG_UNIT_H
