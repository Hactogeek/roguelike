#include "fonction.h"

void ajouter_personne(t_personne* amis, int* nb_amis)
{	
	int saisie_sexe;
	t_personne saisie_personne;
	
	printf("Veuillez saisir le nom de la personne : ");
	scanf("%s",saisie_personne.prenom);
	printf("Veuillez saisir le sexe de la personne (1 homme / 2 femme) : ");
	scanf("%i",&saisie_sexe);
	if(saisie_sexe == 1) {
		saisie_personne.sexe = homme;
	}else if (saisie_sexe == 2){
		saisie_personne.sexe = femme;
	}else {
		printf("vous avez mis un sexe incorrect, c'est maintenant ton probleme. ");
	}
	
	printf("Veuillez saisir sa date de naissance jj/mm/aaaa : ");
	scanf("%i%i%i",&(saisie_personne.naissance.jour),&(saisie_personne.naissance.mois),&(saisie_personne.naissance.an));
	amis[*nb_amis] = saisie_personne;
	*nb_amis= *nb_amis +1;
	
}
