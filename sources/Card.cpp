#include <iostream>
#include "card.h"

void Card::setCharAnimal(FaceAnimal a) {
	switch (a) {
	case Crab:ani = 'c';
		break;
	case Penguin: ani = 'p';
		break;
	case Octopus: ani = 'o';
		break;
	case Turtle: ani = 't';
		break;
	case Walrus: ani = 'w';
		break;
	}
}
void Card::setCharBackground(FaceBackground b) {
	switch (b) {
	case Red:back = 'r';
		break;
	case Yellow: back = 'y';
		break;
	case Green: back = 'g';
		break;
	case Blue: back = 'b';
		break;
	case Purple: back = 'p';
		break;
	}
}