//
// Created by mfbut on 3/10/2019.
//

#include "Board.h"

BattleShip::Board::Board(int numRows, int numCols, char blankChar):boardState(numRows, (std::vector<Cell>(numCols, {blankChar}))), blankChar(blankChar){

}

BattleShip::Board::Board(int numRows, int numCols):boardState(numRows, (std::vector<Cell>(numCols, {'*'}))), blankChar('*') {

}

bool BattleShip::Board::canPlaceShipAt(const ShipPlacement &shipPlacement) const {
    // need to be implemented
    for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd ; ++i) {
        for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd ; ++j) {
            if(at(i,j).containsShip()){
                return false;
            }
        }

    }
    return true;
}

int BattleShip::Board::getNumRows() const {
    return boardState.size();
}

int BattleShip::Board::getNumCols() const {
    return boardState[0].size();
}

std::vector<std::string> BattleShip::Board::getHiddenVersion() const {
    int row = boardState.size();
    int col = boardState[0].size();
    std::vector<std::string> hiddenboard(row, std::string(col, ' '));
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            hiddenboard[i][j] = (boardState[i][j].getContentsIfHidden());
        }
    }
    return hiddenboard;
}

std::vector<std::string> BattleShip::Board::getVisibleVersion() const {
    int row = boardState.size();
    int col = boardState[0].size();
    std::vector<std::string> visibleboard(row, std::string(col, ' ')); // check this part, not exactly sure what two arguments represent
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            visibleboard[i][j] = (boardState[i][j].getContentsIfVisible());
        }
    }
    return visibleboard;
}

void BattleShip::Board::AddShip(char shipChar, const ShipPlacement &shipPlacement) {
    for (int i = shipPlacement.rowStart; i <= shipPlacement.rowEnd ; ++i) {
        for (int j = shipPlacement.colStart; j <= shipPlacement.colEnd ; ++j) {
            at(i,j).setContents(shipChar);
        }

    }
}

bool BattleShip::Board::inBounds(int row, int col) const { //unsigned and signed integer
    if (row < static_cast<int>(boardState.size()) - 1 && row >= 0) {
        if (col < static_cast<int>(boardState[0].size()) - 1 && col >= 0) {
            return true;
        } else {
            return false;
        }
    }else{
        return false;
    }
}

BattleShip::Cell &BattleShip::Board::at(int i, int j) {
    return boardState[i][j];
}

const BattleShip::Cell &BattleShip::Board::at(int i, int j) const {
    return boardState[i][j];
}

bool BattleShip::Board::inBounds(const ShipPlacement &shipPlacement) const {
    if (between(shipPlacement.rowStart, 0, getNumRows()-1) && between(shipPlacement.colStart, 0, getNumCols()-1) &&
    between(shipPlacement.rowEnd, 0, getNumCols()-1) && between(shipPlacement.colEnd, 0, getNumCols()-1)) {
        return true;
    } else{
        return false;
    }
}

bool BattleShip::Board::between(int value, int low, int high) const {
    if(low <= value && value <= high){
        return true;
    }else{
        return false;
    }
}

bool BattleShip::Board::spacesAreEmpty(const ShipPlacement &shipPlacement) const { //only check for empty if is in bound?
    if(shipPlacement.rowStart == shipPlacement.rowEnd){
        for (int i = shipPlacement.colStart; i != shipPlacement.colEnd; i++){
            if(boardState[shipPlacement.rowStart][i].getContents() == '*'){
                continue;
            }else if(boardState[shipPlacement.rowStart][i].getContents() != '*'){
                return false;
            }
        }
    }else if(shipPlacement.colStart == shipPlacement.colEnd ){
        for (int j = shipPlacement.rowStart; j != shipPlacement.rowEnd; j++){
            if(boardState[j][shipPlacement.rowStart].getContents() == '*'){
                continue;
            }else if(boardState[j][shipPlacement.rowStart].getContents() != '*'){
                return false;
            }
        }
    }
    return true;
}
