//
// Created by zahar on 09/12/16.
//

#include "Bow.h"

Bow::Bow() {}

Bow::Bow(Point2d &location, double weaponPower) : ArcherWeapon(location, weaponPower) {
    setWeaponPower(weaponPower*extra);
}

Bow::~Bow() {

}

const string &Bow::getType() const {
    return type;
}

string Bow::toString() {
    return "Bow " +ArcherWeapon::toString();
}
