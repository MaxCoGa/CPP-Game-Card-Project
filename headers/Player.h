
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Reward.h"
using namespace std;



class Player {
	string name;
	string side;
	int nRubies;
	bool activeStatus, displayMode;

public:
	Player() :name("no name"), nRubies(0), side("up"), activeStatus(false) {}
	Player(string name, string side) : name{ name }, side{ side }, nRubies{ 0 }, activeStatus{ false }, displayMode{ false } {}


	string getName() {
		return name;
	}
	void setActive(bool status) {
		activeStatus = status;
	}
	bool isActive() { return activeStatus; }
	int getNRubies() { return nRubies; }
	void addReward(const Reward& aReward) {}	//TO DO //countNRubies += aReward.count;

	void setDisplayMode(bool endOfGame) {
		displayMode = endOfGame;
	}

	friend ostream& operator<<(ostream& os, const Player& dt);
};


#endif 