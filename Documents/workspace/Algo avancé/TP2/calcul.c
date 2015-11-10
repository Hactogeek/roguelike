#include <stdio.h>
#include <stdlib.h>
#include "pile_tab.h"
#include <ctype.h>

int convertir(char c){
	return ((int)c-48);
}
void calcul_postfixe(void){
	char saisie;
	int a,b;

	do{
		printf("veuillez saisir un caractere : ");
		scanf(" %c",&saisie);
			if(isdigit(saisie)){
				depiler(&a);
				depiler(&b);
			}
			
			switch(saisie){
				case '+' : empiler(a+b);break;
				case '-' : empiler(a-b);break;
				case '*' : empiler(a*b);break;
				case '/' : empiler(a/b);break;
				default : empiler(convertir(saisie));
			}
					
	}while(saisie!='\n');
	
	depiler(&a);
	printf("Le resultat est : %i",a);
	
}

int main(void){
	initpile();
	calcul_postfixe();
	return 0;
	
}
