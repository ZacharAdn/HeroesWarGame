#include <iostream>
#include "Game.h"

int main(int argc, char* argv[]) {

    if (argc < 1)
        exit(0);
    if (argv[1] == std::string("-help")){
        cout << "-n [number] -files[file1 file2 ...]" << endl;
        exit(0);
    }

    Game *g = nullptr;
    for (int i = 0; i < stod(argv[2]); i++){
         g = new Game(argv[4+i]);
        delete(g);
    }
//
//    delete (g);

    return 0;
}
