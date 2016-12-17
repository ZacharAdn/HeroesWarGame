//
// Created by zahar on 07/12/16.
//

#include "WizardWeapon.h"

WizardWeapon::WizardWeapon() : Weapon()
{

}

WizardWeapon::WizardWeapon(Point2d &location, double weaponPower)
        : Weapon(location, weaponPower), name("WizardWeapon") {}


WizardWeapon::~WizardWeapon() {

}

string WizardWeapon::toString() {
    return "(WizardWeapon) - "+Weapon::toString();
}

const string &WizardWeapon::getName() const {
    return WizardWeapon::name;
}
