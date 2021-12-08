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
    public:
        Input(SDL_Rect*);
        void horizontalMovement(int); // Takes a direction/speed
        void verticalMovement(int); // Takes a direction/speed
        
        /*
        Jump()



        */

    };

    // Input in = new Input(*rect);

} // namespace diva

#endif