//
// Created by mfbut on 3/9/2019.
//

#include <utility>
#include "HumanPlayer.h"
#include "ShipPlacement.h"
#include "Attack.h"


BattleShip::HumanPlayer::HumanPlayer(const BattleShip::GameAttributes &gameAttributes, BattleShip::StandardView &view):Player(gameAttributes, view){
//how to initialize base class?
}

std::unique_ptr<BattleShip::Move> BattleShip::HumanPlayer::getMove() {
    std::pair<int, int> location = view.getFiringCoordinate(*this);
    auto att = std::make_unique<Attack>(*this, location.first, location.second); // not sure if this is right or not
    return att;
    // how to create a unique pointer
}

void BattleShip::HumanPlayer::placeShips() { //how to determine when ships are placed completely maybe by deleting numbers from game attributes map.
    ShipPlacement SP;
    for (const auto& ship: shipHealths){
        do{
            SP = view.getShipPlacement(*this, ship.first, shipHealths[ship.first]);
        }while(!getBoard().canPlaceShipAt(SP));
        //std::cout << ship.first << "mark";
        getBoard().AddShip(ship.first, SP);
                 //leftoeveroo
    }
    view.showPlacementBoard(*this);
}

void BattleShip::HumanPlayer::initializeName() {
    name = view.getPlayerName(id+1);
}