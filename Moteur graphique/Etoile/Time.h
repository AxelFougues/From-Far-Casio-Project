/****************************************************************************/
/*                                                                          */
/*                                  TIME                                    */
/*                                                                          */
/* Par NineStars                                                            */
/****************************************************************************/

#ifndef DEF_TIME
#define DEF_TIME


// time_get_ticks : retourne le nombre de ticks depuis minuit     1 tick = 1/128 seconde
int time_get_ticks();

// time_get_ticks : retourne le nombre de fps
int time_get_fps();

// time_set_fps : impose le nombre de fps, 1 pour 128 FPS,2 pour 64, 4 pour 32, etc...
void time_set_fps(int fps_wish);

#endif // DEF_TIME
