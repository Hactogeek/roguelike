/* Menu du TP 2 - Base de donnees sur des personnes*/
#include "fonction.h"


/* Programme principal */
int main()
{	

	/* Déclaration de la base de données, de taille maximale 50 et de taille utile nb_amis */
	t_personne amis[N] = 
	{	{"Elodie", femme, {30, 5, 1991}}, 
		{"Julien", homme, {8, 12, 1992}}, 
		{"Chloé", femme, {2, 6, 1993}}, 
		{"Adrien", homme, {11, 1, 1990}}
	};
	int nb_amis = 4 ;

	int choix;	/* Choix de l'utilisateur */

	do
	{	/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Afficher le contenu de la base\n");
		printf(" 2 - Afficher le nombre d'hommes et de femmes\n");
		printf(" 3 - Afficher le prenom de la personne la plus jeune\n");
		printf(" 4 - Afficher les anniversaires d'un prenom\n");
		printf(" 5 - Ajouter une personne\n");
		printf(" 6 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix)
		{	case 1 : afficher_base(amis,nb_amis); break;
			case 2:  afficher_nombre_fh(amis,nb_amis); break;
			case 3:  afficher_cadet(amis,nb_amis); break;
			case 4:  afficher_anniv(amis,nb_amis); break;
			case 5:  ajouter_personne(amis,&nb_amis); break;
			case 6:  break;
			default: printf("Erreur: votre choix doit être compris entre 1 et 6\n");
		}
	}
	while(choix!=6);
	printf("Au revoir !\n");
	return 0;
}
