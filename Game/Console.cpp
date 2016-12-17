//
// Created by zahar on 07/12/16.
//
#include "Console.h"
#include "Point2d.h"
#include "../Characters/Character.h"
#include "../Items/Item.h"


Console::Console() {}


Console::Console(int rowSize,int colSize)
        : rowSize(rowSize), colSize(colSize){}

Console::~Console() {

}


const void Console::fillData(unordered_map<Point2d*,Character*> *Characters, vector<Item*> *Items,char ** Matrix) {
    Console::Characters =Characters;
    Console::Items = Items;
    Console::Matrix=Matrix;

    Point2d *location;
    Item *item;
    char charToPrint;

    for (int i = 0; i < rowSize; ++i) {
        for (int j = 0; j < colSize; ++j) {
            Matrix[i][j]='.';
        }
    }

    for (auto it = Characters->begin(); it != Characters->end(); ++it) {
        charToPrint=it->second->getcharToPrint();
        location = it->first;
        Matrix[location->getX()][location->getY()] = charToPrint;
    }

    for (int k = 0; k < Items->size(); ++k) {
        item  = Items->at(k);
        location = item->getLocation();
        charToPrint = item->getcharToPrint();
        Matrix[location->getX()][location->getY()]= charToPrint;
    }


}

void Console::print() {
    cout << "\n";
    for (int i = 0; i < rowSize; ++i) {
        cout << "\n";
        for (int j = 0; j < colSize; ++j) {
            cout <<  Matrix[i][j];
            cout << "\t";
        }
    }
    cout << "\n";
}
