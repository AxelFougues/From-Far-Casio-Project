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
void userInterface();
void display();
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
int X=1580160;         // coordonees    X%128 donne donc x dans le cube actuel
int Y=2144640;
int Z=2745088;
int sunStorageX[10];
int sunStorageY[10];
int sunStorageZ[10];
int astralStorageX1[90];
int astralStorageY1[90];
int astralStorageZ1[90];
char i, o;
int systemDensity = 0;
int planetDensity = 0;
int planetX, planetY, planetZ, sunX, sunY, sunZ;
int AddIn_main(int isAppli, unsigned short OptionNum){
    //userInterface();
    generateOutputs();                                   //normalement on apelle juste userInterface mais ca provoque le bug: Lignes de planentes 
    displayExternal(0,0,0,0);
    while(!IsKeyDown(KEY_CTRL_EXE)){
        Sleep(10);
    }
}
void userInterface(){
    int x, y, z;
    x =X%128;
    y =Y%128;
    z =Z%128;
    ML_display_vram();
    while(!(X%128 == 64 && Y%128 == 64 && Z%128 == 64)){   //deplacements           //Sys error quand gauche et droite
        if(IsKeyDown(KEY_CTRL_UP)){
            --Y;
            display(1,x,y,z);
        }
        if(IsKeyDown(KEY_CTRL_DOWN)){
            ++Y;
            display(1,x,y,z);
        }
        if(IsKeyDown(KEY_CTRL_LEFT)){
            --X;
            display(1,x,y,z);
        }
        if(IsKeyDown(KEY_CTRL_RIGHT)){
            ++X;
            display(1,x,y,z);
        }
        if(IsKeyDown(KEY_CTRL_SHIFT)){
            --Z;
            display(1,x,y,z);
        }
        if(IsKeyDown(KEY_CTRL_ALPHA)){
            ++Z;
            display(1,x,y,z);
        }
    }
    display(0,x,y,z);
}
void display(call,x,y,z){
    if(call){
        generateOutputs();
        useOutputs();
        displayExternal(0,x,y,z);  //cube central
        Z = Z-128;
        generateOutputs();
        useOutputs();
        displayExternal(-1,x,y,z); //cube central arriere
        Z = Z+128;
        //if(x<=64 && y<=64){            //VVV cubes lateraux , n'existent pas encore dans dispExternal, les integrer depuis la v 0.1
        //    for (i = 0; i < 1; ++i){
        //        X = X-128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(1+i);
        //        Y = Y-128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(3+i);
        //        X = X+128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(5+i);
        //        Y = Y+128;
        //        Z = Z-128;
        //    }
        //    Z = Z+128;
        //}
        //if(x>=64 && y<=64){
        //    for (i = 0; i < 1; ++i){
        //        X = X+128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(1+i);
        //        Y = Y-128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(3+i);
        //        X = X-128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(5+i);
        //        Y = Y+128;
        //        Z = Z-128;
        //    }
        //    Z = Z+128;
        //}
        //if(x<=64 && y>=64){
        //    for (i = 0; i < 1; ++i){
        //        X = X-128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(1+i);
        //        Y = Y+128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(3+i);
        //        X = X+128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(5+i);
        //        Y = Y-128;
        //        Z = Z-128;
        //    }
        //    Z = Z+128;
        //}
        //if(x>=64 && y>=64){
        //    for (i = 0; i < 1; ++i){
        //        X = X+128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(1+i);
        //        Y = Y+128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(3+i);
        //        X = X-128;
        //        generateOutputs();
        //        useOutputs();
        //        displayExternal(5+i);
        //        Y = Y-128;
        //        Z = Z-128;
        //    }
        //    Z = Z+128;
        //}
    
    } //determine le cube a generer et apelle External 
}
void displayExternal(call,x,y,z){
    i = 0;
    if(call==0){
        ML_clear_vram();
        while(i <= systemDensity){
            ML_filled_circle(x+astralStorageX1[i], y+astralStorageY1[i], z+astralStorageZ1[i], 1);
            ++i;
            //            Sleep(30); //observer la generation
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
    srand(X);
    output1 = rand() % 999;
    //output1 = local;
    //local = Y0-(Y/128);
    //while (local>1000){
    //    local /= 10;
    //}
    srand(Y);
    output2 = rand() % 999;
    //output2 = local;
    //local = Z0-(Z/128);
    //while (local>1000){
    //    local /= 10;
    //}
    srand(Z);
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
    systemDensity = output1 / 100;
    planetX, planetY, planetZ;
    for (i = 0; i <= systemDensity; ++i){
        //create suns
        output1= output1*i;
        srand(output1+i);
        sunX = rand() % 128 +1000;
        srand(output2+i);
        sunY = rand() % 128;
        srand(output3+i);
        sunZ = (rand() % 8)+1;
        sunStorageX[i-26] = sunX;
        sunStorageY[i-26] = sunY;
        sunStorageZ[i-26] = sunZ;
        planetDensity = rand() % 9;
        for (o = 0; o < planetDensity; ++o){
            //create planets around sun
            ++i;
            output1= output1*i;
            srand(output1+i);
            planetX = rand() % 62 -21;
            if(planetX =< 9 && planetX >= 0){
                planetX = planetX+9;
            }
            if(planetX => -9 && planetX < 0){
                planetX = planetX-9;
            }
            planetX = sunX+planetX;
            srand(output2+i);
            planetY = rand() % 62 -21;
            if(planetY =< 9 && planetY >= 0){
                planetY = planetY+9;
            }
            if(planetY => -9 && planetY < 0){
                planetY = planetY-9;
            }
            planetY = sunY+planetY;
            while(sqrt(pow(planetX,2)+pow(planetY,2))>20){
                ++planetX;
                ++planetY;
            }
            srand(output3+i);
            planetZ = (rand() % 2)+1;
            astralStorageX1[i-26] = planetX;
            astralStorageY1[i-26] = planetY;
            astralStorageZ1[i-26] = planetZ;
            
        }
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