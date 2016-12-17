//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_ARCHERWEAPON_H
#define CPPEX1_ARCHERWEAPON_H


#include "Weapon.h"
//class Hero;

class ArcherWeapon : public Weapon{

public:

    ArcherWeapon();

    ArcherWeapon(Point2d &location, double weaponPower);

    virtual ~ArcherWeapon();

    virtual const string &getName() const override ;

    virtual const string &getType() const = 0;

    virtual string toString();

private:
    string name;
};


#endif //CPPEX1_ARCHERWEAPON_H
