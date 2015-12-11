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

void JeuCommencer(t_carte * carte,t_personnage * player){
    int i=0,idMob=-1;
    PersonnagePositionner(carte);
    PersonnageInitialiser(player);
    MonstrePositionner(carte);
    while(CheckTestPersonnage(*player)){
		CarteAfficher(*carte);
		idMob=DeplacementMarcher(carte);
		if(idMob != -1){
		    	CombatTaper(player,carte,idMob);
		    	MonstreAttaque(player,carte,idMob);
		}
		i++;
    }
}
