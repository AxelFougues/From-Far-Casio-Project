/****************************************************************************/
/*                                                                          */
/*                                 DEBUG                                    */
/*                                                                          */
/* Par NineStars                                                            */
/****************************************************************************/

#ifndef DEF_DEBUG
#define DEF_DEBUG

#include "fxlib.h"


// debug : affiche dans le coin supérieur gauche
void debug_int(int variable);
void debug_str(const unsigned char *chaine);
void display_fps(int fps);

// debug_tab : affiche dans un écran dédié tous les éléments d'un tableau de int
void debug_tab(int tab[], int taille);

// print_v : affiche un int
void print_v(int variable);

#endif // DEF_DEBUG
