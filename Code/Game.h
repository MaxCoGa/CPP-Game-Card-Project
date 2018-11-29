#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Card.h"
#include "Board.h"
#include "RewardDeck.h"

class Game {
private:
    int _round; //le nombre de tours
    
    //Side _side; //le coter assigner au player
	std::vector<Player*> _player; //vector contenant les player
    
    const Card* _previouscard;
    const Card* _currentcard;
    
    Board& _b;
	RewardDeck& _r;
	//friend std::ostream& operator<<(std::ostream &os, const Game &g);
public:
    //Game() : _round(0){};
	Game(Board& b);
    //~Game(); //destructeur
    
    
    int getRound() const; // returns a number between 0 and 6 corresponding to the current round of the game
    void addPlayer(const Player& ); // adds a Player to this game.
    Player& getPlayer(Side) const; // retourne le player en fonction de son side
    const Card* getPreviousCard();
    const Card* getCurrentCard();
    void setCurrentCard( const Card*);
    Game& getGame(){return *this;}

	friend std::ostream& operator<<(std::ostream &os, const Game &g);
    
    
	//rev 2.0
	//USE ENUM LETTER AND NUMBER FROM BOARD
    Card* getCard(const Letter&, const Number&);
    void setCard( const Letter&, const Number&, Card* );
    
};

#endif
