//
// Created by zahar on 09/12/16.
//

#include <iostream>
#include "Sword.h"


Sword::Sword() {}

Sword::Sword(Point2d &location, double weaponPower) : WarriorWeapon(location, weaponPower) {
    setWeaponPower(weaponPower*extra);
}

Sword::~Sword() {

}

const string &Sword::getType() const {
    return type;
}

string Sword::toString() {
    return "Sword " +WarriorWeapon::toString() +", Weapon Power: "+ to_string(getWeaponPower());;
}
