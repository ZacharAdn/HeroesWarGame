//
// Created by zahar on 06/12/16.
//

#include <sstream>
#include "Character.h"


Character::Character() {}

Character::Character(double hp, double xp, Point2d &startLocation, Point2d &endLocation):
hp(hp) , xp(xp) , location(&startLocation), endLocation(&endLocation) {}

Character::~Character() {

}

void Character::damage(double attack) {
    setHp(getHp()-attack);
}

double Character::getHp() const {
    return hp;
}

void Character::setHp(double hp) {
    Character::hp = hp;
}

double Character::getXp() const {
    return xp;
}

void Character::setXp(double xp) {
    Character::xp = xp;
}

Point2d *Character::getStartLocation() const {
    return location;
}

void Character::setStartLocation(Point2d *startLocation) {
    Character::location = startLocation;
}

Point2d *Character::getEndLocation() const {
    return endLocation;
}

void Character::setEndLocation(Point2d *endLocation) {
    Character::endLocation = endLocation;
}

string Character::toString()
{
    return "Start Point:"+Character::location->toString()+",End Point:"+ Character::endLocation->toString()
           +", HP:"+ to_string(Character::hp) +", XP:"+ to_string(Character::xp);
}


