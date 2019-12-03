//
// Created by mfbut on 3/9/2019.
//

#include <fstream>
#include <algorithm>
#include "Model.h"
namespace BattleShip{
    Model::Model():playerTurn(0), forcedGameOver(false) {}

    Player &Model::getAttackingPlayer() {
        if(playerTurn == 0){
            return *(players.front());
        }else{
            return *(players.back());
        }
    }

    const Player &Model::getAttackingPlayer() const {
        if(playerTurn == 0){
            return *(players.front());
        }else{
            return *(players.back());
        }
    }

    Player &Model::getDefendingPlayer() {
       return getAttackingPlayer().getOpponent();
    }

    const Player &Model::getDefendingPlayer() const {
        return getAttackingPlayer().getOpponent();
    }

    bool Model::isGameOver() const {
        for(auto& pl :players){
            if (pl->allShipsSunk()){
                return true;
            }
        }
        return false;
    }

    void Model::changeTurn() {
        if (playerTurn == 0){
            playerTurn = 1;
        } else{
            playerTurn = 0;
        }
    }

    void Model::loadGameConfigurationFromFile(const std::string &gameConfigurationFile) {
        int x;
        char y;
        int z;
        std::ifstream myfile;
        myfile.open(gameConfigurationFile);
        myfile >> x;
        gameAttributes.setNumRows(x);
        myfile >> x;
        gameAttributes.setNumCols(x);
        myfile >> z;
        for( int i = 0; i < z; i++){
            myfile >> y;
            myfile >> x;
            gameAttributes.addShipAttributes(y, x);
        }
    }



    void Model::endGame() {

    }

    std::unique_ptr<Move> Model::getNextMove() {
        return getAttackingPlayer().getMove();
    }

    Player &Model::getWinner() {
        return getDefendingPlayer();
    }

    void Model::SetOpponents() {
        players.front()->setOpponent(*(players.back()));
        players.back()->setOpponent(*(players.front()));

    }
}
