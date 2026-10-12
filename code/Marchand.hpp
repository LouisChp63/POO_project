#ifndef MARCHAND_HPP
#define MARCHAND_HPP

#include "Objet.hpp"
#include <vector>
#include <iostream>
#include "def.hpp"

class Joueur;

class Marchand
{
private:
    std::vector<Objet> stock;

public:
    Marchand();
    ~Marchand();

    void ajouterObjet(const Objet& obj);
    void enleverObjet(int index);

    void afficherStock() const;
    void interagir(Joueur& joueur);
};

#endif
