#ifndef UIOBJECT_H
#define UIOBJECT_H
#include "GameObject.h"
#include <string>
#include <SDL2/SDL.h>

namespace diva {
    class UIObject : public GameObject{
        public:
        void setText(std::string input){};
        std::string getText(){};
    };
}


#endif