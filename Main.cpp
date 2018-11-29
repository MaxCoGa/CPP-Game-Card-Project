#include <string>
#include <iostream>


#include "Card.h"
#include "Carddeck.h"
#include "Player.h"
#include "Reward.h"
#include "Rewarddeck.h"
#include "Board.h"
#include "Game.h"
#include "Rules.h"
#include "ExpertRules.h"
#include "ExpertDisplay.h"

using namespace std;

/*
Ask player to choose game version, number of players and names of
players.
Create the corresponding players, rules, cards and board for the game.
Display game (will show board and all players)
while Rules.gameOver is false
update status of cards in board as face down
update status of all players in game as active
for each player
Temporarily reveal 3 cards directly in front of the player
while Rules.roundOver is false
# next active player takes a turn
get selection of card to turn face up from active player
update board in game
if Rules.isValid(card) is false
# player is no longer part of the current round
current player becomes inactive
display game
 Remaining active player receives reward (rubies)
print players with their number of rubies sorted from least to most
rubies
print overall winner
*/

void howToPlay(){
	cout << "Show all the RULES TODO TODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODO" << endl;
}

int main(){

//test
#if TEST_PLAYER
	test_player();
#endif

//Game
#if main
	//set Board, Game and Rules to nullptr
	Board* board = nullptr;
	Game* game = nullptr;
	Rules* rules = nullptr;

	//game input
	int input;
	int help;
	int display;//normal or expert
	int rules;//normal or expert

	cout << "Memoarr, the board game. Implemented by Maxime & Valentin" << endl;
	cout << "Press any key to START the game setup or 0 to how to play" << endl;
	while (true) {
		cin >> help;
		if (help = 0) {
			howToPlay();
		}
		else if(help != 0){
			cout << "SETUP" << endl;
			break;
		}
	}
	cout << "This game have two displays: \n0 for normal \n1 for expert" << endl;
#endif

    
}

