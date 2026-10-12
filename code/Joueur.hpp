#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "Personnage.hpp"
#include "Objet.hpp"
#include <vector>
#include <iostream>


class Plateau;
class Hand;
class Jeux;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * super-classe 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Joueur : public Personnage
{
	protected:
		int chance;
		int defausse;

		std::vector<Objet> inventaire;

		Jeux* jeux;
		
		//contructeur protected pour les sous classes
		Joueur(int startPosition, int jetonsInit, int chanceInit, int defausse, int dollarsInit, Hand h, Jeux* j);

	public:

		// destructeur
		virtual ~Joueur();
		
		void jouerTour(Plateau& plateau);	
		
		// piocher main
		void piocherMain();
		
		// défausser N cartes et compléter la main, passage du vectore par référence
		void defausserEtPiocher(std::vector<int>& index);
		void ajouterDefausse(int i);
		int lancerDe();
		
		int getDefausse() const;
		int getChance() const;
		
		//inventaire

		void ajouterObjet(const Objet& obj);
		void enleverObjet(int index);
		bool inventaireVide();

		// Récupérer un objet selon son index
		Objet* getObjet(int index);

		// Afficher l'inventaire
		void afficherInventaire() const;

};

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * sous-classes 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Chevalier : public Joueur
{
	public:
		Chevalier(int startPosition);
};


class Reine : public Joueur
{
	public:
		Reine(int startPosition);

};

class Voleuse : public Joueur
{
	public:
		Voleuse(int startPosition);
};
#endif

