#ifndef TBG_PCUNIT_H
#define TBG_PCUNIT_H

#include "Unit.h"

class PcUnit : public Unit {
public:
//    A constructor
    PcUnit(const std::string& filename);

//    Function "Init" overriting the base Init function
    void Init() override;
private:

};



#endif //TBG_PCUNIT_H
