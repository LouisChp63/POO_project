

#include "Ennemi.hpp"

#include "def.hpp"

#include <iostream>
#include <random>
#include <cstdlib> 
#include <ctime>



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * super-class abstraite 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
* constructeur protégé utilisant celui de Personnage
*/
Ennemi::Ennemi(int startPosition, int jetonsInit, int greedInit, int dollarsInit, int spawnRateInit, Hand h)
    : Personnage(startPosition, jetonsInit, dollarsInit, h), greed(greedInit), spawnRate(spawnRateInit)
{}

/*
*	Génération des ennemis (utiliser le spawn rate mtn)
*/
Ennemi* Ennemi::creerAleatoire(int position)
{
    int r = rand() % TotalSpawnRate;

    if (r <= GobelinSpawnRate)	return new Gobelin(position);
    if (r <= OrcSpawnRate)		return new Orc(position);
    if (r <= LarrySpawnRate)		return new Larry(position);

    return nullptr;
}

/*
*	Destructeur vide
*/
Ennemi::~Ennemi()
{
}


/*
 * Getter
 */

int Ennemi::getGreed() const
{
    return greed;
}

std::string Ennemi::getNom() const
{
	return nom;
}	

int Ennemi::getSpawnRate() const
{
	return spawnRate;
}
/*
*	génération de la main de l'ennemi
*/ 
void Ennemi::fillHand(Hand& h)
{
	int val, coul;
	while(h.taille()<TailleMain)
	{
		val = rand() % 13 + 2;
		coul = rand() % 4;
		Carte carte(static_cast<Valeur>(val), static_cast<Couleur>(coul));
		
		// vérif des doublons 
		if(!h.contient(carte))	h.ajouterCarte(carte);
	}
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * sous-classes des différents personnages
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
// GOBELIN

/* Main fixe du Gobelin : paire de 2 + autres cartes à compléter */
const Hand Gobelin::mainFixeGobelin = []
{
    Hand h;
    h.ajouterCarte(Carte(Valeur::Deux, Couleur::Pique));
    h.ajouterCarte(Carte(Valeur::Deux, Couleur::Coeur));
    return h;
}();


Gobelin::Gobelin(int startPosition)
    : Ennemi(startPosition, GobelinJetons, GobelinGreed, GobelinDollars, GobelinSpawnRate, mainFixeGobelin)
{
	nom="Gobelin Malicieux";
    // complète la main du Gobelin aléatoirement
    Ennemi::fillHand(hand);
}


// ORCS

/* Main fixe de l'orc : début d'une suite  */
const Hand Orc::mainFixeOrc = []
{
    Hand h;
    h.ajouterCarte(Carte(Valeur::Deux, Couleur::Pique));
    h.ajouterCarte(Carte(Valeur::Trois, Couleur::Coeur));
    h.ajouterCarte(Carte(Valeur::Quatre, Couleur::Pique));
    return h;
}();


Orc::Orc(int startPosition)
    : Ennemi(startPosition, OrcJetons, OrcGreed, OrcDollars, OrcSpawnRate, mainFixeOrc)
{
	nom="Orc féroce";
    // complète la main aléatoirement
    Ennemi::fillHand(hand);
}

// Larry

/* Main fixe de Larry : un brelan  */
const Hand Larry::mainFixeLarry = []
{
    Hand h;
    h.ajouterCarte(Carte(Valeur::Dix, Couleur::Pique));
    h.ajouterCarte(Carte(Valeur::Dix, Couleur::Coeur));
    h.ajouterCarte(Carte(Valeur::Dix, Couleur::Trefle));
    return h;
}();


Larry::Larry(int startPosition)
    : Ennemi(startPosition, LarryJetons, LarryGreed, LarryDollars, LarrySpawnRate, mainFixeLarry)
{
	nom="Larry Le malicieux ...";
    // complète la main aléatoirement
    Ennemi::fillHand(hand);
}





