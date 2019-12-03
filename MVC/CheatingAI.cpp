//
// Created by mfbut on 3/11/2019.
//
#include <stdexcept>
#include "CheatingAI.h"
#include "Attack.h"

BattleShip::CheatingAI::CheatingAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::StandardView &view):AiPlayer(gameAttributes, view) {

}

std::unique_ptr<BattleShip::Move> BattleShip::CheatingAI::getMove() {
    auto att = std::make_unique<Attack>(*this, firingLocations.front().first, firingLocations.front().second);
    firingLocations.erase(firingLocations.begin());
    return att;
}

void BattleShip::CheatingAI::setOpponent(BattleShip::Player &itsopponent) {
    Player::setOpponent(itsopponent);
    Board& board = getOpponent().getBoard();
    int row = board.getNumRows();
    int col = board.getNumCols();
    std::pair<int, int> locations;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            if(board.at(i, j).getContents() != '*'){
                locations.first = i;
                locations.second =j;
                firingLocations.push_back(locations);
            }else{
                continue;
            }
        }
    }
}
