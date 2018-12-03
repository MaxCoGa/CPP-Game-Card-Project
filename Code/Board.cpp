#include "Board.h"
#include "CardDeck.h"

Board::Board() {
	reset();
	CardDeck& cd = CardDeck::make_CardDeck();
	if (cd.isEmpty()){
		throw NoMoreCards();
	}
	cd.shuffle();
	int i = 0;
	while (!cd.isEmpty()) {
		cardmatrix[i / 5][i % 5] = cd.getNext();
		++i;
	}
}

Board::~Board() {
	//LIKE THIS IT'S WORKING SO
}


bool Board::isFaceUp(const Letter& l, const Number& n) const {
	if (outOfRange(l, n)) {
		throw OutOfRange();
	}
	if (cardSide[l][n]) {
		return true;
	}
	else {
		return false;
	}
}

bool Board::turnFaceUp(const Letter& l, const Number& n) {
	if (outOfRange(l, n))
		throw OutOfRange();
	drawFaceUp(l, n);
	if (cardSide[l][n])
		return false;
	else {
		cardSide[l][n] = UP;
		return true;
	}
}

bool Board::turnFaceDown(const Letter& l, const Number& n) {
	if (outOfRange(l, n))
		throw OutOfRange();
	drawFaceDown(l, n);
	if (!cardSide[l][n])
		return false;
	else {
		cardSide[l][n] = DOWN;
		return true;
	}
}

//RESET//
void Board::reset() {
	resetFunction();
}

void Board::resetFunction() {
	for (int i = 0; i < 25; ++i) {
		cardSide[i / 5][i % 5] = DOWN;
	}

	for (int boardRows = 0; boardRows < rows; ++boardRows) {
		for (int cardRows = 0; cardRows < 3; ++cardRows) {
			if (cardRows == 1) {
				matrix[boardRows * 4 + cardRows] = 'A' + boardRows;
				matrix[boardRows * 4 + cardRows] += " ";
			}
			else {
				matrix[boardRows * 4 + cardRows] = "  ";
			}
			for (int cardColumns = 1; cardColumns < 20; ++cardColumns) {
				if (cardColumns % 4 == 0 || (boardRows == 2 && cardColumns >= 9 && cardColumns <= 11)) {
					matrix[boardRows * 4 + cardRows] += " ";
				}
				else {
					matrix[boardRows * 4 + cardRows] += "z";
				}
			}
		}
	}
	matrix[20] = "  ";
	for (int column = 1; column < 20; ++column) {
		if (column % 4 == 0) {
			matrix[20] += " ";
		}
		else if (column % 2 == 0) {
			matrix[20] += std::to_string((column + 2) / 4);
		}
		else {
			matrix[20] += " ";
		}
	}



}//RESET//

//TODO
std::ostream& operator<<(std::ostream &os, const Board &b) {
	b.print(os);
	return os;
}
void Board::print(std::ostream &os) const {
	for (auto& i : matrix) {
		os << i;
		os << "\n";
	}
}
//REV 2.0
Card* Board::getCard(const Letter& l, const Number& n) const {
	if (outOfRange(l, n))
		throw OutOfRange();
	else
		return cardmatrix[l][n];
}

void Board::setCard(const Letter& l, const Number& n, Card* c) {
	if (outOfRange(l, n))
		throw OutOfRange();
	cardmatrix[l][n] = c;
}

//CHANGE CARDSIDE
void Board::drawFaceDown(const Letter& l, const Number& n) {
	for (int r = l * 4; r < l * 4 + 3; ++r) {
		matrix[r].replace(n * 4 + 2, 3, "zzz");
	}
}

void Board::drawFaceUp(const Letter& l, const Number& n) {
	for (int r = l * 4; r < l * 4 + 3; ++r) {
		Card* c = cardmatrix[l][n];
		matrix[r].replace(n * 4 + 2, 3, c->operator() (r - l * 4));
	}
}


