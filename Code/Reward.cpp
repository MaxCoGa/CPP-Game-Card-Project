/**
 * Projet 4 CSI 2772[A] Robert Laganiere
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#include "Reward.h"
#include <iostream>

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

std::ostream &operator << (std::ostream &os, const Reward &r) {
	os << r._number;
	return os;
}
