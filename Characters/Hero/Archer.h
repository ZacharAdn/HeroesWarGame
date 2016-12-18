//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_ARCHER_H
#define CPPEX1_ARCHER_H

#include "Hero.h"

class Archer : public Hero{

public:
    Archer();

    /**
     *
     * @param hp
     * @param xp
     * @param startLocation
     * @param endLocation
     * @param name
     * @param gender
     */
    Archer(double hp, double xp, Point2d &startLocation, Point2d &endLocation, string &name, int gender);

    virtual ~Archer();

    const double getRadius() const;

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;
    const double radius = 5;

};


#endif //CPPEX1_ARCHER_H
