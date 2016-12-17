//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_ARCHER_H
#define CPPEX1_ARCHER_H

#include "Hero.h"

class Archer : public Hero{
private:
    const double radius = 5;

public:
    Archer();

    Archer(double hp, double xp, Point2d &startLocation, Point2d &endLocation, string &name, int gender);

    virtual ~Archer();

    const double getRadius() const;

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;


};


#endif //CPPEX1_ARCHER_H
