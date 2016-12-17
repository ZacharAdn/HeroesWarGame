//#include "EnemyCharacter.h"
// Created by zahar on 06/12/16.
//
//
#ifndef CPPEX1_CHARACTER_H
#define CPPEX1_CHARACTER_H

using namespace std;

#include <string>
//#include "../Game/Operation.h"
#include "../Game/Point2d.h"
#include "../Items/Item.h"

class Character{
private:

    double hp;//Health Points
    double xp;//Experience Points
    Point2d *startLocation;
    Point2d * endLocation;

public:

    Character();

    Character(double hp, double xp, Point2d &startLocation,Point2d &endLocation);

    virtual ~Character();

    double getHp() const;

    void setHp(double hp);

    double getXp() const;

    void setXp(double xp);

    Point2d *getStartLocation() const;

    void setStartLocation(Point2d *startLocation);

    Point2d *getEndLocation() const;

    void setEndLocation(Point2d *endLocation);

    virtual string toString();

    virtual char getcharToPrint() = 0;

    void damage(double attack);


};


#endif //CPPEX1_CHARACTER_H
