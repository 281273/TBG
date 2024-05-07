#ifndef TBG_PCUNIT_H
#define TBG_PCUNIT_H

#include "Unit.h"

class PcUnit : public Unit {
public:
    PcUnit(const string& filename);
    void Init() override;
private:

};



#endif //TBG_PCUNIT_H
