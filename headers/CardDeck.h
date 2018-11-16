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

#endif