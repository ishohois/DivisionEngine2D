#ifndef BUTTON_H
#define BUTTON_H
#include "UIObject.h"
#include <string>
#include "SDL2/SDL.h"

namespace diva{
    class Button : public UIObject{
        public:
        virtual void mouseDown(int x, int y){}; 
        virtual void mouseUp(int x, int y){};
        void setText(std::string input){};
        std::string getText(){};
        SDL_Rect rectCollider;
    };
}

#endif
