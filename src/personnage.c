#include "general.h"

void PersonnageAmorcer(){

}

void PersonnageInitialiser(t_personnage perso){
	char pseudo[20];
	
	printf("Création du Personnage\n");
	
	printf("Pseudo : ");
	scanf("%20s", pseudo);
	 
	strcmp(perso.nom, pseudo);
	perso.niveau=0;
	perso.stats.vie=3;
	perso.stats.score=1;
}

void PersonnageAfficher(t_personnage perso){
	printf("Votre Personnage\n");
	
	printf("|Pseudo	|Niveau	|Vie	|Score	|\n");
	printf("|	%s	|	%i	|	%i	|	%i	|\n", perso.nom, perso.niveau, perso.stats.vie, perso.stats.score);
}

void PersonnageTester(/*int test*/){
	int test;
	t_personnage perso;
	scanf("%i", &test);
	switch(test){
		case 1: PersonnageInitialiser(perso); break;
		case 2: PersonnageAfficher(perso); break;
	}
	
}
