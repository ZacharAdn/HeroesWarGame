//
// Created by zahar on 09/12/16.
//

#include "Wand.h"

Wand::Wand() {}

Wand::Wand(Point2d &location, double weaponPower) : WizardWeapon(location, weaponPower) {
    setWeaponPower(weaponPower*extra);
}

Wand::~Wand() {

}

const string &Wand::getType() const {
    return type;
}

string Wand::toString() {
    return "Wand " + WizardWeapon::toString();
}
