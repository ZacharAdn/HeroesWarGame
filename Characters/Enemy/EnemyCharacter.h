//
// Created by zahar on 12/12/16.
//

#ifndef CPPEX1_ENEMYCHARACTER_H
#define CPPEX1_ENEMYCHARACTER_H


#include "../Character.h"
#include "../Hero/Hero.h"

class EnemyCharacter : public Character {

public:
    EnemyCharacter();

    EnemyCharacter(double hp, double xp, Point2d &startLocation, Point2d &endLocation);

    virtual ~EnemyCharacter();

    bool isDead() const;

    void setDead(bool dead);

    void attack(Hero *hero);

    const string &getName() const;

    void setName(const string &name);

    virtual string toString();

private:
    bool dead=false;
    string name;

};


#endif //CPPEX1_ENEMYCHARACTER_H
