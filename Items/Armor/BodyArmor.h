//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_BODYARMOR_H
#define CPPEX1_BODYARMOR_H


#include "Armor.h"
class Hero;

class BodyArmor : public Armor{

public:
    BodyArmor();

    BodyArmor(Point2d &location, double protaction);

    virtual ~BodyArmor();

    virtual void acceptToUse(Hero *hero) override ;

    virtual const string &getName() const override ;

    string toString();

private:
    string name;
};


#endif //CPPEX1_BODYARMOR_H
