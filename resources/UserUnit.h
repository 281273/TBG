#ifndef TBG_USERUNIT_H
#define TBG_USERUNIT_H

#include "Unit.h"

class UserUnit : public Unit {
public:
//    A constructor
    UserUnit(const std::string& filename);

//    Function "Init" overriting the base Init function
    void Init() override;
private:

};


#endif //TBG_USERUNIT_H
