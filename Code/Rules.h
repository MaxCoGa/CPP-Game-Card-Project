#ifndef RULES_H
#define RULES_H

#include <vector>

#include "Game.h"
#include "Player.h"
#include "Card.h"

class Rules
{
private:
	//SIDE
	std::vector<Side> players;
	Side nextPlayer();
	Side previousPlayer();

	//PRIVATE
	int firstplayer;
	int currentplayer;
	int cardsturned = 0; 
public:
	Rules();
	~Rules();//NOT MODIFIED
	bool isValid(const Game& g);
	bool gameOver(const Game& g);
	bool roundOver(const Game& g);
	const Player& getNextPlayer(const Game& g);
};

#endif