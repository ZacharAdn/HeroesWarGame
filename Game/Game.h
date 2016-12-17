//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_GAME_H
#define CPPEX1_GAME_H

#define FULL_HP 100
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>

class Character;
class Point2d;
class Item;
class Hero;
class Enemy;
class EnemyCharacter;
class Sword;
class Console;


using namespace std;


class Game {
public:

    Game();

    void read(string adress);

    void update(const string &type, const string &name);

    void play();


private:
    unordered_map<Point2d*,Character*> *Characters;
    vector<Item*> *Items;
    vector<Hero*> *heroes;
    vector<EnemyCharacter*> *enemies;
    vector<Character*> *outputVec;
    char ** Matrix;
    int MatRowSize,MatColSize;
    Console *console;

    const unordered_map<Point2d*,Character*> &getCharacters() const;

    double getPowerFromFile(ifstream &ifstream);

    Point2d* getPointFromFile(ifstream &ifstream);

    int getGenderFromFile(ifstream &file);

    void calcHeroTrack(Hero *pHero);

    void scanForItems(Hero *pHero);

    void scanForEnemies(Hero *pHero);

    void WAR(Hero *hero);

    Point2d *getNextPoint(Hero *pHero);

    bool isInRange(Point2d *checkdLocation, Hero *hero);

    Point2d *checkBounds(Point2d *hero, Hero *pHero);

    void updateMove(Hero *source, Point2d *destination);

    bool isStillEnemy(EnemyCharacter *enemy);
};


#endif //CPPEX1_GAME_H
