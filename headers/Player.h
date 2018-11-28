/**
 * ProjetDevoir 4 CSI 2772[A] Robert Laganiere
 * Player.h
 * Player object definition
 *
 *
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot
 *
 */

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "Reward.h"
#include "Test.h"
const std::string sideArray[] = {"top","bot","right","left"}; //rotation de joueur selon l'horloge
enum Side{top,bot,right,left};//Grille top,bot,right,left



class Player {
	private:
		std::string _name;//nom du joueur
		Side _boardSide;//utilise l'enum Side
		int _rubies;//nombre de rubie d'un joueur
		bool _active;//statut d'un joueur(a son tour de jouer ou non)
		bool _endOfGame;//partie terminé ou non
	public:
		Player(std::string name, Side side);//constructeur a 2 arguments avec nom du joueur et son cote du board
		~Player();//destructeur


		std::string getName() const;
		void setActive(bool);
		bool isActive() const;//const sinon on peut pas prendre la valeur...
		int getNRubies() const;
		void addReward(const Reward&);
		void setDisplayMode(bool);

		Side getSide() const;

		friend std::ostream& operator<<(std::ostream&, const Player&);
};


#endif 

#if TEST_PLAYER
static void test_player() {
	std::cout << std::endl << "PLAYER CLASS TEST" << std::endl;
	Side side = top;
	Player playerOne("Joe", side);
	side = right;
	Player playerTwo("Maxime", side);
	side = bot;
	Player playerThree("Valentin", side);
	side = left;
	Player playerFour("Robert", side);


	cout << "isActive()" << endl;
	cout << playerOne.isActive() << endl;
	playerOne.setActive(true);
	cout << playerOne.isActive() << endl;

	cout << endl;

	cout << "getSide()" << endl;
	cout << playerOne.getSide() << endl;
	cout << endl;

	cout << "setDisplayMode()" << endl;
	cout << "endOfGame False:" << endl;
	cout << playerOne;
	cout << "endOfGame true:" << endl;
	playerOne.setDisplayMode(true);
	cout << playerOne;
	cout << endl;

	cout << "addReward()" << endl;
	Reward r1(1), r2(4), r3(3);
	cout << playerOne;
	playerOne.addReward(r1);
	cout << playerOne;
	playerOne.addReward(r2);
	cout << playerOne;
	playerOne.addReward(r3);
	cout << playerOne;

	playerOne.setActive(false);
	cout << playerOne.isActive() << endl;
#endif