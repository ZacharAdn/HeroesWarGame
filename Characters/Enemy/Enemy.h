//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_ENEMY_H
#define CPPEX1_ENEMY_H
using namespace std;

#include <string>
#include "EnemyCharacter.h"



class Enemy : public EnemyCharacter{

public:
    Enemy();

    /**
     *
     * @param hp
     * @param xp
     * @param startLocation
     * @param endLocation
     */
    Enemy(double hp, double xp, Point2d &startLocation, Point2d &endLocation);

    virtual ~Enemy();

    virtual char getcharToPrint() override ;

    string toString();
private:

    char charToPrint;
};


#endif //CPPEX1_ENEMY_H
