#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

#include "Player.h"
#include "Card.h"
#include "Board.h"

#ifndef Game_h
#define Game_h



class Game {
private:
    
    friend std::ostream& operator<<(std::ostream &os, const Game &g);
    int _round; //le nombre de tours
    Side _side; //le coter assigner au player
    static std::vector<Player> _player; //vector contenant les player
    const Card* _previouscard;
    const Card* _currentcard;
    
    
public:
     ~Game(); //destructeur
    
    int getRound(); // returns a number between 0 and 6 corresponding to the current round of the game
    void addPlayer(const Player& ); // adds a Player to this game.
    Player& getPlayer(Side); // retourne le player en fonction de son side
    const Card* getPreviousCard();
    const Card* getCurrentCard();
    void setCurrentCard( const Card*);
    
    
    Card* getCard(const Letter&, const Number&);
    void setCard( const Letter&, const Number&, Card* );
    
};
#endif /* Game_h */
