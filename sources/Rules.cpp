#include "Rules.h"



Rules::Rules(){}

	


Rules::~Rules(){}

bool Rules::isValid(const Game& g) {
    return g._currentcard == g._previouscard;
}

bool Rules::gameOver(const Game& g) {
    if(g._round == 7){
        return true;
    }else{
        return false;
    }
}

bool Rules::roundOver(const Game& g) {
    if(g._player.size() == 1){
        return true;
    }else{
        return false;
    }
}

const Player& Rules::getNextPlayer(const Game& g) {
    
    
}

Side Rules::nextPlayer() {
    
}

Side Rules::previousPlayer() {
    
}
