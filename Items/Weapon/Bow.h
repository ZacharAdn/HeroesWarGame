//
// Created by zahar on 09/12/16.
//

#ifndef CPPEX1_BOW_H
#define CPPEX1_BOW_H


#include "ArcherWeapon.h"

class Bow : public ArcherWeapon{
public:

    Bow();

    /**
     *
     * @param location
     * @param weaponPower
     */
    Bow(Point2d &location, double weaponPower);

    virtual ~Bow();

    const string &getType() const;

    virtual string toString();

private:
    const double extra = 1.6;
    const string type = "TwoHandedWeapon";
};


#endif //CPPEX1_BOW_H
