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
    
    carte = CarteCharger();
    PersonnagePositionner(&carte);
    MonstrePositionner(&carte);
    
    PersonnageInitialiser(&personnage);
    
    while(!CheckTestPersonnage(personnage)){
        
        CarteAfficher(carte);
		idMob=DeplacementMarcher(&carte);
        
        if(CheckEscalier(carte.cord.x, carte.cord.y, carte)==1)
        {
            carte = CarteCharger();
            PersonnagePositionner(&carte);
            MonstrePositionner(&carte);
            CarteAfficher(carte);
            idMob=DeplacementMarcher(&carte);
        }
        
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
