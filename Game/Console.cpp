//
// Created by zahar on 07/12/16.
//
#include <fstream>
#include "Console.h"
#include "Point2d.h"
#include "../Characters/Character.h"

Console::Console() {}


Console::Console(int matRowSize,int matColSize)
        : rowSize(matRowSize), colSize(matColSize){}

Console::~Console() {

}


const void Console::fillData(unordered_map<Point2d*,Character*> *Characters, vector<Item*> *Items,char ** Matrix) {
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

void Console::printToFile(string address,vector<Character*> *outputVec) {

    size_t index = address.find("_");
    string newAdress= address.substr(0,index) + "_out.csv";
    ofstream file (newAdress, ofstream::out);

    cout << "\n\n" << newAdress;



    file << "\n";
    for (int i = 0; i < rowSize; ++i) {
        file << "\n";
        for (int j = 0; j < colSize; ++j) {
            file <<  Matrix[i][j];
            file << "\t";
        }
    }
    file << "\n";

    for (int k = 0; k < outputVec->size(); ++k) {
        file << "\n"<<outputVec->at(k)->getTypeName() << ": Point:" << outputVec->at(k)->getStartLocation()->toString() <<
             ", Health:" << to_string(outputVec->at(k)->getHp()) <<", Power:" << to_string(outputVec->at(k)->getXp());
    }


    file.close();
}

