/****************************************************************************/
/*                                                                          */
/*                                  Input                                   */
/*                                                                          */
/* Par NineStars                                                         V2 */
/****************************************************************************/

#include "input.h"

static int SysCallCode[] = {0xD201422B,0x60F20000,0x80010070};
static int (*SysCall)( int R4, int R5, int R6, int R7, int FNo ) = (void*)&SysCallCode;

unsigned char last_key[55] = {0};
unsigned char current_key[55] = {0};


void input_update()
{
    int i;
    for (i=0; i<55; i++)
    {
        last_key[i] = current_key[i];
        if (key_down(i+25))
        {
            if (current_key[i] < 255)
            {
                current_key[i] ++;
            }
        } else {
            current_key[i] = 0;
        }

    }
}

int input_press(char key)
{
    key -= 25;
    return current_key[key];
}

int input_trigger(char key)
{
    key -= 25;
    return (current_key[key] == 1);
}

int input_release(char key)
{
    key -= 25;
    return (last_key[key] && !current_key[key]);
}

int input_hold_short(char key)
{
    key -= 25;
    return current_key[key] == 7;
}

int input_hold_long(char key)
{
    key -= 25;
    return current_key[key] == 14;
}

int input_repeat(char key)
{
    key -= 25;
    if (current_key[key] == 1)
    {
        return 1;
    }
    if (current_key[key] == 8)
    {
        current_key[key] = 6;
        return 1;
    }
    return 0;
}

int input_repeat_short(char key)
{
    key -= 25;
    if (current_key[key] == 1)
    {
        return 1;
    }
    if (current_key[key] == 6)
    {
        current_key[key] = 4;
        return 1;
    }
    return 0;
}

int input_trigger_or_hold(char key)
{
    key -= 25;
    if (last_key[key] > 0 && last_key[key] < 14 && current_key[key] == 0)
    {
        return 1;
    }
    if (current_key[key] == 14)
    {
        return 2;
    }
    return 0;
}

int input_dir4()
{
    if (current_key[K_DOWN-25])  return 2;
    if (current_key[K_LEFT-25])  return 4;
    if (current_key[K_RIGHT-25]) return 6;
    if (current_key[K_UP-25])    return 8;
    return 0;
}

int input_dir8()
{
    if (current_key[K_LEFT-25]  && current_key[K_DOWN-25])  return 1;
    if (current_key[K_DOWN-25]  && current_key[K_RIGHT-25]) return 3;
    if (current_key[K_LEFT-25]  && current_key[K_UP-25])    return 7;
    if (current_key[K_RIGHT-25] && current_key[K_UP-25])    return 9;
    if (current_key[K_DOWN-25])                             return 2;
    if (current_key[K_LEFT-25])                             return 4;
    if (current_key[K_RIGHT-25])                            return 6;
    if (current_key[K_UP-25])                               return 8;
    return 0;
}

void input_manual(char key)
{
    key -= 25;
    current_key[key] += 1;
}



#define SCA 0xD201D002
#define SCB 0x422B0009
#define SCE 0x80010070

typedef int(*sc_i2cp2sip) (char*, char*, short int*, short int*);
typedef int(*sc_iv) (void);
typedef int(*sc_4i) (int, int, int);

const unsigned int sc003b[] = {SCA, SCB, SCE, 0x3B};
const unsigned int sc0015[] = {SCA, SCB, SCE, 0x15};
const unsigned int sc0248[] = {SCA, SCB, SCE, 0x248};

#define RTC_GetTicks (*(sc_iv)sc003b)
#define PutKey (*(sc_4i)sc0248)
#define GlibGetOSVersionInfo (*(sc_i2cp2sip)sc0015)

int OSVersionAsInt(void)
{
	unsigned char mainversion;
	unsigned char minorversion;
	unsigned short release;
	unsigned short build;
	GlibGetOSVersionInfo( &mainversion, &minorversion, &release, &build );
	return ( ( mainversion << 24 ) & 0xFF000000 ) | ( ( minorversion << 16 ) & 0x00FF0000 ) | ( release & 0x0000FFFF );
}
#define isOS2 (OSVersionAsInt() >= 0x02020000)
#define OS2(x,y) ((OSVersionAsInt() >= 0x02020000)?y:x)

void key_inject(int keycode)
{
	(*SysCall)(keycode, 0, 0, 0, 0x248);
}

static void delay()
{
	unsigned char i;
	for(i=0 ; i<5 ; i++);
}

unsigned char CheckKeyRow(unsigned char code)
{
	unsigned char result=0;
	short*PORTB_CTRL=(void*)0xA4000102;
	short*PORTM_CTRL=(void*)0xA4000118;
	char*PORTB=(void*)0xA4000122;
	char*PORTM=(void*)0xA4000138;
	char*PORTA=(void*)0xA4000120;
	short smask;
	char cmask;
	unsigned char column, row;

	column = code>>4;
	row = code &0x0F;

	smask = 0x0003 << (( row %8)*2);
	cmask = ~( 1 << ( row %8) );
	if(row <8)
	{
		*PORTB_CTRL = 0xAAAA ^ smask;
		*PORTM_CTRL = (*PORTM_CTRL & 0xFF00 ) | 0x00AA;
		delay();
		*PORTB = cmask;
		*PORTM = (*PORTM & 0xF0 ) | 0x0F;
	}
	else
	{
		*PORTB_CTRL = 0xAAAA;
		*PORTM_CTRL = ((*PORTM_CTRL & 0xFF00 ) | 0x00AA)  ^ smask;
		delay();
		*PORTB = 0xFF;
		*PORTM = (*PORTM & 0xF0 ) | cmask;
	}
	delay();
	result = (~(*PORTA))>>column & 1;
	delay();
	*PORTB_CTRL = 0xAAAA;
	*PORTM_CTRL = (*PORTM_CTRL & 0xFF00 ) | 0x00AA;
	delay();
	*PORTB_CTRL = 0x5555;
	*PORTM_CTRL = (*PORTM_CTRL & 0xFF00 ) | 0x0055;
	delay();

	return result;
}

unsigned char key_down(unsigned char code)
{
	unsigned short key[8];
	const unsigned short* keyboardregister = (unsigned short*)0xA44B0000;

	if(isOS2)
	{
		unsigned char row = code%10;
		memcpy(&key, keyboardregister, sizeof(unsigned short) << 3);

		return (0 != (key[row >> 1] & 1 << code / 10 - 1 + ((row & 1) << 3)));
	}
	else
	{
		return CheckKeyRow((code % 10) + ((code / 10 - 1) << 4));
	}
}
