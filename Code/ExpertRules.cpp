#include "ExpertRules.h"
bool ExpertRules::isValid(const Game& g) {
	return false;
}

void ExpertRules::crab() {
	std::cout << "Crab:\ncurrent player can play again!\n" << std::endl;
}
void ExpertRules::penguin() {
	std::cout << "Penguin:\ncurrent player can face down a face up card!\n" << std::endl;
}
void ExpertRules::octopus() {
	std::cout << "Octopus:\ncurrent player can swap a card with one of the adjacent one!\n" << std::endl;
}
void ExpertRules::walrus() {
	std::cout << "Turtle:\ncurrent player can choose a card to block for the next turn!\n" << std::endl;
}
void ExpertRules::turtle() {
	//std::cout << "Turtle:\nnothing happen!\n" << std::endl;
	std::cout << "Turtle:\nnext player get his turn skip!\n" << std::endl;
}