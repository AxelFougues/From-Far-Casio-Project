    //userInterface();
    generateOutputs(); 
    x= 64;
    y= 64;
    z= 64;
    display();
    while(!IsKeyDown(KEY_CTRL_EXIT)){
        if(IsKeyDown(KEY_CTRL_DOWN)){
            --y;
            display();
        }
        if(IsKeyDown(KEY_CTRL_UP)){
            ++y;
            display();
        }
        if(IsKeyDown(KEY_CTRL_RIGHT)){
            --x;
            display();
        }
        if(IsKeyDown(KEY_CTRL_LEFT)){
            ++x;
            display();
        }
        if(IsKeyDown(KEY_CTRL_ALPHA)){
            --z;
            display();
        }
        if(IsKeyDown(KEY_CTRL_SHIFT)){
            ++z;
            display();
        }
        if(x>128){
            x=0;
            ++X;
            display();
        }
        if(x<0){
            x=128;
            --X;
            display();
        }
        if(y>128){
            y=0;
            ++Y;
            display();
        }
        if(y<0){
            y=128;
            --Y;
            display();
        }
        if(z>128){
            z=0;
            ++Z;
            display();
        }
        if(z<0){
            z=128;
            --Z;
            display();
        }

    }
        Sleep(10);
}
void display(){
    ML_clear_vram();
    generateOutputs(); //cube central, on s'y trouve
    displayExternal(0,x,y,z);
    if(x<=64 && y<=64){               // dans quart superieur gauche
        X = X-1;
        generateOutputs(); //cube gauche
        displayExternal(0,x-128,y,z);
        Y = Y-1;
        generateOutputs(); //cube superieur gauche
        displayExternal(0,x-128,y-128,z);
        X = X+1;
        generateOutputs(); // cube superieur
        displayExternal(0,x,y-128,z);
        Y = Y+1;
    }
    if(x>=64 && y<=64){               // dans quart superieur droit
        X = X+1;
        generateOutputs(); //cube droit
        displayExternal(0,x+128,y,z);
        Y = Y-1;
        generateOutputs();// cube superieur droit
        displayExternal(0,x+128,y-128,z);
        X = X-1;
        generateOutputs(); // cube superieur
        displayExternal(0,x,y-128,z);
        Y = Y+1;
    }
    if(x<=64 && y>=64){               //dans quart inferieur gauche
        X = X-1;
        generateOutputs(); //cube gauche
        displayExternal(0,x-128,y,z);
        Y = Y+1;
        generateOutputs(); //cube inferieur gauche
        displayExternal(0,x-128,y+128,z);
        X = X+1;
        generateOutputs(); //cube inferieur
        displayExternal(0,x,y+128,z);
        Y = Y-1;
    }
    if(x>=64 && y>=64){               //dans quart inferieur droit
        X = X+1;
        generateOutputs(); //cube droit
        displayExternal(0,x+128,y,z);
        Y = Y+1;
        generateOutputs(); //cube inferieur droit
        displayExternal(0,x+128,y+128,z);
        X = X-1;
        generateOutputs(); //cube inferieur
        displayExternal(0,x,y+128,z);
        Y = Y-1;
    }
    ML_display_vram();
}
void displayExternal(call,x,y,z){
    if(call==0){
        for (i = 0; i < systemDensity-1; ++i){
            ML_circle(x+sunStorageX[i], y+sunStorageY[i], z+sunStorageZ[i], 1);
        }
        for (i = 0; i < planetCount-1; ++i){
            ML_filled_circle(x+astralStorageX1[i], y+astralStorageY1[i], z+astralStorageZ1[i], 1);
        }
    }
}

for (o = 0; o < planetDensity; ++o){
            //create planets around sun

            //X
            srand(output1+sunX+o);
            planetX = (rand() % 47) -15;
            if(planetX <= 9 && planetX >= 0){
                planetX = planetX+9;
            }
            if(planetX >= -9 && planetX <= 0){
                planetX = planetX-9;
            }
            planetX = sunX+planetX;

            //Y
            srand(output2+sunY+o);
            planetY = (rand() % 47) -15;
            if(planetY <= 9 && planetY >= 0){
                planetY = planetY+9;
            }
            if(planetY >= -9 && planetY <= 0){
                planetY = planetY-9;
            }
            planetY = sunY+planetY;
            //while(sqrt(pow(planetX-sunX,2)+pow(planetY-sunY,2))>20){
            //    --planetX;
            //    --planetY;
            //}

            //Z
            srand(output3+sunZ+o);
            planetZ = (rand() % 3)+1;
            astralStorageX1[o] = planetX;   //fill storage
            astralStorageY1[o] = planetY;
            astralStorageZ1[o] = planetZ;
            ++planetCount;
            for (p = o-1; p > 0; --p){
                while(fabs(astralStorageX1[p]-astralStorageX1[o]) <= (astralStorageZ1[p]+astralStorageZ1[o]+1)){
                    ++astralStorageX1[p];
                }
                astralStorageZ1[100] = planetZ;
                while(fabs(astralStorageY1[p]-astralStorageY1[o]) <= (astralStorageZ1[p]+astralStorageZ1[o]+1)){
                    ++astralStorageY1[p];
                }
                
            }
        }