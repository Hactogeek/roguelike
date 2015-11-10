# include <stdio.h> 
# include <stdlib.h>
# include <math.h> 

int Factorielle(int a){
	int total = 1;
	int i;
	for(i=1; i<=a;i++){
		total = total * i;
	}
	return total;
	
}

int main () { 
	int valeur=0; 
	int result = Factorielle (valeur);
	if ( result !=1) printf(" le test a raté"); 
	valeur =1;
	result = Factorielle (valeur);
	if ( result !=1) printf("le test a raté \n ");
	return 0;
	} 
	
