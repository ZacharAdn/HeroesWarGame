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


string Wizard::toString() {
    return "Wizard "+Hero::toString();
}

char Wizard::getcharToPrint() {
    return Wizard::charToPrint;
}


//Item *Wizard::use(Item &item) {
//
//    if(type == "Staff"){
//        return useTwoHeandedWeapon(&item, vi);
//    }else if(type == "Wand"){
//        return useOneHeandedWeapon(&item, vi);
//    }else if(type == "health"){
//        return usePotion(&item, vi);
//    }else if(type == "mana") {
//        return usePotion(&item, vi);
//    }else if(type == "BodyArmor"){
//        return useBodyArmor(&item, vi);
//    }else if(type == "ShieldArmor"){
//        return useShieldArmor(&item, vi);
//    }
//
//
//    return nullptr;
//}
//
