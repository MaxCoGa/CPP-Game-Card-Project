/**
 * Projet CSI 2772[A] Robert Laganiere
 *
 * @author Maxime Cote-Gagne(8851539) & Valentin Magot(8843488)
 *
 */
#ifndef DECK_H
#define DECK_H
template <class C> class Deck{
public:
	virtual ~Deck() {};//destructor a ne pas inlucre dans les derives

	virtual void shuffle() = 0; // Vous devez vous servir de la fonction std::random_shuffle de la bibliothèque standard. 
	virtual C* getNext() = 0;
	virtual bool isEmpty() const = 0;
};
#endif