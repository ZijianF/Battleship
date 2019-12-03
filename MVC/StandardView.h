//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_STANDARDVIEW_H
#define BATTLESHIP_STANDARDVIEW_H
#include <iostream>
#include <utility>
#include "PlayerConfiguration.h"
#include "View.h"
#include "ShipPlacement.h"
#include "Player.h"
#include "AttackResult.h"
#include "Board.h"
//remember to bring up this question
namespace BattleShip  {
class Player; //forward declaration
class Model;
class Move;
class Board;
class StandardView{
 public:
  StandardView();
  StandardView(std::istream& in, std::ostream& out);
  PlayerConfiguration getPlayerConfiguration();
  std::string getPlayerName(int i);
  ShipPlacement getShipPlacement(const Player& player, char shipChar, int shipLen); //ask for
  void updateShipPlacementView(const Player& player); // display board
  std::pair<int, int> getFiringCoordinate(const BattleShip::Player& attacker);
  void showWinner(const Player& winner);
  void showResultOfAttack(const BattleShip::Player& attacker,
                                    const BattleShip::AttackResult& attackResult);

  void showPlayersBoard(const Player& player);
  void showPlacementBoard(const Player& player);
 protected:
  void printBoard(const std::vector<std::string>& board);
  void printBoardAsVisible(const Board& board);
  void printBoardAsObscured(const Board& board);
 public:
  int getAiChoice();
 protected:

  void clearInput();

  std::istream& in;
  std::ostream& out;
};
}

#endif //BATTLESHIP_STANDARDVIEW_H
