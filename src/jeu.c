//
//  jeu.c
//  
//
//  Created by Jean Marvin on 27/11/2015.
//
//

#include "../inc/general.h"

void JeuAmorcer(){

}

void Jeutester(){
    
}

void JeuCommencer(){
    int idMob=-1;
    
    t_carte carte;
    t_personnage personnage;
    
    int etage;
    int monstrePuissance;
    
    carte = CarteCharger();
    
    carte.etage=1;
    carte.monstrePuissance=2;
    
    PersonnagePositionner(&carte);
    MonstrePositionner(&carte, carte.monstrePuissance);
    
    PersonnageInitialiser(&personnage);
    
    while(!CheckTestPersonnage(personnage)){
        
        CarteAfficher(carte);
		idMob=DeplacementMarcher(&carte);
        
        if(CheckEscalier(carte.cord.x, carte.cord.y, carte)==1)
        {
            etage=carte.etage;
            monstrePuissance=carte.monstrePuissance;
            
            carte = CarteCharger();
            
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
            CarteAfficher(carte);
            idMob=DeplacementMarcher(&carte);
        }
        
        printf("Vie : %i\n", personnage.stats.vie);
        printf("Etage : %i\n", carte.etage);
        printf("Score : %i\n", personnage.stats.score);
        
		if(idMob != -1){
		    	CombatTaper(&personnage,&carte,idMob);
		    	MonstreMort(&carte);
		}
        
		MonstreDeplacement(&carte,&personnage);
    }
    system("clear");
    PersonnageAfficherPseudo(personnage);
    printf(" est mort. Paix à son ame");
}
