#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

struct System
{
	System();
	~System();

	SDL_Window* win;
	SDL_Renderer* ren;
	Mix_Chunk* music;
};

extern System sys;

#endif
