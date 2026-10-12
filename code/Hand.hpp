#ifndef HAND_HPP
#define HAND_HPP

#include "Carte.hpp"

#include <vector>
#include <string>

class Hand
{
private:
    std::vector<Carte> cartes;

public:
	
    Hand();
    virtual ~Hand(){}
    // taille de la main
	int taille() const;
	
    // pioche une carte 
    void ajouterCarte(const Carte& c);
    
	// si la main contient la carte
	bool contient(const Carte& c) const; 
    
    // défausser une carte par index
    int defausserCarte(int index);

    // retourne la main par référence en lecture seule 
    const std::vector<Carte>& getCartes() const;
    
    // trie la main par valeur croissante
    void sort();

    // affiche toutes les cartes en ASCII (et trie la main)
    void afficherAscii();
    
    // évaluer la main
    int evaluerMain();
    
    // clear la main (après chaque combat)
    void clear();
    
    // évaluer la main en str
	std::string StrEvaluerMain(int score);
};

#endif

