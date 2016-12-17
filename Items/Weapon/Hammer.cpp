//
// Created by zahar on 09/12/16.
//

#include "Hammer.h"

Hammer::Hammer() {}

Hammer::Hammer(Point2d &location, double weaponPower) : WarriorWeapon(location, weaponPower) {
    setWeaponPower(weaponPower*extra);
}

Hammer::~Hammer() {

}

const string &Hammer::getType() const {
    return type;
}

string Hammer::toString() {
    return "Hammer " + WarriorWeapon::toString();
}