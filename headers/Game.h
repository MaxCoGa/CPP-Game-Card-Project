
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

class Game {
private:
    
    
    int _round; //le nombre de tours
    
    Side _side; //le coter assigner au player
     std::vector<Player> _player; //vector contenant les player
    
     const Card* _previouscard;
     const Card* _currentcard;
    
     Board* _b;
    
    
public:
    Game() : _round(0){};
    ~Game(); //destructeur
    
    friend std::ostream& operator<<(std::ostream &os, const Game &g);
    int getRound(); // returns a number between 0 and 6 corresponding to the current round of the game
    void addPlayer(const Player& ); // adds a Player to this game.
    Player& getPlayer(Side); // retourne le player en fonction de son side
    const Card* getPreviousCard();
    const Card* getCurrentCard();
    void setCurrentCard( const Card*);
    Game& getGame(){return *this;}
    
    
    Card* getCard(const Letter&, const Number&);
    void setCard( const Letter&, const Number&, Card* );
    
};

#endif /* Game_h */
