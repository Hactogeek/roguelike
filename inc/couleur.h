/**
*	\file couleur.h
*	\brief  Protoype gestion couleur terminal
*	\author Tony Marteau, Dimitri Bernot, Marvin Jean
*	\version 1.0.0
*	\date 18 décembre 2015
*/

typedef enum{black, red, green, yellow, blue, magenta, cyan, white}terminal; /**< Colors */
typedef enum{reinit = 0, blink = 5, invertColor= 7}screen; /**< Set screen action */

void color(int color, char type[]);
void fontColor(int color);
void clearScreen();
void reinitColor();
