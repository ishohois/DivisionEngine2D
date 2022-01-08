#ifndef TIMER_H
#define TIMER_H
#include <iostream>
#include <SDL2/SDL.h>

#define FPS 60;

namespace diva
{
    /* Denna klass tillhär spelmotorn 
    Klassen håller koll på 

    */

    class Timer
    {
    public:
        const Uint32 tickInterval = 1000 / FPS; // milliseconds per frame
        inline static Timer *getInstance()
        {
            if (!instance)
            {
                instance = new Timer();
            }
            return instance;
        }

        inline Uint32 getTicks()
        {
            return SDL_GetTicks();
        }

        inline float deltaTime(Uint32 nextTick)
        {
            return (float)delay(nextTick) / 10;
        }

        //float deltaTime = 0;
        inline void frameRateCap(Uint32 nextTick)
        {
            if (delay(nextTick) > 0)
            {
                SDL_Delay(delay(nextTick));
            }
        }

    private:
        Timer() = default;
        int delay(Uint32 nextTick)
        {
            int delay = nextTick - SDL_GetTicks();
            return delay;
        }

        static Timer *instance;
    };
}
#endif