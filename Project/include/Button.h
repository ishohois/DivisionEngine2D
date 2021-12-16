#ifndef BUTTON_H
#define BUTTON_H
#include "UIObject.h"
#include <string>
#include "SDL2/SDL.h"

namespace diva{
    class Button : public UIObject{
        SDL_Rect rectCollider;
    };
}

#endif
