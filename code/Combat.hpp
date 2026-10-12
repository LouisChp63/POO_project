#ifndef COMBAT_HPP
#define COMBAT_HPP


#include "Joueur.hpp"
#include "Ennemi.hpp"
#include "Hand.hpp"



class Combat
{
	private :
		// par ef et non par recopie on veut agir sur l'nique joeur (et les uniques ennemis)
		Joueur& joueur;
		Ennemi& ennemi;
		
		int miseJoueur;
		int miseEnnemi;
		int miseTotale;
		int miseNombre;
		int def;
		int chance;
		
		int resultatCombat;
		bool combatTermine;
		bool joueurCouche;
		bool ennemiCouche;
		
		void initCombat();
		void tourEnnemi();
		void tourJoueur();
		void evaluerResultat();			
		void resetCombat();
		
	public :
	
		virtual ~Combat(){}
		
		Combat(Joueur& j, Ennemi& e);
		
		void lancerCombat();
		
		void miser(int mise);
		void demanderDefausse();
		void utiliserObj();
		void utiliserChance();
		void seCoucher();
		

		void finCombat(int resultat);
		

};


#endif

