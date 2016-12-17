//
// Created by zahar on 07/12/16.
//

//#ifndef CPPEX1_CONSOLE_H
//#define CPPEX1_CONSOLE_H

#include "unordered_map"
#include "vector"
#include "iostream"

class Character;
class Point2d;
class Item;


using namespace std;

class Console {
private:
    unordered_map<Point2d*,Character*> *Characters;
    vector<Item*> *Items;
    char ** Matrix;
    int rowSize, colSize;
public:
    Console();

    Console(int rowSize, int colSize);

    const void fillData(unordered_map<Point2d*,Character*> *Characters, vector<Item*> *Items,char ** Matrix);

    void print();

    virtual ~Console();

};


//#endif //CPPEX1_CONSOLE_H
