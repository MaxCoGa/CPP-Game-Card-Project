#include "ExpertDisplay.h"


    void ExpertDisplay::print(std::ostream& os) const {
		std::string card[4]; 
		bool up = false;
		
		for (int i = 0; i < rows*cols; i++) {
			Letter l = static_cast<Letter>(i / 5);
			Number n = static_cast<Number>(i % 5);
			if (isFaceUp(l, n)) {
				up = true;
				Card* c = getCard(l, n);
				card[0] += c->operator()(0) + " ";
				card[1] += c->operator()(1) + " ";
				card[2] += c->operator()(2) + " ";
				card[3] += ('A' + l);
				card[3] += std::to_string(n + 1) + "  ";
			}
		}
		os << card[0] << std::endl;
		os << card[1] << std::endl;
		os << card[2] << std::endl << std::endl;
		if (up) {
			os << card[3] << std::endl;
		}
		else {
			os << "No more cards is available." << std::endl;
		}

    }

    
	void ExpertDisplay::resetFunction() {
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				cardSide[i][j] = DOWN;
			}
		}

    }