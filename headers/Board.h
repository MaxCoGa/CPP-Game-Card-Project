#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "CardDeck.h"


enum Letter { A, B, C, D, E};
enum Number { I, II, III, IV, V };
enum CardSide {FACE,BACK='Z'};

class Board{
	friend std::ostream& operator<<(std::ostream &os, const Board &b);

	
    static const int rows = 5, cols = 5;
	std::string matrix[21]; //ecran meme
	Card* cardmatrix[rows][cols]; //les cartes
	CardSide cardSide[rows][cols]; //le cote d'une carte

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