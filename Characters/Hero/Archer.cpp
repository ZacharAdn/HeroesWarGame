//
// Created by zahar on 07/12/16.
//

#include "Archer.h"
//#include "Visitor.h"

Archer::Archer() : Hero::Hero(){}


Archer::Archer(double hp, double xp, Point2d &startLocation, Point2d &endLocation, string &name, int gender)
        : Hero(hp, xp, startLocation, endLocation, name, gender), charToPrint('R') {}

Archer::~Archer() {

}

const double Archer::getRadius() const {
    return radius;
}

string Archer::toString() {
    return "Archer "+Hero::toString();
}

char Archer::getcharToPrint() {
    return Archer::charToPrint;
}

//Item *Archer::use(Item &item) {
//    Visitor *vi = getVisitor();
//    string type= item.itemType(vi);
//
//    if(type == "Bow"){
//        return useTwoHeandedWeapon(&item, vi);
//    }else if(type == "CrossBow"){
//        return useOneHeandedWeapon(&item, vi);
//    }else if(type == "health"){
//        return usePotion(&item, vi);
//    }else if(type == "BodyArmor"){
//        return useBodyArmor(&item, vi);
//    }else if(type == "ShieldArmor"){
//        return useShieldArmor(&item, vi);
//    }
//
//    return nullptr;
//}

