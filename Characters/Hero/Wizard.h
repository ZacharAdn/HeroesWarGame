//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_WIZARD_H
#define CPPEX1_WIZARD_H

#include "Hero.h"



class Wizard : public Hero {

public:
    Wizard();

    /**
     *
     * @param hp
     * @param xp
     * @param startLocation
     * @param endLocation
     * @param name
     * @param gender
     */
    Wizard(double hp, double xp, Point2d &startLocation, Point2d &endLocation, const string &name, int gender);

    virtual ~Wizard();

    const double getRadius() const;

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;
    const double radius = 3;

};


#endif //CPPEX1_WIZARD_H
