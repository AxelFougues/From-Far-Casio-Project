/****************************************************************************/
/*                                                                          */
/*                                 CAMERA                                   */
/*                                                                          */
/****************************************************************************/


#ifndef DEF_CAMERA
#define DEF_CAMERA

extern "C"
{
    #include "mathf.h"
    #include "Debug.h"
}
#include "Commun.hpp"


class Camera
{
public:
    Camera();
    void move_forward(int distance);
    void move_theta(float value);
    void move_phi(float value);

public:
    int x, y, z;                // coordonnees de la camera
    float theta, phi;           // angle en radian de la position de la camera
    int cos_theta, sin_theta, cos_phi, sin_phi;
    int focal;
};



#endif
