//
// Created by zahar on 09/12/16.
//

#include "CrossBow.h"

CrossBow::CrossBow() {}

CrossBow::CrossBow(Point2d &location, double weaponPower) : ArcherWeapon(location, weaponPower) {
    setWeaponPower(weaponPower*extra);

}

CrossBow::~CrossBow() {

}

const string &CrossBow::getType() const {
    return type;
}

string CrossBow::toString() {
    return "CrossBow " + ArcherWeapon::toString();
}
