/**
*	\file combat.c
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/
#include "../inc/general.h"


/** \fn void PersonnagePositionner(t_carte * carte)
*   \brief Cherche un endroit pour placer le personnage dans une salle
*   \param carte La carte du jeu
*   \return Rien
*/
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

/** \fn void PersonnageInitialiser(t_personnage * perso)
*   \brief Initialise les parametres de la variable perso
*   \param perso Le personnage
*   \return Rien
*/
void PersonnageInitialiser(t_personnage * perso){
	char pseudo[20];
	
    printf("\nCréation Personnage\n");
    
	printf("Pseudo : ");
	scanf("%20s", pseudo);
	
    strcpy(perso->nom, pseudo);
    printf("%s",  perso->nom);
    
	perso->experience.niveau=0;
	perso->experience.xp=0;
	perso->experience.xpRequis=50;// Initialisation de l'experience
	
	perso->caract.vitalite=100;
	perso->caract.force=2;
	perso->caract.agilite=10;// initialisation des caracteristiques
	
	perso->stats.vie=perso->caract.vitalite;
	perso->stats.score=0;// Initialisation des statistiques;
	
	if(!strcmp(pseudo,"Marvin")){
		perso->caract.vitalite=420;
		perso->stats.vie=420;
		perso->caract.force=42;
		perso->caract.agilite=90;
	}
	
	
	
    
    printf("Fin Creation Personnage\n\n");
}

/** \fn void PersonnageAfficherPseudo(t_personnage player)
*   \brief Affiche le pseudo en couleur du player 
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherPseudo(t_personnage player){
	color(6, player.nom);
}

/** \fn void PersonnageAfficherNiveau(t_personnage player)
*   \brief Affiche le niveau en couleur du player
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherNiveau(t_personnage player){
	char niveau[10];
	sprintf(niveau, "%i", player.experience.niveau);
	color(6, niveau);

}

/** \fn void PersonnageAfficherVie(t_personnage player)
*   \brief Affiche la vie en couleur du player
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherVie(t_personnage player){
	char vie[10];
	int couleur;
	
	if(player.stats.vie >= player.caract.vitalite / 2) {
		couleur = 2; //Vert
	} else if(player.stats.vie >= player.caract.vitalite / 4) {
		couleur = 3; //Cyan
	} else {
		couleur = 1;
	}
	
	sprintf(vie, "%i", player.stats.vie);
	color(couleur, vie);
}

/** \fn void PersonnageAfficherVieMax(t_personnage player)
*   \brief Affiche la vitaité en couleur du player
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherVieMax(t_personnage player){
	char vitalite[10];
	sprintf(vitalite, "%i", player.caract.vitalite);
	color(2, vitalite);
}

/** \fn void PersonnageAfficherScore(t_personnage player)
*   \brief Affiche le score en couleur du player
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherScore(t_personnage player){
	char score[10];
	sprintf(score, "%i", player.stats.score);
	color(6, score);
}

/** \fn void PersonnageAfficherXP(t_personnage player)
*   \brief Affiche l'xp en couleur du player
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherXP(t_personnage player){
	char xp[10];
	sprintf(xp, "%i", player.experience.xp);
	color(6, xp);
}

/** \fn void PersonnageAfficherXpRequis(t_personnage player)
*   \brief Affiche l'xp requis en couleur du player
*   \param player Le personnage
*   \return Rien
*/
void PersonnageAfficherXpRequis(t_personnage player){
	char xpRequis[10];
	sprintf(xpRequis, "%i", player.experience.xpRequis);
	color(6, xpRequis);
}

/** \fn void PersonnageAfficher(t_personnage perso)
*   \brief Affiche les parametre du player
*   \param perso Le personnage
*   \return Rien
*/
void PersonnageAfficher(t_personnage perso){
	printf("| Pseudo : ");
	PersonnageAfficherPseudo(perso);
	
	printf(" | Niveau : ");
	PersonnageAfficherNiveau(perso);
	
	printf(" | Vie : ");
	PersonnageAfficherVie(perso);
	printf("/");
	PersonnageAfficherVieMax(perso);
	
	printf(" | Score : ");
	PersonnageAfficherScore(perso);
	
	printf(" | XP : ");
	PersonnageAfficherXP(perso);
	
	printf("/");
	PersonnageAfficherXpRequis(perso);
	printf(" |\n");    
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

/** \fn void PersonnageLevelUp(t_personnage * player)
*   \brief Fait passer le player d'un niveau et increment ses paramètres
*   \param player Le personnage
*   \return Rien
*/
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
