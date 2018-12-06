#include "rewarddeck.h"
#include <algorithm>//utilise pour random_shuffle
#include <random>
#include<ctime>


std::vector<Reward*> RewardDeck::deck;
RewardDeck* RewardDeck::rd = nullptr;//Pour le singleton
RewardDeck::RewardDeck() {
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
}
RewardDeck& RewardDeck::make_RewardDeck() {


	if (RewardDeck::rd == nullptr) {
		RewardDeck::rd = new RewardDeck();
		rd->size = deck.size() - 1;
	}
	return *rd;
}

RewardDeck::~RewardDeck() {
	for (auto &i : deck) {
		delete i;
	}
	deck.clear();
}

void RewardDeck::shuffle() {
	if (!deck.empty()) {
		srand(unsigned(time(NULL)));
		std::random_shuffle(deck.begin(), deck.end());//std::random_shuffle is use CHECK!
	}

}

Reward* RewardDeck::getNext() {
	if (isEmpty()) {
		return nullptr;
	}
	else {
		Reward* c = deck[size];
		size--;
		return c;
	}
}

bool RewardDeck::isEmpty() const {
	if (size < 0) {
		return true;
	}
	else {
		return false;
	}
}