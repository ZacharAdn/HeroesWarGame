//
// Created by zahar on 07/12/16.
//

#include "BodyArmor.h"
#include "../../Characters/Hero/Hero.h"

BodyArmor::BodyArmor() {}

BodyArmor::BodyArmor(Point2d &location, double protaction) : Armor(location, protaction) ,name("BodyArmor") {}

BodyArmor::~BodyArmor() {

}

string BodyArmor::toString() {
    return "BodyArmor " +Armor::toString();
}

void BodyArmor::acceptToUse(Hero *hero) {
    hero->use(this);
}

const string &BodyArmor::getName() const {
    return BodyArmor::name;
}

//string BodyArmor::itemType(Operation *visitor) {
//    return visitor->visit(this);
//}
