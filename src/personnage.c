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
		
		}while(!CheckSalle(x,y,*carte));// Crée des position tant que le personnage n'est pas dans une salle
			carte->cord.x=x;
			carte->cord.y=y;// Une fois que c'est bon les coordonné sont affecté	
}

void PersonnageInitialiser(t_personnage * perso){
	char pseudo[20];
	
    printf("\nCréation Personnage\n");
    
	printf("Pseudo : ");
	scanf("%20s", pseudo);
	
    strcpy(perso->nom, pseudo);
    
	perso->experience.niveau=0;
	perso->experience.xp=0;
	perso->experience.xpRequis=50;// Initialisation de l'experience
	
	perso->caract.vitalite=100;
	perso->caract.force=2;
	perso->caract.agilite=10;// initialisation des caracteristiques
	
	perso->stats.vie=perso->caract.vitalite;
	perso->stats.score=0;// Initialisation des statistiques;
	
	
	
    
    printf("Fin Creation Personnage\n\n");
}

void PersonnageAfficherPseudo(t_personnage player){
	int taille=strlen(player.nom),i;
	for(i=0;i<taille;i++){
		printf("%c",player.nom[i]);
	}

}

void PersonnageAfficherNiveau(t_personnage player){
	char[2] niveau;
	sprintf(player.experience.niveau, niveau);
	color(7, niveau);

}

void PersonnageAfficherVie(t_personnage player){
	char[2] niveau;
	sprintf(player.experience.niveau, niveau);
	color(7, player.experience.vie);
}

void PersonnageAfficherVieMax(t_personnage player){
	char[2] niveauMax;
	sprintf(player.experience.niveau, niveau);
	color(7, player.experience.vie);
}

void PersonnageAfficherScore(t_personnage player){
	color(7, player.experience.score);

}

void PersonnageAfficherXP(t_personnage player){
	color(7, player.experience.xp);
}

void PersonnageAfficherXpRequis(t_personnage player){
	color(7, player.experience.xpRequis);
}

void PersonnageAfficher(t_personnage perso){
	printf("|Pseudo: ");
	PersonnageAfficherPseudo(perso);
	
	printf(" |Niveau : ");
	PersonnageAfficherNiveau(perso);
	
	printf(" |Vie : ");
	PersonnageAfficherVie(perso);
	
	printf(" |Score : ");
	PersonnageAfficherScore(perso);
	
	printf(" |XP : ");
	PersonnageAfficherXP(perso);
	
	printf("/ ");
	PersonnageAfficherXpRequis(perso);
	//printf(" |Niveau : %i |Vie : %i/%i |Score : %i |Xp : %i/%i|\n\n",perso.experience.niveau, perso.stats.vie,perso.caract.vitalite, perso.stats.score,perso.experience.xp,perso.experience.xpRequis);
    
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
            case 2: PersonnageAfficher(perso); break;
            case 3: PersonnageSauvegarder(&perso); break;
            case 4: PersonnageCharger(&perso); break;
            case 6: printf(""); break;
            default : printf("Erreur votre choix doit etre compris entre 1 et 6\n");
        }
    }while(test!=6);
	
}
void PersonnageLevelUp(t_personnage * player){
	int gainVita=0, gainForce=0, gainAgi=0;
	
	player->experience.niveau+=1;
	player->experience.xp-=player->experience.xpRequis;
	player->experience.xpRequis*=1.2;// Gestion de l'xp lors du level up
	
	gainVita = nHasard(4)+5;//Gain aleatoire entre 5 et 8 pdv
	gainForce = nHasard(2)+1;
	gainAgi = nHasard(2)+1;//Gain aleatoire entre 1 et 2
	player->caract.vitalite += gainVita;
	player->caract.force += gainForce;
	player->caract.agilite += gainAgi;// Gestion du gain de stats lors du level up
	
	player->stats.vie = player->caract.vitalite;//Le joueur regenere sa vie lors du level up
	player->stats.score += 1000;//Lorsque le joueur level up il gagne du score
	
	printf("Le joueur est passé au niveau %i !\n",player->experience.niveau);
}
