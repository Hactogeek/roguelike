typedef enum{black, red, green, yellow, blue, magenta, cyan, white}terminal; /**< Colors */
typedef enum{reinit = 0, blink = 5, invertColor= 7}screen; /**< Set screen action */

void color(int color, char type[]);
void fontColor(int color);
void clearScreen();
void reinitColor();
