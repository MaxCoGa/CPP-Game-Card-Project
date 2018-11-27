#ifndef EXPECTBOARD_H
#define EXPERTBOARD_H

#include "Board.h"

#include <iostream>



class ExpertBoard : public Board
{
	friend std::ostream& operator<< (std::ostream&, const Board&);
protected:
	void print(std::ostream& os) const ;//override;
	void faceUp(const Letter&, const Number&) ;//override;
	void faceDown(const Letter&, const Number&) ;//override;
	void resetFunction() ;//override;
public:
	ExpertBoard() : Board() {};
	~ExpertBoard() {};
};


#endif