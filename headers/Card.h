#ifndef CARD_H
#define CARD_H
#include <string>

enum FaceAnimal { Crab='C', Penguin='P', Octopus='O', Walrus='W', Turtle='T' };
enum FaceBackground { Red='R', Green='G', Purple='P', Blue='B', Yellow='Y' };

class Card {
	friend class CardDeck;
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
	/*Card(FaceAnimal animal, FaceBackground background):
		_animal(animal), _background(background)
		{}*/
		
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

	std::string operator() (const int row) const;


	operator FaceAnimal() const { 
		return _animal;
	}

	operator FaceBackground() const { 
		return _background; 
	}

	//void print();
};

#endif 

/*
Card c(Penguin, Red);
	for (int i = 0; i < c.getNRows(); ++i) {
		std::cout << c(i) << std::endl;
	}
	*/