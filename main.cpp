#include "Controller.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include "Controller.h"
#include "Model.h"
#include "StandardView.h"


int main(int argc, char** argv) {
    BattleShip::Controller cont;
    if (argc == 2){
        cont.setupGame(argv[1]);
    }else if(argc == 3){
        cont.setupGame(argv[1], std::stoi(argv[2]));
    }
    cont.playGame();

    return 0;
}
