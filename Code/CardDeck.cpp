#include "carddeck.h"

#include <algorithm>//utilise pour random_shuffle

std::vector<Card*> CardDeck::deck;

CardDeck& CardDeck::make_CardDeck() {//make factory 
	CardDeck* cd = new CardDeck();
	for (auto colour : { Card::FaceBackground::Blue, Card::FaceBackground::Green, Card::FaceBackground::Purple, Card::FaceBackground::Red, Card::FaceBackground::Yellow }) {
		for (auto animal : { Card::FaceAnimal::Crab, Card::FaceAnimal::Octopus, Card::FaceAnimal::Penguin, Card::FaceAnimal::Turtle, Card::FaceAnimal::Walrus }) {
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