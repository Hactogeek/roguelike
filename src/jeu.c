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
    
    int etage;
    int monstrePuissance;
    
    carte = CarteCreer();
    
    carte.etage=1;
    carte.monstrePuissance=2;
    
    PersonnagePositionner(&carte);
    MonstrePositionner(&carte, carte.monstrePuissance);
    
    PersonnageInitialiser(&personnage);
    personnage.stats.score=0;
    while(!CheckTestPersonnage(personnage)){
    	JeuContinuer(&carte, &personnage);      
        /*printf(CLEAR_SC);
        //Chargement d'un nouvel étage
        if(CheckEscalier(carte.cord.x, carte.cord.y, carte)) {
            etage=carte.etage;
            monstrePuissance=carte.monstrePuissance;
            
            carte.escalierVu = 0;
            carte = CarteCreer();
            
            carte.etage=etage+1;
            if(carte.etage%2==0)
            {
                carte.monstrePuissance=monstrePuissance+1;
            }
            else
            {
                carte.monstrePuissance=monstrePuissance;
            }    
            personnage.stats.score+=500;
            PersonnagePositionner(&carte);
           
            
            MonstrePositionner(&carte, carte.monstrePuissance);
           
        }
        
        PersonnageAfficher(personnage);
        CarteAfficher(&carte);
        printf("Dernier evenement : %s\n", carte.dernierEvenement);
        strcpy(carte.dernierEvenement, "");
        do {
        	printf("Entrez votre prochaine action ou deplacement : ");
        	scanf(" %c", &action);
        	actionValide = 1;
        	switch(action) {
        		case 's' : 	idMob = DeplacementMarcher(1, &carte); break;
        		case 'q' : 	idMob = DeplacementMarcher(2, &carte); break;
        		case 'z' : 	idMob = DeplacementMarcher(3, &carte); break;
        		case 'd' : 	idMob = DeplacementMarcher(4, &carte); break;
        		
        		case 'a' : 	Sauvegarde(carte, personnage); break;
        		
        		default : actionValide = 0;
        	}
        } while(!actionValide);
        
		if(idMob != -1){
		    	CombatTaper(&personnage,&carte,idMob);
		    	MonstreMort(&carte);
		}
        
		MonstreDeplacement(&carte,&personnage);*/
		
    }
    printf(CLEAR_SC);
    PersonnageAfficherPseudo(personnage);
    printf(" est mort. Paix à son ame");
}

void JeuContinuer(t_carte * carte, t_personnage * personnage) {
	char action;
	int actionValide = 0;
    int idMob=-1;
    
    int etage;
    int monstrePuissance;
    
	printf(CLEAR_SC);
    //Chargement d'un nouvel étage
    if(CheckEscalier(carte->cord.x, carte->cord.y, *carte)) {
        etage=carte->etage;
        monstrePuissance=carte->monstrePuissance;
        
        carte->escalierVu = 0;
        *carte = CarteCreer();
        
        carte->etage=etage+1;
        if(carte->etage%2==0)
        {
            carte->monstrePuissance=monstrePuissance+1;
        }
        else
        {
            carte->monstrePuissance=monstrePuissance;
        }    
        personnage->stats.score+=500;
        PersonnagePositionner(carte);
       
        
        MonstrePositionner(carte, carte->monstrePuissance);
       
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
