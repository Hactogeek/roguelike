#include "fonction.h"

/* Compte le nbr d'homme et de femme et l'affiche*/
void afficher_nombre_fh(t_personne* amis, int nb_amis)
{	
	int i,nb_h =0 ,nb_f =0;
	for( i = 0; i< nb_amis; i++){
		if(amis[i].sexe == 1) nb_h++;
		else nb_f++;
	}
	printf("Il y a %i hommes et %i femmes. \n",nb_h,nb_f);
}
