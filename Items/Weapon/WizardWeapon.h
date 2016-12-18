//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_WIZARDWEAPON_H
#define CPPEX1_WIZARDWEAPON_H


#include "Weapon.h"

class WizardWeapon: public Weapon {
public:
    WizardWeapon();

    /**
     * abstract class for wizard weapons
     * @param location
     * @param weaponPower
     */
    WizardWeapon(Point2d &location, double weaponPower);

    virtual ~WizardWeapon();

    virtual const string &getName() const override ;

    virtual const string &getType() const = 0;

    virtual string toString();

private:
    string name;
};


#endif //CPPEX1_WIZARDWEAPON_H
