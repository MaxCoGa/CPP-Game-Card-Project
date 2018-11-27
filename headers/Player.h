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
//using namespace std;
const std::string sideArray[] = {"top","bot","right","left"};
enum Side{top,bot,right,left};//Grille top,bot,right,left



class Player {
	private:
		std::string _name;//nom du joueur
		Side _boardSide;//utilise l'enum Side
		int _rubies;//nombre de rubie d'un joueur
		bool _active;//statut d'un joueur(a son tour de jouer ou non)
		bool _endOfGame;//partie terminé ou non
	public:
		Player(std::string, Side);//constructeur a 2 arguments avec nom du joueur et son cote du board
		~Player();//destructeur


		std::string getName() const;
		void setActive(bool);
		bool isActive();
		int getNRubies() const;
		void addReward(const Reward&);
		void setDisplayMode(bool);

		Side getSide() const;

		friend std::ostream& operator<<(std::ostream&, const Player&);
};


#endif 