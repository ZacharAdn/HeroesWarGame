//
// Created by zahar on 06/12/16.
//

#ifndef CPPEX1_HERO_H
#define CPPEX1_HERO_H
using namespace std;

#define POSITIVE_SIDE -1
#define NEGATIVE_SIDE 1
#define FULL 100

#include <string>
#include "iostream"
#include "../Character.h"

class ShieldArmor;
class BodyArmor;
class EnemyCharacter;
class Weapon;
class Potion;


class Hero : public Character {
public:

    Hero();

    Hero(double hp, double xp, Point2d &startLocation, Point2d &endLocation, const string &name, int gender);

    virtual ~Hero();

    const string &getName() const;

    void setName(const string &name);

    virtual const double getRadius() const = 0;

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

    virtual void use(Weapon *weapon);

    virtual void use(Potion *potion);

    virtual void use(BodyArmor *bodyArmor);

    virtual void use(ShieldArmor *shieldArmor);

    void move(Point2d *dest);

    void attack(EnemyCharacter *enemy);

    virtual string toString();

    void setEnemyToWar(EnemyCharacter *enemy);

    EnemyCharacter *getEnemyToWar() const;

    bool isNewItem() const;

    void takesNewItem(bool b);

    ShieldArmor *getThrownArmor() const;

    void throwTheArmor(ShieldArmor *pArmor);

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


    void checkAndTakeWeapon(Weapon *pWeapon);

};


#endif //CPPEX1_HERO_H
