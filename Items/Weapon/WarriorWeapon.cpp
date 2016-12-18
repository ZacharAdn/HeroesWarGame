//
// Created by zahar on 06/12/16.
//

#include "WarriorWeapon.h"

WarriorWeapon::WarriorWeapon() : Weapon()
{

}

WarriorWeapon::WarriorWeapon(Point2d &location, double weaponPower)
        : Weapon(location,weaponPower), name("WarriorWeapon")
{}

WarriorWeapon::~WarriorWeapon() {

}

const string &WarriorWeapon::getName() const {
    return WarriorWeapon::name;
}

string WarriorWeapon::toString() {
    return "(WarriorWeapon) - "+Weapon::toString();
}
