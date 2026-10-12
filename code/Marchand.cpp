#include "Marchand.hpp"
#include "Joueur.hpp"
#include <iostream>


// on met tous les objets chez le marchand
Marchand::Marchand()
{
    stock.push_back(Objet(Type::DoubleMise));
    stock.push_back(Objet(Type::Apoil));
    stock.push_back(Objet(Type::BonusJetons));
    stock.push_back(Objet(Type::Fois2Dollars));
    stock.push_back(Objet(Type::Defausse));
}

Marchand::~Marchand() {}

void Marchand::ajouterObjet(const Objet& obj)
{
    stock.push_back(obj);
}

void Marchand::enleverObjet(int index)
{
    if (index >= 0 && index < (int)stock.size()) stock.erase(stock.begin() + index);
}

void Marchand::afficherStock() const
{
    std::cout << "\n=== MARCHAND ===\n";
    
    for (size_t i = 0; i < (stock.size()); i++)
    {
        std::cout << i << " - " << stock[i].toString()
                  << " (prix: " << PrixObjet << " dollars)\n";
    }
    std::cout << "-1 - Quitter\n";
}

void Marchand::interagir(Joueur& joueur)
{
    if (stock.empty())
    {
        std::cout << "Le marchand n'a plus rien à vendre.\n";
        return;
    }

    int choix = 0;

    while (true)
    {
        afficherStock();
        std::cout << "Vos dollars : " << joueur.getDollars() << "\n";
        std::cout << "Choisissez un objet : (-1 pour quitter)";
        std::cin >> choix;

        if (choix == -1)
        {
            std::cout << "Vous quittez le marchand.\n";
            return;
        }

        if (choix < 0 || choix >= (int)stock.size())
        {
            std::cout << "Choix invalide.\n";
        }

        if (joueur.getDollars() < PrixObjet)
        {
            std::cout << "Pas assez de jetons !\n";
            return;
        }

        // Achat
        joueur.ajouterDollars(-PrixObjet);
        joueur.ajouterObjet(stock[choix]);

        std::cout << "Vous avez acheté : "
                  << stock[choix].toString() << "\n";

        enleverObjet(choix);
    }
}
