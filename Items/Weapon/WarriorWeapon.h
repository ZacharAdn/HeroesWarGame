//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_WARRIORWEAPON_H
#define CPPEX1_WARRIORWEAPON_H
using namespace std;

#include <string>
#include "Weapon.h"


class WarriorWeapon : public Weapon{

public:
    WarriorWeapon();

    WarriorWeapon(Point2d &location, double weaponPower);

    virtual ~WarriorWeapon();

    virtual const string &getName() const override ;

    virtual const string &getType() const = 0;

    virtual string toString();


private:
    string name;
};


#endif //CPPEX1_WARRIORWEAPON_H
