//
// Created by zahar on 09/12/16.
//

#include "Staff.h"

Staff::Staff() {}

Staff::Staff(Point2d &location, double weaponPower) : WizardWeapon(location, weaponPower) {
    setWeaponPower(weaponPower*extra);
}

Staff::~Staff() {

}

const string &Staff::getType() const {
    return type;
}

string Staff::toString() {
    return "Staff " +WizardWeapon::toString();
}

