#include "Jeux.hpp"
#include <algorithm>
#include <random>
#include <cstdlib>


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * super-class abstraite 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// Destructeur (vide)

Jeux::~Jeux()
{
}

// Méthodes

void Jeux::melanger()
{
    std::random_shuffle(cartes.begin(), cartes.end());
}


Carte Jeux::piocher()
{
	Carte c = cartes.back();	// select la denière carte
	cartes.pop_back();			// dégage la dernière carte

	return c;					// donc on pioche la dernière carte	
}


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * sous-classes des différents jeux
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

// JeuStandard un jeu tout à fait normal
JeuStandard::JeuStandard()
{
	reset();
}

void JeuStandard::construireDeck()
{
	cartes.clear();
    for (int c = 0; c < 4; c++)	// boucle sur les couleurs
    {
        for (int v = 2; v <= 14; v++)	// boucle sur les valeurs
        {
            cartes.push_back( Carte ( static_cast<Valeur>(v), static_cast<Couleur>(c) ) );	
            // remplir le vecteur avec v et c casté sur <Valeur> et <Couleur> les classes énumérées 
            // dans Carte.hpp 
    	}
    }
}

void JeuStandard::reset()
{
    construireDeck();
    melanger();
}

// JeuRouge (26 coeurs et 26 carreaux)
JeuRouge::JeuRouge()
{
	reset();
}

void JeuRouge::construireDeck()
{
		cartes.clear();
    for (int c = 0; c < 4; c++)	
    {
        for (int v = 2; v <= 14; v++)
        {
        	// le modulo permet d'avoir soit c = 0 (Coeur) soit c = 1 (Carreau) 
            cartes.push_back( Carte ( static_cast<Valeur>(v), static_cast<Couleur>(c%2) ) );	
    	}
    }	
}

void JeuRouge::reset() 
{
	construireDeck();
	melanger();
}

// JeuVoleuse	(que des cartes supéreur à 6)


JeuVoleuse::JeuVoleuse()
{
	reset();
}

void JeuVoleuse::construireDeck()
{
	cartes.clear();
    for (int c = 0; c < 4; c++)	
    {
        for (int v = 6; v <= 14; v++)
        { 
            cartes.push_back( Carte ( static_cast<Valeur>(v), static_cast<Couleur>(c) ) );	
    	}
    }	
}

void JeuVoleuse::reset() 
{
	construireDeck();
	melanger();
}



// jeu Test

JeuTest::JeuTest()
{
	reset();
}

void JeuTest::construireDeck()
{
	cartes.clear();
	cartes.push_back( Carte ( static_cast<Valeur>(14), static_cast<Couleur>(0) ) );	
	cartes.push_back( Carte ( static_cast<Valeur>(2), static_cast<Couleur>(0) ) );	
	cartes.push_back( Carte ( static_cast<Valeur>(13), static_cast<Couleur>(0) ) );
	cartes.push_back( Carte ( static_cast<Valeur>(4), static_cast<Couleur>(0) ) );		
	cartes.push_back( Carte ( static_cast<Valeur>(3), static_cast<Couleur>(0) ) );	
}

void JeuTest::reset()
{
	construireDeck();
	melanger();
}


