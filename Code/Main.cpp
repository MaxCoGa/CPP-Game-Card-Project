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

//#include <iomanip>//new
//#include <windows.h>//new



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
	std::cout << std::endl;
	test_player();
#endif
#if TEST_CARD
	std::cout << std::endl;
	test_card();
#endif

#if TEST_REWARD
std::cout << std::endl;
	test_reward();
#endif
#if TEST_CARDDECK
std::cout << std::endl;
	test_carddeck();
#endif
#if TEST_REWARDDECK
std::cout << std::endl;
	test_rewarddeck();
#endif
/*
#if TEST_BOARD
std::cout << std::endl;
	test_board();
#endif
#if TEST_GAME
std::cout << std::endl;
	test_game();
#endif
#if TEST_RULES
std::cout << std::endl;
	test_rules();
#endif
#if TEST_EXPERTDISPLAY
std::cout << std::endl;
	test_expertdisplay();
#endif
#if TEST_EXPERTRULES
std::cout << std::endl;
	test_expertrules();
#endif
*/

//Game
#if MAIN
	while (true) {//big loop to make the game playable again after 7 rounds //Maybe?
		//ADD counter for number of game win or loss it may be an array/vector of win or loss

		//Objects that need to be destroy after
		Board* board = nullptr;
		Game* game = nullptr;
		Rules* rules = nullptr;

		//TESTING COLOR
		int color = 2;
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 31);


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
			//std::cout << "HELP LOOP" << std::endl;
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
			//std::cout << "DISPLAY LOOP" << std::endl;
			std::cin >> display;
			if (!std::cin.fail() && display == 0) {
				std::cout << "Normal display choose\n" << std::endl;
				board = new Board();
				break;
			}
			else if (!std::cin.fail() && display == 1) {
				std::cout << "Expert display choose\n" << std::endl;
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
		std::cout << "This game have two differents set of rules: \n0 for normal \n1 for expert" << std::endl;
		while (true) {
			//std::cout << "RULES LOOP" << std::endl;
			std::cin >> rule;
			if (!std::cin.fail() && rule == 0) {
				std::cout << "Normal rule choose\n" << std::endl;
				game = new Game(*board);
				rules = new Rules();
				break;
			}
			else if (!std::cin.fail() && rule == 1) {
				std::cout << "Expert rule choose\n" << std::endl;
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
		std::cout << "Select number of players: 2 to 4" << std::endl;
		int numPlayers = -1;
		int tempNumPlayers = -1;
		while (numPlayers == -1) {
			//std::cout << "NUMBERS LOOP" << std::endl;
			std::cin >> numPlayers;
			if (!std::cin.fail() && (numPlayers > 1 && numPlayers < 5)) {
			}
			else {
				std::cout << "Invalid input. Enter 2, 3, or 4 as the number of players" << std::endl;
				numPlayers = -1;
				std::cin.clear();
				std::cin.ignore(100, '\n');
			}
		}
		tempNumPlayers = numPlayers;
		for (auto &side : { top, right, bot, left }) {
			//std::cout << "NAME LOOP" << std::endl;
			std::cout <<"Enter player " << side + 1 << " name" << std::endl;
			//int i = 0;
			while (true) {
				std::cin >> playerName;
				if (!std::cin.fail() && (playerName != "" || playerName != "\n")) {
					Player p(playerName, side);
					p.setActive(true);
					game->addPlayer(p);
					//std::cout << p << std::endl;//TESTING ONLY
					break;
				}
				else {
					std::cout << "Invalid input." << std::endl;
					std::cin.clear();
					std::cin.ignore(100, '\n');
				}
				//i++;
				
			}
			tempNumPlayers--;
			if (tempNumPlayers < 1) break;

			
		}

		//TO CHANGE// MAKE IT MORE READABLE

		//game start
		std::cout << "START" << std::endl;
		std::cin.clear();
		std::cin.ignore(100, '\n');

		//game over loop - go through the game rounds
		while (!rules->gameOver(*game)) {
			std::cout << std::endl << std::endl << "ROUND " << game->getRound() + 1 << std::endl << std::endl;
			board->reset();//make everything face down
			
			tempNumPlayers = numPlayers;//temp number

			std::cout << *game << std::endl;//show the game with all the card backsiede down

			//reveal cards section - show each player their card selection
			for (auto &side:{top,right,bot,left}) {
				//std::cout << *game << std::endl;

				Player& p = game->getPlayer(side);
				p.setActive(true);

				std::cout << sideArray[side] << " player " << p.getName() << " see his three middle fronts cards" << std::endl;
				//std::cout << Side(0) << " " << side << std::endl;//test purpose only
				if (side == Side(0)) {//Top
					board->turnFaceUp(A, TWO);
					board->turnFaceUp(A, THREE);
					board->turnFaceUp(A, FOUR);
				}
				else if (side == Side(1)) {//right
					board->turnFaceUp(B, FIVE);
					board->turnFaceUp(C, FIVE);
					board->turnFaceUp(D, FIVE);
				}
				else if (side == Side(2)) {//bot
					board->turnFaceUp(E, TWO);
					board->turnFaceUp(E, THREE);
					board->turnFaceUp(E, FOUR);
				}
				else if (side == Side(3)) {//left
					board->turnFaceUp(B, ONE);
					board->turnFaceUp(C, ONE);
					board->turnFaceUp(D, ONE);
				}

				std::cout << std::endl << *board << std::endl;

				std::cout << "Enter to continue." << std::endl;
				std::cin;
				std::cin.clear();
				std::cin.ignore(100, '\n');
				board->reset();

				//remove one temp player each time
				--tempNumPlayers;
				if (tempNumPlayers < 1) break;

				
				
			} //end reveal card selection

			std::cout << *game << std::endl; //print the board beforegame starts
			
			//round over loop - go through the round until only one active player remains
			while (!rules->roundOver(*game)) {
				bool validCardChoice = false;
				Player p = rules->getNextPlayer(*game);
				Letter tmpL;
				char tL;
				Number tmpN;
				int tN;

				// change starting side

				//player chooses card by specifying letter and number, validate card choice loop
				while (!validCardChoice) {
					std::cout << p.getName() <<" on the " << sideArray[p.getSide()] << " turn!" << std::endl;
					
					
					//CHOOSE LETTER
					std::cout << "Letter (A, B, C, D, E)" << std::endl;

					
					while (true) {
						std::cin >> tL;
						if (!std::cin.fail() && (tL == 'A' || tL == 'B' || tL == 'C' || tL == 'D' || tL == 'E' || tL == 'a' || tL == 'b' || tL == 'c' || tL == 'd' || tL == 'e')) {
							if (tL == 'A' || tL == 'B' || tL == 'C' || tL == 'D' || tL == 'E') {
								tmpL = Letter(tL - 'A');
							}

							if (tL == 'a' || tL == 'b' || tL == 'c' || tL == 'd' || tL == 'e') {
								tmpL = Letter(tL - 'a');
							}

							std::cin.clear();
							std::cin.ignore(100, '\n');
							break;
						}
						else {
							std::cout << "A, B, C, D, or E ONLY!" << std::endl;
							std::cin.clear();
							std::cin.ignore(100, '\n');
						}
					}


					//CHOOSE NUMBER
					std::cout << "Number 1, 2, 3, 4, 5" << std::endl;

					while (true) {
						std::cin >> tN;
						if (!std::cin.fail() && (tN == 1 || tN == 2 || tN == 3 || tN == 4 || tN == 5)) {
							tmpN = Number(tN - 1);
							std::cin.clear();
							std::cin.ignore(100, '\n');
							break;
						}
						else {
							std::cout << "1, 2, 3, 4, or 5 ONLY!" << std::endl;
							tN = -1;
							std::cin.clear();
							std::cin.ignore(100, '\n');
						}
					}

					//no card at the center
					if (tmpL == C && tmpN == THREE) {
						std::cout << "C3 is not a valid postition" << std::endl;
					}
					else {
						Card* c = game->getCard(tmpL, tmpN);

						//If valid card is choosen!!!
						if (board->turnFaceUp(tmpL, tmpN)) {
							validCardChoice = true;
							game->setCurrentCard(c);
							if (!rules->isValid(*game)) {
								p.setActive(false);//make the player inactive for the rest of the round
								game->addPlayer(p);
							}
							std::cout << std::endl << *game << std::endl;
						}
						else {
							std::cout << "Card is already face up." << std::endl;
						}

					}


				} //end validate card choice loop
			} //end of round over loop


			//put all players active
			game->next();
		

		} //end of game loop


		//Game is terminated
		//low to high
		std::vector<Player> pl;
		for (int i = 0; i < numPlayers; ++i) {
			pl.push_back(rules->getNextPlayer(*game));
		}
		std::cout <<  "Game is finished" <<std::endl;
		std::cout << "Scores:" << std::endl;
		while (pl.size() != 0) {
			int temp = 0;
			for (int i = 1; i < pl.size(); ++i) {
				if (pl[i].getNRubies() <= pl[temp].getNRubies())
					temp = i;
			}
			pl[temp].setDisplayMode(true);
			std::cout << pl[temp] << std::endl;
			if (pl.size() == 1) {
				std::cout << "The winner is " << pl[temp].getName() << " with " << pl[temp].getNRubies() << " rubies." << std::endl;
			}
			pl.erase(pl.begin() + temp);
		}
		/*
		if (true) {
			std::cout << "New Game? y/n" << std::endl;
			char yn;
			std::cin >> yn;
			if (yn == 'n') {
				*/
				//destroy objects
				delete board;
				delete game;
				delete rules;

				break;
			//}
			//break;//make out of loop
		//}




		
	}//BIG LOOP WHILE/// DONT REMOVE
#endif
	return 0;

    
}

