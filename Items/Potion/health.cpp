//
// Created by zahar on 07/12/16.
//

#include "health.h"

health::health() {}

health::health(Point2d &location, double amount) : Potion(location, amount), name("health") {}

health::~health() {

}

const string &health::getName() const {
    return health::name;
}

string health::toString() {
    return  "health " + Potion::toString();
}
