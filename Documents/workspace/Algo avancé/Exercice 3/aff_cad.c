#include "fonction.h"

/* affiche la plus jeune de la base de donnée*/
void afficher_cadet(t_personne* amis, int nb_amis)
{
	int i,min =-1,indice_min=-1,tempo;
	for( i = 0; i< nb_amis; i++){
		tempo = concatenation_j(amis[i].naissance.an, amis[i].naissance.mois, amis[i].naissance.jour);
		if(tempo > min){
			 indice_min = i;
			 min = tempo;
		 }
	}
	printf("Le plus jeune est %s. \n",amis[indice_min].prenom);
}
