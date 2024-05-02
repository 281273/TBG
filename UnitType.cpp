//
// Created by Admin on 2024/05/02.
//

#include "UnitType.h"


int UnitType::GetType(){
return 0;
}

vector<string> UnitType::GetStats(int typenum){
    switch (typenum) {
        case 1:
            hp="20";
            dmgmulti="1.25";
            name="SABER";
            break;
        case 2:
            hp="15";
            dmgmulti="1.5";
            name="LANCER";
            break;
        case 3:
            hp="10";
            dmgmulti="1.75";
            name="ARCHER";
            break;
    }
    vector <string> stats;
    stats.push_back(hp);
    stats.push_back(dmgmulti);
    stats.push_back(name);

    return stats;
}
