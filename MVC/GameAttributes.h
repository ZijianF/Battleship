//
// Created by mfbut on 3/9/2019.
//

#ifndef BATTLESHIP_GAMEATTRIBUTES_H
#define BATTLESHIP_GAMEATTRIBUTES_H
#include <istream>
#include <map>
namespace BattleShip {
    class GameAttributes {
    public:
        GameAttributes();
        GameAttributes(int numRows, int numCols);
        GameAttributes(std::istream& in);

        int getNumRows() const;
        void setNumRows(int Rows);
        int getNumCols() const;
        void setNumCols(int Cols);

        int getShipSize(char ShipChar);
        const std::map<char, int>& getShipAttributes() const;
        void addShipAttributes(char letter, int size);

    private:
        int numRows, numCols;
        std::map<char, int> shipAttributes;
    };

    std::istream& operator>>(std::istream& in, GameAttributes& gameAttributes);

}
#endif //BATTLESHIP_GAMEATTRIBUTES_H
