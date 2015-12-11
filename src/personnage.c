#include "../inc/general.h"

void PersonnageAmorcer(){

}

//Cherche un endroit pour placer le personnage dans une salle
void PersonnagePositionner(t_carte * carte){
	int bienPlace=0,x,y;
	srand(time(NULL));
	do{
		x=uHasard(TAILLE_CARTE_X);
		y=uHasard(TAILLE_CARTE_Y);
		
		}while(!CheckSalle(x,y,*carte));
			carte->cord.x=x;
			carte->cord.y=y;	
	printf("Position du personnage positionner : %i %i\n",carte->cord.x,carte->cord.y);
}

void PersonnageInitialiser(t_personnage * perso){
	char pseudo[20];
	
    printf("\nCréation Personnage\n");
    
	printf("Pseudo : ");
	scanf("%20s", pseudo);
	 
    strcpy(perso->nom, pseudo);
    
	perso->experience.niveau=0;
	perso->stats.vie=20;
	perso->stats.score=1;
	perso->caract.force=2;
    
    printf("Fin Creation Personnage\n\n");
}

void PersonnageAfficher(t_personnage * perso){
	
    Appel0("PersonnageAfficher");
    
    printf("\nVotre Personnage\n");
	
	printf("|Pseudo	|Niveau	|Vie	|Score	|\n");
	printf("|	%s	|	%i	|	%i	|	%i	|\n\n", perso->nom, perso->experience.niveau, perso->stats.vie, perso->stats.score);
    
    Appel1("PersonnageAfficher");
}

void PersonnageSauvegarder( t_personnage * perso){
    FILE * PersoSauvegarde;
    
    Appel0("PersonnageSauvegarder");
    
    PersoSauvegarde = fopen("save/persosauvegarde", "w");
    
    fprintf(PersoSauvegarde, "@%s_%i_%i_%i@", perso->nom, perso->experience.niveau, perso->stats.vie, perso->stats.score);
    
    fclose(PersoSauvegarde);
    
    Appel1("PersonnageSauvegarder");
}

void PersonnageCharger(t_personnage * perso)
{
    char pseudo[20];
    int niveau, vie, score;
    
    FILE * PersoSauvegarde;
    
    Appel0("PersonnageCharger");
    
    PersoSauvegarde = fopen("save/persosauvegarde", "r");
    
    if(PersoSauvegarde!=NULL)
     {
        fscanf(PersoSauvegarde, "%s", pseudo);
        fscanf(PersoSauvegarde, "%i", &niveau);
        fscanf(PersoSauvegarde, "%i", &vie);
        fscanf(PersoSauvegarde, "%i", &score);
        
        strcpy(perso->nom, pseudo);
        
        perso->experience.niveau=niveau;
        perso->stats.vie=vie;
        perso->stats.score=score;
        
        fclose(PersoSauvegarde);
     }
    else
        printf("Aucune sauvegarde de personnage a ete faite avant\n");
    
    Appel1("PersonnageCharger");
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
        printf(" 4 - Charger Personnage\n");
        printf(" 6 - Quitter\n\n");
        
        printf("Votre choix :");
        scanf("%i", &test);
        
        switch(test){
            case 1: PersonnageInitialiser(&perso); break;
            case 2: PersonnageAfficher(&perso); break;
            case 3: PersonnageSauvegarder(&perso); break;
            case 4: PersonnageCharger(&perso); break;
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
	
}
void PersonnageLevelUp(t_personnage * player){
	
	player->experience.niveau+=1;
	player->experience.xp-=player->experience.xpRequis;
	player->experience.xpRequis*=1.2;
}

void PersonnageAfficherPseudo(t_personnage player){
	int taille=strlen(player.nom),i;
	for(i=0;i<taille;i++){
		printf("%c",player.nom[i]);
	}

}
