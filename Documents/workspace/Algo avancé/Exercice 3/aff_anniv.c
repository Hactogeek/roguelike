#include "fonction.h"
void afficher_anniv(t_personne* amis, int nb_amis)
{	
	char saisie_prenom[20];
	int i,resultat =0;
	printf("Saisir le prénom dont vous voulez la datede naissance : ");
	scanf("%s",saisie_prenom);
	for(i=0;i<N;i++){
		if(!strcmp(saisie_prenom,amis[i].prenom)){
			printf("%i / %i / %i \n", amis[i].naissance.jour,amis[i].naissance.mois,amis[i].naissance.an);
			resultat++;
		}
	}
	if(resultat ==0)printf("Il n'y a pas de %s dans la base",saisie_prenom);
}
