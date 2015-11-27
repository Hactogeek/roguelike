//
//  Structure.h
//  
//
//  Created by Jean Marvin on 27/11/2015.
//
//

#ifndef _Structure_h
#define _Structure_h

#define TAILLE_CARTE_X 10
#define TAILLE_CARTE_Y 10

typedef struct {int x; int y;}t_posJoueur;
typedef struct {int grille[TAILLE_CARTE_X][TAILLE_CARTE_Y];t_posJoueur cord;}t_carte;

typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_statistique;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;
typedef struct {char nom[20]; int niveau; t_statistique stats; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;

#endif
