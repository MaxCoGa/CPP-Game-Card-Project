#ifndef REWARDDECK_H
#define REWARDDECK_H


#include "reward.h"
#include "deck.h"
#include <vector>
#include <iterator>
#include <iostream>

class RewardDeck : public Deck<Reward>{//meme structure que CardDeck juste avec les noms Reward au lieu de Card
    private:
        static std::vector<Reward*> deck;
	    int lastCard = -1;


		RewardDeck() {};

    public:
		~RewardDeck();
        RewardDeck(const RewardDeck&) = delete;
        RewardDeck& operator=(const RewardDeck&) = delete;


        static RewardDeck& make_RewardDeck();
        virtual void shuffle();
        virtual Reward* getNext();
        virtual bool isEmpty() const;
};
#if TEST_REWARDDECK
#include <iostream>
using std::cout;//REMOVE
using std::endl;
static void test_rewarddeck() {
	std::cout << std::endl << "TEST REWARDDECK" << std::endl;
	RewardDeck *rd = &RewardDeck::make_RewardDeck();
	cout << "Print rewards" << endl;
	while (!rd->isEmpty()) {
		Reward* r = rd->getNext();
		cout << r->operator int() << ", ";
	}
	cout << endl << endl;
	cout << "Check if deck is empty." << endl;
	if (rd->getNext() == nullptr) {
		cout << "Null pointer returned. Deck is empty.";
	}
	else {
		cout << "Null pointer NOT returned. Error is deck size.";
	}
	cout << endl << endl;
	cout << "Shuffle deck check." << endl;
	cout << "Original:" << endl;
	while (!rd->isEmpty()) {
		Reward* r = rd->getNext();
		cout << r->operator int() << ", ";
	}
	cout << endl;
	rd->shuffle();
	cout << "Shuffle test:" << endl;
	while (!rd->isEmpty()) {
		Reward* r = rd->getNext();
		cout << r->operator int() << ", ";
	}

}
#endif
#endif