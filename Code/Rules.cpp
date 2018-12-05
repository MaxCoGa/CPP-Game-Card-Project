#include "Rules.h"

//players est un vector!!!

Rules::Rules()
{
	//Ordre des joueurs : Top, Right, Bottom, Left : Sens d'horloge
	for (auto side : { top, right, bot, left }) {//AUTO IS NICE TO USE HERE! should be use everywhere when we can instead!!
		players.push_back(side);
	}
	//set initial player indices
	firstplayer = 0;
	currentplayer = firstplayer - 1; //current player is not selected, will be incremented by nextPlayer on first run
}



bool Rules::isValid(const Game& g) {
	//current and previous cards have to match either animal or colour
	++cardsturned;
	const Card* cc = g.getCurrentCard();
	const Card* pc = g.getPreviousCard();
	if (pc == nullptr) {
		return true;
	}
	if (((FaceAnimal)*cc == (FaceAnimal)*pc) || ((FaceBackground)*cc == (FaceBackground)*pc)) {
		return true;
	}
	else {
		return false;
	}
}

bool Rules::gameOver(const Game& g) {
	//maximum 7 rounds in game
	if (g.getRound() >= 7) {
		return true;
	}
	else {
		return false;
	}
}

bool Rules::roundOver(const Game& g) {
	Player* player = nullptr;
	std::vector<Player*> activeplayers;
	//create vector of active players
	for (auto &p : players) {
		try {
			player = &g.getPlayer(p);
			if (player->isActive()) {
				activeplayers.push_back(player);
			}
		}
		catch (NoPlayer e) {
		}
	}
	//round over when only one active player remains, or all cards are turned over (in which case we take the last player to win the round)
	if (activeplayers.size() == 1) {
		cardsturned = 0;
		return true;
	}
	else if (activeplayers.size() == 0) throw "Round can not be over because something went horribly wrong. Rules could not detect any active players!";
	else if (cardsturned == 24) {
		activeplayers.pop_back();
		for (auto &p : activeplayers) {
			p->setActive(false);
		}
		cardsturned = 0;
		return true;
	}
	else return false;
}

const Player& Rules::getNextPlayer(const Game& g) {
	Player* player = nullptr;
	//some player sides may not be present in game, try getting a reference from Game
	int attempts = players.size(); //number of attempts to obtain a valid player
	while (player == nullptr) {
		try {
			player = &g.getPlayer(nextPlayer()); //get next player object
			if (!player->isActive()) player == nullptr;
		}
		catch (NoPlayer e) {
			attempts--;
			if (attempts == 0) throw "Rules could not obtain valid players from Game";
		}
	}

	return *player;
}



Side Rules::nextPlayer() {
	if (currentplayer < players.size() - 1) {
		++currentplayer;
	}
	else {
		currentplayer = firstplayer;
	}

	return players[currentplayer];
}

Side Rules::previousPlayer() {
	if (currentplayer > 0) {
		--currentplayer;
	}
	else {
		currentplayer = players.size() - 1;
	}

	return players[currentplayer];
}
