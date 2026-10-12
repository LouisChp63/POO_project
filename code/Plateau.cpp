#include "Plateau.hpp"
#include "Ennemi.hpp"
#include "Joueur.hpp"


/*
 * Constructeur
 */
Plateau::Plateau(int t) : taille(t),  cases(t, CaseType::Vide), objets(t) 
{
	// Génération des cases ennemis
	for (int i = 1; i < (taille-1) ;i++)
	{
		int r = rand() % 100;
		if (r<PourcentageEnnemi)	
		{
			cases[i] = CaseType::Ennemi;
			
			// générer un ennemi aléatoire
			Ennemi* e = Ennemi::creerAleatoire(i);
			// le stocker dans une liste
            ennemis.push_back(e);
			
		}
	}
	
	// Génération des cases obj
	    // Objets
    for (int i = 1; (i < taille - 1); i++)
    {
        if (cases[i] == CaseType::Vide && rand() % 100 < PourcentageObjet)
        {
            cases[i] = CaseType::Obj;
            Type t = static_cast<Type>(rand() % 6);
            objets[i] = Objet(static_cast<Type>(rand() % 6));
        }
    }
}

/*
* Destructeur 
*
* ON EST OBLIGE DE DETRUIRE LES ENNEMI CAR APPELES PAR REF
*
*/


Plateau::~Plateau()
{
	for (int i = 0; i <ennemis.size(); i++)
	{
		delete ennemis[i];
	}
}

/*
 * Méthodes
 */


int Plateau::getTaille() const
{
    return taille;
    
}

const std::vector<Ennemi*>& Plateau::getEnnemis() const
{
	return ennemis;
}

bool Plateau::isValid(int position)
{
	// 0 si on est en dehors du plateau
    return (position >= 0 && position < taille);
}


bool Plateau::hasEnnemi(int position)
{
    if (position < 0 || position >= taille) return false;

    return cases[position] == CaseType::Ennemi;

}

void Plateau::clearCase(int position)
{
        cases[position] = CaseType::Vide;
}
bool Plateau::hasObj(int position)
{
    if (position < 0 || position >= taille) return false;
    
	return(cases[position] == CaseType::Obj);
}

Ennemi* Plateau::getEnnemi(int position)
{
	for (int i = 0; i <ennemis.size(); i++)
	{
        if (ennemis[i]->getPosition() == position) return ennemis[i];
    }
    return nullptr;
}

Objet Plateau::prendreObjet(int position)
{
    cases[position] = CaseType::Vide;
    return objets[position];
}

