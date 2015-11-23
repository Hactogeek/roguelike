/*
 * Structure du programme principal
 */

structure pour une case de la carte -> vide, mur, sol ?
structure pour le contenu d'une case -> porte = mur ; perso, mob, escalier, coffre = sol
structure pour le personnage -> niveau, nom, t_stats, t_carac, t_equipement, t_inventaire,
structure pour une partie -> difficulte, perso, seed


//Bloc menu
int menuChoisir(;;choix) {
	-> nouvelle partie ?
	-> charger partie ?
	-> quitter ?
	
	return choix;
}

//Bloc création
t_jeu partieCreer(;;jeu) {
	t_jeu jeu;
	
	jeu.difficulte = difficulteChoisir(;;jeu.difficulte);
	jeu.perso = personnageCreer(;;jeu.perso); //Si le reste est terminé, sinon juste le nom du perso
	jeu.seed = seedGenerer(;;jeu.seed);
	
	return jeu;
}

int difficulteChoisir(;;difficulte) {
	int difficulte
	
	-> choix de la difficulté entre deux entiers
	/*
	 * Influence de la difficulté :
	 *  - stats des monstres (PV, dégats)
	 *  - génération coffres et loots
	 */
	 
	return difficulte;
}

t_personnage personnageCreer(;;personnageCree) {
	t_personnage personnageCree;
	
	-> niveau 1
	-> nom
	-> stats nulles
	-> carac initialisées
	-> Si reste terminé : classes
	
	return personnageCree;
}

type_seed seedGenerer(;;seed) {
	type_seed seed;
	-> Proposer à l'utilisateur de rentrer son propre seed
	
	-> Sinon génération d'un seed
	
	return seed;
}

//Bloc chargement
t_jeu partieCharger(;;jeu) {
	sauvegardeChoisir(;;sauvegarde);
	-> si existe
	sauvegardeCharger(sauvegarde;;jeu);
	
	return jeu;
}

//Bloc jeu
int jeuCommencer(jeu;;raison_arret) {
}
	
	
int main() {
	int choix_menu;
	
	choix_menu = 
	menuChoisir(;;choix_menu);
	
	-> menu (si entre 1 et 3)
	
	//1
	partieCreer(;;jeu);
	//2
	partieCharger(;;jeu);
	
	jeuCommencer(jeu;;raison_arret);
	
	//3
	menuQuitter(raison_arret;;);
	
	return 0;
}
