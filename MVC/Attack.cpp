//
// Created by mfbut on 3/10/2019.
//

#include "Attack.h"


BattleShip::Attack::Attack(BattleShip::Player &attacker, int row, int col):Move(attacker), row(row), col(col){

}

void BattleShip::Attack::enact(BattleShip::Model &model, BattleShip::StandardView &view) {
    //moveMaker.fireAt(getRow(),getCol());
    view.showResultOfAttack(moveMaker, moveMaker.fireAt(getRow(),getCol())); //might need to check back
}

bool BattleShip::Attack::isValid() const {
    return false;
}

const int BattleShip::Attack::getRow() const {
    return row;
}

const int BattleShip::Attack::getCol() const {
    return col;
}
