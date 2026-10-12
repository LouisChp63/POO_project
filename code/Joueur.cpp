#include "Joueur.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "Jeux.hpp"
#include "Marchand.hpp"
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
Joueur::Joueur(int startPosition, int jetonsInit, int chanceInit, int defausse, int dollarsInit, Hand h, Jeux* j)
    : Personnage(startPosition, jetonsInit, dollarsInit, h), chance(chanceInit), defausse(defausse), jeux(j)
{}

/*
 * Fonction utilitaires
 */

int Joueur::lancerDe()
{
    return rand() % 6 + 1;
}

void Joueur::piocherMain()
{
	// opérateur -> car jeux est passé par référence
	jeux->melanger();

    while (hand.taille() < TailleMain)
    {
        hand.ajouterCarte(jeux->piocher());
    }
}

void Joueur::defausserEtPiocher(std::vector<int>& index)
{
	// On part de l'index le plus grand (sinon ils vont changer...)
	for(int i = (index.size() - 1) ; i>=0 ; i--)
	{
		hand.defausserCarte(index[i]);
	}
	while (hand.taille()<TailleMain)
	{
		hand.ajouterCarte(jeux->piocher());
	}
}



/*
*	Destructeur
*/
Joueur::~Joueur()
{
    delete jeux;
    std::cout<<"Joueur détruit";
}

/*
 * Jouer un tour (methode générale pour chaque joueur)
 */
void Joueur::jouerTour(Plateau& plateau)
{
    if (jetons <= 0)
    {
        std::cout << "Plus de jetons...\n" << std::endl;
        return;
    }
	int i ;
	
	std::cout << "Appuyez sur : \n 1 pour lancer le dès !! \n 2 pour aller voir le marchand !! \n 3 afficher vos stats" << std::endl;
	std::cin >> i ;

	if (i==1)
	{

		int de = lancerDe();
		jetons-=dice_cost;

		int nouvellePosition = position + de;

		if (plateau.isValid(nouvellePosition))
		{
		    position = nouvellePosition;
		    std::cout << "Le joueur avance de " << de
		              << " -> position " << position << std::endl;
		}
		else
		{
		    position = plateau.getTaille() - 1;
		    std::cout << "Le joueur atteint la fin du plateau !" << std::endl;
		}

	}
	else if (i==2)
	{
		Marchand marchand;
		marchand.interagir(*this);
	}
	else if (i==3)
	{
				std::cout
			  <<"|défausse :            "<<getDefausse() << "\n"
			  <<"|jetons restants :     "<<getJetons()<<"\n"
			  <<"|dollars actuel :      "<<getDollars()<<"\n"
			  <<"|position actuelle :   "<<getPosition()<<"\n"
			  <<"|chance :              "<<getChance()<<"\n";	
	
	}
	else return;
    // PLUS TARD :
    // interaction avec ennemi / objet / marchand
}


void Joueur::ajouterDefausse(int i)
{
	defausse+=i;
}

/*
 * Getter
 */

int Joueur::getChance() const
{
    return chance;
}
int Joueur::getDefausse() const
{
    return defausse;
}

/*
*	Inventaire
*/

void Joueur::ajouterObjet(const Objet& obj)
{ 
	inventaire.push_back(obj); 
}

void Joueur::enleverObjet(int index)
{
    if (index >= 0 && index < inventaire.size())
    {
        inventaire.erase(inventaire.begin() + index);
    }
}

Objet* Joueur::getObjet(int index)
{
    if (index >= 0 && index < static_cast<int>(inventaire.size()))
        return &inventaire[index];
    else
        return nullptr; // index invalide
}

bool Joueur::inventaireVide()
{
    if (inventaire.empty())
    {
        return true;
    }
    else return false;

}

void Joueur::afficherInventaire() const
{
    std::cout << "\n=== Inventaire ===\n";
    if (inventaire.empty())
    {
        std::cout << "Aucun objet.\n";
        return;
    }

    for (size_t i = 0; i < inventaire.size(); i++)
    {
        std::cout << i << ": " << inventaire[i].toString() << "\n";
    }
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * sous-classes des différents personnages
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
 
/*
 * Chevalier
 */
 
Chevalier::Chevalier(int startPosition)
	: Joueur(startPosition, ChevalierJetons, ChevalierChance, ChevalierDefausse, ChevalierDollars, Hand(), ChevalierJeu)
{}

/*
 * Reine Rouge
 */

Reine::Reine(int startPosition) 
	: Joueur(startPosition, ReineJetons, ReineChance, ReineDefausse, ReineDollars, Hand(), ReineJeu)
{}
 
/*
*  Voleuse
 */ 
 
Voleuse::Voleuse(int startPosition)
	: Joueur(startPosition, VoleuseJetons, VoleuseChance, VoleuseDefausse, VoleuseDollars, Hand(), VoleuseJeu)
{}
	


