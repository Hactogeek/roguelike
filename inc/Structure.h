/**
*	\file Structure.h
*	\brief  Structure utile au roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/


#ifndef _Structure_h
#define _Structure_h

#define SALLES_MAX_X    	2
#define SALLES_MAX_Y    	5
#define TAILLE_SALLE_X  	15
#define TAILLE_SALLE_Y  	15
#define TAILLE_CARTE_X  	TAILLE_SALLE_X * SALLES_MAX_X
#define TAILLE_CARTE_Y  	TAILLE_SALLE_Y * SALLES_MAX_Y
#define SALLES_MAX      	SALLES_MAX_X * SALLES_MAX_Y
#define NB_MAX_MONSTRE 		SALLES_MAX_X * SALLES_MAX_Y * 2
#define CLEAR_SC			"\e[1;1H\e[2J"
#define COULEUR_NORMALE		black
#define COULEUR_BROUILLARD	blue

/**
*	\struct t_posMonstre
*	\brief Position des monstres
*/
typedef struct {
	int x;
	int y;
} t_posMonstre;

/**
*	\struct t_monstre
*	\brief Position, Vie et puissance des monstres
*/
typedef struct {
	t_posMonstre monstrePos;
	int monstreVie;
	int puissance;
} t_monstre;

/**
*	\struct t_posJoueur
*	\brief Position du joueur
*/
typedef struct {
	int x;
	int y;
} t_posJoueur;

/**
*	\struct t_porte
*	\brief 
*/
typedef struct {
	int haut;
	int bas;
	int gauche;
	int droite;
} t_porte;

/**
*	\struct t_carte
*	\brief 
*/
typedef struct {
	int grille[TAILLE_CARTE_X][TAILLE_CARTE_Y];
	t_posJoueur cord;
	int nbMonstreCarte;
	t_monstre monstre[NB_MAX_MONSTRE];
	int etage;
	int monstrePuissance;
	t_porte porte[SALLES_MAX_X][SALLES_MAX_Y];
	int escalierVu;
	char dernierEvenement[100];
} t_carte;

/**
*	\struct t_caracteristique
*	\brief Vitalite, force et agilite du joueur
*/
typedef struct {
	int vitalite;
	int force;
	int agilite;
} t_caracteristique;

/**
*	\struct t_statistique
*	\brief Vie et score du joueur
*/
typedef struct {
	int vie;
	int score;
} t_statistique;

typedef struct {
	int arme;
	int armure;
} t_equip;

typedef struct {
	int aReflechir;
} t_inv;

/**
*	\struct t_experience
*	\brief Niveau, experience et experience prochain niveau du joueur
*/
typedef struct {
	int niveau;
	int xpRequis;
	int xp;
} t_experience;

/**
*	\struct t_personnage
*	\brief Experiencen statistique et caracteristique du joueur
*/
typedef struct {
	char nom[20];
	t_experience experience;
	t_statistique stats;
	t_caracteristique caract;
	t_equip equipement;
	t_inv inventaire;
} t_personnage;

typedef struct {
	int seed;
	t_personnage perso;
	int difficulte;
} t_partie;

#endif
