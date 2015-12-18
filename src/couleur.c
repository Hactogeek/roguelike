#include "../inc/general.h"

/**
 * Récupère le code correspondant à la couleur
 * @param  color Couleur demandée
 * @return       Code correspondant, écran blanc si code incorrect
 */
char * getColor(int color, char type[]){

	if(strcmp(type, "Screen") == 0){
		if(color == reinit) return "0"; // Reinit default colors
		if(color == black) return "40"; // Screen color
		if(color == red) return "41";
		if(color == green) return "42";
		if(color == yellow) return "43";
		if(color == blue) return "44";
		if(color == magenta) return "45";
		if(color == cyan) return "46";
		if(color == white) return "47";
	}

	if(color == black) return "30"; // Font color
	if(color == red) return "31";
	if(color == green) return "32";
	if(color == yellow) return "33";
	if(color == blue) return "34";
	if(color == magenta) return "35";
	if(color == cyan) return "36";
	return "37";
}


/**
 * Change la couleur de l'écran ou de la police
 * @param color Couleur à utiliser
 * @param type Texte à changer de couleur ou arrière plan
 */
void color(int color, char type[]){
	char colorToUse[3];

	strcpy(colorToUse, getColor(color, type));
	
	printf("\033[%sm",colorToUse); // Change le texte / l'écran avec la couleur désirée
	if(strcmp(type, "Screen") != 0){
		printf("%s", type);
		printf("\033[%sm", getColor(reinit, "Screen")); // Réinitialise le texte suivant en blanc
	}

}

/**
 * Réinitialise la couleur de l'écran
 */
void reinitColor() {
	printf("\033[%sm", getColor(reinit, "Screen")); // Réinitialise le texte suivant en blanc
}


/**
 * Change la couleur de la police
 * @param color Couleur à utiliser
 */
void fontColor(int color){
	printf("\033[%sm",getColor(color, " ")); // Change le texte avec la couleur désirée
}

/**
 * Efface l'écran
 */
void clearScreen(){
	printf("\033[H\033[2J");
	printf("\033[H\033[2J");
	printf("\033[H\033[2J");
}
