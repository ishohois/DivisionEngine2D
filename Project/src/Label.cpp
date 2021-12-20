#include "SystemResources.h"
#include "Label.h"
#include <string>
#include <SDL2/SDL_ttf.h>
using namespace std;

namespace diva{
    
    Label::Label(int x, int y, int w, int h,
		std::string txt): UIObject(), text(txt)
	{
		SDL_Surface* surf = TTF_RenderText_Solid(system.get_font(), text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(system.renderer, surf);
		SDL_FreeSurface(surf);
	}

     void Label::gameObjectUpdate(float dt){
         
    }

    void Label::setText(std::string newText) {
		text = newText;
		SDL_DestroyTexture(texture);
		SDL_Surface* surf = TTF_RenderText_Solid(system.get_font(),
			text.c_str(), { 0,0,0 });
		texture = SDL_CreateTextureFromSurface(system.renderer, surf);
		SDL_FreeSurface(surf);
	}

   std::string Label::getText(){
		return text;
	}

    Label* Label::getInstance(int x, int y, int w,
		int h, std::string txt) {
		return new Label(x, y, w, h, txt);
	}

    void Label::draw() const {
		//SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
	}

}