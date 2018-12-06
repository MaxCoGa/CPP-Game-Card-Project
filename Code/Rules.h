/**
 * Projet 4 CSI 2772[A] Robert Laganiere
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef RULES_H
#define RULES_H

#include <vector>

#include "Game.h"
#include "Player.h"
#include "Card.h"

class Rules
{
private:
protected://need for the implement of expertrules
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
	~Rules() {};//should work 
	bool isValid(const Game& g);
	bool gameOver(const Game& g);
	bool roundOver(const Game& g);
	const Player& getNextPlayer(const Game& g);
};

#endif