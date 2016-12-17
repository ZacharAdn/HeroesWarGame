#include <iostream>
#include "Game.h"

#include <fstream>

int main() {


//    unordered_map<Point2d*,Character*> *map = new unordered_map<Point2d*,Character*>;
    vector<Item*> *vec = new vector<Item*> ();
    char** mat = nullptr ;

    string adr= "/home/zahar/ClionProjects/cppEx1/input/input2.csv";

    Game *g = new Game();//,mat);

    g->read(adr);
//    g->update();
    g->play();


    return 0;
}
