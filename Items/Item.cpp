//
// Created by zahar on 06/12/16.
//

#include "Item.h"
#include "../Characters/Hero/Hero.h"


Item::Item() {}

Item::Item(Point2d &location) : location(&location) {}

Item::~Item() {}


Point2d *Item::getLocation() const {
    return location;
}

void Item::setLocation(Point2d *location) {
    Item::location = location;
}

string Item::toString() {
    return "location:"+getLocation()->toString();
}

