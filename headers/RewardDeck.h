#ifndef REWARDDECK_H
#define REWARDDECK_H

class RewardDeck : public Deck<Reward>{//meme structure que CardDeck juste avec les noms Reward au lieu de Card
    private:
        static vector<Reward*> deck;
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