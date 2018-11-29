#include "Test.h"


#include "Player.h"
#include "Card.h"
#include "Carddeck.h"
#include "Reward.h"
#include "Rewarddeck.h"
#include "Board.h"
#include "Game.h"
#include "Rules.h"
#include "ExpertDisplay.h"
#include "ExpertRules.h"


#include <string>
#include <iostream>

#include <iomanip>//new
#include <windows.h>//new



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
	std::cout << "Show all the RULES TODO TODOTODOTODOTODOTODOTODOTODOTODOTODOTODOTODO" << std::endl;
}

int main(){

//unit class test
#if TEST_PLAYER
	test_player();
#endif
/*
#if TEST_CARD
	test_card();
#endif
#if TEST_REWARD
	test_reward();
#endif
#if TEST_CARDDECK
	test_carddeck();
#endif
#if TEST_REWARDDECK
	test_rewarddeck();
#endif
#if TEST_BOARD
	test_board();
#endif
#if TEST_GAME
	test_game();
#endif
#if TEST_RULES
	test_rules();
#endif
#if TEST_EXPERTDISPLAY
	test_expertdisplay();
#endif
#if TEST_EXPERTRULES
	test_expertrules();
#endif
*/

//Game
#if MAIN
	while (true) {//big loop to make the game replayed after 7 rounds
		//ADD counter for number of game win or loss it may be an array/vector of win or loss

		//major definitions
		Board* board = nullptr;
		Game* game = nullptr;
		Rules* rules = nullptr;

		//TESTING COLOR
		int color = 2;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);


		//game input
		int input;//general input
		int help;
		int display;//normal(0) or expert(1)
		int rule;//normal(0) or expert(1)
		std::string playerName;

		std::cout << "Memoarr, the board game. Implemented by Maxime & Valentin\n" << std::endl;
		std::cout << "Press any key to START the game setup or 1 to how to play" << std::endl;
		//HELP
		while (true) {
			std::cin >> help;
			if (!std::cin.fail() && help == 1) {
				std::cin.clear();
				howToPlay();
				break;
			}
			else if (std::cin.fail() || help != 1) {
				std::cin.clear();
				std::cin;
				std::cin.ignore(100, '\n');
				std::cout << "\nSETUP" << std::endl;
				break;

			}
		}
		//cin.clear();

		//Ask player to choose game version
		//DISPLAY
		std::cout << "This game have two displays: \n0 for normal \n1 for expert" << std::endl;
		while (true) {
			std::cin >> display;
			if (!std::cin.fail() && display == 0) {
				std::cout << "Normal display choose" << std::endl;
				//board = new Board();
				break;
			}
			else if (!std::cin.fail() && display == 1) {
				std::cout << "Expert display choose" << std::endl;
				//board = new Board();//change to new ExpertDisplay();
				break;

			}
			else {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "0(normal) or 1(expert) only!" << std::endl;
			}
		}
		//cin.clear();

		//RULES
		std::cout << "This game have two differents way to play: \n0 for normal \n1 for expert" << std::endl;
		while (true) {
			std::cin >> rule;
			if (!std::cin.fail() && rule == 0) {
				std::cout << "Normal rule choose" << std::endl;
				//game = new Game(*board);
				//rules = new Rules();
				break;
			}
			else if (!std::cin.fail() && rule == 1) {
				std::cout << "Expert rule choose" << std::endl;
				//game = new Game(*board);
				//rules = new Rules();//change to new ExpertRules();
				break;

			}
			else {
				std::cin.clear();
				std::cin.ignore(100, '\n');
				std::cout << "0(normal) or 1(expert) only!" << std::endl;
			}
		}



		//number of players and names of players.
		int playersNumber = 1;
		std::cout << "Number of players? 2, 3 or 4?" << std::endl;
		while (true) {
			std::cin >> input;
			if (!std::cin.fail() && (input > 1 && input < 5)) {//CREATE PLAYERS
				for (auto &side : { top, right, bot, left }) {//ambigue avec using namespace std;???
					if (playersNumber > input) {
						break;
					}
					std::cout << "Player " << playersNumber++ << " : ";
					std::cin >> playerName;
					Player player(playerName, side);

				}


			}
			else {
				std::cout << "Only 2 to 4 players can play this game!" << std::endl;
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
		}
		
	}
#endif
	return 0;

    
}

