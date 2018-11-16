#include "Reward.h"
#include <iostream>

Reward::Reward(int number) {
	if(number<=4 && number >=1){
		_number=number;
	}else{
		_number  =1;
	}
}

std::ostream &operator << (std::ostream &os, const Reward &r) {
	os << r._number;
	return os;
}
