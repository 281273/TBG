
#include "PcUnit.h"

PcUnit::PcUnit(const string& filename,const string& name,float hp,float dmgmulti,bool active): Unit(filename,name,hp,dmgmulti,active){
    LoadTexture(filename);
    Init();
}

