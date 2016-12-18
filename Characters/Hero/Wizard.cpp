////    Visitor *vi = getVisitor();

// Created by zahar on 07/12/16.
//

#include "Wizard.h"

Wizard::Wizard(): Hero::Hero() {}

Wizard::Wizard(double hp, double xp, Point2d &startLocation, Point2d &endLocation, const string &name, int gender)
        : Hero(hp, xp, startLocation, endLocation, name, gender), charToPrint('Z') {}

Wizard::~Wizard() {

}

const double Wizard::getRadius() const {
    return radius;
}


char Wizard::getcharToPrint() {
    return Wizard::charToPrint;
}

string Wizard::toString() {
    return "Wizard "+Hero::toString();
}
