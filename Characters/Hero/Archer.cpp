//
// Created by zahar on 07/12/16.
//

#include "Archer.h"

Archer::Archer() : Hero::Hero(){}


Archer::Archer(double hp, double xp, Point2d &startLocation, Point2d &endLocation, string &name, int gender)
        : Hero(hp, xp, startLocation, endLocation, name, gender), charToPrint('R'),typeName("Archer") {}

Archer::~Archer() {

}

const double Archer::getRadius() const {
    return radius;
}

char Archer::getcharToPrint() {
    return Archer::charToPrint;
}

string Archer::toString() {
    return "Archer "+Hero::toString();
}

const string &Archer::getTypeName() {
    return typeName;
}

