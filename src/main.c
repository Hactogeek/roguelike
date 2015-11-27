#include "../inc/general.h"

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
        printf(" 6 - Quitter\n");
        
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix){	
			case 1: printf("Pas encore fais");break;
			case 2: printf("Pas encore fais");break;
            case 3:{
                t_carte carte;
                CarteCharger(carte);
                JeuCommencer(carte);
                break;

            }
            case 4: CarteTester(1); break;
			case 5: PersonnageTester(); break;
            case 6: printf("Au Revoir\n"); break;
			default: printf("Erreur: votre choix doit etre compris entre 1 et 6\n");
		}
	}while(choix!=6);
    
    return 0;
}
