#include "ExpertRules.h"
bool ExpertRules::isValid(const Game& g) {
	++cardsturned;
	const Card* cc = g.getCurrentCard();
	const Card* pc = g.getPreviousCard();

	if ((pc == nullptr) || ((FaceAnimal)*cc == (FaceAnimal)*pc) || ((FaceBackground)*cc == (FaceBackground)*pc)) {
		if (cc == block) {
			std::cout << "Your card choice was blocked in the previous turn! You have lost this round." << std::endl;
			return false;
		}

		//CRAB
		if ((FaceAnimal)*cc == Crab) {
			std::cout << "Crab:\ncurrent player can play again!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}	
			previousPlayer();

		}

		//PENGUIN
		else if (((FaceAnimal)*cc == Penguin) && (pc != nullptr)) {
			std::cout << "Penguin:\ncurrent player can face down a face up card!\n" << std::endl;

			
		}

		//OCTOPUS
		else if ((FaceAnimal)*cc == Octopus) {
			std::cout << "Octopus:\ncurrent player can swap a card with one of the adjacent one!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}
		}


		//WALRUS
		else if ((FaceAnimal)*cc == Walrus) {
			std::cout << "Walrus:\ncurrent player can choose a card to block for the next turn!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}

			return true;
		}


		//TURTLE
		else if ((FaceAnimal)*cc == Turtle) {
			std::cout << "Turtle:\nnext player get his turn skip!\n" << std::endl;

			if (cardsturned == 24) {
				return true;
			}
			getNextPlayer(g);
			
		}
		block = nullptr;
		return true;
	}
	else {
		block = nullptr;
		return false;
	}
}
