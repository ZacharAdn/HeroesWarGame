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






//Item *Warrior::use(Item &item) {
//    Visitor *vi = getVisitor();
//    string type= item.itemType(vi);
//
//    if(type == "Hammer"){
//        return useTwoHeandedWeapon(&item, vi);
//    }else if(type == "Sword"){
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
//
//}

string Warrior::toString() {
    return "Warrior "+Hero::toString();
}

char Warrior::getcharToPrint() {
    return Warrior::charToPrint;
}
