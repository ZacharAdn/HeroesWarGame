//);
// Created by zahar on 06/12/16.
//

#include "Enemy.h"
//#include "Operation.h"



Enemy::Enemy() {}

Enemy::Enemy(double hp, double xp, Point2d &startLocation, Point2d &endLocation)
        : EnemyCharacter(hp, xp, startLocation,endLocation),charToPrint('E') {}

Enemy::~Enemy() {

}

//string Enemy::accept(Operation *v) {
//    return v->visit(this);
//}

string Enemy::toString() {
    return "Enemy " + EnemyCharacter::toString();
}

char Enemy::getcharToPrint() {
    return Enemy::charToPrint;
}




