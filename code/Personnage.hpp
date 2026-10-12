#ifndef PERSONNAGE_HPP
#define PERSONNAGE_HPP

#include "Hand.hpp"


// Super classe incluant les ennemis et les joueurs
class Personnage
{
protected:
    int position;   // position sur le plateau
    int jetons;
    int dollars;
    Hand hand;
    
    // constructeur protected (que pour les classes filles)
    Personnage(int startPosition, int jetonsInit, int dollarsInit, Hand h);


public:
    // destructeur
    virtual ~Personnage();

		
	void ajouterJetons(int n);
	void ajouterDollars(int n);
		

    // Getters
    int getPosition() const;
    int getDollars() const;
    int getJetons() const;
    Hand& getHand();
};

#endif

