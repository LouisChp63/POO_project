#ifndef ENNEMI_HPP
#define ENNEMI_HPP

#include "Personnage.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include <vector>
#include <string>

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * super-classe 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


class Ennemi : public Personnage
{
	protected:
			
		int greed;		// si ils misent beaucoup
		int spawnRate;	// proba d'apparition en %
		std::string nom;
		
		//contructeur protected pour les sous classes
		Ennemi(int startPosition, int jetonsInit, int greedInit, int dollarsInit, int spawnRateInit, Hand h);
		
		// complète une main avec des cartes aléatoires, en static car pas besoin d'un ennemi forcément
    	static void fillHand(Hand& h);

	public:
		// destructeur
		virtual ~Ennemi();	
		// générateur de monstre aléatoire, en * car on crééra des ennemis particuliers (gobelins...) 
		// en static car la fonction ne dépend pas d'un ennemi
		static Ennemi* creerAleatoire(int position);
		

		// rajouter une fonction qui renvoi le nom de l'ennemi
		std::string getNom() const;		
		int getGreed() const;
		int getSpawnRate() const;
};



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * sous-classes 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */



class Gobelin : public Ennemi
{
	private:
		// Main constante pour tous les gobelins
		static const Hand mainFixeGobelin;

	public:
		Gobelin(int startPosition);
};


class Orc : public Ennemi
{
	private:
		// Main constante pour tous les Orcs
		static const Hand mainFixeOrc;

	public:
		Orc(int startPosition);
};

class Larry : public Ennemi
{
	private:
		// Main constante pour tous les Larry
		static const Hand mainFixeLarry;

	public:
		Larry(int startPosition);
};

#endif

