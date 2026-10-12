#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Joueur.hpp"
#include "Ennemi.hpp"
#include "Plateau.hpp"
#include "Hand.hpp"
#include "Carte.hpp"
#include "Combat.hpp"
#include "Objet.hpp"
#include "GameManager.hpp"


int main()
{
    std::srand(std::time(nullptr));
    GameManager game;
    game.initParti();
    game.lancerParti();
    return 0;
}


/*
int main()
{
    // Création d'un chevalier
    Chevalier c(0);

    // Ajouter des objets à l'inventaire
    c.ajouterObjet(Objet(Type::DoubleMise));
    c.ajouterObjet(Objet(Type::BonusJetons));
    c.ajouterObjet(Objet(Type::Defausse));

    // Afficher l'inventaire
    c.afficherInventaire();

	c.enleverObjet(1);
	
	c.afficherInventaire();
	
    return 0;
}

*/

/*
int main()
{
    std::srand(std::time(nullptr));

    Chevalier joueur(1);
    Gobelin ennemi(2);

    Combat combat(joueur, ennemi);
    combat.lancerCombat();

    std::cout << "\n=== FIN DU PROGRAMME ===\n";
    return 0;
}
*/
