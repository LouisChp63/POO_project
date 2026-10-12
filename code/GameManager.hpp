#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

#include "Plateau.hpp"
#include "Joueur.hpp"
#include "Marchand.hpp"

class GameManager
{
private:
    Plateau plateau;
    Joueur* joueur; //passage par ref, GameManager va créer Joueur 
    bool jeuTermine;

public:
    GameManager();
    ~GameManager();
    void generique();
    void initParti();
    void lancerParti();
    void printPlateau();		// affiche la plateau en ascii
    
};





#endif

