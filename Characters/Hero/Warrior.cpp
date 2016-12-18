//
// Created by zahar on 06/12/16.
//

#include "Warrior.h"


Warrior::Warrior(): Hero::Hero()
{

}


Warrior::Warrior(double hp, double xp, Point2d &startLocation, Point2d &endLocation, string &name, int gender)
        : Hero(hp, xp, startLocation, endLocation, name, gender),charToPrint('A') {}

Warrior::~Warrior()  {}


const double Warrior::getRadius() const {
    return radius;
}

char Warrior::getcharToPrint() {
    return Warrior::charToPrint;
}

string Warrior::toString() {
    return "Warrior "+Hero::toString();
}
