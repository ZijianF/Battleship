//
// Created by mfbut on 3/9/2019.
//
#include <utility>
#include "Utility.h"
#include "GameAttributes.h"
#include "StandardView.h"

BattleShip::GameAttributes::GameAttributes(){

}

BattleShip::GameAttributes::GameAttributes(int numRows, int numCols) : numRows(numRows), numCols(numCols) {

}

BattleShip::GameAttributes::GameAttributes(std::istream &in) {

}

int BattleShip::GameAttributes::getNumRows() const {
    return numRows;
}

void BattleShip::GameAttributes::setNumRows(int Rows) {
    numRows = Rows;
}

int BattleShip::GameAttributes::getNumCols() const {
    return numCols;
}

void BattleShip::GameAttributes::setNumCols(int Cols) {
    numCols = Cols;
}

int BattleShip::GameAttributes::getShipSize(char ShipChar){ //why const?
    return shipAttributes[ShipChar];
}

const std::map<char, int> &BattleShip::GameAttributes::getShipAttributes() const {
    return shipAttributes;
}

void BattleShip::GameAttributes::addShipAttributes(char letter, int size) {
    shipAttributes[letter] = size;
}
