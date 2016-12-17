//
// Created by zahar on 09/12/16.
//
//
#ifndef CPPEX1_HAMMER_H
#define CPPEX1_HAMMER_H


#include "WarriorWeapon.h"

class Hammer : public WarriorWeapon {
private:
    const double extra = 1.6;
    const string type = "TwoHandedWeapon";
public:
    Hammer();

    Hammer(Point2d &location, double weaponPower);

    virtual ~Hammer();

    const string &getType() const;

    virtual string toString();
};


#endif //CPPEX1_HAMMER_H
