#define TAILLE_SALLE 10

#include <stdio.h>
#include <stdlib.h>

void carteCharger() {
	FILE * salle;
	
	salle=fopen("./map/test_map.txt", "r");
	
	if(salle != NULL) {
		fclose(salle);
		printf("Parfait !");
	} else {
		printf("Meh");
	}
}

/*int main() {
	carteCharger();
	return 0;
}*/
