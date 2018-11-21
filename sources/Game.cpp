

#include <stdio.h>
#include "Game.h"

std::vector<Player> Game::_player;

std::ostream &operator << (std::ostream &os, const Game &g) {
    
    for (auto i : Game::_player) {
        os << i;
    }
    
    return os;
}

int Game::getRound() {
    return _round;
}

void Game::addPlayer(const Player& player){
    
    _player.push_back(player);

}


Player& Game::getPlayer(Side side){
    return _player.at(side);
}

const Card* Game::getPreviousCard(){
    
    return _previouscard;
}

const Card* Game::getCurrentCard(){
    
    return _currentcard;
}

void Game::setCurrentCard(const Card* c){
    
    _currentcard = c;
}

Game::~Game() {

    _player.clear();
}




