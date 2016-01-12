/**
*	\file carte.h
*	\brief  Protoype fonction carte
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 decembre 2015
*/

/** \fn void CarteInitialiser(t_carte *carte)
*   \brief Initialise la carte donnee en parametre en remplissant sa grille de 0
*   \param *carte L'adresse de la carte
*/
void CarteInitialiser(t_carte * carteGrille);

/** \fn int SallesPossiblesCompter(FILE *carteFichier)
*   \brief Retoure le nombre de salles differentes comptees dans le fichier donne en paramètre
*   \param *carteFichier Le fichier contenant les differents paterns de salles
*   \return Le nombre de paterns differents
*/
int SallesPossiblesCompter(FILE *carteFichier);

/** \fn void PorteInitialiser(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y])
*   \brief Initialise le tableau des portes en le remplissant de 0
*   \param porte[SALLES_MAX_X][SALLES_MAX_Y] Le tableau contenant les portes
*/
void PorteInitialiser(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);

/** \fn void PortePlacer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y])
*   \brief Place toutes les portes possibles et logiques
*   \param porte[SALLES_MAX_X][SALLES_MAX_Y] Le tableau contenant les portes
*/
void PortePlacer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);

/** \fn void PorteRetirer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y])
*   \brief Retire certaines portes choisies de maniere aleatoire
*   \param porte[SALLES_MAX_X][SALLES_MAX_Y] Le tableau contenant les portes
*/
void PorteRetirer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);


/** \fn void ObstaclesPlacer(int nb_salles_x, int nb_salles_y, t_carte *carte)
*   \brief Place un obstacle dans une salle donnee
*   \param nb_salles_x La coordonnee en ordonnee de la salle
*	\param nb_salles_y La coordonnee en abscisse de la salle
*	\param *carte L'adresse de la carte
*/
void ObstaclesPlacer(int nb_salles_x, int nb_salles_y, t_carte *carte);

/** \fn void EscalierChoix(t_carte * carte)
*   \brief Choisi l'emplacement de l'escalier et le place e cet endroit de la carte, en s'assurant que ce soit bien dans une salle et non voisin d'un chemin
*	\param *carte L'adresse de la carte
*/
void EscalierChoix(t_carte * carte);

/** \fn void MatriceAfficher(int matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y])
*   \brief Affiche la carte sous sa forme de matrice
*	\param matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y] La matrice e afficher
*/
void MatriceAfficher(int matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y]);

/** \fn void VideAfficher(void)
*   \brief Permet d'afficher le vide contenu dans la carte
*/
void VideAfficher();

/** \fn void MurAfficher(int i, int j, t_carte carte)
*   \brief Permet d'afficher un mur en fonction des salles l'entourant
*	\param i La coordonnee en ordonnee de la case contenant le mur
*	\param j La coordonnee en abscisse de la case contenant le mur
*	\param carte La carte
*/
void MurAfficher(int i, int j, t_carte carte);

/** \fn void SolAfficher(void)
*   \brief Permet d'afficher le sol contenu dans la carte
*/
void SolAfficher();

/** \fn void CheminAfficher(void)
*   \brief Permet d'afficher le chemin contenu dans la carte
*/
void CheminAfficher();

/** \fn void EscalierAfficher(void)
*   \brief Permet d'afficher l'escalier contenu dans la carte
*/
void EscalierAfficher();

/** \fn void ObstacleAfficher(void)
*   \brief Permet d'afficher l'obstacle contenu dans la carte
*/
void ObstacleAfficher();

/** \fn void CarteAfficher(t_carte * carte)
*   \brief Permet d'afficher la carte complete, comme vue sur la console
*	\param *carte L'adresse de la carte a afficher
*/
void CarteAfficher(t_carte * carte);

/** \fn void CarteCreer(void)
*   \brief Permet de creer une carte a partir d'un fichier contenant des paterns
*	\return La carte ainsi cree
*/
t_carte CarteCreer();
