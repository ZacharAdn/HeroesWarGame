//
// Created by zahar on 09/12/16.
//

#ifndef CPPEX1_SWORD_H
#define CPPEX1_SWORD_H


#include "WarriorWeapon.h"

class Sword : public WarriorWeapon {
public:
    Sword();

    /**
     *
     * @param location
     * @param weaponPower
     */
    Sword(Point2d &location, double weaponPower);

    virtual ~Sword();

    const string &getType() const;

    virtual string toString();


private:
    const double extra = 1.2;
    const string type = "OneHandedWeapon";
};


#endif //CPPEX1_SWORD_H
