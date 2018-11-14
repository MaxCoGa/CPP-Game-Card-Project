#ifndef REWARD_H
#define REWARD_H

#include <iostream>

class Reward{
private:
	Reward();
public:
	friend std::ostream &operator << (std::ostream &out, const Reward &r);

};

#endif