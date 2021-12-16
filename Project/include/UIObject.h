#ifndef UIOBJECT_H
#define UIOBJECT_H
#include "GameObject.h"
#include <SDL2/SDL.h>

namespace diva {
    class UIObject : public GameObject{
        public:
        virtual void mouseDown(int x, int y){}; 
        virtual void mouseUp(int x, int y){};
        void setText(std::string input){};
        std::string getText(){};
    };
}


#endif