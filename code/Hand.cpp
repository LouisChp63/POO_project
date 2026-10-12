#include "Hand.hpp"
#include "def.hpp"
#include <iostream>
#include <algorithm> 

void Hand::ajouterCarte(const Carte& c)
{
    cartes.push_back(c);
}

Hand::Hand(){};

void Hand::clear()
{
	cartes.clear();
}

bool Hand::contient(const Carte& c) const
{
    for (int i = 0; i < cartes.size(); i++)
    {
        if(cartes[i]==c) return true;
    }
    return false;
} 

// Défausse une carte par index (on part de 0)
int Hand::defausserCarte(int index)
{
    if (index >= 0 && index < cartes.size())
    {
        cartes.erase(cartes.begin() + index);
        return 1;
    }
    else
    {
        std::cout << "Index invalide pour la défausse : " << index << std::endl;
        return 0;
    }
}

int Hand::taille() const
{
    return cartes.size();
}

const std::vector<Carte>& Hand::getCartes() const
{
    return cartes;
}

void Hand::sort()
{
	std::sort(cartes.begin(), cartes.end());
}

// Affiche toutes les cartes de la main, une par une
void Hand::afficherAscii()
{
	sort();
    for (int i = 0; i < cartes.size(); i++)
    {
        cartes[i].afficherASCII();
        
        std::cout <<"----(" <<i<<")----" << std::endl;
    }
}

int Hand::evaluerMain()
{
	sort();
	int i = 0;
	
	int Paire = 0;
	bool Brelan = false;
	bool Carre = false;
	bool Couleur = true;
	bool Suite = true;
	bool SuiteAsBas = false;

    
    int max = cartes[TailleMain-1].getValeurInt();
    
	while (i < TailleMain - 1)
	{
		int count = 1;

		// comparaison carte à carte (suite / couleur)
		if (cartes[i].getValeurInt() + 1 != cartes[i + 1].getValeurInt()) Suite = false;
		
		if (cartes[i].getCouleur() != cartes[i + 1].getCouleur()) 		  Couleur = false;

		// compter les cartes égales
		while (i + count < TailleMain && cartes[i].getValeurInt() == cartes[i + count].getValeurInt())
		{
		    count++;
		    max = cartes[i].getValeurInt();
		}

		if (count == 4) Carre = true;
		else if (count == 3) Brelan = true;
		else if (count == 2) Paire++;



		i += count;
	}


	if (cartes[4].getValeurInt() == 14 &&  // As
		cartes[0].getValeurInt() == 2 &&
		cartes[1].getValeurInt() == 3 &&
		cartes[2].getValeurInt() == 4 &&
		cartes[3].getValeurInt() == 5)
	{
		SuiteAsBas = true;
	}
	
	Suite=(Suite||SuiteAsBas);
	
    if (Carre)						return (140+max);			// carre
    if (Brelan && Paire == 1)		return (120+max);			// full house
    if (Couleur && Suite)			return (160+max);			// quinte flush
    if (Couleur)					return (100+max);			// couleur
    if (Suite)						return (80+max);			// suite
    if (Brelan)						return (60+max);			// brelan
    if (Paire == 2)					return (40+max);			// double paire
    if (Paire == 1)					return (20+max);			// paire
 	  								return max;					// carte haute
}

std::string Hand::StrEvaluerMain(int score)
{
	if (score >160)		return (" Quinte flush!!!");
	if (score >140)		return (" Carre");
	if (score >120)		return (" Full House");
	if (score >100)		return (" Couleur");
	if (score >80)		return (" Suite");
	if (score >60)		return (" Brelan");
	if (score >40)		return (" Double Paire");
	if (score >20)		return (" Paire");
						return (" Carte Haute");
}

