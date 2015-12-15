#include "../inc/general.h"

int main(){

	int choix,i,j ;    
	fflush(stdout);
	do{
		/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Nouvelle partie\n");
		printf(" 2 - Charger partie\n");
		printf(" 3 - Quitter\n");
		
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix){	
			case 1: JeuCommencer();break;
			case 2: printf("Pas encore fais");break;
			case 3: printf("Au Revoir\n"); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 3\n");
		}
	}while(choix!=3);
	
	return 0;
}
