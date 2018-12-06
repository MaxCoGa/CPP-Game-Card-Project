/**
 * Projet 4 CSI 2772[A] Robert Laganiere
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef EXPERTRULES_H
#define EXPERTRULES_H

#include "Rules.h"
#include "Board.h"


class ExpertRules : public Rules
{
private:
	Board * board;
	Card *block = nullptr;
public:
	ExpertRules() : Rules() {};
	~ExpertRules() {};
	bool isValid(const Game& g);//redefined from Rules!!
	bool roundOver(const Game& g);
	void set(Board *b) { board = b; };
};

#endif