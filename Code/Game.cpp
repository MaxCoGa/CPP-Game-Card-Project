

#include "Game.h"
#include "Board.h"

//const Card* Game::_previouscard;
//const Card* Game::_currentcard;
//std::vector<Player> Game::_player;
//Board* Game::_b;
Game::Game(Board& b) : _r(RewardDeck::make_RewardDeck()), _b(b) {
	_r.shuffle();
}

std::ostream& operator <<(std::ostream &os, const Game &g) {
	os << g._b << std::endl;
	return os;
}


int Game::getRound() const {
    return _round;
}

void Game::addPlayer(const Player& player){
    //TODO
    //player.push_back(new Player(player));

}


Player& Game::getPlayer(Side side) const{
	//TODO
	return *_player[side];//need vector ptr
}

const Card* Game::getPreviousCard(){
    
    return _previouscard;
}

const Card* Game::getCurrentCard(){
    
    return _currentcard;
}

void Game::setCurrentCard(const Card* c){
	_previouscard = _currentcard;
    _currentcard = c;
}


//REV 2.0
//MAY WORK IDK SO TOCHECK
Card* Game::getCard(const Letter& letter, const Number& number) {
	return _b.getCard(letter, number);
}

void Game::setCard(const Letter& letter, const Number& number, Card* card) {
	_b.setCard(letter, number, card);
}
