# Projet de Roguelike

Tony Marteau, Dimitri Bernot, Marvin Jean

Nous avons debuté la réalisation de ce programme dans le cadre du projet de troisième semestre en Sciences pour l'Ingénieur à l'Université du Maine.

Un roguelike est un jeu où un personnage évolue dans un environnement hostile et dont il doit avancer pour faire croitre son score. C'est un jeu sans fin qui a pour seul but de faire un score aussi élevé qu possible. Le joueur devra donc vaincre des monstres ou encore ouvrir des coffres pour acquerir de l'expérience et du score pour pouvoir continuer son évolution.

Le programme sera écrit en langage C et devra afficher le rendu du jeu dans le terminal, du moins pour le début. Nous pourrons à terme nous permettre d'utiliser une interface graphique.

## Sommaire
  **Projet Roguelike**
  1. **[A Faire](#a-faire)**
  2. **[Idée](#idée)**
  3. **[Changelog](#changelog)**
  4. **[Répartition](#répartition)** 
  5. **[Compilation](#compilation)**
  6. **[Utilisation](#utilisation)**
	
## A Faire

 - [x] Dévelopement
  - [x] Génération de la grille
   - [x] Chemin entre les salles 
  - [x] Déplacement du personnage
  - [x] Changement d'étage
  - [x] Sauvegarde de la partie
  - [x] Charger d'une partie
  - [x] Gestion des monstres
  - [x] Caractéristique
   - [x] Positionnement aléatoire
  - [x] Systeme de combat
 - [x] Makefile
 - [x] Test
 - [x] Documentation
 - [x] Github
  - [x] Création
  - [x] Organisation definitive
  - [x] README à jour
 - [x] Compte Rendu
 - [ ] Interface Graphique

## Idée
 - Inventaire
 - Classe pour le personnage
 - Musique
	
## Changelog
 - 2/12/15 : Déplacement du joueur dans une map générée aleatoirement. Déplacement de monstres dans une map générée aléatoirement.
 - 14/12/15 : Deplacement joueur / monstre mis en commun et en version definitive. Implementation de statisitque et caracteristique (peut etre a revoir). Chemin aleatoire lors de la generation.
 - 15/12/15 : Version terminal jouable, ajout de quelques couleurs.

## Répartition
 - Tony : Les monstres
 - Dimitri : La carte
 - Marvin : Le joueur

##Compilation

Pour lancer l'éxécutable du programme et l'utiliser il suffit de taper la commande suivante dans le terminal :

> $ make

##Execution

Pour lancer l'écécutable du programme et l'utiliser il suffit de taper la commande suivante dans le terminal :

> $ bin/roguelike
