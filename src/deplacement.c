
void Deplacement_amorcer(){
}

void Deplacement_tester(int t){
	t_carte map
		switch(t){case 1 :Deplacement_marcher(map); break;}
}

/* Deplace le personnage qui est au position entré */
void Deplacement_marcher(t_carte map){
	
	char cmd_move;
	do{
		scanf("%c",&cmd_move);
		switch(cmd_move){
			case 'd': map.cord.x += (map.grille[map.cord.x+1][map.cord.y]!=1);break;
			case 's': map.cord.y -= (map.grille[map.cord.x][map.cord.y-1]!=1);break;
			case 'q': map.cord.x -= (map.grille[map.cord.x-1][map.cord.y]!=1);break;
			case 'z': map.cord.y += (map.grille[map.cord.x][map.cord.y+1]!=1);break;
		} // Effectue le deplacement et la verification de la position, le personnage ne peut pas etre dans un mur.
			

}


