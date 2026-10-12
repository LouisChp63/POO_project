#include "GameManager.hpp"
#include "Combat.hpp"

#include <string>
#include <ctime>




GameManager::GameManager() : plateau(TaillePlateau), joueur(nullptr),jeuTermine(false)
{}

GameManager::~GameManager()
{
    delete joueur;	// on détruit bien joueur à la fin 
}

void GameManager::printPlateau()
{
    std::cout << "\nPlateau :\n";

    for (int i = 0; i < plateau.getTaille(); i++)
    {
        if (i == joueur->getPosition())
            std::cout << "J";
        else if (plateau.hasEnnemi(i))
            std::cout << "X";
        else if (plateau.hasObj(i))
            std::cout << "O";
        else
            std::cout << "-";
    }
    std::cout << "\n";
}


void GameManager::generique()
{
	std::cout<<"Vous vous réveillez ...\n"
	<< "en état d'ébriété...\n"
	<< "l'air hébété...\n"
	<< "vous regardez votre poche...\n"
	<< "deux choses y sont : un jeux de carte, et une note \n"
	<< "VOUS DEVEZ UNE ENORME SOMME DE JETONS AU ROI !!! ET VOUS DEVEZ PAYER AUJOURD'HUI !!!!!!!\n"
	<< "Ni une ni deux vous vous élancez vers le chateau pour éviter la décapitation...\n";
}


void GameManager::lancerParti()
{
    while (!jeuTermine)
    {
    	printPlateau();
        joueur->jouerTour(plateau);

        int pos = joueur->getPosition();
        
        if (joueur->getJetons()<=0)
        {
        	std::cout << "Game OVER !\n";
            jeuTermine = true;
            break;
        }

        if (plateau.hasEnnemi(pos))
        {
            Ennemi* e = plateau.getEnnemi(pos);
			Combat combat(*joueur, *e);
			combat.lancerCombat();
			std::cout << "\n=== FIN DU COMBAT ===\n";
			plateau.clearCase(pos);
        }

        if (plateau.hasObj(pos))
        {
            Objet obj = plateau.prendreObjet(pos);
            joueur->ajouterObjet(obj);
            std::cout << "Objet récupéré !\n";
            plateau.clearCase(pos);
        }
        if (pos >= plateau.getTaille() - 1)
        {
             std::cout << "Vous avez atteint le chatrau, avez vous la bonne somme de "<<SommeCible <<" jetons ?\n";
             
        	if(joueur->getJetons()>SommeCible)	std::cout << "OUI !!! victoire !\n";
            else	std::cout << "NON... victoire de courte durée, la prison vous attend...\n";
            jeuTermine = true;
        }

    }
}


void GameManager::initParti()
{
	int gene;
	std::cout<<"1 pour skip le générique, 0 pour le voir \n";
	
	std::cin >> gene;
	
	if(gene==0)	generique();
	
	std::cout << "\nAtteignez la fin du Plateau en ayant au moins " << SommeCible << " Jetons !!\nAtention, chaque déplacement vous coute 1 jetons...Bon courage :)\n";
	
    std::cout << "Choisissez votre personnage :\n";
    std::cout << "1 - Chevalier\n";
    std::cout << "2 - Reine Rouge\n";
    std::cout << "3 - Voleuse\n";

    int choix;
    std::cin >> choix;

    switch (choix)
    {
        case 1:
            joueur = new Chevalier(0);
            break;
        
        case 2:
        	joueur = new Reine(0);
        	break;
        	
        case 3:
        	joueur = new Voleuse(0);
            break;
            
        default:
            std::cout << "Choix invalide, Chevalier par défaut.\n";
            joueur = new Chevalier(0);
            break;
    }

    std::cout << "Personnage créé !\n";
}





