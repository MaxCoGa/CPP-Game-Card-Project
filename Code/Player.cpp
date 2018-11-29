#include "Player.h"

#include <string>
#include <iostream>

Player::Player(std::string name, Side side):
 _name(name), _boardSide(side), _rubies(0), _active(false), _endOfGame(false)
 {}

Player::Player(const Player& p) :
	_name(p._name), _boardSide(p._boardSide),
	_rubies(p._rubies), _active(p._active), _endOfGame(p._endOfGame) {}

Player::~Player()
{}

std::string Player::getName() const{
	return _name;
}


void Player::setActive(bool active){
	_active = active;
}

bool Player::isActive() const{
	return _active;
}

int Player::getNRubies() const{
	return _rubies;
}

void Player::addReward(const Reward& reward){
	_rubies += reward;//besoins de faire un operator int() dans reward.h
}

void Player::setDisplayMode(bool endOfGame){
	_endOfGame = endOfGame;
}

Side Player::getSide() const{
	return _boardSide;
}

//joueur imprimable a l'ecran avec ca
std::ostream & operator<<(std::ostream & os, const Player & m){
	if (!m._endOfGame) {//si faux
		os << m.getName() << " : " << sideArray[m.getSide()] << " " << (m.isActive() ? "active" : "inactive") << std::endl;;
	}
	else {//sinon
		os << m.getName() << " : " << m.getNRubies() << " rubies \n";
	}

	return os;
}


