#include <iostream>
#include "card.h"

std::string Card::operator() (const int row) const {
	if (row > 2) {
		return "";
	}
	if (row == 1) {
		char line[] = { _background, _animal, _background, '\0' };
		return std::string(line);
	}
	else {
		char line[] = { _background, _background, _background, '\0' };
		return std::string(line);
	}
}