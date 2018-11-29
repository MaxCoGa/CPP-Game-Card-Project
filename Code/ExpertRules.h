#ifndef EXPERTRULES_H
#define EXPERTRULES_H

#include "Rules.h"
#include "Board.h"


class ExpertRules : public Rules
{
private:
	Board * board;

    //Crab='C', Penguin='P', Octopus='O', Walrus='W', Turtle='T'
    void crab();
    void penguin();
	void crab();
	void octopus();
    void walrus();
    void turtle();
public:
	ExpertRules() : Rules() {};
	~ExpertRules();
	bool isValid(const Game& g);
};

#endif