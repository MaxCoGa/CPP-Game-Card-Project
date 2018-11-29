#include "Board.h"
#include "CardDeck.h"

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

//TODO
std::ostream& operator<<(std::ostream &os, const Board &b) {
	for (auto& i : b.matrix) {
		os << i;
		os << "\n";
	}
	return os;
}

Card* Board::getCard(const Letter&, const Number&) const {
	return 0;
}
void Board::setCard(const Letter&, const Number&, Card*) {

}

