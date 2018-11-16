#include "carddeck.h"

#include <algorithm>//utilise pour random_shuffle

std::vector<Card*> CardDeck::deck;

CardDeck& CardDeck::make_CardDeck() {
	CardDeck* cd = new CardDeck();
	//5 animals, 5 colours
	for (auto colour : { FaceBackground::Blue, FaceBackground::Green, FaceBackground::Purple, FaceBackground::Red, FaceBackground::Yellow }) {
		for (auto animal : { FaceAnimal::Crab, FaceAnimal::Octopus, FaceAnimal::Penguin, FaceAnimal::Turtle, FaceAnimal::Walrus }) {
			deck.push_back(new Card(animal, colour));
		}
	}
	cd->lastCard = deck.size() - 1;
	return *cd;
}


void CardDeck::shuffle() {
	if (!deck.empty()) std::random_shuffle(deck.begin(), deck.end());
}



Card* CardDeck::getNext() {
	if (isEmpty()) {
		return nullptr;
	}
	else {
		Card* c = deck[lastCard];
		lastCard--;
		return c;
	}
}




bool CardDeck::isEmpty() const {
	if (lastCard < 0) {
		return true;
	}
	else {
		return false;
	}
}

CardDeck::~CardDeck() {
	for (auto &i : deck) {
		delete i;
	}
	deck.clear();
}