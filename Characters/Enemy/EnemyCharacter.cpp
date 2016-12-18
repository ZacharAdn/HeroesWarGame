//
// Created by zahar on 12/12/16.
//

#include "EnemyCharacter.h"
#include "../../Items/Armor/ShieldArmor.h"
#include "../../Items/Armor/BodyArmor.h"

EnemyCharacter::EnemyCharacter() {}

EnemyCharacter::EnemyCharacter(double hp, double xp, Point2d &startLocation, Point2d &endLocation)
        : Character(hp, xp,startLocation,endLocation) {}

EnemyCharacter::~EnemyCharacter() {

}

void EnemyCharacter::attack(Hero *hero) {
    double attack=getXp();
    cout <<"\n" << toString() << " \nATTACK\n" << hero->toString();
    if(hero->getBodyArmor() != nullptr){
        attack*= hero->getBodyArmor()->getProtection();
        cout << "\nhero BodyArmor power "<< hero->getBodyArmor()->getProtection();
    }
    if(hero->getShieldArmor() != nullptr){
        attack*= hero->getShieldArmor()->getProtection();
        cout << "\nhero shieldArmor power "<< hero->getShieldArmor()->getProtection();
    }

    cout << ", powerAttack:" << attack;
    hero->damage(attack);
    cout<< "\nHP hero after damage:"<<hero->getHp() <<"\n";
}

bool EnemyCharacter::isDead() const {
    return dead;
}

void EnemyCharacter::setDead(bool dead) {
    EnemyCharacter::dead = dead;
}

const string &EnemyCharacter::getName() const {
    return name;
}

void EnemyCharacter::setName(const string &name) {
    EnemyCharacter::name = name;
}

string EnemyCharacter::toString() {
    return "(EnemyCharacter) name:"+getName()+", "+Character::toString();
}

