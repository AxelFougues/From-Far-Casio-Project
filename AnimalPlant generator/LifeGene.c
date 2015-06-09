/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : [ProjectName].c                                 */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#include "fxlib.h"
#include "stdio.h"
#include "math.h"
#include "MonochromeLib.h"
void display();
//****************************************************************************
//  AddIn_main (Sample program main function)
//
//  param   :   isAppli   : 1 = This application is launched by MAIN MENU.
//                        : 0 = This application is launched by a strip in eACT application.
//
//              OptionNum : Strip number (0~3)
//                         (This parameter is only used when isAppli parameter is 0.)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int x = 64;
int y = 32;
int mainBody[2];
int head[2];
int tail[2];
int feet[2];
int neck[2];
int horns[1];
int eye[0];
int AddIn_main(int isAppli, unsigned short OptionNum){
    while(!IsKeyDown(KEY_CTRL_EXIT)){
        mainBody[0] = (rand() % 23)-3;
        mainBody[1] = (rand() % 7)-2;
        mainBody[2] = (rand() % 1);
        head[0] = (rand() % 2)+(mainBody[1]/5);
        head[1] = (rand() % 2)+(head[0]/2);
        head[2] = (rand() % 3);
        tail[0] = (rand() % 4);
        tail[1] = mainBody[1]-2 -(rand() % 2);
        tail[2] = (rand() % 2);
        feet[0] = (rand() % 2);
        feet[1] = (rand() % 2)+1;
        feet[2] = (rand() % 1)+1;
        neck[0] = (rand() % 4);
        neck[1] = mainBody[1]-2 -(rand() % 2);
        neck[2] = (rand() % 2);
        horns[0] = (rand() % 4);
        horns[1] = (rand() % 3);
        eye[0] = (rand() % 2);
        display();
    }

    return 1;
}
void display(){
    ML_filled_ellipse_in_rect(x, y, x+mainBody[0], y+mainBody[1], mainBody[2]);
    if(neck[0]){
        ML_line(x, y, x+3, y+neck[2], 1);
        if(neck[1]){
            for (i = 1; i < (neck[1]/2); ++i){
                ML_line(x, y+i, x+3, y+neck[2]+i, 1);
            }
            for (i = 1; i < (neck[1]/2); ++i){
                ML_line(x, y-i, x+3, y+neck[2]-i, 1);
            }
            if(neck[0]>=2){
                for (i = 0; i < (neck[1]/2-1); ++i){
                    ML_line(x+3, y+neck[2], x+3+x+3, y+neck[2]+y+neck[2]+i, 1);
                }
                for (i = 0; i < (neck[1]/2-1); ++i){
                    ML_line(x+3, y+neck[2], x+3+x+3, y+neck[2]+y+neck[2]-i, 1);
                }
            }
            if(neck[0]>=3){
                    ML_line(2*x+6, 2*y+neck[2], 3*x+9, 3*y+2*neck[2], 1);
            }
            if(neck[0]>=4){
                    ML_line(3*x+9, 3*y+2*neck[2], 4*x+12, 4*y+2*neck[2], 1);
            }
        }
        for (i = 0; i < head[2]; ++i){
            ML_line(4*x+12, 4*y+2*neck[2]+i, 4*x+12+head[0], 4*y+2*neck[2]+i, 1);
        }

    }else{
        ML_line(x+mainBody[0], y+mainBody[1]+i, x+mainBody[0]+head[0], y+mainBody[1]+i, 1);
    }

}



//****************************************************************************
//**************                                              ****************
//**************                 Notice!                      ****************
//**************                                              ****************
//**************  Please do not change the following source.  ****************
//**************                                              ****************
//****************************************************************************


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

//****************************************************************************
//  InitializeSystem
//
//  param   :   isAppli   : 1 = Application / 0 = eActivity
//              OptionNum : Option Number (only eActivity)
//
//  retval  :   1 = No error / 0 = Error
//
//****************************************************************************
int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section

