void CarteInitialiser(t_carte * carteGrille);
void CarteAmorcer();

int SallesPossiblesCompter(FILE *carteFichier);
void PorteInitialiser(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);
void PortePlacer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);
void PorteRetirer(t_porte porte[SALLES_MAX_X][SALLES_MAX_Y]);

void ObstaclesPlacer(int nb_salles_x, int nb_salles_y, t_carte *carte);
void EscalierChoix(t_carte * carte);

void MatriceAfficher(int matrice[TAILLE_CARTE_X][TAILLE_CARTE_Y]);
void CarteAfficher(t_carte * carte);

t_carte CarteCharger();

void CarteTester(int test);
