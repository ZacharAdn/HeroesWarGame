//
// Created by zahar on 07/12/16.
//

#include "Potion.h"
#include "../../Characters/Hero/Hero.h"


Potion::Potion(): Item::Item(), amount() {

}



Potion::Potion(Point2d &location, double amount) : Item(location), amount(amount), charToPrint('P') {}


Potion::~Potion() {

}

double Potion::getAmount() const {
    return Potion::amount;
}

void Potion::setAmount(double amount) {
    Potion::amount = amount;
}

string Potion::toString() {
    return "(Potion) - "+ getLocation()->toString()+ ", amount: " + to_string(Potion::amount);
}

char Potion::getcharToPrint() {
    return Potion::charToPrint;
}

void Potion::acceptToUse(Hero *hero) {
    hero->use(this);
}