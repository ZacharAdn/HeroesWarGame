//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_ITEM_H
#define CPPEX1_ITEM_H

using namespace std;

#include <string>
#include <typeinfo>
#include <iomanip>
#include "../Game/Point2d.h"
class Hero;

class Item {
public:
    Item();

    Item(Point2d &location);

    virtual ~Item();

    Point2d *getLocation() const;

    void setLocation(Point2d *location);

    virtual string toString();

    virtual char getcharToPrint() = 0;

    virtual void acceptToUse(Hero *hero) = 0;

    virtual const string &getName() const = 0;

private:
    Point2d *location;

};


#endif //CPPEX1_ITEM_H
