#ifndef TBG_PCUNIT_H
#define TBG_PCUNIT_H

#include "Unit.h"

class PcUnit : public Unit {
public:
    PcUnit(const std::string& filename);

    //Personal position etc, for Player png
    void Init() override;
private:

};



#endif //TBG_PCUNIT_H
