//
// Created by zahar on 07/12/16.
//

#include "mana.h"

mana::mana() {}

mana::mana(Point2d &location, double amount) : Potion(location, amount), name("mana") {}

mana::~mana() {

}

string mana::toString() {
    return "mana " +Potion::toString();
}

const string &mana::getName() const {
    return mana::name;
}

//string mana::itemType(Operation *visitor) {
//    return visitor->visit(this);
//}
