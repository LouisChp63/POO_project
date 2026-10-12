#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>   

#include "def.hpp"
#include "Combat.hpp"
#include "Carte.hpp"
#include "Hand.hpp"


Combat::Combat(Joueur& j, Ennemi& e)
    : joueur(j),
      ennemi(e),
      miseJoueur(0),
      miseEnnemi(0),
      miseTotale(0),
      miseNombre(2),
      chance(1),
      def(joueur.getDefausse()),
      resultatCombat(0),
      combatTermine(false),
      joueurCouche(false),
      ennemiCouche(false)
{
}

void Combat::initCombat()
{
    std::cout << "\n=== DEBUT DU COMBAT ===\n";
	
	std::cout << "\nVous affrontez : " << ennemi.getNom() << "\n";
	joueur.piocherMain();
	std::cout << "\n\nVoilà votre MAIN messire\n\n";
	joueur.getHand().afficherAscii();
	miseNombre=2;
}

void Combat::miser(int mise)
{
		miseTotale+=mise;
}


/*
*	à finir
*/


void Combat::finCombat(int resultat)
{
    resultatCombat = resultat;
    combatTermine = true;

    switch (resultat)
    {
        case -1: // joueur se couche
            std::cout << "Vous vous êtes couché... perte de " << PerteCouche <<" $\n";
			joueur.ajouterDollars(PerteCouche);
            break;

        case 4: // chance réussie (pillage)
            std::cout << "PILLAGE RÉUSSI ! vous remportez tous les DOLLARS !\n";
			joueur.ajouterDollars(ennemi.getDollars());
			joueur.ajouterJetons(miseTotale);
			joueur.ajouterJetons(ennemi.getJetons());	// si l'ennemi n'a pas tout misé 
            break;

        case 1: // victoire normale
            std::cout << "Victoire !\n";
            joueur.ajouterJetons(miseTotale);
            joueur.ajouterDollars(ennemi.getDollars());
            break;
            
        case 2: // victoire ennemi couché
        	std::cout<<"ennemi couché!\n";
        	joueur.ajouterJetons(miseTotale);
        	break;

        case 0: // égalité
            std::cout << "Égalité.\n";
            break;

        case -2: // défaite
            std::cout << "Défaite...\n";
            
            break;
    }
}

void Combat::utiliserChance()
{
	int r = joueur.lancerDe();
	std::cout << "\nSuspense......\n";
	if ((r+joueur.getChance())>=DeclanchementChance)
	{
	
		finCombat(4);	// win parfaite, évennement pillage
		return;
	}
	else
	{
			std::cout << "\n ECHEC CRITIQUE !!!\n";
	}
}

void Combat::seCoucher()
{
	finCombat(-1);		// Coucher
	return;
}

void Combat::utiliserObj()
{
	if (joueur.inventaireVide())
	{
		std::cout<<"inventaire vide...\n";
		return;
	}
	int indice=0;
	joueur.afficherInventaire();
    std::cout << "Quel est votre choix d'objet ? (tapez l'indice, -1 pour quitter)\n";	
	std::cin >> indice;
	
	if (indice==-1) return;
		
	Objet* obj = joueur.getObjet(indice);

	if (obj == nullptr)
	{
		std::cout << "Objet invalide pb\n";
		return;
	}

	Type type = obj->getType();

	if (type == Type::Aucun)
	{
		std::cout << "Si vous voyez ça... y'a un pb\n";
	}
	if (type == Type::Defausse)
	{
		joueur.ajouterDefausse(1);
		std::cout << "+ 1 défausse\n";
	}
	if (type == Type::DoubleMise)
	{
		miseTotale=miseTotale*2;
		std::cout << "mise X 2 !!!\n";
	}
	if (type == Type::Apoil)
	{
		std::cout << "voilà la main ennemie !\n";
		ennemi.getHand().afficherAscii();
	}
	if (type == Type::BonusJetons)
	{
		joueur.ajouterJetons(15);
		std::cout << "+ 15 jetons pour vous\n";
	}
	if (type == Type::Fois2Dollars)
	{
		joueur.ajouterJetons(joueur.getDollars());
		std::cout << "* 2 sur les dollars pour vous !\n";	
	}
	joueur.enleverObjet(indice);

}

void Combat::evaluerResultat()
{

    int scoreJoueur = joueur.getHand().evaluerMain();
    int scoreEnnemi = ennemi.getHand().evaluerMain();
    
    std::cout << "\n\nMAIN ennemie\n\n";
	
	ennemi.getHand().afficherAscii();


    std::cout << "Score joueur  : " << scoreJoueur << joueur.getHand().StrEvaluerMain(scoreJoueur) << "\n";
    std::cout << "Score ennemi  : " << scoreEnnemi << ennemi.getHand().StrEvaluerMain(scoreEnnemi) << "\n";

    if (scoreJoueur > scoreEnnemi)
    {
		finCombat(1);		// victoire
		return;
    }
    else if (scoreJoueur < scoreEnnemi)
    {
		finCombat(-2);		// défaite
		return;
    }
    else
    {
		finCombat(0);		// égalité
		return;
    }

}


// rajouter l'obligation au joueur de mettre autant que l'ennemi ou all-in

