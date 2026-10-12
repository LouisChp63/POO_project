#ifndef JEUX_HPP
#define JEUX_HPP

#include <vector>
#include "Carte.hpp"


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * super-class abstraite 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Jeux
{
	protected:
		// vecteur du jeux de cartes contenant des objets Carte
		std::vector<Carte> cartes;
	public:
		// destructeur
		virtual ~Jeux();
		virtual void reset() = 0;
		virtual void construireDeck() = 0;
		Carte piocher(); 
		void melanger();
		int taille() const;
};

#endif

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * sous-classes des différents jeux
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


// jeu standard avec les 52 cartes de base
class JeuStandard : public Jeux
{
	private :
		void construireDeck() override;
	public:	
		// uniquement le constructeur
		JeuStandard();
		void reset() override;
};



// jeu ROUGE, comporte que des coeur et que des carreaux 

class JeuRouge : public Jeux
{
	private :
		void construireDeck() override;
	public:	
		// uniquement le constructeur
		JeuRouge();
		void reset() override;
};

// jeu test 

class JeuTest : public Jeux
{
	private :
		void construireDeck() override;
	public:	
		// uniquement le constructeur
		JeuTest();
		void reset() override;
};

// jeu Voleuse 

class JeuVoleuse : public Jeux
{
	private :
		void construireDeck() override;
	public:	
		// uniquement le constructeur
		JeuVoleuse();
		void reset() override;
};


