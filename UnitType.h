//
// Created by Admin on 2024/05/02.
//

#ifndef TBG_UNITTYPE_H
#define TBG_UNITTYPE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class UnitType {
public:
    int GetType();
    vector<string> GetStats(int typenum);
private:

    string hp;
    string dmgmulti;
    string name;

};


#endif //TBG_UNITTYPE_H
