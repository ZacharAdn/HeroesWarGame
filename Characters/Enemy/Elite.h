//
// Created by zahar on 09/12/16.
//

#ifndef CPPEX1_ELITE_H
#define CPPEX1_ELITE_H


#include "EnemyCharacter.h"

class Elite : public EnemyCharacter{
public:
    Elite();

    Elite(double hp, double xp, Point2d &startLocation, Point2d &endLocation);

    virtual ~Elite();

    virtual char getcharToPrint() override ;

    string toString();

private:
    char charToPrint;
};


#endif //CPPEX1_ELITE_H
