//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_MANA_H
#define CPPEX1_MANA_H


#include "Potion.h"

class mana : public Potion{
public:
    mana();

    mana(Point2d &location, double amount);

    virtual ~mana();

    virtual const string &getName() const override ;

    string toString();

private:
    string name;
};


#endif //CPPEX1_MANA_H
