//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_SHIELDARMOR_H
#define CPPEX1_SHIELDARMOR_H

#include "Armor.h"

class ShieldArmor : public Armor{

public:

    ShieldArmor();

    ShieldArmor(Point2d &location, double protaction);

    virtual ~ShieldArmor();

    virtual void acceptToUse(Hero *hero) override ;

    virtual const string &getName() const override ;

    string toString();

private:
    string name;
};


#endif //CPPEX1_SHIELDARMOR_H
