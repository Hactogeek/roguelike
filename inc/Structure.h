//
//  Structure.h
//  
//
//  Created by Jean Marvin on 27/11/2015.
//
//

#ifndef _Structure_h
#define _Structure_h
#define SALLES_MAX_X    2
#define SALLES_MAX_Y    5
#define TAILLE_SALLE_X  15
#define TAILLE_SALLE_Y  15
#define TAILLE_CARTE_X  TAILLE_SALLE_X * SALLES_MAX_X
#define TAILLE_CARTE_Y  TAILLE_SALLE_Y * SALLES_MAX_Y
#define SALLES_MAX      SALLES_MAX_X * SALLES_MAX_Y
#define NB_MAX_MONSTRE 20



typedef struct {int x; int y;}t_posMonstre;
typedef struct {t_posMonstre monstrePos; int monstreVie; int puissance;}t_monstre;

typedef struct {int x; int y;}t_posJoueur;

typedef struct {int grille[TAILLE_CARTE_X][TAILLE_CARTE_Y];t_posJoueur cord; /*t_posMonstre*/ t_monstre monstre[NB_MAX_MONSTRE];}t_carte;

typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_statistique;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;
typedef struct {int niveau;int xpRequis;int xp} t_experience
typedef struct {char nom[20];t_experience experience; t_statistique stats; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;

#endif
