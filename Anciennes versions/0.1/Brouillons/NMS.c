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
int output1, output2, output3;
long const X0=123456123*128;
long const Y0=130899089*128;
long const Z0=130989899*128;
long X=123456123*128;
long Y=130899089*128;
long Z=130989899*128;
int planetStorageX1[125];
int planetStorageY1[125];
int planetStorageZ1[125];
int planetStorageX2[125];
int planetStorageY2[125];
int planetStorageZ2[125];
int planetStorageX3[125];
int planetStorageY3[125];
int planetStorageZ3[125];
int planetStorageX4[125];
int planetStorageY4[125];
int planetStorageZ4[125];
int planetStorageX5[125];
int planetStorageY5[125];
int planetStorageZ5[125];
int planetStorageX6[125];
int planetStorageY6[125];
int planetStorageZ6[125];
int planetStorageX7[125];
int planetStorageY7[125];
int planetStorageZ7[125];
int planetStorageX8[125];
int planetStorageY8[125];
int planetStorageZ8[125];
char i = 0;
int AddIn_main(int isAppli, unsigned short OptionNum){
    userInterface();
    return 1;
}
void userInterface(){
    int cubelimitX, cubelimitY, cubelimitZ;
    display(1);
    while(cubelimitX<=128 && cubelimitY<=128 && cubelimitZ<=128 && cubelimitX>=0 && cubelimitY>=0 && cubelimitZ>=0){
        if(IsKeyDown(KEY_CTRL_UP)){
            --Y;
            --cubelimitY;
            display(0);
        }
        if(IsKeyDown(KEY_CTRL_DOWN)){
            ++Y;
            ++cubelimitY;
            display(0);
        }
        if(IsKeyDown(KEY_CTRL_LEFT)){
            --X;
            --cubelimitX;
            display(0);
        }
        if(IsKeyDown(KEY_CTRL_RIGHT)){
            ++X;
            ++cubelimitX;
            display(0);
        }
        if(IsKeyDown(KEY_CTRL_SHIFT)){
            --Z;
            --cubelimitZ;
            display(0);
        }
        if(IsKeyDown(KEY_CTRL_ALPHA)){
            ++Z;
            ++cubelimitZ;
            display(0);
        }
    }
    display(1);
}
void display(call){
    if(call){
        generateOutputs();
        useOutputs(1);
        if(X%128!=64 && Y%128!=64){
            if(X%128<=64 && Y%128<=64){
                for (i = 0; i < 1; ++i){
                    X = X-128;
                    generateOutputs();
                    useOutputs(2+i);
                    Y = Y-128;
                    generateOutputs();
                    useOutputs(3+i);
                    X = X+128;
                    generateOutputs();
                    useOutputs(4+i);
                    Y = Y+128;
                    Z = Z-128;
                }
                Z = Z+128;
            }
            if(X%128>=64 && Y%128<=64){
                for (i = 0; i < 1; ++i){
                    X = X+128;
                    generateOutputs();
                    useOutputs(2+i);
                    Y = Y-128;
                    generateOutputs();
                    useOutputs(3+i);
                    X = X-128;
                    generateOutputs();
                    useOutputs(4+i);
                    Y = Y+128;
                    Z = Z-128;
                }
                Z = Z+128;
            }
            if(X%128<=64 && Y%128>=64){
                for (i = 0; i < 1; ++i){
                    X = X-128;
                    generateOutputs();
                    useOutputs(2+i);
                    Y = Y+128;
                    generateOutputs();
                    useOutputs(3+i);
                    X = X+128;
                    generateOutputs();
                    useOutputs(4+i);
                    Y = Y-128;
                    Z = Z-128;
                }
                Z = Z+128;
            }
            if(X%128>=64 && Y%128>=64){
                for (i = 0; i < 1; ++i){
                    X = X+128;
                    generateOutputs();
                    useOutputs(2+i);
                    Y = Y+128;
                    generateOutputs();
                    useOutputs(3+i);
                    X = X-128;
                    generateOutputs();
                    useOutputs(4+i);
                    Y = Y-128;
                    Z = Z-128;
                }
                Z = Z+128;
            }
        }
        userInterface();
    }
    ML_clear_vram();
    if(X%128<=64 && Y%128<=64){
        while(planetStorageX2[i+1] != 0){
            ML_point(64-((128-planetStorageX2[i])+(64-X%128))+(planetStorageZ2[i]/100), 64-((128-planetStorageY2[i])+(128-(Y%128))), planetStorageZ2[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX3[i+1] != 0){
            ML_point(64-(128-planetStorageX3[i]+(X%128))+(planetStorageZ3[i]/100), 64-(128-planetStorageY3[i]+(Y%128))+(planetStorageZ3[i]/100), planetStorageZ3[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX4[i+1] != 0){
            ML_point(64-((128-planetStorageX4[i]+128)-(128-(X%128)))+(planetStorageZ4[i]/100), 64-(128-planetStorageY4[i]+128+(128-Y%128))-(planetStorageZ4[i]/100)+2, planetStorageZ4[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX5[i+1] != 0){
            ML_point(planetStorageX5[i]+(64-X%128)-(planetStorageZ5[i]/100), planetStorageY5[i]+(64-Y%128)-(planetStorageZ5[i]/100), planetStorageZ5[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX6[i+1] != 0){
            ML_point(64-((128-planetStorageX6[i])+(64-X%128))+(planetStorageZ6[i]/100), 64-((128-planetStorageY6[i])+(128-(Y%128))), planetStorageZ6[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX7[i+1] != 0){
            ML_point(64-(128-planetStorageX7[i]+(X%128))+(planetStorageZ7[i]/100), 64-(128-planetStorageY7[i]+(Y%128))+(planetStorageZ7[i]/100), planetStorageZ7[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX8[i+1] != 0){
            ML_point(64-((128-planetStorageX8[i]+128)-(128-(X%128)))+(planetStorageZ8[i]/100), 64-(128-planetStorageY8[i]+128+(128-Y%128))-(planetStorageZ8[i]/100)+2, planetStorageZ8[i]/100, 1);
            ++i;
        }
        i = 0;
    }
    if(X%128>=64 && Y%128<=64){
        while(planetStorageX2[i+1] != 0){
            ML_point(64+((128-planetStorageX2[i])+(64-X%128))+(planetStorageZ2[i]/100), 64-((128-planetStorageY2[i])+(128-(Y%128))), planetStorageZ2[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX3[i+1] != 0){
            ML_point(64-(128-planetStorageX3[i]+(X%128))+(planetStorageZ3[i]/100), 64-(128-planetStorageY3[i]+(Y%128))+(planetStorageZ3[i]/100), planetStorageZ3[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX4[i+1] != 0){
            ML_point(64+((128-planetStorageX4[i]+128)-(128-(X%128)))+(planetStorageZ4[i]/100), 64-(128-planetStorageY4[i]+128+(128-Y%128))-(planetStorageZ4[i]/100)+2, planetStorageZ4[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX5[i+1] != 0){
            ML_point(planetStorageX5[i]+(64-X%128)-(planetStorageZ5[i]/100), planetStorageY5[i]+(64-Y%128)-(planetStorageZ5[i]/100), planetStorageZ5[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX6[i+1] != 0){
            ML_point(64+((128-planetStorageX6[i])+(64-X%128))+(planetStorageZ6[i]/100), 64-((128-planetStorageY6[i])+(128-(Y%128))), planetStorageZ6[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX7[i+1] != 0){
            ML_point(64-(128-planetStorageX7[i]+(X%128))+(planetStorageZ7[i]/100), 64-(128-planetStorageY7[i]+(Y%128))+(planetStorageZ7[i]/100), planetStorageZ7[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX8[i+1] != 0){
            ML_point(64+((128-planetStorageX8[i]+128)-(128-(X%128)))+(planetStorageZ8[i]/100), 64-(128-planetStorageY8[i]+128+(128-Y%128))-(planetStorageZ8[i]/100)+2, planetStorageZ8[i]/100, 1);
            ++i;
        }
        i = 0;
    }
    if(X%128<=64 && Y%128>=64){
        while(planetStorageX2[i+1] != 0){
            ML_point(64-((128-planetStorageX2[i])+(64-X%128))+(planetStorageZ2[i]/100), 64-((128-planetStorageY2[i])+(128-(Y%128))), planetStorageZ2[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX3[i+1] != 0){
            ML_point(64-(128-planetStorageX3[i]+(X%128))+(planetStorageZ3[i]/100), 64+(128-planetStorageY3[i]+(Y%128))+(planetStorageZ3[i]/100), planetStorageZ3[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX4[i+1] != 0){
            ML_point(64+((128-planetStorageX4[i]+128)-(128-(X%128)))+(planetStorageZ4[i]/100), 64+(128-planetStorageY4[i]+128+(128-Y%128))-(planetStorageZ4[i]/100)+2, planetStorageZ4[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX5[i+1] != 0){
            ML_point(planetStorageX5[i]+(64-X%128)-(planetStorageZ5[i]/100), planetStorageY5[i]+(64-Y%128)-(planetStorageZ5[i]/100), planetStorageZ5[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX6[i+1] != 0){
            ML_point(64-((128-planetStorageX6[i])+(64-X%128))+(planetStorageZ6[i]/100), 64-((128-planetStorageY6[i])+(128-(Y%128))), planetStorageZ6[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX7[i+1] != 0){
            ML_point(64-(128-planetStorageX7[i]+(X%128))+(planetStorageZ7[i]/100), 64+(128-planetStorageY7[i]+(Y%128))+(planetStorageZ7[i]/100), planetStorageZ7[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX8[i+1] != 0){
            ML_point(64+((128-planetStorageX8[i]+128)-(128-(X%128)))+(planetStorageZ8[i]/100), 64+(128-planetStorageY8[i]+128+(128-Y%128))-(planetStorageZ8[i]/100)+2, planetStorageZ8[i]/100, 1);
            ++i;
        }
        i = 0;
    }
    if(X%128>=64 && Y%128>=64){
        while(planetStorageX2[i+1] != 0){
            ML_point(64+((128-planetStorageX2[i])+(64-X%128))+(planetStorageZ2[i]/100), 64-((128-planetStorageY2[i])+(128-(Y%128))), planetStorageZ2[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX3[i+1] != 0){
            ML_point(64+(128-planetStorageX3[i]+(X%128))+(planetStorageZ3[i]/100), 64+(128-planetStorageY3[i]+(Y%128))+(planetStorageZ3[i]/100), planetStorageZ3[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX4[i+1] != 0){
            ML_point(64-((128-planetStorageX4[i]+128)-(128-(X%128)))+(planetStorageZ4[i]/100), 64+(128-planetStorageY4[i]+128+(128-Y%128))-(planetStorageZ4[i]/100)+2, planetStorageZ4[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX5[i+1] != 0){
            ML_point(planetStorageX5[i]+(64-X%128)-(planetStorageZ5[i]/100), planetStorageY5[i]+(64-Y%128)-(planetStorageZ5[i]/100), planetStorageZ5[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX6[i+1] != 0){
            ML_point(64+((128-planetStorageX6[i])+(64-X%128))+(planetStorageZ6[i]/100), 64-((128-planetStorageY6[i])+(128-(Y%128))), planetStorageZ6[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX7[i+1] != 0){
            ML_point(64+(128-planetStorageX7[i]+(X%128))+(planetStorageZ7[i]/100), 64+(128-planetStorageY7[i]+(Y%128))+(planetStorageZ7[i]/100), planetStorageZ7[i]/100, 1);
            ++i;
        }
        i = 0;
        while(planetStorageX8[i+1] != 0){
            ML_point(64-((128-planetStorageX8[i]+128)-(128-(X%128)))+(planetStorageZ8[i]/100), 64+(128-planetStorageY8[i]+128+(128-Y%128))-(planetStorageZ8[i]/100)+2, planetStorageZ8[i]/100, 1);
            ++i;
        }
        i = 0;
    }
    ML_display_vram();
}
void generateOutputs(){// genere 3 constantes en fonc de X Y Z et des seed X0 Y0 Z0
    int local, local1;
    local = X0-(X/128);
    while(local/1000>=0){
        local1 = local%10;
        local = (local-local1)/10;
    }
    output1 = local;
    local = Y0-(Y/128);
    while(local/1000>=0){
        local1 = local%10;
        local = (local-local1)/10;
    }
    output2 = local;
    local = Z0-(Z/128);
    while(local/1000>=0){
        local1 = local%10;
        local = (local-local1)/10;
    }
    output3 = local;
    local = output1;
    output1 = output3*output2;
    local1 = output2;
    output2= local*output3;
    output3= local*local1;
    do{
        local1 = output1%10;
        output1 = (output1-local1)/10;
    } while (output1/100>=0);
    do{
        local1 = output2%10;
        output2 = (output2-local1)/10;
    } while (output2/100>=0);
    do
    {
        local1 = output3%10;
        output3 = (output3-local1)/10;
    } while (output3/100>=0);
}
void useOutputs(call){// rempli les listes d'infos des planetes avec les outputs
    int planetDensity = 16 + (output1 / 10);
    int planetX, planetY, planetZ;
    for (i = 26; i == planetDensity+26; ++i){
        planetX = (i/2) + (output1/10) -33;
        planetY = (i/2) + (output2/10) -33;
        planetZ = (i/2) + (output3/10) -33;
        switch(call){
        case 1:
            planetStorageX1[i-26] = planetX;
            planetStorageY1[i-26] = planetY;
            planetStorageZ1[i-26] = planetZ;
            break;
        case 2:
            planetStorageX2[i-26] = planetX;
            planetStorageY2[i-26] = planetY;
            planetStorageZ2[i-26] = planetZ;
            break;
        case 3:
            planetStorageX3[i-26] = planetX;
            planetStorageY3[i-26] = planetY;
            planetStorageZ3[i-26] = planetZ;
            break;
        case 4:
            planetStorageX4[i-26] = planetX;
            planetStorageY4[i-26] = planetY;
            planetStorageZ4[i-26] = planetZ;
            break;
        case 5:
            planetStorageX5[i-26] = planetX;
            planetStorageY5[i-26] = planetY;
            planetStorageZ5[i-26] = planetZ;
            break;
        case 6:
            planetStorageX6[i-26] = planetX;
            planetStorageY6[i-26] = planetY;
            planetStorageZ6[i-26] = planetZ;
            break;
        case 7:
            planetStorageX7[i-26] = planetX;
            planetStorageY7[i-26] = planetY;
            planetStorageZ7[i-26] = planetZ;
            break;
        case 8:
            planetStorageX8[i-26] = planetX;
            planetStorageY8[i-26] = planetY;
            planetStorageZ8[i-26] = planetZ;
            break;
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

