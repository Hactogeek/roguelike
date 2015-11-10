#ifndef FONCTION_H
#define FONCTION_H

#include<stdio.h>
#include<string.h>
#define N 50

/* Définition du type date (jour, mois, année) */
typedef struct { int jour, mois, an; } t_date;

/* Définition du type sexe avec la convention INSEE */
typedef enum { homme = 1, femme } t_sexe;

/* Définition du type personne (prénom, sexe, date de naissance) */
typedef struct { char prenom[20] ; t_sexe sexe ; t_date naissance ; } t_personne ;

int concatenation_j(int annee,int mois,int j);
void afficher_base(t_personne* amis, int nb_amis);
void afficher_nombre_fh(t_personne* amis, int nb_amis);
void afficher_cadet(t_personne* amis, int nb_amis);
void afficher_anniv(t_personne* amis, int nb_amis);	
void ajouter_personne(t_personne* amis, int* nb_amis);

#endif
