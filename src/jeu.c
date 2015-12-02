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
        while(i!=5){
            DeplacementMarcher(carte);
            CarteAfficher(carte);
            i++;
        }
    

}