void Combat::tourJoueur()
{
	int choix;

	
	std::cout <<"\n[Actuellement en combat]\n"
			  <<"|défausse restante :     "<<def << "\n"
			  <<"|jetons restants :       "<<joueur.getJetons()<<"\n"
			  <<"|pot actuel :            "<< miseTotale<<"\n\n";
	
	std::cout << "Quel est votre choix (saisissez en console le numéro correspondant) ? \n\n" << "Miser plus ? (1)\nUtiliser un Objet ? (2)\nUtiliser votre chance ? (3)\nDéfausser ? (4)\nVous coucher ? (5)\nDévoiler les cartes ? (6)\n\n";
	
	std::cin >> choix;	
	
	if (choix==1)
	{
		int mise=1000;
		std::cout<<"Vous pouvez encore miser "<< miseNombre <<" fois\n";
		if (miseNombre>0)
		{
			while(mise>joueur.getJetons())
			{	
				std::cout<<"Combien voulez vous miser ? (doit être inférieur à votre nombre de jeton)\n";
				//std::cout<<joueur.getJetons();	//debug
				
				std::cin>>mise;
			}
			miseNombre--;
			miseJoueur+=mise;
			joueur.ajouterJetons(-mise);
			miser(mise);
		}

	}
	else if (choix==2)
	{
		std::cout<<"Regardons votre inventaire\n";
		utiliserObj();
	}
	else if (choix==3)
	{
		if  (chance>0)
		{
			std::cout<<"Vous allez utiliser votre chance... attention ...\n";
			utiliserChance();
			chance--;
			if (combatTermine) return;
		}
		else std::cout<<"Vous avez déjà utiliser votre chance\n";
	}
	else if (choix==4)
	{
		if (def > 0)
		{
		    demanderDefausse();
		}
		else
		{
		    std::cout << "Vous n'avez plus de défausse disponible.\n";
		}
	}
	else if (choix==5)
	{
		std::cout<<"aie aie aie, qui ne porte point ses bourses, perd la sienne";
		seCoucher();
		return;		// au cas ou
	}
	else if (choix==6)
	{
		combatTermine=true;
		evaluerResultat();
		return;
	}
	else 
	{
		std::cout << "t'es pas le pinguin qui glisse le plus loin ... \n\n";
		tourJoueur();
		return;
	}

}

void Combat::tourEnnemi()
{
    if (combatTermine) return; // pour pas que l'ennemi fasse un autre tour

    int miseMaxParTour = 2;  // l'ennemi ne mise pas plus de 2 fois
    int misesEffectuees = 0;

    if (misesEffectuees >= miseMaxParTour) return;

    int r = rand() % 10;
    int mise = 0;

    // si r + greed > seuil il mise

    if (r + ennemi.getGreed() > TauxDeMiseEnnemi)		// cf def.hpp
    {
        int miseCible = miseJoueur + rand() % (ennemi.getGreed() + 1); 
        
        if (miseCible<ennemi.getJetons()) 
        {
        	mise = miseCible;
            std::cout << "L'ennemi mise " << mise << " jetons.\n";
        }
        
        else if (ennemi.getJetons()>0)
        {
        	mise = ennemi.getJetons();
			 std::cout << "L'ennemi ALL IN " << mise << " jetons.\n";
		}
        miseEnnemi += mise;
        miseTotale += mise;
        misesEffectuees++;
        ennemi.ajouterJetons(-mise);


    }
    else
    {
        std::cout << "L'ennemi se couche.\n";
        finCombat(2); // ennemi couché
        return;
    }
}

void Combat::demanderDefausse()
{
    if (def <= 0)
    {
        std::cout << "Aucune défausse restante.\n";
        return;
    }

    std::vector<int> indices;
    int index;

    std::cout << "\nEntrez les indices des cartes à défausser ex : 0 1 -1, -1 pour finir)\n> ";

    while (true)
    {
        std::cin >> index;

        if (index == -1) 	break;

        if (index >= 0 && index < joueur.getHand().taille())
        {
            indices.push_back(index);
        }
        else
        {
            std::cout << "Index invalide.\n";
        }
    }

    if (indices.empty())
    {
        std::cout << "Aucune carte défaussée.\n";
        return;
    }

    def -= 1;

    joueur.defausserEtPiocher(indices);

    std::cout << "\nMain après défausse et pioche :\n";
    joueur.getHand().afficherAscii();
}


void Combat::resetCombat()
{
	// nettoyage des mains (important pour ne pas contaminer la population)
    joueur.getHand().clear();
    ennemi.getHand().clear();

    
    miseJoueur = 0;
    miseEnnemi = 0;
    miseTotale = 0;
    miseNombre = 0;

    joueurCouche = false;
    ennemiCouche = false;
    combatTermine = false;
}


// boucle principale de combat

void Combat::lancerCombat()
{

    if (joueur.getJetons() <= 0)
    {
        std::cout << "passe\n";
        return;
   	}
    initCombat();

    while (!combatTermine)
    {
        tourJoueur();
        if (combatTermine) break;

        tourEnnemi();
    }		
	resetCombat(); // reset des jeux et hand
}






