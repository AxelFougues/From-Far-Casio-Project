/****************************************************************************/
/*                                                                          */
/*                              SCENE SPACE                                 */
/*                                                                          */
/****************************************************************************/


#include "Scene_Space.hpp"
extern Game game;
extern int scene;


/****************************************************************************/
/*                            INITIALSATION                                 */
/****************************************************************************/
Scene_Space::Scene_Space()
{
    camera = &game.camera;

    for (int i=0; i<MAX_STARS; i++)
    {
        stars[i].x = 50*i;
        stars[i].y = 0;
        stars[i].z = 0;
        stars[i].radius = 20;
    }

   //stars[0].x = -50;      stars[0].y = -50;     stars[0].z = 500;   stars[0].radius = 20;
   //stars[1].x = 0;    stars[1].y =  -50;     stars[1].z = 500;   stars[1].radius = 20;
   //stars[2].x = 50;   stars[2].y = -50;     stars[2].z = 500;   stars[2].radius = 20;
   //stars[3].x = -50;    stars[3].y = 0;  stars[3].z = 500;   stars[3].radius = 20;
   //stars[4].x = 0;    stars[4].y = 0;     stars[4].z = 500;   stars[4].radius = 20;
   //stars[5].x = 50;      stars[5].y = 0; stars[5].z = 500;   stars[5].radius = 20;
   //stars[6].x = -50;    stars[6].y = 50; stars[6].z = 500;   stars[6].radius = 20;
   //stars[7].x = 0;   stars[7].y = 50;  stars[7].z = 500;   stars[7].radius = 20;
   //stars[8].x = 50;   stars[8].y = 50;  stars[8].z = 500;   stars[8].radius = 20;

    //int t1 = time_get_ticks();
    //for (int i=0; i<1000; i++)

    while(scene == SCENE_SPACE)
    {
        // mise à jour des graphismes
        screen_update();
        // mise à jour du clavier
        input_update();
        // gestion du jeu
        engine_update();
        // régulation des fps
        //time_set_fps(FPS);
    }
}


/****************************************************************************/
/*                             screen_update                                */
/****************************************************************************/
void Scene_Space::screen_update()
{
    ML_clear_vram();
    ML_rectangle(0, 0, 127, 63, 0, ML_TRANSPARENT, ML_BLACK);
    int cos_phi = camera->cos_phi;
    int sin_phi = camera->sin_phi;
    int cos_theta = camera->cos_theta;
    int sin_theta = camera->sin_theta;
    //float cos_az = cosf(camera->roll);
    //float sin_az = sinf(camera->roll);


    for (int i=0; i<MAX_STARS; i++)
    {
        Star* star = &stars[i];
        int x_delta = cos_theta * (star->x - camera->x) - sin_theta * (star->z - camera->z);
        int y_delta = - sin_phi * sin_theta * (star->x - camera->x) / SHIFT_V + cos_phi * (star->y - camera->y) / SHIFT_V - sin_phi * cos_theta * (star->z - camera->z) / SHIFT_V;
        int z_delta = cos_phi * sin_theta * (star->x - camera->x) / SHIFT_V + sin_phi * (star->y - camera->y) + cos_phi * cos_theta * (star->z - camera->z) / SHIFT_V;

        //int x_delta = cos_theta * (star->x - camera->x) / SHIFT_V - sin_theta * (star->z - camera->z) / SHIFT_V;
        //int y_delta = - sin_phi * sin_theta * (star->x - camera->x) / (SHIFT_V * SHIFT_V) + cos_phi * (star->y - camera->y) / SHIFT_V - sin_phi * cos_theta * (star->z - camera->z) / (SHIFT_V * SHIFT_V);
        //int z_delta = cos_phi * sin_theta * (star->x - camera->x) / (SHIFT_V * SHIFT_V) + sin_phi * (star->y - camera->y) / SHIFT_V + cos_phi * cos_theta * (star->z - camera->z) / (SHIFT_V * SHIFT_V);


        if (z_delta > 0)
        {
            int x_screen = x_delta * camera->focal / z_delta;
            int y_screen = y_delta * camera->focal / z_delta;
            int radius_screen = star->radius * camera->focal * SHIFT_V / z_delta;
            if (radius_screen > 300) radius_screen = 300;

            ML_filled_circle(x_screen + 64, y_screen + 32, radius_screen, ML_WHITE);
        }

    }



    ML_vertical_line(64, 0, 3, ML_XOR);
    ML_vertical_line(64, 60, 63, ML_XOR);
    ML_horizontal_line(32, 0, 5, ML_XOR);
    ML_horizontal_line(32, 122, 127, ML_XOR);

    display_fps(time_get_fps());

    ML_display_vram();
}


/****************************************************************************/
/*                             engine_update                                */
/****************************************************************************/
void Scene_Space::engine_update()
{
    if (input_press(K_COMMA))   camera->move_forward(-VITESSE);
    if (input_press(K_STORE))   camera->move_forward(VITESSE);
    if (input_press(K_LEFT))    camera->move_theta(-ROTATION_H);
    if (input_press(K_RIGHT))   camera->move_theta(ROTATION_H);
    if (input_press(K_UP))      camera->move_phi(-ROTATION_V);
    if (input_press(K_DOWN))    camera->move_phi(ROTATION_V);
}




