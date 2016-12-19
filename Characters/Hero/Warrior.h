//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_WARRIOR_H
#define CPPEX1_WARRIOR_H

#include <cmath>
#include "Hero.h"

class Warrior : public Hero{
public:

    Warrior();

    /**
     *
     * @param hp
     * @param xp
     * @param startLocation
     * @param endLocation
     * @param name
     * @param gender
     */
    Warrior(double hp, double xp, Point2d &startLocation, Point2d &endLocation,  string &name, int gender);

    virtual ~Warrior();


    /**
     * Getters and Setters
     *
     */

    const double getRadius() const;

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;
    const double radius = sqrt(2);

};


#endif //CPPEX1_WARRIOR_H

