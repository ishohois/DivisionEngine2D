#include "SystemResources.h"

namespace diva
{
    SystemResources::SystemResources()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("DivisionEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);
        //Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
        // music = Mix_LoadWAV((resPath + "sounds/....").c_str());
        // Mix_PlayChannel(-1, music, -1);
    }

    SystemResources::~SystemResources()
    {
        Mix_FreeChunk(music);
        Mix_CloseAudio();
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    
    SystemResources system;
};
