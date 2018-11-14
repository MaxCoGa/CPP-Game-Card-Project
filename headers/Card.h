#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

enum FaceAnimal { Crab, Penguin, Octopus, Walrus, Turtle };
enum FaceBackground { Red, Green, Purple, Blue, Yellow };

class Card {
private:
	FaceAnimal animal;
	FaceBackground background;
	int nRow = 3;
	char ani, back;
	string cardView[3];
	Card(FaceAnimal a, FaceBackground b) : animal(a), background(b) {
		setCharAnimal(a);
		setCharBackground(b);
		for (int i = 0; i < nRow; i++) {
			if (i == 1) {
				cardView[i] = back + ani + back;
			}
			else
			{
				cardView[i] = back + back + back;
			}
		}
	}

public:
	int getNRows() const { return nRow; }
	void setCharAnimal(FaceAnimal);
	void setCharBackground(FaceBackground);
};

#endif 