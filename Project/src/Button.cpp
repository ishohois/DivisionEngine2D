#include "Button.h"
#include <SDL2/SDL_ttf.h>
#include "SystemResources.h"

namespace diva{
    Button::Button(int x, int y, int w, int h, std::string txt){
        SDL_Surface* surf = TTF_RenderText_Solid(sys.get_font(), txt.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(system.renderer, surf);
		SDL_FreeSurface(surf);
    }

    Button::~Button(){
        SDL_DestroyTexture(texture);
    }

    Button* Button::getInstance(int x, int y, int w, int h, std::string txt) {
		return new Button(x, y, w, h, txt);
	}

    void Button::mouseDown(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			isDown = true;
	}

    void Button::mouseUp(const SDL_Event& eve) {
		SDL_Point p = { eve.button.x, eve.button.y };
		if (SDL_PointInRect(&p, &getRect()))
			perform(this);

		isDown = false;
	}
}