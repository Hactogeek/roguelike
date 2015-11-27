#include "../inc/general.h"

void PersonnageAmorcer(){

}

void PersonnageInitialiser(t_personnage * perso){
	char pseudo[20];
	
    Appel0("PersonnageInitialiser");
    printf("\nCréation Personnage\n");
    
	printf("Pseudo : ");
	scanf("%20s", pseudo);
	 
    strcpy(perso->nom, pseudo);
    
	perso->niveau=0;
	perso->stats.vie=3;
	perso->stats.score=1;
    
    printf("Fin Creation Personnage\n\n");
    Appel1("PersonnageInitialiser");
}

void PersonnageAfficher(t_personnage * perso){
	
    Appel0("PersonnageAfficher");
    
    printf("\nVotre Personnage\n");
	
	printf("|Pseudo	|Niveau	|Vie	|Score	|\n");
	printf("|	%s	|	%i	|	%i	|	%i	|\n\n", perso->nom, perso->niveau, perso->stats.vie, perso->stats.score);
    
    Appel1("PersonnageAfficher");
}

void PersonnageSauvegarder( t_personnage * perso){
    FILE * PersoSauvegarde;
    
    Appel0("PersonnageSauvegarder");
    
    PersoSauvegarde = fopen("save/persosauvegarde", "w");
    
    fprintf(PersoSauvegarde, "@%s_%i_%i_%i@", perso->nom, perso->niveau, perso->stats.vie, perso->stats.score);
    
    fclose(PersoSauvegarde);
    
    Appel1("PersonnageSauvegarder");
}

void PersonnageTester(){
	int test;
	t_personnage perso;
    
    printf("PersonnageTester : \n\n");
    
    do{
        printf("\nMenu :\n");
        printf(" 1 - Initialiser Personnage\n");
        printf(" 2 - Afficher Personnage\n");
        printf(" 3 - Sauvegarder Personnage\n");
        printf(" 6 - Quitter\n\n");
        
        printf("Votre choix :");
        scanf("%i", &test);
        
        switch(test){
            case 1: PersonnageInitialiser(&perso); break;
            case 2: PersonnageAfficher(&perso); break;
            case 3: PersonnageSauvegarder(&perso); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
	
}
