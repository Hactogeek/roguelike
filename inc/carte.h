/**
*	\file carte.h
*	\brief  Roguelike
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 d�cembre 2015
*/

/** \fn void CarteInitialiser(t_carte *carte)
*   \brief Initialise la carte donn�e en param�tre en remplissant sa grille de 0
*   \param *carte L'adresse de la carte
*/
void CarteInitialiser(t_carte * carteGrille);

/** \fn int SallesPossiblesCompter(FILE *carteFichier)
*   \brief Retoure le nombre de salles diff�rentes compt�es dans le fichier donn� en param�tre
*   \param *carteFichier Le fichier contenant les diff�rents paterns de salles
*   \return Le nombre de paterns diff�rents
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
*   \brief Retire certaines portes choisies de mani�re al�atoire
*   \param porte[SALLES_MAX_X][SALLES_MAX_Y] Le tableau contenant les portes
*/
void PorteRetirer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);


/** \fn void ObstaclesPlacer(int nb_salles_x, int nb_salles_y, t_carte *carte)
*   \brief Place un obstacle dans une salle donn�e
*   \param nb_salles_x La coordonn�e en ordonn�e de la salle
*	\param nb_salles_y La coordonn�e en abscisse de la salle
*	\param *carte L'adresse de la carte
*/
void ObstaclesPlacer(int nb_salles_x, int nb_salles_y, t_carte *carte);

/** \fn void EscalierChoix(t_carte * carte)
*   \brief Choisi l'emplacement de l'escalier et le place � cet endroit de la carte, en s'assurant que ce soit bien dans une salle et non voisin d'un chemin
*	\param *carte L'adresse de la carte
*/
void EscalierChoix(t_carte * carte);

/** \fn void MatriceAfficher(int matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y])
*   \brief Affiche la carte sous sa forme de matrice
*	\param matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y] La matrice � afficher
*/
void MatriceAfficher(int matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y]);

/** \fn void VideAfficher(void)
*   \brief Permet d'afficher le vide contenu dans la carte
*/
void VideAfficher();

/** \fn void MurAfficher(int i, int j, t_carte carte)
*   \brief Permet d'afficher un mur en fonction des salles l'entourant
*	\param i La coordonn�e en ordonn�e de la case contenant le mur
*	\param j La coordonn�e en abscisse de la case contenant le mur
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
*   \brief Permet d'afficher la carte compl�te, comme vue sur la console
*	\param *carte L'adresse de la carte � afficher
*/
void CarteAfficher(t_carte * carte);

/** \fn void CarteCharger(void)
*   \brief Permet de cr�er une carte � partir d'un fichier contenant des paterns
*	\return La carte ainsi cr��e
*/
t_carte CarteCharger();
