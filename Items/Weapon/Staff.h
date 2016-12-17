//
// Created by zahar on 09/12/16.
//

#ifndef CPPEX1_STAFF_H
#define CPPEX1_STAFF_H


#include "WizardWeapon.h"

class Staff : public WizardWeapon{
private:
    const double extra = 1.6;
    const string type = "TwoHandedWeapon";
    double weaponPower;

public:
    Staff();

    Staff(Point2d &location, double weaponPower);

    virtual ~Staff();

    const string &getType() const;

    virtual string toString();
};


#endif //CPPEX1_STA`FF_H
