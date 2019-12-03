//
// Created by mfbut on 3/11/2019.
//

#include "RandomAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::RandomAI::RandomAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::StandardView &view)
        : AiPlayer(gameAttributes, view) {

    int row = board.getNumRows();
    int col = board.getNumCols();
    std::pair<int, int> locations;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            locations.first = i;
            locations.second =j;
            firingLocations.push_back(locations);
        }
    }
}

std::unique_ptr<BattleShip::Move> BattleShip::RandomAI::getMove() {
    auto itr = chooseRandom(firingLocations, randomNumberGenerator);
    auto att = std::make_unique<Attack>(*this, (*itr).first, (*itr).second);
    firingLocations.erase(itr);
    return att;
}
