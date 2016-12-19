//#include "EnemyCharacter.h"
// Created by zahar on 06/12/16.
//
//
#ifndef CPPEX1_CHARACTER_H
#define CPPEX1_CHARACTER_H

using namespace std;

#include <string>
#include "../Game/Point2d.h"
#include "../Items/Item.h"

class Character{
private:

    double hp;
    double xp;
    Point2d *location;
    Point2d * endLocation;

public:


    Character();

    /**
     * Character in the game
     *
     * @param hp Health Point
     * @param xp Experience Point
     * @param startLocation
     * @param endLocation
     */
    Character(double hp, double xp, Point2d &startLocation,Point2d &endLocation);

    virtual ~Character();


    /**
     *
     * @return representing char for each Character
     */
    virtual char getcharToPrint() = 0;

    /**
     * The damage caused by attacks
     * @param attack
     */
    void damage(double attack);

    /**
     * Getters and Setters
     *
     */

    double getHp() const;

    void setHp(double hp);

    double getXp() const;

    void setXp(double xp);

    Point2d *getStartLocation() const;

    void setStartLocation(Point2d *startLocation);

    Point2d *getEndLocation() const;

    void setEndLocation(Point2d *endLocation);

    virtual string toString();

};


#endif //CPPEX1_CHARACTER_H
