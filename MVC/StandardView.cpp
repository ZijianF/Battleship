//
// Created by mfbut on 3/9/2019.
//

#include <algorithm>
#include <vector>
#include <cctype>
#include "StandardView.h"
#include "Utility.h"

BattleShip::StandardView::StandardView():in(std::cin), out(std::cout){

}

BattleShip::StandardView::StandardView(std::istream &in, std::ostream &out):in(in), out(out) {

}

BattleShip::PlayerConfiguration BattleShip::StandardView::getPlayerConfiguration() {
    int x;
    int human;
    int ai;
    out << "What type of game do you want to play?" <<std::endl;
    out << "1. Human vs Human" <<std::endl;
    out << "2. Human vs AI" <<std::endl;
    out << "3. AI vs AI" <<std::endl;
    out << "Your choice: ";
    in >> x;
    if (x == 1){
        human = 2;
        ai = 0;
    }else if (x == 2){
        human = 1;
        ai = 1;
    }else if (x == 3){
        human = 0;
        ai = 2;
    }
    BattleShip::PlayerConfiguration playerConfiguration(human, ai);
    return playerConfiguration;
}

std::string BattleShip::StandardView::getPlayerName(int i) { //how set id? use changeturn?
    std::string name;
    out << "Player " << i <<" please enter your name: ";
    in >> name;
    return name;
}

ShipPlacement BattleShip::StandardView::getShipPlacement(const BattleShip::Player &player, char shipChar, int shipLen) {
    char direction;
    int row, col;
    ShipPlacement sp;
    showPlacementBoard(player);
    out << player.getName() << ", " << "do you want to place " << shipChar << " horizontally or vertically?\n";
    out << "Enter h for horizontal or v for vertical" << std::endl;
    out << "Your choice: ";
    in >> direction;
    out << player.getName() << ", enter the row and column you want to place " << shipChar << ", which is " << shipLen << " long, at with a space in between row and col: ";
    in >> row;
    in >> col;
    if (direction == 'h'){
         sp.rowStart = row;
         sp.colStart = col;
         sp.rowEnd = row;
         sp.colEnd = col + shipLen-1; // (row, col, row, col + shipLen);
    }else{
        sp.rowStart = row;
        sp.colStart = col;
        sp.rowEnd = row + shipLen-1;
        sp.colEnd = col;
    }
    return sp;
}

void BattleShip::StandardView::updateShipPlacementView(const BattleShip::Player &player) {

}

std::pair<int, int> BattleShip::StandardView::getFiringCoordinate(const BattleShip::Player &attacker) {
    std::pair<int, int> cor;
    int x, y;
    out << attacker.getName() << "'s Firing Board" <<std::endl;
    showPlayersBoard(attacker.getOpponent());
    out << attacker.getName() << "'s Placement Board"<< std::endl;
    showPlacementBoard(attacker);
    out << attacker.getName() << ", where would you like to fire?\n";
    out << "Enter your attack coordinate in the form row col:\n";
    in >> x;
    in >> y;
    cor.first = x;
    cor.second = y;
    return cor;
}

void BattleShip::StandardView::showWinner(const BattleShip::Player &winner) {
    out << winner.getName() << " won the game!";
}

void BattleShip::StandardView::showResultOfAttack(const BattleShip::Player &attacker,
                                                  const BattleShip::AttackResult &attackResult) {
    out << attacker.getName() << "'s Firing Board" << std::endl;
    showPlayersBoard(attacker.getOpponent());
    out << attacker.getName() << "'s Placement Board" << std::endl;
    showPlacementBoard(attacker);
    if(attackResult.hit){
        out << attacker.getName() << " hit " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar << "!" << std::endl;
        if(attackResult.destroyed){
            out << attacker.getName() << " destroyed " << attacker.getOpponent().getName() << "'s " << attackResult.shipChar <<"!" <<std::endl;
        }
    }else if(!attackResult.hit){
        out << "Missed." << std::endl;
    }
}

void BattleShip::StandardView::showPlayersBoard(const BattleShip::Player &player) { //can use opponent's board;
    printBoardAsObscured(player.getBoard());
}

void BattleShip::StandardView::showPlacementBoard(const BattleShip::Player &player) {
    //(player.getBoard().getVisibleVersion());//not right, consider print board
    printBoardAsVisible(player.getBoard());
}

void BattleShip::StandardView::printBoard(const std::vector<std::string> &board) {
    int row = board.size();
    int col = board[0].size();
    out << "  ";
    for (int x = 0; x < row; x++){
        out << x <<' ';
    }
    out << std::endl;
    for (int i  = 0; i <row; i++){
        out << i << ' ';
        for (int j = 0; j < col; j++){

            out << board[i][j] << ' ';
        }
        out << std::endl;
    }
 //   out << std::endl;

}

void BattleShip::StandardView::printBoardAsVisible(const BattleShip::Board &board) {
    printBoard(board.getVisibleVersion());
}

void BattleShip::StandardView::printBoardAsObscured(const BattleShip::Board &board) {
    printBoard(board.getHiddenVersion());
}

int BattleShip::StandardView::getAiChoice() {
    int x;
    out << "What AI do you want?\n";
    out << "1. Cheating AI\n";
    out << "2. Random AI\n";
    out << "3. Hunt Destroy AI\n";
    out << "Your choice:\n";
    in >> x;
    return x;
}

void BattleShip::StandardView::clearInput() {

}
