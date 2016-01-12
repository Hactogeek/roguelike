#include "../inc/general.h"

void JeuAmorcer(){

}

void Jeutester(){
    
}

void JeuCommencer(){
	printf(CLEAR_SC);
	char action;
	int actionValide = 0;
    int idMob=-1;
    
    t_carte carte;
    t_personnage personnage;
    
    carte = CarteCreer();
    
    carte.etage=1;
    carte.monstrePuissance=2;
    
    PersonnagePositionner(&carte);
    MonstrePositionner(&carte, carte.monstrePuissance);
    
    PersonnageInitialiser(&personnage);
    personnage.stats.score=0;
    
    JeuContinuer(&carte, &personnage);
}

void EtageChanger(t_carte * carte, t_personnage * personnage) {
	//Tampons
	int etage = 0;
	int monstrePuissance = 0; 
	etage = carte->etage;
	monstrePuissance = carte->monstrePuissance;
	
    carte->escalierVu = 0;
    *carte = CarteCreer();
    
    etage++;
    if(carte->etage%2==0) {
        monstrePuissance++;
    }
    
    carte->etage = etage;
    carte->monstrePuissance = monstrePuissance;
    //printf("monstrePuissance : %i", monstrePuissance);
    
    personnage->stats.score+=500;
    PersonnagePositionner(carte);
		    
    MonstrePositionner(carte, carte->monstrePuissance);
}

void JeuContinuer(t_carte * carte, t_personnage * personnage) {
	char action;
	int actionValide = 0;
    int idMob=-1;
    int i;
    
    while(!CheckTestPersonnage(*personnage)){
		printf(CLEAR_SC);
		
		if(CheckTestEtage(*carte)) {
			EtageChanger(carte, personnage);
		}
		
		PersonnageAfficher(*personnage);
		CarteAfficher(carte);
		printf("Dernier evenement : %s\n", carte->dernierEvenement);
		strcpy(carte->dernierEvenement, "");
		do {
			printf("Entrez votre prochaine action ou deplacement : ");
			scanf(" %c", &action);
			actionValide = 1;
			switch(action) {
				case 's' : 	idMob = DeplacementMarcher(1, carte); break;
				case 'q' : 	idMob = DeplacementMarcher(2, carte); break;
				case 'z' : 	idMob = DeplacementMarcher(3, carte); break;
				case 'd' : 	idMob = DeplacementMarcher(4, carte); break;
				
				case 'a' : 	Sauvegarde(*carte, *personnage); break;
				
				default : actionValide = 0;
			}
		} while(!actionValide);
		

		if(idMob != -1){
			CombatTaper(personnage,carte,idMob);
			MonstreMort(carte);
		}
		

		MonstreDeplacement(carte,personnage);
	}
	
	printf(CLEAR_SC);
    PersonnageAfficherPseudo(*personnage);
    printf(" est mort. Paix à son ame");
}

void JeuCharger() {
	FILE * sauvegarde;
	sauvegarde = fopen("save/save.txt", "r");
	t_carte carte;
	t_personnage personnage;
	
	if(sauvegarde != NULL) {
		Charger(&carte, &personnage, sauvegarde);
		fclose(sauvegarde);
		JeuContinuer(&carte, &personnage);
	} else {
		printf("Aucune sauvegarde n'est disponible");
	}
}
