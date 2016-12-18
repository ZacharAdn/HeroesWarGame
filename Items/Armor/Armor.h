//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_ARMOR_H
#define CPPEX1_ARMOR_H

#include "../Item.h"
class Hero;

class Armor : public Item{

public:

    Armor();

    /**
     *
     * @param location
     * @param protection
     */
    Armor(Point2d &location, double protection);

    virtual ~Armor();

    virtual double getProtection() const;

    virtual void setProtection(double protection);

    virtual char getcharToPrint() override ;

    virtual const string &getName() const =0 ;

    virtual void acceptToUse(Hero *hero) =0  ;

    virtual string toString();

private:
    char charToPrint;
    double protection;
    string name;
};


#endif //CPPEX1_ARMOR_H
