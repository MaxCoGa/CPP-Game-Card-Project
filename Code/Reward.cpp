/**
 * Projet CSI 2772[A] Robert Laganiere
 * Reward.cpp
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "Reward.h"
#include <iostream>


/*Constructor*/
Reward::Reward(int number) {
	if(number<=4 && number >=1){
		_number=number;
	}else{
		_number = number % 4;
		if (_number == 0) {
			_number = 1;
		}
	}
}


/*print a reward*/
std::ostream &operator << (std::ostream &os, const Reward &r) {
	os << r._number;
	return os;
}

//REV 2.0
/* conversion operators to type int returning the number of rubies*/
Reward::operator int() const {
	return _number;
}