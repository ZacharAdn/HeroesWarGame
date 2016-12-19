//
// Created by zahar on 07/12/16.
//

#ifndef CPPEX1_CONSOLE_H
#define CPPEX1_CONSOLE_H

using namespace std;

#include "unordered_map"
#include "vector"
#include "iostream"

class Character;
class Point2d;
class Item;

class Console {
public:
    Console();

    /**
     *
     * @param matRowSize
     * @param matColSize
     */
    Console(int matRowSize, int matColSize);

    /**
     * fill the data from the Vector and the Map to the Matrix game
     * @param Characters
     * @param Items
     * @param Matrix
     */
    const void fillData(unordered_map<Point2d*,Character*> *Characters, vector<Item*> *Items,char ** Matrix);

    void print();

    virtual ~Console();

private:
    char ** Matrix;
    int rowSize, colSize;

};


#endif //CPPEX1_CONSOLE_H
