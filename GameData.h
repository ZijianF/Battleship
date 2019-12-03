//
// Created by truma on 3/17/2019.
//

#ifndef BATTLESHIP_GAMEDATA_H
#define BATTLESHIP_GAMEDATA_H

#include "istream"
#include "map"
namespace Battleship{
    class GameData {
    public:

    protected:
        int numRows, numCols;
        std::map<char, int> ships;
    };
}



#endif //BATTLESHIP_GAMEDATA_H
