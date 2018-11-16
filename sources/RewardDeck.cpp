#include "rewarddeck.h"
#include <algorithm>

std::vector<Reward*> RewardDeck::deck;

RewardDeck& RewardDeck::make_RewardDeck() {
	for (int i = 0; i < NUM1RUBIES; ++i) {
		deck.push_back(new Reward(1));
	}
	for (int i = 0; i < NUM2RUBIES; ++i) {
		deck.push_back(new Reward(2));
	}
	for (int i = 0; i < NUM3RUBIES; ++i) {
		deck.push_back(new Reward(3));
	}
	for (int i = 0; i < NUM4RUBIES; ++i) {
		deck.push_back(new Reward(4));
	}
	RewardDeck* rd = new RewardDeck();
	rd->lastCard = deck.size() - 1;
	return *(rd);
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

RewardDeck::~RewardDeck() {
	for (auto &i : deck) {
		delete i;
	}
	deck.clear();
}