/**
 * Projet 4 CSI 2772[A] Robert Laganiere
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef EXPERTDISPLAY_H
#define EXPERTDISPLAY_H

#include "Board.h"
#include <vector>
#include <iostream>



class ExpertDisplay : public Board
{
	friend std::ostream& operator<< (std::ostream&, const Board&);
protected:
	void print(std::ostream& os) const ;
	void faceUp(const Letter&, const Number&) {};
	void faceDown(const Letter&, const Number&) {};
	void resetFunction() ;
public:
	ExpertDisplay() : Board() {};
	~ExpertDisplay() {};
};


#endif