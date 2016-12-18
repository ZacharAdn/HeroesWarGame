//
// Created by zahar on 07/12/16.
//

#include <iostream>
#include <algorithm>

#include "Game.h"
#include "../Items/Potion/mana.h"
#include "../Items/Potion/health.h"
#include "../Items/Armor/BodyArmor.h"
#include "../Items/Armor/ShieldArmor.h"
#include "../Items/Weapon/Sword.h"
#include "../Items/Weapon/Hammer.h"
#include "../Items/Weapon/Bow.h"
#include "../Items/Weapon/CrossBow.h"
#include "../Items/Weapon/Staff.h"
#include "../Items/Weapon/Wand.h"
#include "../Characters/Hero/Warrior.h"
#include "../Characters/Hero/Wizard.h"
#include "../Characters/Hero/Archer.h"
#include "../Characters/Enemy/Enemy.h"
#include "../Characters/Enemy/Elite.h"
#include "Console.h"



Game::Game(string adress)
        : adress(adress), heroes(new vector<Hero*>()), enemies(new vector<EnemyCharacter*>()),
          Characters(new unordered_map<Point2d*,Character*>()), Items(new vector<Item*>()),
          outputVec(new vector<Character*>())
{}


void Game::read() {
    ifstream file (adress, ifstream::in);
    string value;
    int heroCounter= 0,enemyCounter=0;

    while (file.good()) {
        double power;
        Hero *hero= nullptr;
        EnemyCharacter *enemy= nullptr;

        getline(file, value, ',');
        std::transform(value.begin(), value.end(), value.begin(), ::tolower);

        //find and fill the  data structure's the Matrix of the game, every Item and Charachter
        if (value.find("matrix") != string::npos) {
            getline(file, value, ',');
            MatRowSize = atoi(value.c_str());
            getline(file, value, ',');
            MatColSize = atoi(value.c_str());

            Matrix = new char *[MatRowSize];
            for (int l = 0; l < MatRowSize; l++) {
                Matrix[l] = new char[MatColSize];
            }

        } else if (value.find("warrior") != string::npos) {
            string name = "Warrior " + to_string(heroCounter++);
            hero = new Warrior(FULL_HP, readDoubleFromFile(file), *readPoint2DFromFile(file), *readPoint2DFromFile(file), name,
                               readIntFromFile(file));
            Characters->emplace(hero->getStartLocation(),hero);
            heroes->push_back(hero);

        } else if (value.find("wizard") != string::npos) {
            string name = "Wizard "+to_string(heroCounter++);
            hero = new Wizard(FULL_HP, readDoubleFromFile(file), *readPoint2DFromFile(file), *readPoint2DFromFile(file), name,
                              readIntFromFile(file));
            Characters->emplace(hero->getStartLocation(),hero);
            heroes->push_back(hero);

        } else if (value.find("archer") != string::npos) {
            string name = "Archer "+to_string(heroCounter++);
            hero = new Archer(FULL_HP, readDoubleFromFile(file), *readPoint2DFromFile(file), *readPoint2DFromFile(file), name,
                              readIntFromFile(file));
            Characters->emplace(hero->getStartLocation(),hero);
            heroes->push_back(hero);

        } else if (value.find("enemy") != string::npos) {
            enemy = new Enemy(FULL_HP, readDoubleFromFile(file), *readPoint2DFromFile(file), *readPoint2DFromFile(file));
            enemy->setName("Enemy"+to_string(enemyCounter++));
            Characters->emplace(enemy->getStartLocation(),enemy);
            enemies->push_back(enemy);

        } else if (value.find("elite") != string::npos) {
            enemy = new Elite(FULL_HP, readDoubleFromFile(file), *readPoint2DFromFile(file), *readPoint2DFromFile(file));
            enemy->setName("Elite Enemy"+to_string(enemyCounter++));
            Characters->emplace(enemy->getStartLocation(),enemy);
            enemies->push_back(enemy);

        } else if (value.find("mana") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new mana(*readPoint2DFromFile(file), power));

        } else if (value.find("health") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new health(*readPoint2DFromFile(file), power));

        } else if (value.find("bodyarmor") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new BodyArmor(*readPoint2DFromFile(file), power));

        } else if (value.find("shieldarmor") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new ShieldArmor(*readPoint2DFromFile(file), power));

        } else if (value.find("sword") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new Sword(*readPoint2DFromFile(file), power));

        } else if (value.find("hammer") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new Hammer(*readPoint2DFromFile(file), power));

        } else if (value.find("bow") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new Bow(*readPoint2DFromFile(file), power));

        } else if (value.find("crossbow") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new CrossBow(*readPoint2DFromFile(file), power));

        } else if (value.find("staff") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new Staff(*readPoint2DFromFile(file), power));

        } else if (value.find("wand") != string::npos) {
            power = readDoubleFromFile(file);
            Items->push_back(new Wand(*readPoint2DFromFile(file), power));

        }
    }
    file.close();

    //send to console to init and print
    console = new Console(MatRowSize, MatColSize);
    console->fillData(Characters, Items,Matrix);
    cout << "start mat:";
    console->print();
    cout << "\n\n";
}

