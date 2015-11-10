#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
	return a+b;
	}

int main (){
	//arranger
	int n1=5;
	int	n2=3;
	//agir
	int resultat = add (n1,n2);
	//auditer
	if (resultat!=8)printf(" le test a raté");
	else printf(" la somme de %d et %d est %d \n: ",n1, n2, resultat);
	return 0;
}
