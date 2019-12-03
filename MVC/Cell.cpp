//
// Created by mfbut on 3/10/2019.
//

#include <stdexcept>
#include "Cell.h"

BattleShip::Cell::Cell(char contents, const char hiddenMarker, const char hitMarker, const char missMarker):contents(contents),firedAt(false), hiddenMarker(hiddenMarker), hitMarker(hitMarker), missMarker(missMarker) {

}

BattleShip::Cell::Cell(char contents):contents(contents),firedAt(false), hiddenMarker('*'), hitMarker('X'), missMarker('O') {

}

char BattleShip::Cell::getContents() const {
    return contents;
}

void BattleShip::Cell::setContents(char shipchar) {
    contents = shipchar;
}

char BattleShip::Cell::getContentsIfHidden() const {
    if(HasBeenFiredAt()){
        return getContents();
    }
    return hiddenMarker;

}

char BattleShip::Cell::getContentsIfVisible() const {
    return getContents();
}

bool BattleShip::Cell::HasBeenFiredAt() const {
    return firedAt;
}

void BattleShip::Cell::setHasBeenFiredAt(bool hasBeenFiredAt) {
    if (!hasBeenFiredAt){
        firedAt = true;
    }
}

bool BattleShip::Cell::containsShip() const {
    if(getContents() == '*'){
        return false;
    }
    return true;
}
