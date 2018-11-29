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
	//ADD counter for number of game win or loss it may be an array/vector of win or loss

	//major definitions
	Board* board = nullptr;
	Game* game = nullptr;
	Rules* rules = nullptr;

	//TESTING COLOR
	int color = 2;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);


	//game input
	int input;
	int help;
	int display;//normal or expert
	int rule;//normal or expert
	cout.width(100); cout << "Memoarr, the board game. Implemented by Maxime & Valentin\n" << endl;
	cout.width(99); cout << "Press any key to START the game setup or 1 to how to play" << endl;
	while (true) {
		cin >> help;
		if (!cin.fail() && help == 1){
			cin.clear();
			howToPlay();
			break;
		}
		else if(cin.fail() || help != 1){ 
			cin.clear();
			cin;
			cin.ignore(100, '\n');
			cout << "\nSETUP" << endl;
			break;
			
		}
	}
	//cin.clear();

	cout << "This game have two displays: \n0 for normal \n1 for expert" << endl;
	while (true) {
		cin >> help;
		if (!cin.fail() && (display == 0 || display ==1)){
			cin.clear();
			howToPlay();
			break;
		}
		else if(cin.fail() && (display != 0 || display != 1)){ 
			cin.clear();
			cin;
			cin.ignore(100, '\n');
			cout << "\nSETUP" << endl;
			break;
			
		}
	}
	//cin.clear();

	
#endif

    
}

