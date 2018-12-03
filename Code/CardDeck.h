#ifndef CARDDECK_H
#define CARDDECK_H

#include "deck.h"
#include "card.h"
#include <vector>

class CardDeck : public Deck<Card>{
    private:
        static std::vector<Card*> deck;
        int lastCard = -1;
        CardDeck(){};
    public:
        ~CardDeck();
        CardDeck(const CardDeck& cd) = delete;
        CardDeck& operator= (const CardDeck& cd) = delete;

        
        static CardDeck& make_CardDeck();

        virtual void shuffle();
        virtual Card* getNext();
        virtual bool isEmpty() const;
};

#if TEST_CARDDECK
#include <iostream>
static void test_carddeck() {
	std::cout << std::endl << "TEST CARDDECK" << std::endl;
	CardDeck* cd = &CardDeck::make_CardDeck();
	//test unshuffled card deck
	std::cout << "print in order:" << std::endl;
	while (!cd->isEmpty()) {
		Card& c = *(cd->getNext());
		std::cout << c(1) << " ";
	}
	std::cout << std::endl;
	//test nullptr return
	if (cd->getNext() == nullptr) {
		std::cout << std::endl << "nullptr" << std::endl;
	}
	else {
		std::cout << std::endl << "no nullptr in empty deck" << std::endl;
	}
	//test shuffled card deck
	std::cout << std::endl;
	cd->shuffle();
	std::cout << "print in order" << std::endl;
	while (!cd->isEmpty()) {
		Card& c = *(cd->getNext());
		std::cout << c(1) << " ";
	}
	std::cout << std::endl;
	//test nullptr return after shuffle
	if (cd->getNext() == nullptr) {
		std::cout << std::endl << "nullptr" << std::endl;
	}
	else {
		std::cout << std::endl << "empty deck!" << std::endl;
	}
	//attempt to create another card deck and use it
	CardDeck* cd2 = &CardDeck::make_CardDeck();
	//test nullptr return
	std::cout << std::endl << "Not possible to create an another deck" << std::endl;
	std::cout << "return of the same card -> nullptr" << std::endl;
	if (cd2->getNext() == nullptr) {
		std::cout << std::endl << "next card in empty deck -> nullptr" << std::endl;
	}
	else {
		std::cout << std::endl << "try to take card anyway" << std::endl;
	}
}
#endif

#endif