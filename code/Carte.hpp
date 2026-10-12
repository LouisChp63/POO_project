#ifndef CARTE_HPP
#define CARTE_HPP

#include <string>

enum class Couleur
{
    Coeur,
    Carreau,
    Trefle,
    Pique
};

enum class Valeur
{
    Deux 	= 2,
    Trois	= 3,
    Quatre	= 4,
    Cinq	= 5,
    Six		= 6,
    Sept	= 7,
    Huit	= 8,
    Neuf	= 9,
    Dix		= 10,
    Valet	= 11,
    Dame	= 12,
    Roi		= 13,
    As 		= 14
};

class Carte
{
	private:
	    Valeur valeur;
	    Couleur couleur;

	public:
	    Carte(Valeur v, Couleur c);
	    
	    // création de l'opérateur '==' pour tester les égalités other car on compare 2 cartes, const car opérateur de test
    	bool operator==(const Carte& other) const;
    	
    	// création de l'opérateur '>' pour trier
    	bool operator>(const Carte& other) const;
    	// création de l'opérateur '<' pour trier
    	bool operator<(const Carte& other) const;

		// getters

	    Valeur getValeur() const;
	    Couleur getCouleur() const;
		int getValeurInt() const;

		// pour avoir le beau rendu visuel :)

	    void afficherASCII() const;
	    
	    virtual ~Carte();
};

#endif

