#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "CardDeck.h"
#include <iostream>


enum Letter { A, B, C, D, E};
enum Number { ONE, TWO, THREE, FOUR, FIVE };
enum CardSide {FACE,BACK='Z'};

class Board{
	

protected:
    static const int rows = 5, cols = 5;
	std::string matrix[21]; //ecran meme
	Card* cardmatrix[rows][cols]; //les cartes
	CardSide cardSide[rows][cols]; //le cote d'une carte

public:
	Board();
	virtual ~Board();
	Board(const Board&) = delete;
	Board& operator=(const Board&) = delete;

	bool isFaceUp(const Letter&, const Number&) const;
	bool turnFaceUp(const Letter&, const Number&);
	bool turnFaceDown(const Letter&, const Number&);
	void reset();

	friend std::ostream& operator<<(std::ostream &os, const Board &b);


    //rev2 du projet
	Card* getCard(const Letter&, const Number&) const;
	void setCard(const Letter&, const Number&, Card*);
};


#endif