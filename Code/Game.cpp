#include "game.h"

Game::Game(Board& b) : rd(RewardDeck::make_RewardDeck()), board(b) {
	rd.shuffle();
}

Game::~Game()
{
	for (auto i : players) {
		delete i;
	}
}

void Game::addPlayer(const Player& p) {
	bool playerPresent = false;
	for (auto &ep : players) {
		if (p.getSide() == ep->getSide()) {
			playerPresent = true;
			ep->setActive(p.isActive());
			break;
		}
	}
	if (!playerPresent) {
		players.push_back(new Player(p));
	}
}

Player& Game::getPlayer(Side s) const {
	//ensure requested player is present
	if (s < players.size() && players[s] != nullptr) {
		return *(players[s]);
	}
	else {
		throw NoPlayer();
	}
}

void Game::setCurrentCard(const Card* c) {
	previousCard = currentCard;
	currentCard = c;
}

Card* Game::getCard(const Letter& l, const Number& n) const {
	return board.getCard(l, n);
}

void Game::setCard(const Letter& l, const Number& n, Card* c) {
	board.setCard(l, n, c);
}


//OSTREAM
std::ostream& operator<< (std::ostream& os, const Game& g) {
	os << g.board << std::endl;
	for (int i = 0; i < g.players.size(); ++i) {
		if (g.players[i] != nullptr) {
			os << *g.players[i];
		}
	}
	return os;
}

void Game::next() {//add reward
	previousCard = 0;
	currentCard = 0;
	++round;
	for (auto p : players) {
		
		if (p->isActive()) {
			int tmp1 = p->getNRubies();
			p->addReward(*rd.getNext());
			int tmp2 = p->getNRubies();
			int tmp3 = tmp2 - tmp1;

			std::cout << p->getName() << " receive " << tmp3 << " rubies from winning this round" << std::endl;

		}
	}
	//make all player actve for next round
	for (auto p : players) {
		p->setActive(true);
	}
}