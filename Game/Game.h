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
#define FULL_HP 100// full health power
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
     * @param adress of the input file
     */
    Game(string address);

    virtual ~Game();

    /**
     * read from file the data and fill the data structures
     *
     */
    void read();

    /**
     * update the matrix of the game
     * @param type
     * @param name
     */
    void update(const string &type, const string &name);

    /**
     *the main loop of the game, run all the heroe's to progress on their way
     */
    void play();


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
     * @return power field
     */
    double readDoubleFromFile(ifstream &ifstream);


    /**
     *
     * @param ifstream
     * @return location field
     */
    Point2d* readPoint2DFromFile(ifstream &ifstream);

    /**
     *
     * @param file
     * @return gender field
     */
    int readIntFromFile(ifstream &file);

    /**
     * calculate the direction and the distance to the destination
     * @param pHero
     */
    void calcHeroTrack(Hero *pHero);

    /**
     * scan for items in hero radius
     * @param pHero
     */
    void scanForItems(Hero *pHero);

    /**
     * scan for enemies in hero radius
     * @param pHero
     */
    void scanForEnemies(Hero *pHero);

    bool isStillEnemy(EnemyCharacter *enemy);

    /**
     * the fight between the hero and the enemy in hes radius
     * @param hero
     */
    void WAR(Hero *hero);

    /**
     * check the best way to move progress
     * @param pHero
     * @return destination point
     */
    Point2d *getNextPoint(Hero *pHero);

    /**
     * check if item/charachter in the radius range
     * @param checkdLocation
     * @param hero
     * @return
     */
    bool isInRange(Point2d *checkdLocation, Hero *hero);


    /**
     * check if the hero moves out of the matrix bounds
     * @param location
     * @param hero
     * @return the correct point
     */
    Point2d *checkBounds(Point2d *hero, Hero *pHero);

    /**
     * call the update for move
     * @param source
     * @param destination
     */
    void updateMove(Hero *source, Point2d *destination);

};


#endif //CPPEX1_GAME_H
