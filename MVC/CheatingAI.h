//
// Created by mfbut on 3/11/2019.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"

namespace BattleShip {
class CheatingAI  : public AiPlayer{
 public:
  CheatingAI(const GameAttributes& gameAttributes, StandardView& view);
  virtual std::unique_ptr<Move> getMove() override;

    void setOpponent(Player &itsopponent) override;

protected:
    std::vector<std::pair<int, int>> firingLocations;
};
}

#endif //BATTLESHIP_CHEATINGAI_H
