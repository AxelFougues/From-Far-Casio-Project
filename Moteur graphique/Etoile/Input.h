/****************************************************************************/
/*                                                                          */
/*                                  Input                                   */
/*                                                                          */
/* Par NineStars                                                         V2 */
/****************************************************************************/

#ifndef DEF_INPUT
#define DEF_INPUT



// input_update :  mets à jour le clavier, il faut appeler cette méthode une fois par frame
void input_update();

// input_press : renvoie 1 si la touche key est pressée, 0 sinon
int input_press(char key);

// input_trigger : renvoie 1 au moment où key est pressée, 0 sinon
int input_trigger(char key);

// input_release : renvoie 1 au moment où key est relachée, 0 sinon
int input_release(char key);

// input_hold_short : renvoie 1 si la touche a été pressée un court instant, 0 sinon
int input_hold_short(char key);

// input_hold_long : renvoie 1 si la touche a été pressée un long instant, 0 sinon
int input_hold_long(char key);

// input_repeat : renvoie 1 quand la touche est pressée, puis des 1 à intervalle régulier
int input_repeat(char key);

// input_reapeat_short : renvoie 1 quand la touche est pressée, puis des 1 à intervalle régulier courts
int input_repeat_short(char key);

// input_trigger_or_hold : renvoie 1 si la touche est pressée rapidement, 2 si elle est maintenue, 0 sinon
int input_trigger_or_hold(char key);

// input_dir4 : renvoie un nombre donnant la direction des touches fléchées suivant l'ordre du pavé numérique
//              sans prendre en compte les diagonales, 0 si aucune direction
int input_dir4();

// input_dir8 : renvoie un nombre donnant la direction des touches fléchées suivant l'ordre du pavé numérique
//              en prenant en compte les diagonales, 0 si aucune direction
int input_dir8();

// input_manual : simule l'appuie sur la touche
void input_manual(char key);






void key_inject(int keycode);
unsigned char key_down(unsigned char code);

/***************/
/** Key codes **/
/***************/
#define K_0 71
#define K_1 72
#define K_2 62
#define K_3 52
#define K_4 73
#define K_5 63
#define K_6 53
#define K_7 74
#define K_8 64
#define K_9 54
#define K_DP 61
#define K_EXP 51
#define K_PMINUS 41
#define K_PLUS 42
#define K_MINUS 32
#define K_MULT 43
#define K_DIV 33
#define K_FRAC 75
#define K_LPAR 55
#define K_RPAR 45
#define K_COMMA 35
#define K_STORE 25
#define K_XTT 76
#define K_LOG 66
#define K_LN 56
#define K_SIN 46
#define K_COS 36
#define K_TAN 26
#define K_SQUARE 67
#define K_POW 57
#define K_EXE 31
#define K_DEL 44
#define K_AC 32
#define K_FD 65
#define K_EXIT 47
#define K_SHIFT 78
#define K_ALPHA 77
#define K_OPTN 68
#define K_VARS 58
#define K_UP 28
#define K_DOWN 37
#define K_LEFT 38
#define K_RIGHT 27
#define K_F1 79
#define K_F2 69
#define K_F3 59
#define K_F4 49
#define K_F5 39
#define K_F6 29
#define K_MENU 48

#endif
