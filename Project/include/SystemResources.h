#ifndef SYSTEMRESOURCES_H
#define SYSTEMRESOURCES_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <string>

namespace diva
{
    struct SystemResources
    {
        SystemResources();
        ~SystemResources();

        SDL_Window *window;
        SDL_Renderer *renderer;
        Mix_Chunk *music;
    };

    extern std::string resPath;
    extern SystemResources system;
};

#endif
