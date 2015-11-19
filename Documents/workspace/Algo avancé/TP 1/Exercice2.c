#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define N 20

int main(void){
	int i,j,ind,taille,tampon;
	char ch[N],petit;
	
	printf("Veuillez saisir votre mot : ");
	scanf("%s",ch);
	taille = strlen(ch);
	// on trie la j-ieme valeur
	for(j =0; j < taille; j++){
		
		petit ='z';
		// on cherche la plus petite valeur
		for(i=j+1;i < taille;i++){
			
			if(ch[i]< petit){ 
				petit = ch[i];
				ind = i;
			}
			
		}
		//on permute
		ch[ind]=ch[j];
		ch[j]= petit;
		printf("%s \n",ch);
	}
	
}
