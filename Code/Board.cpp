#include "Board.h"

Board::~Board() {

}

bool Board::isFaceUp(const Letter&, const Number&) const {
    return true;
}

bool Board::turnFaceUp(const Letter&, const Number&) {
    return true;
}

bool Board::turnFaceDown(const Letter&, const Number&) {
    return true;
}

void Board::reset() {

}

