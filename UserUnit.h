#ifndef TBG_USERUNIT_H
#define TBG_USERUNIT_H

#include "Unit.h"

class UserUnit : public Unit {
public:
    UserUnit(const string& filename);
    void Init() override;

private:

};


#endif //TBG_USERUNIT_H
