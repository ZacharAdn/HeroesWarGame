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

    /**
     * abstract class of enemies
     * @param hp
     * @param xp
     * @param startLocation
     * @param endLocation
     */
    EnemyCharacter(double hp, double xp, Point2d &startLocation, Point2d &endLocation);

    virtual ~EnemyCharacter();

    /**
     * attack back the hero
     * @param hero
     */
    void attack(Hero *hero);


    /**
     * Getters and Setters
     *
     */
    bool isDead() const;

    void setDead(bool dead);

    const string &getName() const;

    void setName(const string &name);

    virtual string toString();

private:
    bool dead = false;
    string name;

};


#endif //CPPEX1_ENEMYCHARACTER_H
