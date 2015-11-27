//
//  Structure.h
//  
//
//  Created by Jean Marvin on 27/11/2015.
//
//

#ifndef _Structure_h
#define _Structure_h

typedef struct {int contenuCase;}t_case;
typedef struct {int x; int y;}t_posJoueur;
typedef struct {t_case grille[N][M];t_posJoueur cord}t_carte;

typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_stats;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;

typedef struct {char nom[20]; int niveau; t_stats statistique; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;

#endif
