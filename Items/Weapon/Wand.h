//
// Created by zahar on 09/12/16.
//

#ifndef CPPEX1_WAND_H
#define CPPEX1_WAND_H


#include "WizardWeapon.h"

class Wand : public WizardWeapon{
private:
    const double extra = 1.2;
    const string type = "OneHandedWeapon";
public:
    Wand();

    Wand(Point2d &location, double weaponPower);

    virtual ~Wand();

    const string &getType() const;

    virtual string toString();
};


#endif //CPPEX1_WAND_H
