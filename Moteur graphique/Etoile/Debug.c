/****************************************************************************/
/*                                                                          */
/*                                 DEBUG                                    */
/*                                                                          */
/* Par NineStars                                                            */
/****************************************************************************/

#include "Debug.h"


void debug_int(int variable)
{
    SaveDisp(SAVEDISP_PAGE1);
    PopUpWin(3);
	locate(10,4);
	print_v(variable);
	Bdisp_PutDisp_DD();
	Sleep(50);
	Sleep(700);
	RestoreDisp(SAVEDISP_PAGE1);
	Bdisp_PutDisp_DD();
}

void debug_str(const unsigned char *chaine)
{
    SaveDisp(SAVEDISP_PAGE1);
    PopUpWin(3);
	locate(8,4);
	Print(chaine);
	Bdisp_PutDisp_DD();
	Sleep(50);
	Sleep(700);
	RestoreDisp(SAVEDISP_PAGE1);
	Bdisp_PutDisp_DD();
}

void display_fps(int fps)
{
    locate(0,0);
    print_v(fps);
}

void print_v(int variable)
{

    int i, length=0;
    char str[12] = "0";
    if(variable)
    {
        if(variable<0)
        {
            length++;
            str[0] = '-';
            variable = -variable;
        }
        for(i=variable ; i ; i/=10) length++;
        str[length] = 0;
        for( ; variable ; variable/=10) str[--length] = variable%10+'0';
    }
    Print(str);
}
