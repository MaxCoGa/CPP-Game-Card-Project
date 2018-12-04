#include "rewarddeck.h"
#include <algorithm>


std::vector<Reward*> RewardDeck::deck;

RewardDeck& RewardDeck::make_RewardDeck() {

	//3 1 rubies
	for (int i = 0; i < 3; ++i) {
		deck.push_back(new Reward(1));
	}

	//2 2 rubies
	for (int i = 0; i < 2; ++i) {
		deck.push_back(new Reward(2));
	}

	//1 3 rubies
	for (int i = 0; i < 1; ++i) {
		deck.push_back(new Reward(3));
	}

	//1 4 rubies
	for (int i = 0; i < 1; ++i) {
		deck.push_back(new Reward(4));
	}
	RewardDeck* rd = new RewardDeck();
	rd->lastCard = deck.size() - 1;
	return *(rd);
}

RewardDeck::~RewardDeck() {
	for (auto &i : deck) {
		delete i;
	}
	deck.clear();
}

void RewardDeck::shuffle() {
	if (!deck.empty()) std::random_shuffle(deck.begin(), deck.end());
}

Reward* RewardDeck::getNext() {
	if (isEmpty()) {
		return nullptr;
	}
	else {
		Reward* c = deck[lastCard];
		lastCard--;
		return c;
	}
}

bool RewardDeck::isEmpty() const {
	if (lastCard < 0) {
		return true;
	}
	else {
		return false;
	}
}