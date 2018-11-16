#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

enum FaceAnimal { Crab, Penguin, Octopus, Walrus, Turtle };
enum FaceBackground { Red, Green, Purple, Blue, Yellow };

class Card {
	friend class Deck;
private:
	FaceAnimal _animal;
	FaceBackground _background;
	//int nRow = 3;
	//char face, colour;

	Card(FaceAnimal animal, FaceBackground background):
		_animal(animal), _background(background)
		{}//constructeur privee

public:
	//string row(int row);
	//int getNRows() const { return nRow; }

	void getAnimal(FaceAnimal) const;//inline au lieu de void?
	void getBackground(FaceBackground) const;//inline au lieu de void?
	
	//CardDeck en a besoins
	Card(const Card& c) = delete; //ne peut pas être copié 
	Card& operator= (const Card& c) = delete; //ni assigné
	//

	~Card() {}//destructeur

	inline int getNRows() const { //trois rangee
		return 3;	
	}

	string operator() (const int row) const;


	operator FaceAnimal() const { 
		return _animal;
	}

	operator FaceBackground() const { 
		return _background; 
	}

	//void print();
};

#endif 