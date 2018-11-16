#ifndef REWARDDECK_H
#define REWARDDECK_H

#define NUM1RUBIES (4)
#define NUM2RUBIES (3)
#define NUM3RUBIES (2)
#define NUM4RUBIES (1)

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

#endif