#include "SystemResources.h"

namespace diva
{

    SystemResources::SystemResources()
    {
        SDL_Init(SDL_INIT_EVERYTHING);
        window = SDL_CreateWindow("DivisionEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREENWIDTH, SCREENHEIGHT, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);

    }

    SystemResources::~SystemResources()
    {
        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_Quit();
    }
    
    std::string resPath = "./resources/";
    SystemResources system;
};
