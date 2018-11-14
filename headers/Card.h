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
	char face, colour;

	Card(char face_animal, char colour_background);

public:
	string row(int row);
	int getNRows() const { return nRow; }

	void setCharAnimal(FaceAnimal);
	void setCharBackground(FaceBackground);
	
	void print();
};

#endif 