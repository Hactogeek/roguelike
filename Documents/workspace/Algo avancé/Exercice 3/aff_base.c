#include "fonction.h"

/*Affiche la base de donnés*/
void afficher_base(t_personne* amis, int nb_amis)
{
	int i;
	for( i = 0; i< nb_amis; i++){
		printf(" n° %i : %s ,", nb_amis, amis[i].prenom);
		if(amis[i].sexe == 1)printf("homme");
		else printf("femme");
		printf(" , %i / %i / %i . \n", amis[i].naissance.jour,amis[i].naissance.mois,amis[i].naissance.an);
		}
	
}
