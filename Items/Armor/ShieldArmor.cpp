//
// Created by zahar on 07/12/16.
//

#include "ShieldArmor.h"
#include "../../Characters/Hero/Hero.h"

ShieldArmor::ShieldArmor() {}

ShieldArmor::ShieldArmor(Point2d &location, double protaction) : Armor(location, protaction), name("ShieldArmor") {}

ShieldArmor::~ShieldArmor() {

}

string ShieldArmor::toString() {
    return "ShieldArmor " +Armor::toString();
}

void ShieldArmor::acceptToUse(Hero *hero) {
    hero->use(this);
}

const string &ShieldArmor::getName() const {
    return ShieldArmor::name;
}
