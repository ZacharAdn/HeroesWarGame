//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_HEALTH_H
#define CPPEX1_HEALTH_H


#include "Potion.h"

class health: public Potion {
public:

    health();

    health(Point2d &location, double amount);

    virtual ~health();

    virtual const string &getName() const override ;

    string toString();

private:
    string name;
};


#endif //CPPEX1_HEALTH_H
