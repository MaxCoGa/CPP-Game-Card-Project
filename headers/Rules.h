#ifndef RULES_H
#define RULES_H

#include <vector>

#include "Game.h"
#include "Player.h"
#include "Card.h"

class Rules
{
protected:
	std::vector<Side> players;
	int firstplayer, currentplayer;
	Side nextPlayer(); 
	Side previousPlayer();
	int cardsturned = 0; 
public:
	Rules();
	virtual ~Rules();
	virtual bool isValid(const Game& g);
	virtual bool gameOver(const Game& g);
	virtual bool roundOver(const Game& g);
	virtual const Player& getNextPlayer(const Game& g);
};

#endif