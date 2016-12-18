//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_HERO_H
#define CPPEX1_HERO_H
using namespace std;

#include <string>
#include "iostream"
#include "../Character.h"

#define POSITIVE_SIDE -1
#define NEGATIVE_SIDE 1
#define FULL 100

class ShieldArmor;
class BodyArmor;
class EnemyCharacter;
class Weapon;
class Potion;


class Hero : public Character {
public:

    Hero();

    /**
     *
     * @param hp
     * @param xp
     * @param startLocation
     * @param endLocation
     * @param name
     * @param gender
     */
    Hero(double hp, double xp, Point2d &startLocation, Point2d &endLocation, const string &name, int gender);

    virtual ~Hero();

    /**
     * apply to hero the use of weapon in hes radius
     * called from acceptToUse function in Item class
     * using Visitor design patterm
     * @param weapon
     */
    virtual void use(Weapon *weapon);

    /**
     * apply to hero the use of potion in hes radius
     * @param potion
     */
    virtual void use(Potion *potion);

    /**
     * apply to hero the use of body armor in hes radius
     * @param bodyArmor
     */
    virtual void use(BodyArmor *bodyArmor);

    /**
     * apply to hero the use of shield armor in hes radius
     * @param shieldArmor
     */
    virtual void use(ShieldArmor *shieldArmor);

    /**
     * moves the hero to hes destination
     * @param dest
     */
    void move(Point2d *dest);

    /**
     * attack enemy in the radius
     * @param enemy
     */
    void attack(EnemyCharacter *enemy);


    /**
     *
     * @return the radius scanning for enemys and items on the map
     */
    virtual const double getRadius() const = 0;

    void throwTheArmor(ShieldArmor *pArmor);

    const string &getName() const;

    void setName(const string &name);

    int getGender() const;

    void setGender(int gender);

    ShieldArmor *getShieldArmor() const;

    void setShieldArmor(ShieldArmor *shieldArmor);

    BodyArmor *getBodyArmor() const;

    void setBodyArmor(BodyArmor *bodyArmor);

    int getSideX() const;

    void setSideX(int sideX);

    int getSideY() const;

    void setSideY(int sideY);

    double getDistanceX() const;

    void setDistanceX(double distanceX);

    double getDistanceY() const;

    void setDistanceY(double distanceY);

    bool isAtWar() const;

    void setAtWar(bool atWar);

    Weapon *getWeapon() const;

    void setWeapon(Weapon *weapon);

    void setEnemyToWar(EnemyCharacter *enemy);

    EnemyCharacter *getEnemyToWar() const;

    bool isTakeNewItem() const;

    void takesNewItem(bool b);

    ShieldArmor *getThrownArmor() const;

    virtual string toString();

private:
    string name;
    int gender;
    int sideX,sideY;
    double distanceX,distanceY;
    bool atWar = false;
    bool newItem = false;

    Weapon *weapon;
    ShieldArmor *shieldArmor,*toThrow;
    BodyArmor *bodyArmor;
    Potion *potion;
    EnemyCharacter *enemyToWar;

    /**
     * checks for num of free hands and holding shields by hero
     * @param pWeapon
     */
    void checkAndTakeWeapon(Weapon *pWeapon);

};


#endif //CPPEX1_HERO_H
