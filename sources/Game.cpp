

#include "Game.h"
#include "Board.h"

const Card* Game::_previouscard;
const Card* Game::_currentcard;
std::vector<Player> Game::_player;
Board* Game::_b;

std::ostream &operator << (std::ostream &os, const Game &g) {
    
    os << g._b << std::endl;
    
    for (auto i : Game::_player) {
       os  << i;
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
    delete _b;
    delete _previouscard;
    delete _currentcard;
}

