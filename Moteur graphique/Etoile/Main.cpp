/****************************************************************************/
/*                                                                          */
/*   CASIO fx-9860G SDK Library                                             */
/*                                                                          */
/*   File name : [ProjectName].c                                            */
/*                                                                          */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                            */
/*                                                                          */
/****************************************************************************/

int main();

extern "C"
{
    #include <fxlib.h>
    #include "MonochromeLib.h"
}
#include "Commun.hpp"
#include "Game.hpp"

// scenes //
#include "Scene_Space.hpp"


// variables globales //
Game game;
int scene = SCENE_SPACE;

int main()
{
    game.Game();
    while(scene != STOP)
    {
        // transition de changement de scene
        ML_rectangle(0, 0, 128, 64, 0, ML_BLACK, ML_CHECKER);
        ML_display_vram();
        Sleep(80);

        switch (scene)
        {
            case SCENE_SPACE:
                Scene_Space scene_space;
                break;
        }
    }

    unsigned int key;
    while(1) GetKey(&key);
    return 1;
}




extern "C"
{
    int AddIn_main(int isAppli, unsigned short OptionNum)
    {
        return main();
    }

    #pragma section _BR_Size
    unsigned long BR_Size;
    #pragma section
    #pragma section _TOP
    int InitializeSystem(int isAppli, unsigned short OptionNum)
    {
        return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
    }
    #pragma section
    /* AddIn_main(isAppli(1=MAIN,0=eAct), OptionNum(isAppli==0?0~3)) :: int(Done?1:0) */
}
