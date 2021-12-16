#include "Input.h"
namespace diva
{

    Input::Input(SDL_Rect *r) : rect(r)
    {
        
    }

   /* void Input::horizontalMovement(int dirSpeed)
    {
        (*rect).x = (*rect).x + dirSpeed;
    }*/ //kommer nog ersättas med isKeyDown()
    
    void Input::jump(int dirSpeed){
        (*rect).y = (*rect).y + dirSpeed;
    }

    bool Input::isKeyDown(SDL_Scancode key){
        if (keyState != 0){
            if(keyState[key] == 1){//om tangenten faktiskt blir nedtryckt
                return true;
            }else{
                return false;
            }
        }return false;
    }//använd denna funktion i RigidBody för att kunna öka hastigheten.

}
