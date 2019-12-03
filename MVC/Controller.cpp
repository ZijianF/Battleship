//
// Created by mfbut on 3/9/2019.
//

#include <stdexcept>
#include <vector>
#include <sstream>
#include <fstream>
#include "PlayerConfiguration.h"
#include "Controller.h"
#include "HumanPlayer.h"
#include "AiPlayer.h"
#include "StandardView.h"
#include "CheatingAI.h"
#include "RandomAI.h"
#include "HuntDestroyAI.h"
#include "memory"
#include "Model.h"

//BattleShip::Controller::Controller(bool hasBeenSetUp, const BattleShip::Model &model,
//                              const std::unique_ptr<BattleShip::View> &view) : hasBeenSetUp(hasBeenSetUp),
//                                                                             model(model), view(nullptr) {}


void BattleShip::Controller::setupGame(const std::string& GameConfigurationFile, int seed) {
    AiPlayer::seed_random_number_generator(seed);
    model.loadGameConfigurationFromFile(GameConfigurationFile);
    setupGame();



}

void BattleShip::Controller::setupGame(const std::string &GameConfigurationFile) {
    model.loadGameConfigurationFromFile(GameConfigurationFile);
    setupGame();
}

void BattleShip::Controller::setupGame() {
    PlayerConfiguration pc = view->getPlayerConfiguration();
    if (pc.numHumanPlayers == 1){
        model.addPlayer<HumanPlayer>(*view);
        int aic = view->getAiChoice();
        if (aic == 1){
            model.addPlayer<CheatingAI>(*view);
        }else if(aic == 2){
            model.addPlayer<RandomAI>(*view);
        }else if(aic == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }
    }else if (pc.numHumanPlayers == 2){
        model.addPlayer<HumanPlayer>(*view);
        model.addPlayer<HumanPlayer>(*view);
    }else if (pc.numHumanPlayers == 0){
        int aic = view->getAiChoice();
        if (aic == 1){
            model.addPlayer<CheatingAI>(*view);
        }else if(aic == 2){
            model.addPlayer<RandomAI>(*view);
        }else if(aic == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }
        aic = view->getAiChoice();
        if (aic == 1){
            model.addPlayer<CheatingAI>(*view);
        }else if(aic == 2){
            model.addPlayer<RandomAI>(*view);
        }else if(aic == 3){
            model.addPlayer<HuntDestroyAI>(*view);
        }
    }
    model.SetOpponents();
    hasBeenSetUp = true;
}

void BattleShip::Controller::playGame() {
    while(!model.isGameOver()){
        auto attack = model.getNextMove();
        attack->enact(model, *view);
        model.changeTurn();
    }
    view->showWinner(model.getWinner());
} // first when miss a shot, shiphealths will be changed and game never ends.
// then when playing in AI mode, the game ends it self automatically, have not checked this yet. //segfault appeared
BattleShip::Controller::Controller():view(std::make_unique<StandardView>(std::cin, std::cout)){

}



