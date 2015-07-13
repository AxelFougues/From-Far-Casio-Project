/****************************************************************************/
/*                                                                          */
/*                                  TIME                                    */
/*                                                                          */
/* Par NineStars                                                            */
/****************************************************************************/

#include "Time.h"

#define SCA 0xD201D002
#define SCB 0x422B0009
#define SCE 0x80010070

typedef int(*sc_iv) (void);
const unsigned int sc003ba[] = {SCA, SCB, SCE, 0x3B};

#define RTC_GetTicks (*(sc_iv)sc003ba)

int time_get_ticks()
{
	return RTC_GetTicks();
}

int time_get_fps()
{
    static unsigned int fps = 0, fps_count = 0, time = 0;

    if( time_get_ticks() - time >= 128)
		{
			fps = fps_count;
			fps_count = 1;
			time = time_get_ticks();
		} else fps_count++;

return fps;
}


void time_set_fps(int fps_wish)
{
    static unsigned int fps = 0, fps_count = 0;

    //fps_wish = 128 / fps_wish;

    do
    {
        fps = time_get_ticks();
    }
    while(fps < fps_count+fps_wish);
    fps_count = time_get_ticks();
}
