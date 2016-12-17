//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_WIZARD_H
#define CPPEX1_WIZARD_H

#include "Hero.h"



class Wizard : public Hero {
private:
    const double radius = 3;

public:
    Wizard();

    Wizard(double hp, double xp, Point2d &startLocation, Point2d &endLocation, const string &name, int gender);

    virtual ~Wizard();

    const double getRadius() const;

//    virtual Item *use(Weapon *weapon) override ;
//
//    virtual Item *use(Potion *potion) override ;
//
//    virtual Item *use(BodyArmor *bodyArmor) override ;
//
//    virtual Item *use(ShieldArmor *shieldArmor) override ;

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;


};


#endif //CPPEX1_WIZARD_H
