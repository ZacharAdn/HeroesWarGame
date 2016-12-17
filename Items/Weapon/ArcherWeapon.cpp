//
// Created by zahar on 07/12/16.
//

#include "ArcherWeapon.h"


ArcherWeapon::ArcherWeapon() : Weapon() {}

ArcherWeapon::ArcherWeapon(Point2d &location, double weaponPower)
        : Weapon(location ,weaponPower),name("ArcherWeapon") {}

ArcherWeapon::~ArcherWeapon() {}
string ArcherWeapon::toString() {
    return "(ArcherWeapon) - "+Weapon::toString();
}

const string &ArcherWeapon::getName() const {
    return ArcherWeapon::name;
}