void Game::play() {
    Hero *hero= nullptr;
    Point2d *source,*nextPoint;
    size_t i;

    //calculate the direction and the distance to the destination for every hero
    for (size_t i = 0; i < heroes->size(); ++i) {
        calcHeroTrack(heroes->at(i));
    }

    while(!heroes->empty()) {
        while(i < heroes->size()){
            hero = heroes->at(i);

            if (!hero->isAtWar()) {
                scanForItems(hero);
                scanForEnemies(hero);
            }

            if (hero->isAtWar() && !hero->getEnemyToWar()->isDead()) {
                WAR(hero);
            } else {
                hero->setAtWar(false);
                hero->setEnemyToWar(nullptr);
                source = hero->getStartLocation();

                nextPoint = getNextPoint(hero);
                if (hero->getEndLocation() == nextPoint) {
                    cout << "\n"<< hero->getName() << " get to destination, WIN!";
                    heroes->erase(heroes->begin() + i);
                    outputVec->push_back((Character *&&) hero);//TODO enemys to output vector.
                    i--;
                } else {
                    hero->move(nextPoint);
                    cout << "\n"<<hero->toString();
                    updateMove(hero, source);
                }
            }
            i++;
        }
    }
}


void Game::updateMove(Hero *hero, Point2d *source) {
    unordered_map<Point2d *, Character *>::iterator it;
    Characters->erase(source);
    Characters->emplace(hero->getStartLocation(),hero);
    update("","");
}




void Game::update(const string &type, const string &name) {
    if(type == "Item") {
        for (size_t j = 0; j < Items->size(); ++j) {
            if (Items->at(j)->getName() == name) {
                cout << ", erased " << Items->at(j)->getName();
                Items->erase(Items->begin() + j);
                break;
            }
        }
    }else if(type == "Character"){
        for (auto it = Characters->begin(); it != Characters->end(); ++it) {
            if(it->second->getHp() <= 0){
                Characters->erase(it->first);
            }
        }
    }

    console->fillData(Characters,Items,Matrix);
    console->print();
}


double Game::readDoubleFromFile(ifstream &file) {
    string value;
    getline(file, value, ',');
    return stod(value.c_str());
}


int Game::readIntFromFile(ifstream &file) {
    int i;
    file >> i;
    return i;
}

Point2d* Game::readPoint2DFromFile(ifstream &file) {
    int x,y;
    string value;

    getline(file, value, ',');
    x = atoi(value.c_str());

    getline(file, value, ',');
    y = atoi(value.c_str());

    return new Point2d(x,y);
}

const unordered_map<Point2d*,Character*> &Game::getCharacters() const {
    return *Characters;
}

void Game::calcHeroTrack(Hero *hero) {
    Point2d *location;
    Point2d *destination;
    double distanceX,distanceY;

    location = hero->getStartLocation();
    destination = hero->getEndLocation();

    distanceX = destination->getX() - location->getX();
    if(distanceX > 0){
        hero->setSideX(POSITIVE_SIDE);
    }else{
        hero->setSideX(NEGATIVE_SIDE);
    }
    hero->setDistanceX(abs(distanceX));

    distanceY = destination->getY() - location->getY();
    if(distanceY > 0){
        hero->setSideY(POSITIVE_SIDE);
    }else{
        hero->setSideY(NEGATIVE_SIDE);
    }
    hero->setDistanceY(abs(distanceY));
}

void Game::scanForItems(Hero *hero) {
    size_t i = 0;
    hero->takesNewItem(false);

    while(i < Items->size()){
        if(isInRange(Items->at(i)->getLocation(), hero)){
            Items->at(i)->acceptToUse(hero);//visitor design pattern
            if(hero->isTakeNewItem()){
                if(hero->getThrownArmor() != nullptr){//if the hero takes 2 heanded weapon TODO test
                    hero->getThrownArmor()->setLocation(hero->getStartLocation());
                    Items->push_back(hero->getThrownArmor());
                    hero->throwTheArmor(nullptr);
                }
                i--;
                update("Item", Items->at(i)->getName());
            }
        }
        i++;
    }
}

