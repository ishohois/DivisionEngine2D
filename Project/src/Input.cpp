#include "Input.h"
namespace diva
{

    Input::Input(SDL_Rect *r) : rect(r)
    {
    }

    void Input::horizontalMovement(int dirSpeed)
    {
        (*rect).x = (*rect).x + dirSpeed;
    }
    
    void Input::verticalMovement(int dirSpeed){
        // not implemented;
    }

}
