typedef struct {int contenuCase;}t_case;
typedef struct {int x; int y;}t_posJoueur;
typedef struct {t_case grille[N][M];t_posJoueur cord}t_carte;

typedef struct {int vitalite; int force; int agilite;}t_caracteristique;
typedef struct {int vie; int score;}t_stats;
typedef struct {int arme; int armure;}t_equip;
typedef struct {int aReflechir;}t_inv;

typedef struct {char nom[20]; int niveau; t_stats statistique; t_caracteristique caract; t_equip equipement; t_inv inventaire;}t_personnage;

typedef struct {int seed;  t_personnage perso; int difficulte;}t_partie;


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
