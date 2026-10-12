#ifndef DEF_HPP
#define DEF_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>   


// Ce fichier contient tous les #define


/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *    Définitons du Jeux
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


#define dice_cost 						1			// coût du déplacement sur le plateau
#define TailleMain						5			// Taille des mains (à ne pas changer svp)
#define PourcentageEnnemi				50			// Pourcentage de cases ennemies
#define PourcentageObjet				20			// Pourcentage de cases objets
#define TaillePlateau					40			// taille du plateau
#define	DeclanchementChance				5			// valeur pour laquelle on peut utiliser Chance
#define TauxDeMiseEnnemi				4			// A quel point les ennemis misent (100=peu,4=plus) 
#define PrixObjet						15			// Prix des objet 
#define	SommeCible						20			// Somme de jetons nécessaire à la fin du jeu
#define PerteCouche						7			// Nombre de $ perdu lorsque que l'on se couche

		
// note : l'esperance du nombre d'ennemi est de PourcentageEnnemi*TaillePlateau/100, de même pour les objets

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *    Définitons des joeurs
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */   

// Chevalier 

#define ChevalierJetons					10
#define ChevalierChance					1
#define ChevalierDollars				25
#define ChevalierDefausse				2
#define ChevalierJeu					(new JeuStandard())

// Reine rouge

#define ReineJetons						7
#define ReineChance						2
#define ReineDollars					30
#define ReineDefausse					3
#define ReineJeu						(new JeuRouge())

// Voleuse 

#define VoleuseJetons					15
#define VoleuseChance					0
#define VoleuseDollars					15
#define VoleuseDefausse					2
#define VoleuseJeu						(new JeuVoleuse())

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *    Définitons des ennemis
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */   
 
// Gobelin 

#define GobelinJetons					4
#define GobelinGreed					7 
#define GobelinDollars					5
#define GobelinSpawnRate				30

// Orc

#define OrcJetons						8
#define OrcGreed						4 
#define OrcDollars						4
#define OrcSpawnRate					20+GobelinSpawnRate		// en %

// LArry

#define LarryJetons						15
#define LarryGreed						10
#define LarryDollars					20
#define LarrySpawnRate					10+OrcSpawnRate			// en %


#define TotalSpawnRate					(LarrySpawnRate)

#endif

