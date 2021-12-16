#ifndef INPUT_H
#define INPUT_H
#include <SDL2/SDL.h>

namespace diva
{
    class Input
    {
    private:
        SDL_Rect *rect;
        /* data */
        ~Input();
    public:
        Input(SDL_Rect*);
       // void horizontalMovement(int); // Takes a direction/speed
        void jump(int);
        Uint8* keyState; //pekare till SDL_GetKeyboardState 
        bool isKeyDown(SDL_Scancode key); //enum med alla tangenter
    };
    // Input in = new Input(*rect); 
} 

#endif