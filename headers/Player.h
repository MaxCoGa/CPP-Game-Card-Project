
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Reward.h"
using namespace std;

class Reward;

class Player {
	private:
		string name;
		char boardSide;
		int rubies;
		bool status;
		static bool ENDGAME;
	public:
		Player(string nameIn);
		Player(string nameIn, int playerNumber);


		string getName() const;
		void setActive(bool s);
		bool isActive() const;
		int getNRubies() const;
		void addReward(const Reward&);
		void setDisplayMode(bool endOfGame);

		
		friend ostream& operator<<(ostream&, const Player&);
};


#endif 