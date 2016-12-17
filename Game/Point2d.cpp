//
// Created by zahar on 06/12/16.
//

#include "Point2d.h"

Point2d::Point2d(): x(0),y(0) {}

Point2d::Point2d(int x, int y) : x(x), y(y) {}

Point2d::~Point2d() {

}

int Point2d::getX() const {
    return x;
}

void Point2d::setX(int x) {
    Point2d::x = x;
}

int Point2d::getY() const {
    return y;
}

void Point2d::setY(int y) {
    Point2d::y = y;
}

string Point2d::toString() {
    return "["+ to_string(Point2d::x) +","+to_string(Point2d::y)+"]";
}
//
//Point2d &Point2d::operator=(const Point2d *point) {
//    Point2d::x = point->x;
//    Point2d::y = point->y;
//    return *this;
//}
