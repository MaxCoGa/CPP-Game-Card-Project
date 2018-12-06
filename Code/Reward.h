/**
 * Projet 4 CSI 2772[A] Robert Laganiere
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef REWARD_H
#define REWARD_H

#include <iostream>

class Reward{
	friend class RewardDeck;
private:
	int _number;
	//Reward(int number);
public:
	Reward(int number);
	//utilise pour RewardDeck
	Reward(const Reward&) = delete;
	Reward& operator=(const Reward&) = delete;
	//SOME TESTING//

	friend std::ostream &operator << (std::ostream &os, const Reward &r);
	operator int()const{//utilise pour add un ruby d'un joueur
		return _number;
	}
};

#if TEST
static void test_reward() {
	std::cout << std::endl << "TEST REWARD"<< std::endl;
	Reward r1(0), r2(2), r3(3);
	std::cout << "Constructor: " << std::endl;
	std::cout << "r1: " << r1 << std::endl;
	std::cout << "r2: " << r2 << std::endl;
	std::cout << "r3: " << r3 << std::endl;
}
#endif


#endif