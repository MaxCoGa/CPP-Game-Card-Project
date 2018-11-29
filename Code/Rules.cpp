#include "Rules.h"



Rules::Rules(){
	//tour des joueur dans le sens d'un horloge
	for (auto side : { top,right,bot,left }) {
		players.push_back(side);
	}
	//init le premier joueur à jouer normalement ils utilisent les cartes volcans
	firstplayer = 0;
	currentplayer = firstplayer - 1;
}


bool Rules::isValid(const Game& g) {
	//TODO
    //return g._currentcard == g._previouscard; //doit utiliser getters pour y avoir accès
	//return g.getCurrentCard == g.getPreviousCard;
	return false;
}

bool Rules::gameOver(const Game& g) {
    //if(g._round == 7){//maximum de round(7)
	if(g.getRound() == 7){//getRound needs to be const too
        return true;
    }else{//retroune faux si on a pas 7 rounds encore
        return false;
    }
}

bool Rules::roundOver(const Game& g) {
	//TODO
	Player *player = nullptr;
	std::vector<Player*> active;
	return false;
}

const Player& Rules::getNextPlayer(const Game& g) {
	//TODO
	Player *player = nullptr;
	return *player;
;
}
