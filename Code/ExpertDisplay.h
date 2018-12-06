#ifndef EXPERTDISPLAY_H
#define EXPERTDISPLAY_H

#include "Board.h"
#include <vector>
#include <iostream>



class ExpertDisplay : public Board
{
	friend std::ostream& operator<< (std::ostream&, const Board&);
protected:
	void print(std::ostream& os) const ;//override;
	void faceUp(const Letter&, const Number&) {};//override;
	void faceDown(const Letter&, const Number&) {};//override;
	void resetFunction() ;//override;
public:
	ExpertDisplay() : Board() {};
	~ExpertDisplay() {};
};


#endif