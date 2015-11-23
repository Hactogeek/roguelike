typedef struct {int vie; int score;}t_stats;

typedef struct {char nom[20]; int niveau; t_stats statistique; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

void PersonnageAmorcer(){

}

void PersonnageInitialiser(t_personnage perso){
	char pseudo[20];
	
	printf("Création du Personnage\n");
	
	printf("Pseudo : ");
	scanf("%20s", pseudo);
	 
	strcmp(perso.nom, pseudo);
	perso.niveau=0;
	perso.statistique.vie=3;
	perso.statistique.score=1;
}

void PersonnageTester(int test){
	t_personnage perso;
	switch(test){
		case 1: PersonnageInitialiser(perso); break;
	}
	
}
