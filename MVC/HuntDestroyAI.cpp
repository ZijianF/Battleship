//
// Created by mfbut on 3/11/2019.
//

#include <algorithm>
#include "HuntDestroyAI.h"
#include "Attack.h"
#include "Utility.h"

BattleShip::HuntDestroyAI::HuntDestroyAI(const BattleShip::GameAttributes &gameAttributes, BattleShip::StandardView &view):RandomAI(gameAttributes, view) {
    int row = board.getNumRows();
    int col = board.getNumCols();
    std::pair<int, int> locations;
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            locations.first = i;
            locations.second =j;
            firingLocations.push_back(locations);
        }
    }
}

std::unique_ptr<BattleShip::Move> BattleShip::HuntDestroyAI::getMove() {
    if(priorityFiringQueue.empty()){
        auto itr = chooseRandom(firingLocations, randomNumberGenerator);
        auto att = std::make_unique<Attack>(*this, (*itr).first, (*itr).second);
        int row = (*itr).first;
        int col = (*itr).second;
        if(getOpponent().getBoard().at(row, col).getContents() != '*'){
            if(getOpponent().getBoard().at(row, col).getContents() != 'X'){
                if(getOpponent().getBoard().at(row, col).getContents() != 'O'){
                    std::pair<int, int> pair(row, col);
                    std::vector<std::pair<int, int>> sur = getSurroundingLocations(pair);
                    for(auto& p : sur){
                        if(contains(p, firingLocations)){
                            priorityFiringQueue.push_back(p);
                            firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), p),firingLocations.end());
                        }
                    }
                }
            }
        }
        firingLocations.erase(itr);
        return att;
    }
    auto att = std::make_unique<Attack>(*this, priorityFiringQueue.front().first, priorityFiringQueue.front().second);
    int row = priorityFiringQueue.front().first;
    int col = priorityFiringQueue.front().second;
    if(getOpponent().getBoard().at(row, col).getContents() != '*'){
        if(getOpponent().getBoard().at(row, col).getContents() != 'X'){
            if(getOpponent().getBoard().at(row, col).getContents() != 'O'){
                std::pair<int, int> pair(row, col);
                std::vector<std::pair<int, int>> sur = getSurroundingLocations(pair);
                for(auto& p : sur){
                    if(contains(p, firingLocations)){
                        priorityFiringQueue.push_back(p);
                        firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), p),firingLocations.end());
                    }
                }
            }
        }
    }
    priorityFiringQueue.erase(priorityFiringQueue.begin());
    return att;
    /*if(priorityFiringQueue.empty()){
        auto itr = chooseRandom(firingLocations, randomNumberGenerator);
        auto att = std::make_unique<Attack>(*this, (*itr).first, (*itr).second);
        if (getOpponent().getBoard().at((*itr).first, (*itr).second).getContents()!='*'){ //means it hits a shipchar
            if(getOpponent().getBoard().at((*itr).first, (*itr).second).getContents()!='X'){
                if(getOpponent().getBoard().at((*itr).first, (*itr).second).getContents()!='O'){
                    std::pair<int, int> p((*itr).first, (*itr).second); //create a pair so getSurroundingLocation can use it
                    for (auto locs : getSurroundingLocations(p)){
                        if(contains(locs, firingLocations)){
                            firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), locs),firingLocations.end());
                            priorityFiringQueue.push_back(locs);
                            return att;
                        }
                    }
                }
            }
        }
        firingLocations.erase(itr);
        return att;
    }
    auto att = std::make_unique<Attack>(*this, priorityFiringQueue.front().first, priorityFiringQueue.front().second);
    std::pair<int, int> temp;
    temp.first = priorityFiringQueue.front().first;
    temp.second = priorityFiringQueue.front().second;
    if (getOpponent().getBoard().at(temp.first, temp.second).getContents()!='*'){ //means it hits a shipchar
        if(getOpponent().getBoard().at(temp.first, temp.second).getContents()!='X'){
            if(getOpponent().getBoard().at(temp.first, temp.second).getContents()!='O'){
                std::pair<int, int> p(temp.first, temp.second); //create a pair so getSurroundingLocation can use it
                for (auto locs : getSurroundingLocations(p)){
                    if(contains(locs, firingLocations)){
                        firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), locs),firingLocations.end());
                        priorityFiringQueue.push_back(locs);
                    }
                }
            }
        }
    }
    if (getOpponent().getBoard().at(temp.first, temp.second).getContents()!='*'){ //means it hits a shipchar
        std::pair<int, int> p(temp.first, temp.second); //create a pair so getSurroundingLocation can use it
        for (auto locs : getSurroundingLocations(p)){
            if(contains(locs, firingLocations)){
                priorityFiringQueue.push_back(locs);
            }else{
                continue;
                }
        }
    }
    //firingLocations.erase(std::find(firingLocations.begin(), firingLocations.end(), temp));
    //firingLocations.erase(std::remove(firingLocations.begin(), firingLocations.end(), temp),firingLocations.end());
    priorityFiringQueue.erase(priorityFiringQueue.begin());
    return att;*/
}

std::vector<std::pair<int, int>>
BattleShip::HuntDestroyAI::getSurroundingLocations(const std::pair<int, int> &center) const {
    std::vector<std::pair<int, int>> sur;
    std::pair<int, int> left(center.first, center.second-1);
    std::pair<int, int> up(center.first-1, center.second);
    std::pair<int, int> right(center.first, center.second+1);
    std::pair<int, int> down(center.first+1, center.second);
    sur.push_back(left);
    sur.push_back(up);
    sur.push_back(right);
    sur.push_back(down);
    return sur;
}
