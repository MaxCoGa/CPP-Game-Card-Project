#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "CardDeck.h"


enum Letter { A, B, C, D, E};
enum Number { I, II, III, IV, V };

class Board{
	friend std::ostream& operator<<(std::ostream &os, const Board &b);
    std::string lines[5];
public:
	Board() = default;
	virtual ~Board();
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;

	bool isFaceUp(const Letter&, const Number&) const;
	bool turnFaceUp(const Letter&, const Number&);
	bool turnFaceDown(const Letter&, const Number&);
	void reset();


    //rev2 du projet
	Card* getCard(const Letter&, const Number&) const;
	void setCard(const Letter&, const Number&, Card*);
};


#endif