#ifndef GAME_H
#define GAME_H
#include "Test.h"
#include "player.h"
#include "card.h"
#include "board.h"
#include "rewarddeck.h"
#include <exception>
#include <vector>

//exceptions
struct NoSuchPlayer : public std::exception {
	const char * what() const throw () {
		return "NoSuchPlayer exception: no player on the requested side";
	}
};

class Game
{
	const Card *previousCard, *currentCard;
	Board& board;
	int round;
	std::vector<Player*> players;
	RewardDeck& rd;

	friend std::ostream& operator<< (std::ostream& os, const Game& g);
public:
	Game(Board&);
	~Game();
	inline int getRound() const { return round; }
	void addPlayer(const Player&);
	Player& getPlayer(Side) const;
	inline const Card* getPreviousCard() const { return previousCard; }
	inline const Card* getCurrentCard() const { return currentCard; }
	void setCurrentCard(const Card*);
	Card* getCard(const Letter&, const Number&) const;
	void setCard(const Letter&, const Number&, Card*);
	
	void next();//new function
};
#endif
