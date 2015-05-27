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
#include "MonochromeLib.h"
void generateOutputs();
void useOutputs();
void userInterface();
void printVariable();
void display();
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
int planetStorageX1[125];
int planetStorageY1[125];
int planetStorageZ1[125];
char i = 0;
int AddIn_main(int isAppli, unsigned short OptionNum){
    userInterface();
    return 1;
}
void PrintVariable(int x, int y, int val, int color){
    int n, ret;
    char c[20];
    ret = 0;
    n = val;
    do{
        n /= 10;
        ret++;
    } while(n > 0);
    x = x-(ret-1)*4;
    sprintf(c, "%d", val);
    PrintMini(x, y, (unsigned char*)c, color);
}
void userInterface(){
    int x, y, z;
    x =X%128;
    y =Y%128;
    z =Z%128;
    ML_display_vram();
    while(!(X%128 == 64 && Y%128 == 64 && Z%128 == 64)){   //deplacements 
        if(IsKeyDown(KEY_CTRL_UP)){
            --Y;
            display(1);
        }
        if(IsKeyDown(KEY_CTRL_DOWN)){
            ++Y;
            display(1);
        }
        if(IsKeyDown(KEY_CTRL_LEFT)){
            --X;
            display(1);
        }
        if(IsKeyDown(KEY_CTRL_RIGHT)){
            ++X;
            display(1);
        }
        if(IsKeyDown(KEY_CTRL_SHIFT)){
            --Z;
            display(1);
        }
        if(IsKeyDown(KEY_CTRL_ALPHA)){
            ++Z;
            display(1);
        }
    }
    display(0);
}
void display(call){
    if(call){
        generateOutputs();
        useOutputs();
        displayExternal(0);
        Z = Z-128;
        generateOutputs();
        useOutputs();
        displayExternal(-1);
        Z = Z+128;
        if(X%128<=64 && Y%128<=64){
            for (i = 0; i < 1; ++i){
                X = X-128;
                generateOutputs();
                useOutputs();
                displayExternal(1+i);
                Y = Y-128;
                generateOutputs();
                useOutputs();
                displayExternal(3+i);
                X = X+128;
                generateOutputs();
                useOutputs();
                displayExternal(5+i);
                Y = Y+128;
                Z = Z-128;
            }
            Z = Z+128;
        }
        if(X%128>=64 && Y%128<=64){
            for (i = 0; i < 1; ++i){
                X = X+128;
                generateOutputs();
                useOutputs();
                displayExternal(1+i);
                Y = Y-128;
                generateOutputs();
                useOutputs();
                displayExternal(3+i);
                X = X-128;
                generateOutputs();
                useOutputs();
                displayExternal(5+i);
                Y = Y+128;
                Z = Z-128;
            }
            Z = Z+128;
        }
        if(X%128<=64 && Y%128>=64){
            for (i = 0; i < 1; ++i){
                X = X-128;
                generateOutputs();
                useOutputs();
                displayExternal(1+i);
                Y = Y+128;
                generateOutputs();
                useOutputs();
                displayExternal(3+i);
                X = X+128;
                generateOutputs();
                useOutputs();
                displayExternal(5+i);
                Y = Y-128;
                Z = Z-128;
            }
            Z = Z+128;
        }
        if(X%128>=64 && Y%128>=64){
            for (i = 0; i < 1; ++i){
                X = X+128;
                generateOutputs();
                useOutputs();
                displayExternal(1+i);
                Y = Y+128;
                generateOutputs();
                useOutputs();
                displayExternal(3+i);
                X = X-128;
                generateOutputs();
                useOutputs();
                displayExternal(5+i);
                Y = Y-128;
                Z = Z-128;
            }
            Z = Z+128;
        }
    
    } //determine le cube a generer et apelle External 
}
void displayExternal(call){
    if(call==0){
        while(planetStorageX1[i+1] != 0){
        ML_circle(128-planetStorageX1[i], 128-planetStorageY1[i], planetStorageZ1[i]/100, 1);
        ++i;
        ML_display_vram();
        }
        i = 0;
    }
    //if(X%128<=64 && Y%128<=64){
    //    if(call==1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==3){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==5){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==-1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(planetStorageX1[i]+(64-X%128)-(planetStorageZ1[i]/100), planetStorageY1[i]+(64-Y%128)-(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==2){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==4){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==6){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //}
    //if(X%128>=64 && Y%128<=64){
    //    if(call==1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==3){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==5){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==-1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(planetStorageX1[i]+(64-X%128)-(planetStorageZ1[i]/100), planetStorageY1[i]+(64-Y%128)-(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==2){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==4){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==6){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64-(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //}
    //if(X%128<=64 && Y%128>=64){
    //    if(call==1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==3){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==5){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==-1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(planetStorageX1[i]+(64-X%128)-(planetStorageZ1[i]/100), planetStorageY1[i]+(64-Y%128)-(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==2){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==4){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==6){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //}
    //if(X%128>=64 && Y%128>=64){
    //    if(call==1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==3){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==5){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==-1){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(planetStorageX1[i]+(64-X%128)-(planetStorageZ1[i]/100), planetStorageY1[i]+(64-Y%128)-(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==2){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+((128-planetStorageX1[i])+(64-X%128))+(planetStorageZ1[i]/100), 64-((128-planetStorageY1[i])+(128-(Y%128))), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==4){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64+(128-planetStorageX1[i]+(X%128))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+(Y%128))+(planetStorageZ1[i]/100), planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //    if(call==6){
    //        while(planetStorageX1[i+1] != 0){
    //            ML_circle(64-((128-planetStorageX1[i]+128)-(128-(X%128)))+(planetStorageZ1[i]/100), 64+(128-planetStorageY1[i]+128+(128-Y%128))-(planetStorageZ1[i]/100)+2, planetStorageZ1[i]/100, 1);
    //            ++i;
    //        }
    //        i = 0;
    //    }
    //}  // genere le cube demande
}
void generateOutputs(){// genere 3 constantes en fonc de X Y Z et des seed X0 Y0 Z0
    int local, local1;
    local = X0-(X/128);
    while (local>1000){
        local /= 10;
    }
    output1 = local;
    local = Y0-(Y/128);
    while (local>1000){
        local /= 10;
    }
    output2 = local;
    local = Z0-(Z/128);
    while (local>1000){
        local /= 10;
    }
    output3 = local;
    local = output1;
    output1 = output3*output2;
    local1 = output2;
    output2= local*output3;
    output3= local*local1;
    do{                               // les outputs sont redimenssiones a un maximum de 999 
        local1 = output1%10;
        output1 = (output1-local1)/10;
    } while (output1>1000);
    do{
        local1 = output2%10;
        output2 = (output2-local1)/10;
    } while (output2>1000);
    do
    {
        local1 = output3%10;
        output3 = (output3-local1)/10;
    } while (output3>1000);
    useOutputs();
}
void useOutputs(){// rempli les listes d'infos des planetes grace aux outputs (a refaire si systemes solaires)
    int planetDensity = 16 + (output1 / 10);
    int planetX, planetY, planetZ;
    for (i = 26; i <= planetDensity+26; ++i){  //output+i
        planetX = (i-output1);
        while(planetX<0){
            planetX=planetX*10;
        }
        while(planetX>128){
            planetX=planetX/10;
        }
        planetY = (i-output2);
        while(planetY<0){
            planetY=planetY*10;
        }
        while(planetY>128){
            planetY=planetY/10;
        }
        planetZ = (i-output3);
        while(planetZ<0){
            planetZ=planetZ*10;
        }
        while(planetZ>128){
            planetZ=planetZ/10;
        }
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

