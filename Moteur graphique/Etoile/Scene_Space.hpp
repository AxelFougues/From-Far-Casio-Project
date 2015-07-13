/****************************************************************************/
/*                                                                          */
/*                              SCENE SPACE                                 */
/*                                                                          */
/****************************************************************************/


#ifndef DEF_SCENE_SPACE
#define DEF_SCENE_SPACE


extern "C"
{
    #include "stdlib.h"
    #include "fxlib.h"
    #include "Mathf.h"
    #include "MonochromeLib.h"
    #include "Input.h"
    #include "Time.h"
}
#include "Commun.hpp"
#include "Game.hpp"
#include "Camera.hpp"


#define VITESSE 10
#define ROTATION_V 0.025
#define ROTATION_H 0.04
#define MAX_STARS 200


struct Star
{
    int x, y, z;
    int radius;
};

class Scene_Space
{
public:
    Scene_Space();
    void screen_update();
    void engine_update();
public:
    Camera* camera;
    Star stars[MAX_STARS];
};

#endif
