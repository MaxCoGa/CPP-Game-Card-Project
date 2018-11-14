#include "Player.h"
#include "Reward.h"

#include <string>
#include <iostream>

Player::Player(string nameIn) {
	name = nameIn;
	boardSide = 'B';
	rubies = 0;
	status = true;
}

Player::Player(string nameIn, int playerNumber) {
	name = nameIn;
	
	if(playerNumber == 1) {
		boardSide = 'B';
	} else if(playerNumber == 2) {
		boardSide = 'T';
	} else if(playerNumber == 3) {
		boardSide = 'L';
	} else {
		boardSide = 'R';
	}
	
	rubies = 0;
	status = true;
}

string Player::getName() const {
	return name;
}
void Player::setActive(bool s) {
	status = s;
}
bool Player::isActive() const{
	return status;
}
int Player::getNRubies() const {
	return rubies;
}
void Player::addReward(const Reward&) {
	rubies = rubies + 10;
}
void Player::setDisplayMode(bool endOfGame) {
	ENDGAME = endOfGame;
}

ostream& operator<<(ostream& out, const Player& p) {
	if(Player::ENDGAME == false) {
		if(p.isActive()){
			out << p.getName()<<": "<<p.boardSide<<" (active)"<<endl;
		} else {
			out << p.getName()<<": "<<p.boardSide<<" (inactive)"<<endl;
		}
	} else {
		out<<p.getName()<<": "<<p.getNRubies()<<" rubies"<<endl;
	}
	
	return out;
}