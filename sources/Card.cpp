#include <iostream>
#include "card.h"

Card::Card( char faceIn, char colourIn) {
	face = faceIn;
	colour = colourIn;
}

string Card::row(int rowNum) {
	if(rowNum == 0 || rowNum == 2) {
		return colour<<colour<<colour;
	} else {
		return colour<<face<<colour;
	}
}

void Card::print() {
	for(int row = 0; row<3; ++row) {
		string rowString = c(row);
		cout << rowString << endl;
	}
}