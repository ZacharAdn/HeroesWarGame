//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_WARRIOR_H
#define CPPEX1_WARRIOR_H

#include <cmath>
#include "Hero.h"

class Warrior : public Hero{
private:
    const double radius = sqrt(2);
public:

    Warrior();

    Warrior(double hp, double xp, Point2d &startLocation, Point2d &endLocation,  string &name, int gender);

    virtual ~Warrior();

    const double getRadius() const;

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;

//
};


#endif //CPPEX1_WARRIOR_H

