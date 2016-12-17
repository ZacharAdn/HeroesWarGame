//
// Created by zahar on 06/12/16.
//

#include "Armor.h"
#include "../../Characters/Hero/Hero.h"


Armor::Armor():Item::Item(), protection()
{

}


Armor::Armor(Point2d &location, double protection) : Item(location),name("Armor"), protection(protection), charToPrint('S')
{

}

Armor::~Armor()
{

}

double Armor::getProtection() const
{
    return protection;
}

void Armor::setProtection(double protection)
{
    Armor::protection = protection;
}

string Armor::toString()
{
    return "(Armor) - "+Item::toString() + ", protection: "+ to_string(Armor::protection);
}

char Armor::getcharToPrint() {
    return Armor::charToPrint;
}
