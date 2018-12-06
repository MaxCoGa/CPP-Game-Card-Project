#include "carddeck.h"
#include <algorithm>//utilise pour random_shuffle
#include <random>
#include<ctime>
std::vector<Card*> CardDeck::deck;
CardDeck* CardDeck::cd = nullptr;//Pour le singleton

CardDeck::CardDeck(){
	for (auto colour : { FaceBackground::Blue, FaceBackground::Green, FaceBackground::Purple, FaceBackground::Red, FaceBackground::Yellow }) {
		for (auto animal : { FaceAnimal::Crab, FaceAnimal::Octopus, FaceAnimal::Penguin, FaceAnimal::Turtle, FaceAnimal::Walrus }) {
			deck.push_back(new Card(animal, colour));

		}
	}
}

CardDeck& CardDeck::make_CardDeck() {//make factory 

	if (CardDeck::cd == nullptr) {
		CardDeck::cd = new CardDeck();		
		cd->size = deck.size() - 1;
	} 
	return *cd;



}

CardDeck::~CardDeck() {
	//delete cd;
	for (auto &i : deck) {
		delete i;
	}
	deck.clear();
}

void CardDeck::shuffle() {//shuffle finish
	srand(unsigned(time(NULL)));
	std::random_shuffle(deck.begin(), deck.end());//std::random_shuffle is use CHECK!
	
}



Card* CardDeck::getNext() {
	//si le deck(card/reward) est vide -> nullptr, sinon en 
	if (isEmpty()) {
		return nullptr;
	}
	else {
		Card* c = deck[size];
		size--;
		return c;
	}
}




bool CardDeck::isEmpty() const {
	if (size < 0) {
		return true;
	}
	else {
		return false;
	}
}
