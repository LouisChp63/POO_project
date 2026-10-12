#include "Carte.hpp"
#include <iostream>

/*
 * Constructeur destructeur
*/
Carte::Carte(Valeur v, Couleur c) : valeur(v), couleur(c) {}

Carte::~Carte() {}

/*
 * Getters
*/
Valeur Carte::getValeur() const
{
    return valeur;
}

Couleur Carte::getCouleur() const
{
    return couleur;
}

// on est obligé de cast ici (en cast sécurisé selon le compilateur) 
int Carte::getValeurInt() const
{
    return static_cast<int>(valeur);
}
/*
*	Opérateur
*/

// '=='
bool Carte::operator==(const Carte& other) const
{
    return (valeur == other.valeur && couleur == other.couleur);
}

// '>'
bool Carte::operator>(const Carte& other) const
{
    return (valeur > other.valeur);
}

bool Carte::operator<(const Carte& other) const
{
    return (valeur < other.valeur);
}



/*
 * Affichage ASCII
 * 
 * affiche la cart en ascii 1 par 1
*/
void Carte::afficherASCII() const
{
    static const char* symboles[] = { "♥", "♦", "♣", "♠" };
    static const char* valeursCourtes[] = 
    {
        "", "", "2", "3", "4", "5", "6", "7",
        "8", "9", "10", "V", "D", "R", "A"
    };

    std::string v = valeursCourtes[(int)valeur];
    std::string s = symboles[(int)couleur];

    std::string left  = v + std::string(2 - v.size(), ' ');
    std::string right = std::string(2 - v.size(), ' ') + v;

    std::cout << "┌─────────┐\n";
    std::cout << "│ " << left  << "      │\n";
    std::cout << "│         │\n";
    std::cout << "│    " << s << "    │\n";
    std::cout << "│         │\n";
    std::cout << "│      " << right << " │\n";
    std::cout << "└─────────┘\n";
}

