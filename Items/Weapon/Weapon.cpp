//
// Created by zahar on 06/12/16.
//

#include "Weapon.h"
#include "../../Characters/Hero/Hero.h"

Weapon::Weapon()
        : Item(),weaponPower()
{

}

Weapon::Weapon(Point2d &location, double weaponPower)
        : Item(location), weaponPower(weaponPower),charToPrint('W')
{

}

Weapon::~Weapon()
{

}

double Weapon::getWeaponPower() const
{
    return Weapon::weaponPower;
}

void Weapon::setWeaponPower(double weaponPower)
{
    Weapon::weaponPower=weaponPower;
}

string Weapon::toString() {
    return Item::toString();
}

char Weapon::getcharToPrint() {
    return Weapon::charToPrint;
}

void Weapon::acceptToUse(Hero *hero) {
    hero->use(this);
}