void Game::scanForEnemies(Hero *hero) {
    for (size_t j = 0; j < enemies->size(); ++j) {
        if(isInRange(enemies->at(j)->getStartLocation(), hero)){//check if enemies in the radius
            hero->setAtWar(true);
            hero->setEnemyToWar(enemies->at(j));
        }
    }
}

bool Game::isInRange(Point2d *checkdLocation, Hero *hero) {
    double radius = hero->getRadius();
    Point2d *heroLocation = hero->getStartLocation();

    return ((abs(checkdLocation->getX() - heroLocation->getX())) <= radius)
           && ((abs(checkdLocation->getY()-heroLocation->getY())) <= radius);
}

void Game::WAR(Hero *hero) {
    EnemyCharacter *enemy = hero->getEnemyToWar();

    hero->attack(enemy);

    if(enemy->getHp() <= 0){
        hero->setAtWar(false);
        hero->setEnemyToWar(nullptr);
        enemy->setDead(true);
        outputVec->push_back((Character *&&) enemy);
        cout << "\nEnemy dead!\n";
        update("Character", "");
    }

    if(!enemy->isDead()){
        enemy->attack(hero);

        if(hero->getHp() <= 0){
            cout << "\n"<< hero->getName()<< "dead!\n";
            update("Character", "");
        }
    }

}

Point2d *Game::getNextPoint(Hero *hero) {
    if(hero->getDistanceX() > 0 && hero->getDistanceY() >0){// go to alachson
        hero->setDistanceX(hero->getDistanceX()-1);
        hero->setDistanceY(hero->getDistanceY()-1);

        if(hero->getSideX()==POSITIVE_SIDE && hero->getSideY()==POSITIVE_SIDE){
            return checkBounds(new Point2d(hero->getStartLocation()->getX() + 1, hero->getStartLocation()->getY() + 1),hero);;
        }else if(hero->getSideX()==NEGATIVE_SIDE && hero->getSideY()==NEGATIVE_SIDE){
            return checkBounds(new Point2d(hero->getStartLocation()->getX()-1,hero->getStartLocation()->getY()-1),hero);;
        }else if(hero->getSideX()==NEGATIVE_SIDE && hero->getSideY()==POSITIVE_SIDE){
            return checkBounds(new Point2d(hero->getStartLocation()->getX()-1,hero->getStartLocation()->getY()+1),hero);
        }else if(hero->getSideX()==POSITIVE_SIDE && hero->getSideY()==NEGATIVE_SIDE){
            return checkBounds(new Point2d(hero->getStartLocation()->getX()+1,hero->getStartLocation()->getY()-1),hero);
        }
    }else if(hero->getDistanceX() == 0 && hero->getDistanceY() >0){
        hero->setDistanceY(hero->getDistanceY()-1);
        if(hero->getSideY() == POSITIVE_SIDE){
            return checkBounds(new Point2d(hero->getStartLocation()->getX(),hero->getStartLocation()->getY()+1),hero);
        }else{
            return checkBounds(new Point2d(hero->getStartLocation()->getX(),hero->getStartLocation()->getY()-1),hero);
        }
    }else if(hero->getDistanceY() == 0 && hero->getDistanceX() >0){
        hero->setDistanceX(hero->getDistanceX()-1);
        if(hero->getSideX() == POSITIVE_SIDE){
            return checkBounds(new Point2d(hero->getStartLocation()->getX()+1,hero->getStartLocation()->getY()),hero);
        }else{
            return checkBounds(new Point2d(hero->getStartLocation()->getX()-1,hero->getStartLocation()->getY()),hero);
        }
    }else if(hero->getDistanceY() == 0 && hero->getDistanceX() == 0){
        cout <<"\nGAME OVER";
        return hero->getEndLocation();
    }
}

Point2d *Game::checkBounds(Point2d *location, Hero *hero) {
    Point2d *currectLocation=location;
    if(location->getX() >= MatColSize){
        currectLocation->setX(MatColSize-1);
    }
    if(location->getY() >= MatRowSize){
        currectLocation->setY(MatRowSize-1);
    }

    return currectLocation;
}

bool Game::isStillEnemy(EnemyCharacter *enemy) {
    return enemy->isDead();
}


