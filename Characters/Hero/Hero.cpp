//
// Created by zahar on 06/12/16.
//

#include "Hero.h"
#include "../Enemy/EnemyCharacter.h"
#include "../../Items/Weapon/Weapon.h"
#include "../../Items/Potion/Potion.h"
#include "../../Items/Armor/BodyArmor.h"
#include "../../Items/Armor/ShieldArmor.h"


Hero::  Hero() {}



Hero::Hero(double hp, double xp, Point2d &startLocation, Point2d &endLocation, const string &name, int gender)
        : Character(hp, xp, startLocation, endLocation), name(name),gender(gender),shieldArmor(nullptr)
        ,bodyArmor(nullptr),weapon(nullptr),potion(nullptr),enemyToWar(nullptr) {}


Hero::~Hero() {

}

void Hero::use(Weapon *weapon) {

    if (getName().find("Warrior")!= string::npos ) {
        if (weapon->getName() == "WarriorWeapon") {
            checkAndTakeWeapon(weapon);
        }
    } else if (getName().find("Wizard")!= string::npos) {
        if (weapon->getName() == "WizardWeapon") {
            checkAndTakeWeapon(weapon);
        }
    } else if (getName().find("Archer")!= string::npos) {
        if (weapon->getName() == "ArcherWeapon") {
            checkAndTakeWeapon(weapon);
        }
    }

}

void Hero::checkAndTakeWeapon(Weapon *pWeapon) {
    if (Hero::getWeapon() == nullptr || Hero::getWeapon()->getWeaponPower() < pWeapon->getWeaponPower()) {
        setWeapon(pWeapon);
        takesNewItem(true);
        cout <<"\n" << getName() << " takes " << pWeapon->getName() << ", weaponPower:"<< pWeapon->getWeaponPower();
        cout <<"\n"<<toString();
        if (pWeapon->getType() == "TwoHandedWeapon") {
            throwTheArmor(getShieldArmor());
            setShieldArmor(nullptr);
        }else{
            throwTheArmor(nullptr);
        }
    }
}

void Hero::use(Potion *potion) {

    if(potion->getName() == "mana" && getName() == "Wizard") {
        takePotion(potion);
    }else if(potion->getName() == "health"){
        takePotion(potion);
    }
}

void Hero::takePotion(Potion *potion) {
    setHp(getHp() + potion->getAmount());
    if (getHp() > FULL) {
        setHp(FULL);
    }
    cout <<"\n" << getName() << " takes " << potion->getName()<< ", amount:"<<potion->getAmount();
    cout <<"\n"<<toString();
    takesNewItem(true);


}

void Hero::use(BodyArmor *bodyArmor) {
    if(getBodyArmor() == nullptr || Hero::getBodyArmor()->getProtection() < bodyArmor->getProtection()){
        setBodyArmor(bodyArmor);
        cout <<"\n" << getName() << " takes " << bodyArmor->getName() << ", protaction:"<<bodyArmor->getProtection();
        cout <<"\n"<<toString();
        takesNewItem(true);
    }
}

void Hero::use(ShieldArmor *shieldArmor) {
    if((getWeapon() == nullptr || getWeapon()->getType() == "OneHandedWeapon") &&
       (shieldArmor->getProtection() > Hero::getShieldArmor()->getProtection())) {
        setShieldArmor(shieldArmor);
        cout <<"\n" << getName() << " takes " << shieldArmor->getName() << ", protaction:"<<shieldArmor->getProtection();
        cout <<"\n"<<toString();

        takesNewItem(true);
    }
}

void Hero::move(Point2d *dest) {
    cout <<"\n" << getName() << " moves from " << getStartLocation()->toString() << ", to:"<< dest->toString();

    setStartLocation(dest);

}



void Hero::attack(EnemyCharacter *enemy) {
    cout <<"\n" << toString() << " \nATTACK\n" << enemy->toString();
    double attack = getXp();
    if(getWeapon() != nullptr){
        attack *= getWeapon()->getWeaponPower();
        cout << "with \n"<< getWeapon()->toString();
    }
    enemy->damage(attack);
    cout << "\nHP enemy after damage: " << enemy->getHp()<<"\n";
}

const string &Hero::getName() const {
    return name;
}

void Hero::setName(const string &name) {
    Hero::name = name;
}

int Hero::getGender() const {
    return gender;
}

void Hero::setGender(int gender) {
    Hero::gender = gender;
}

ShieldArmor *Hero::getShieldArmor() const {
    return shieldArmor;
}

void Hero::setShieldArmor(ShieldArmor *shieldArmor) {
    Hero::shieldArmor = shieldArmor;
}

BodyArmor *Hero::getBodyArmor() const {
    return bodyArmor;
}

void Hero::setBodyArmor(BodyArmor *bodyArmor) {
    Hero::bodyArmor = bodyArmor;
}

int Hero::getSideX() const {
    return sideX;
}

void Hero::setSideX(int sideX) {
    Hero::sideX = sideX;
}

int Hero::getSideY() const {
    return sideY;
}

void Hero::setSideY(int sideY) {
    Hero::sideY = sideY;
}

double Hero::getDistanceX() const {
    return distanceX;
}

void Hero::setDistanceX(double distanceX) {
    Hero::distanceX = distanceX;
}

double Hero::getDistanceY() const {
    return distanceY;
}


void Hero::setDistanceY(double distanceY) {
    Hero::distanceY = distanceY;
}

bool Hero::isAtWar() const {
    return atWar;
}


void Hero::setAtWar(bool atWar) {
    Hero::atWar = atWar;
}

Weapon *Hero::getWeapon() const {
    return weapon;
}


void Hero::setWeapon(Weapon *weapon) {
    Hero::weapon = weapon;
}

void Hero::setEnemyToWar(EnemyCharacter *enemy) {
    Hero::enemyToWar=enemy;
}


EnemyCharacter *Hero::getEnemyToWar() const {
    return enemyToWar;
}



void Hero::takesNewItem(bool b) {
    Hero::newItem = b;
}

bool Hero::isTakeNewItem() const {
    return newItem;
}

void Hero::throwTheArmor(ShieldArmor *pArmor) {
    toThrow = pArmor;
}

ShieldArmor *Hero::getThrownArmor() const {
    return toThrow;
}

string Hero::toString() {
    return "(Hero), name:" + Hero::name + ", Gender:" + to_string(Hero::gender) +", "+Character::toString();
}
