#define N 10
#define M 10
//#include "../inc/deplacement.h"
#include "../inc/personnage.h"
#include "../inc/Outil.h"

/*typedef struct {int contenuCase;}t_case;
typedef struct {int x; int y;}t_posJoueur;
typedef struct {t_case grille[N][M];t_posJoueur cord}t_carte;*/

/*typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_stats;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;
typedef struct {char nom[20]; int niveau; t_stats statistique; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;*/

//typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;




int main(){
	int choix;
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
			case 3: /*testDeplacer()*/; break;
			case 4: /*CarteTester(1)*/; break;
			case 5: PersonnageTester(); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}while(choix!=6);
    return 0;
}
