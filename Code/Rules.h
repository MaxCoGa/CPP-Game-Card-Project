#ifndef RULES_H
#define RULES_H

#include <vector>

#include "Game.h"
#include "Player.h"
#include "Card.h"

class Rules
{
private:
	std::vector<Side> players;
	int firstplayer;
	int currentplayer;
	int cardsturned = 0; 
public:
	Rules();
	~Rules();
	bool isValid(const Game& g);
	bool gameOver(const Game& g);
	bool roundOver(const Game& g);
	const Player& getNextPlayer(const Game& g);
};

#endif