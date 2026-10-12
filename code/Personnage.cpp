#include "Personnage.hpp"

/*
 * Constructeur
 */
Personnage::Personnage(int startPosition, int jetonsInit, int dollarsInit, Hand h)
    : position(startPosition), jetons(jetonsInit), dollars(dollarsInit), hand(h) {}

/*
 * Destructeur
*/
Personnage::~Personnage()
{
}


/*
*	Autres
*/
void Personnage::ajouterJetons(int n)
{
	jetons += n;
	if (jetons<0)	jetons = 0;
}

void Personnage::ajouterDollars(int n)
{
	dollars += n;
	if (dollars<0)	dollars = 0;
}

/*
 * Getters
 */
int Personnage::getPosition() const
{
    return position;
}

int Personnage::getJetons() const
{
    return jetons;
}

int Personnage::getDollars() const
{
    return dollars;
}

Hand& Personnage::getHand()
{
	return hand;
}


