//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_GAME_H
#define CPPEX1_GAME_H

using namespace std;
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <vector>
#define FULL_HP 100
class Character;
class Point2d;
class Item;
class Hero;
class Enemy;
class EnemyCharacter;
class Sword;
class Console;


class Game {
public:

    /**
     * the main class of the game
     * @param adress
     */
    Game(string address);

    /**
     * read from file the data and fill the data structures
     */
    void read();

    /**
     * update the matrix of the game
     * @param type
     * @param name
     */
    void update(const string &type, const string &name);

    /**
     *
     */
    void play();


    const unordered_map<Point2d*,Character*> &getCharacters() const;
private:
    string address;
    unordered_map<Point2d*,Character*> *Characters;
    vector<Item*> *Items;
    vector<Hero*> *heroes;
    vector<EnemyCharacter*> *enemies;
    vector<Character*> *outputVec;
    char ** Matrix;
    int MatRowSize,MatColSize;

    Console *console;


    /**
     *
     * @param ifstream
     * @return
     */
    double readDoubleFromFile(ifstream &ifstream);

    Point2d* readPoint2DFromFile(ifstream &ifstream);

    int readIntFromFile(ifstream &file);

    void calcHeroTrack(Hero *pHero);

    void scanForItems(Hero *pHero);

    void scanForEnemies(Hero *pHero);

    bool isStillEnemy(EnemyCharacter *enemy);

    void WAR(Hero *hero);

    Point2d *getNextPoint(Hero *pHero);

    bool isInRange(Point2d *checkdLocation, Hero *hero);

    Point2d *checkBounds(Point2d *hero, Hero *pHero);

    void updateMove(Hero *source, Point2d *destination);
};


#endif //CPPEX1_GAME_H
