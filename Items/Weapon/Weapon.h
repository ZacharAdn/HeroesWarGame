//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_WEAPON_H
#define CPPEX1_WEAPON_H
using namespace std;

#include "../Item.h"
class Hero;

class Weapon : public Item{

public:
    Weapon();

    /**
     *
     * @param location
     * @param weaponPower
     */
    Weapon(Point2d &location, double weaponPower);

    virtual ~Weapon();

    virtual double getWeaponPower() const;

    virtual void setWeaponPower(double weaponPower);

    virtual const string &getType() const = 0;

    virtual const string &getName() const = 0;

    void acceptToUse(Hero *hero) override ;

    char getcharToPrint() override ;

    virtual string toString();

private:
    double weaponPower;
    char charToPrint;
    string name;

};


#endif //CPPEX1_WEAPON_H
