#define N
#define M
#include "deplacement.h"
#include "personnage.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {int contenuCase;}t_case;
typedef struct {int x; int y;}t_posJoueur;
typedef struct {t_case grille[N][M];t_posJoueur coordonnées}t_carte;

typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_stats;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;

typedef struct {char nom[20]; int niveau; t_stats statistique; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;




void main(){
	int i;
	do{
		/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Nouvelle partie\n");
		printf(" 2 - Charger partie\n");
		printf(" 3 - Test deplacement\n");
		printf(" 4 - Test generation salles\n");
		printf(" 5 - Initialiser Joueur\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix){	
			case 1: printf("Pas encore fais");break;
			case 2: printf("Pas encore fais");break;
			case 3: testDeplacer(); break;
			case 4: printf("Pas encore fais");break;
			case 5: PersonnageTester(); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}while(choix!=6);
	
}
