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
#include "MonochromeLib.h"
void generateOutputs();
void useOutputs();
void displayExternal();
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
int output1, output2, output3;
int const X0=1580160; // les trois seed sont considerees comme origines de l'espace. MULTIPLES DE 128, X0-1580160/128 donne le cube actuel(je crois)
int const Y0=2144640;
int const Z0=2745088;
int X=0;         // coordonees    X%128 donne donc x dans le cube actuel
int Y=0;
int Z=0;
int planetStorageX1[125];
int planetStorageY1[125];
int planetStorageZ1[125];
char i = 0;
int planetDensity = 0;
int planetX, planetY, planetZ;
int AddIn_main(int isAppli, unsigned short OptionNum){
    generateOutputs();
    displayExternal(0);
    while(!IsKeyDown(KEY_CTRL_EXE)){
        Sleep(10);
    }
}
void displayExternal(call){
    i = 0;
    if(call==0){
        ML_clear_vram();
        while(i <= planetDensity){
            ML_filled_circle(128-planetStorageX1[i], 128-planetStorageY1[i], planetStorageZ1[i], 1);
            ++i;
//            Sleep(30);
            ML_display_vram();
        }
    }
}
void generateOutputs(){// genere 3 constantes en fonc de X Y Z et des seed X0 Y0 Z0
    //int local, local1;
    //local = X0-(X/128);
    //while (local>1000){
    //    local /= 10;
    //}
    rand(X);
    output1 = rand() % 999;
    //output1 = local;
    //local = Y0-(Y/128);
    //while (local>1000){
    //    local /= 10;
    //}
    rand(Y);
    output2 = rand() % 999;
    //output2 = local;
    //local = Z0-(Z/128);
    //while (local>1000){
    //    local /= 10;
    //}
    rand(Z);
    output3 = rand() % 999;
    //output3 = local;
    //output1=output1*X;
    //output2=output2*Y;
    //output3=output3*Z;
    //do{                               // les outputs sont redimenssiones a un maximum de 999 
    //    local1 = output1%10;
    //    output1 = (output1-local1)/10;
    //} while (output1>1000);
    //do{
    //    local1 = output2%10;
    //    output2 = (output2-local1)/10;
    //} while (output2>1000);
    //do
    //{
    //    local1 = output3%10;
    //    output3 = (output3-local1)/10;
    //} while (output3>1000);

    useOutputs();
}
void useOutputs(){// rempli les listes d'infos des planetes grace aux outputs (a refaire si systemes solaires)
    planetDensity = 16 + (output1 / 10);
    planetX, planetY, planetZ;
    for (i = 26; i <= planetDensity+26; ++i){
        rand(output1+i);
        planetX = rand() % 128;
//        while(planetX<0){
//            planetX=planetX*10;
//        }
//        while(planetX>128){
//            planetX=planetX/10;
//        }
        rand(output2+i);
        planetY = rand() % 128;
//        while(planetY<0){
//            planetY=planetY*10;
//        }
//        while(planetY>128){
//            planetY=planetY/10;
//        }
        rand(output3+i);
        planetZ = (rand() % 2)+1;
//        while(planetZ<0){
//            planetZ=planetZ*10;
//        }
//        while(planetZ>128){
//            planetZ=planetZ/10;
//        }
        planetStorageX1[i-26] = planetX;
        planetStorageY1[i-26] = planetY;
        planetStorageZ1[i-26] = planetZ;
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