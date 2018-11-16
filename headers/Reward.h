#ifndef REWARD_H
#define REWARD_H

#include <iostream>

class Reward{
	friend class RewardDeck;
private:
	int _number;
	Reward(int number);
public:
	//Reward(int number);
	
	//utilise pour RewardDeck
	Reward(const Reward&) = delete;
	Reward& operator=(const Reward&) = delete;
	//

	friend std::ostream &operator << (std::ostream &os, const Reward &r);
	operator int()const{//utilise pour add au rubie d'un joueur
		return _number;
	}
};

#endif