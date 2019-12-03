//
// Created by mfbut on 3/10/2019.
//

#include "EndGame.h"

BattleShip::EndGame::EndGame(BattleShip::Player &moveMaker) : Move(moveMaker) {

}

void BattleShip::EndGame::enact(BattleShip::Model &model, BattleShip::StandardView &view) {

}

bool BattleShip::EndGame::isValid() const {
    return false;
}
