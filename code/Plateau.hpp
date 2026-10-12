#ifndef PLATEAU_HPP
#define PLATEAU_HPP

#include <vector>
#include "def.hpp"
#include "Objet.hpp" 


class Ennemi;

enum class CaseType
{
    Vide,
    Ennemi,
    Obj
};

class Plateau
{
	private:
		int taille;   // nombre de cases total
		std::vector<CaseType> cases;
		// liste des ennemi, en * car cela peux être des gobelins, orcs ect...
		std::vector<Ennemi*> ennemis;
		std::vector<Objet> objets; 

	public:

		Plateau(int t);
		virtual ~Plateau(); 	// à utiliser pr détruire les ennemis*
		
		int getTaille() const;
		const std::vector<Ennemi*>& getEnnemis() const;
		
		bool isValid(int position);
		
		// Pour lancer la logique de combat
		bool hasEnnemi(int position);
		
		bool hasObj(int position);
		
		void clearCase(int position);
		
		Ennemi* getEnnemi(int position);
    	Objet prendreObjet(int position);
};

#endif

