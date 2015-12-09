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

void JeuCommencer(t_carte * carte){
    int i=0;
    Appel0("JeuCommencer");
    PersonnagePositionner(carte);
    while(i!=100){
    	system("clear");
	CarteAfficher(*carte);
        DeplacementMarcher(carte); 
        
        i++;
    }
    Appel1("JeuCommencer");
}
