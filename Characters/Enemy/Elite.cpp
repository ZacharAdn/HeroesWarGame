//
// Created by zahar on 09/12/16.
//

#include "Elite.h"

Elite::Elite() {}


Elite::~Elite() {

}

Elite::Elite(double hp, double xp, Point2d &startLocation, Point2d &endLocation)
        : EnemyCharacter(hp, xp, startLocation,endLocation), charToPrint('L') {}


char Elite::getcharToPrint() {
    return Elite::charToPrint;
}

string Elite::toString() {
    return "Elite "+ EnemyCharacter::toString();
}
