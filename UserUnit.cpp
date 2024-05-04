#include "UserUnit.h"

UserUnit::UserUnit(const string& filename,const string& name,float hp,float dmgmulti,bool active): Unit(filename,name,hp,dmgmulti,active){
    LoadTexture(filename);
    Init();
}

