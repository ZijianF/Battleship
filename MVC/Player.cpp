//
// Created by mfbut on 3/9/2019.
//

#include "Player.h"

int BattleShip::Player::num_instances = 0;


BattleShip::Player::Player(const BattleShip::GameAttributes &gameAttributes, BattleShip::StandardView &view): id(num_instances),
shipHealths(gameAttributes.getShipAttributes()),
view(view),
board(gameAttributes.getNumRows(), gameAttributes.getNumCols()){ //how can I initialize board
    ++num_instances;
}

const std::string &BattleShip::Player::getName() const {
    return name;
}

void BattleShip::Player::setName(const std::string &pname) {
    name = pname;
}

const BattleShip::Board &BattleShip::Player::getBoard() const {
    return board;
}

BattleShip::Board &BattleShip::Player::getBoard() {
    return board;
}

const int BattleShip::Player::getId() const {
    return id;
}

bool BattleShip::Player::operator==(const BattleShip::Player &rhs) const {
    return *this == rhs;
}

bool BattleShip::Player::operator!=(const BattleShip::Player &rhs) const {
    return *this != rhs;
}

bool BattleShip::Player::allShipsSunk() const {
    for(const auto& ship : shipHealths){
        if(ship.second != 0){
            return false;
        }
    }
    return true;
}

BattleShip::AttackResult BattleShip::Player::fireAt(int row, int col) { //ship health somehow got set to 0
    Board& oppBoard = opponent->getBoard();
    if(getOpponent().getBoard().at(row, col).containsShip()){
        //std::cout <<getOpponent().getName() << "'shealth1 is "<< getOpponent().shipHealths[getBoard().at(row, col).getContents()];
        int health; //getOpponent().shipHealths[getBoard().at(row, col).getContents()]-=1;
        char shipchar; //getOpponent().getBoard().at(row, col).getContents();
        shipchar = getOpponent().getBoard().at(row, col).getContents();
        health = getOpponent().shipHealths[oppBoard.at(row, col).getContents()]-1;
        getOpponent().shipHealths[oppBoard.at(row, col).getContents()] = health;
       // std::cout <<getOpponent().getName()<< "'shealth2 is "<< getOpponent().shipHealths[getBoard().at(row, col).getContents()];

        getOpponent().getBoard().at(row, col).setContents('X');
        getOpponent().getBoard().at(row, col).setHasBeenFiredAt(false);
        AttackResult result(true, health == 0, shipchar);
        return result;
    }
    //
    // std::cout << getOpponent().shipHealths[getBoard().at(row, col).getContents()] << "health";
    getOpponent().getBoard().at(row, col).setContents('O');
    getOpponent().getBoard().at(row, col).setHasBeenFiredAt(false);
    AttackResult result(false, false, '*');
    return result;
}

BattleShip::Player &BattleShip::Player::getOpponent() {
    return *opponent;
}

const BattleShip::Player &BattleShip::Player::getOpponent() const {
    return *opponent;
}

void BattleShip::Player::setOpponent(BattleShip::Player& itsopponent) {
    opponent = &itsopponent;
}

bool BattleShip::Player::hit(char shipChar) {
    return false;
}



/*bool BattleShip::Player::hit(char shipChar) {
    return false;
}*/
